#include "gtest/gtest.h"
#include "SDL2/SDL.h"
#include "MessageMaker.hpp"
#include "ButtonsAxesStatus.hpp"

TEST(MessageMakerStandardTests, MakeMessage){

    xpadcar_rpi::ButtonsAxesStatus buttonsAxis {};
    xpadcar_rpi::MessageMaker messageMaker;

    std::string returnedString = messageMaker.MakeMessage(buttonsAxis.testAxes, buttonsAxis.testButtons);
    std::string expectedString {"{[rightTrigger:0][leftTrigger:0][keyA:0]}"};
    EXPECT_EQ(returnedString, expectedString);


    buttonsAxis.rightTrigger = 10;
    buttonsAxis.leftTrigger = 20;
    buttonsAxis.keyA = true;
    returnedString = messageMaker.MakeMessage(buttonsAxis.testAxes, buttonsAxis.testButtons);
    expectedString = "{[rightTrigger:10][leftTrigger:20][keyA:1]}";
    EXPECT_EQ(returnedString, expectedString);

    buttonsAxis.rightTrigger = 100;
    buttonsAxis.leftTrigger = 100;
    buttonsAxis.keyA = false;
    returnedString = messageMaker.MakeMessage(buttonsAxis.testAxesEnum, buttonsAxis.testButtonsEnum);
    expectedString = "{[0:100][1:100][10:0]}";
    EXPECT_EQ(returnedString, expectedString);
}