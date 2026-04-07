#include "CppUnitTest.h"
#include "../decision/Point.h"
#include "../decision/Color.h"
#include "../decision/LineStyle.h"
#include "../decision/Line.h"
#include <sstream>
#include <string>
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LineTests {

    TEST_CLASS(PointTests) {
public:
    TEST_METHOD(Point_EqualityOperator_ReturnsTrueForEqualPoints) {
        Point p1(5, 10);
        Point p2(5, 10);
        Assert::IsTrue(p1 == p2);
    }

    TEST_METHOD(Point_InequalityOperator_ReturnsTrueForDifferentPoints) {
        Point p1(5, 10);
        Point p2(10, 5);
        Assert::IsTrue(p1 != p2);
    }

    TEST_METHOD(Point_OutputStream_FormatsCorrectly) {
        Point p(3, 7);
        ostringstream oss;
        oss << p;
        Assert::AreEqual(string("(3, 7)"), oss.str());
    }

    TEST_METHOD(Point_InputStream_ReadsCorrectly) {
        istringstream iss("15 25");
        Point p;
        iss >> p;
        Assert::AreEqual(15, p.x);
        Assert::AreEqual(25, p.y);
    }
    };

    TEST_CLASS(ColorTests) {
public:
    TEST_METHOD(Color_ValidComponents_CreatesColor) {
        Color c(100, 150, 200);
        Assert::AreEqual(100u, c.GetRed());
        Assert::AreEqual(150u, c.GetGreen());
        Assert::AreEqual(200u, c.GetBlue());
    }

    TEST_METHOD(Color_InvalidComponents_ThrowsException) {
        auto func = [] { Color c(300, 0, 0); };
        Assert::ExpectException<out_of_range>(func);
    }

    TEST_METHOD(Color_OutputStream_FormatsCorrectly) {
        Color c(255, 128, 0);
        ostringstream oss;
        oss << c;
        Assert::AreEqual(string("RGB(255, 128, 0)"), oss.str());
    }

    TEST_METHOD(Color_InputStream_ReadsCorrectly) {
        istringstream iss("50 100 200");
        Color c(0, 0, 0);
        iss >> c;
        Assert::AreEqual(50u, c.GetRed());
        Assert::AreEqual(100u, c.GetGreen());
        Assert::AreEqual(200u, c.GetBlue());
    }
    };

    TEST_CLASS(LineStyleTests) {
public:
    TEST_METHOD(LineStyle_DefaultConstructor_SetsSolidAndThickness1) {
        LineStyle style;
        Assert::AreEqual(LineType::Solid, style.GetType());
        Assert::AreEqual(1, style.GetThickness());
    }

    TEST_METHOD(LineStyle_ValidParameters_CreatesStyle) {
        LineStyle style(LineType::Dash, 5);
        Assert::AreEqual(LineType::Dash, style.GetType());
        Assert::AreEqual(5, style.GetThickness());
    }

    TEST_METHOD(LineStyle_InvalidThickness_ThrowsException) {
        auto func = [] { LineStyle style(LineType::Solid, 0); };
        Assert::ExpectException<invalid_argument>(func);
    }

    TEST_METHOD(LineStyle_TypeToString_ReturnsCorrectString) {
        LineStyle style(LineType::DashDot, 2);
        Assert::AreEqual(string("dash-dot"), style.TypeToString());
    }

    TEST_METHOD(LineStyle_OutputStream_FormatsCorrectly) {
        LineStyle style(LineType::Dot, 3);
        ostringstream oss;
        oss << style;
        string result = oss.str();
        Assert::IsTrue(result.find("dot") != string::npos);
        Assert::IsTrue(result.find("thickness=3") != string::npos);
    }

    TEST_METHOD(LineStyle_SetThickness_UpdatesValue) {
        LineStyle style;
        style.SetThickness(10);
        Assert::AreEqual(10, style.GetThickness());
    }

    TEST_METHOD(LineStyle_SetInvalidThickness_ThrowsException) {
        LineStyle style;
        auto func = [&style] { style.SetThickness(-1); };
        Assert::ExpectException<invalid_argument>(func);
    }
    };

    TEST_CLASS(LineTests) {
public:
    TEST_METHOD(Line_ConstructorWithPointsOnly_UsesDefaultStyleAndBlackColor) {
        Point p1(10, 20);
        Point p2(30, 40);
        Line line(p1, p2);
        Assert::AreEqual(p1, line.GetStart());
        Assert::AreEqual(p2, line.GetEnd());
        Assert::AreEqual(LineType::Solid, line.GetStyle().GetType());
        Assert::AreEqual(1, line.GetStyle().GetThickness());
        Assert::AreEqual(0u, line.GetColor().GetRed());
        Assert::AreEqual(0u, line.GetColor().GetGreen());
        Assert::AreEqual(0u, line.GetColor().GetBlue());
    }

    TEST_METHOD(Line_ConstructorWithAllParameters_SetsCorrectly) {
        Point p1(5, 15);
        Point p2(25, 35);
        Color color(100, 150, 200);
        LineStyle style(LineType::Dash, 4);
        Line line(p1, p2, color, style);
        Assert::AreEqual(p1, line.GetStart());
        Assert::AreEqual(p2, line.GetEnd());
        Assert::AreEqual(color.GetRed(), line.GetColor().GetRed());
        Assert::AreEqual(color.GetGreen(), line.GetColor().GetGreen());
        Assert::AreEqual(color.GetBlue(), line.GetColor().GetBlue());
        Assert::AreEqual(LineType::Dash, line.GetStyle().GetType());
        Assert::AreEqual(4, line.GetStyle().GetThickness());
    }

    TEST_METHOD(Line_SetStyle_UpdatesStyle) {
        Point p1(0, 0);
        Point p2(10, 10);
        Line line(p1, p2);
        LineStyle newStyle(LineType::Dot, 5);
        line.SetStyle(newStyle);
        Assert::AreEqual(LineType::Dot, line.GetStyle().GetType());
        Assert::AreEqual(5, line.GetStyle().GetThickness());
    }

    TEST_METHOD(Line_SetColor_UpdatesColor) {
        Point p1(0, 0);
        Point p2(10, 10);
        Line line(p1, p2);
        Color newColor(255, 0, 255);
        line.SetColor(newColor);
        Assert::AreEqual(255u, line.GetColor().GetRed());
        Assert::AreEqual(0u, line.GetColor().GetGreen());
        Assert::AreEqual(255u, line.GetColor().GetBlue());
    }

    TEST_METHOD(Line_ToString_ReturnsFormattedString) {
        Point p1(1, 2);
        Point p2(3, 4);
        Color color(10, 20, 30);
        LineStyle style(LineType::DashDot, 2);
        Line line(p1, p2, color, style);
        string result = line.ToString();
        Assert::IsTrue(result.find("(1, 2) -> (3, 4)") != string::npos);
        Assert::IsTrue(result.find("RGB(10, 20, 30)") != string::npos);
        Assert::IsTrue(result.find("dash-dot") != string::npos);
    }

    TEST_METHOD(Line_Print_OutputsToString) {
        Point p1(1, 1);
        Point p2(5, 5);
        Line line(p1, p2);
        ostringstream output;
        auto oldCoutBuffer = cout.rdbuf();
        cout.rdbuf(output.rdbuf());
        line.Print();
        cout.rdbuf(oldCoutBuffer);
        Assert::IsTrue(output.str().find("Line:") != string::npos);
    }

    TEST_METHOD(Line_OutputStreamOperator_WorksCorrectly) {
        Point p1(2, 3);
        Point p2(7, 8);
        Color color(50, 100, 150);
        LineStyle style(LineType::Solid, 1);
        Line line(p1, p2, color, style);
        ostringstream oss;
        oss << line;
        Assert::IsTrue(oss.str().find("(2, 3)") != string::npos);
        Assert::IsTrue(oss.str().find("(7, 8)") != string::npos);
    }

    TEST_METHOD(Line_ReadFromStream_ValidInput_ReturnsCorrectLine) {
        istringstream iss("10 20\n30 40\n255 0 0\nsolid 2\n");
        Line line = Line::ReadFromStream(iss);
        Assert::AreEqual(10, line.GetStart().x);
        Assert::AreEqual(20, line.GetStart().y);
        Assert::AreEqual(30, line.GetEnd().x);
        Assert::AreEqual(40, line.GetEnd().y);
        Assert::AreEqual(255u, line.GetColor().GetRed());
        Assert::AreEqual(0u, line.GetColor().GetGreen());
        Assert::AreEqual(0u, line.GetColor().GetBlue());
        Assert::AreEqual(LineType::Solid, line.GetStyle().GetType());
        Assert::AreEqual(2, line.GetStyle().GetThickness());
    }

    TEST_METHOD(Line_ReadFromStream_InvalidColor_ThrowsException) {
        istringstream iss("10 20\n30 40\n300 0 0\nsolid 2\n");
        auto func = [&iss] { Line::ReadFromStream(iss); };
        Assert::ExpectException<out_of_range>(func);
    }

    TEST_METHOD(Line_ReadFromStream_InvalidThickness_ThrowsException) {
        istringstream iss("10 20\n30 40\n255 0 0\nsolid 0\n");
        auto func = [&iss] { Line::ReadFromStream(iss); };
        Assert::ExpectException<invalid_argument>(func);
    }

    TEST_METHOD(Line_ReadFromStream_InvalidLineType_ThrowsException) {
        istringstream iss("10 20\n30 40\n255 0 0\ninvalid_type 2\n");
        auto func = [&iss] { Line::ReadFromStream(iss); };
        Assert::ExpectException<invalid_argument>(func);
    }
    };
}