#include "Harl.hpp"

Harl::Harl()
{
    cout << "Harl: I am Harl, the universe revolves around me!" << endl;
}

Harl::~Harl()
{
    cout << "Harl: This place sucks anyways" << endl;
}

void Harl::debug()
{
    cout << "Harl: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << endl;
}

void Harl::info()
{
    cout << "Harl: I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << endl;
}

void Harl::warning()
{
    cout << "Harl: I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << endl;
}

void Harl::error()
{
    cout << "Harl: This is unacceptable, I want to speak to the manager now." << endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            (this->*functions[i])();
    }
}

void Harl::complain_about_everything()
{
    this->complain("debug");
    this->complain("info");
    this->complain("warning");
    this->complain("error");
}

