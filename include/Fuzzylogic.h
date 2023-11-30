#ifndef FuzzyLogic_H_
#define FuzzyLogic_H_
#include <Arduino.h>
#include <Fuzzy.h>

class FuzzyLogic 
{
private:
    /* data */

    Fuzzy *fuzzy = new Fuzzy();

    // set input sensor mq135
    FuzzySet *nh3_normal = new FuzzySet(0, 10, 10, 25);
    FuzzySet *nh3_tinggi = new FuzzySet(26, 30, 30, 35);
    FuzzySet *nh3_sangat_tinggi = new FuzzySet(36, 45, 45, 50);

    // set input sensor Mq4
    FuzzySet *ch4_normal = new FuzzySet(0, 100, 100, 200);
    FuzzySet *ch4_tinggi = new FuzzySet(201, 250, 250, 300);
    FuzzySet *ch4_sangat_tinggi = new FuzzySet(301, 750, 750, 1000);

    // set input sensor mq7
    FuzzySet *co_normal = new FuzzySet(0, 4, 4, 8);
    FuzzySet *co_tinggi = new FuzzySet(9, 15, 15, 25);
    FuzzySet *co_sangat_tinggi = new FuzzySet(26, 50, 50, 80);

    // set output clasication
    FuzzySet *normal = new FuzzySet(0, 25, 25, 50);
    FuzzySet *bahaya = new FuzzySet(51, 75, 75, 100);
    FuzzySet *sangat_bahaya = new FuzzySet(101, 125, 125, 150);
    void fuzzy_set_input_output();
    void fuzzy_set_rule();

public:
    FuzzyLogic(/* args */);
    void fuzzy_init();
    void fuzzy_compute(float nh3, float ch4, float co);
};

#endif