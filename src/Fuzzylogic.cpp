#include "FuzzyLogic.h"

static FuzzyLogic *instance = NULL;

FuzzyLogic::FuzzyLogic()
{
    instance = this;
}

void FuzzyLogic::fuzzy_set_input_output()
{
    // Fuzzy input
    FuzzyInput *input_nh3 = new FuzzyInput(1);

    input_nh3->addFuzzySet(nh3_normal);
    input_nh3->addFuzzySet(nh3_tinggi);
    input_nh3->addFuzzySet(nh3_sangat_tinggi);
    fuzzy->addFuzzyInput(input_nh3);

    FuzzyInput *input_ch4 = new FuzzyInput(2);

    input_ch4->addFuzzySet(ch4_normal);
    input_ch4->addFuzzySet(ch4_tinggi);
    input_ch4->addFuzzySet(ch4_sangat_tinggi);
    fuzzy->addFuzzyInput(input_ch4);

    FuzzyInput *input_co = new FuzzyInput(3);

    input_co->addFuzzySet(co_normal);
    input_co->addFuzzySet(co_tinggi);
    input_co->addFuzzySet(co_sangat_tinggi);
    fuzzy->addFuzzyInput(input_co);

    // Fuzzy output

    FuzzyOutput *output = new FuzzyOutput(1);

    output->addFuzzySet(normal);
    output->addFuzzySet(bahaya);
    output->addFuzzySet(sangat_bahaya);
    fuzzy->addFuzzyOutput(output);
}

void FuzzyLogic::fuzzy_set_rule()
{

    // fuzzy rule with output normal
    //  IF nh3 is normal and ch4 is normal and co is normal THEN normal
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_normal = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_normal->joinWithAND(nh3_normal, ch4_normal);
    FuzzyRuleAntecedent *if_nh3_normal_and_ch3_normal_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch3_normal_and_co_normal->joinWithAND(if_nh3_normal_and_ch4_normal, co_normal);

    FuzzyRuleConsequent *then_normal = new FuzzyRuleConsequent();
    then_normal->addOutput(normal);

    FuzzyRule *fuzzy_rule_normal = new FuzzyRule(1, if_nh3_normal_and_ch3_normal_and_co_normal, then_normal);
    fuzzy->addFuzzyRule(fuzzy_rule_normal);

    // IF nh3 is tinggi and ch4 is normal and co is normal THEN bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_normal = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_normal->joinWithAND(nh3_tinggi, ch4_normal);
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_normal_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_normal_and_co_normal->joinWithAND(if_nh3_tinggi_and_ch4_normal, co_normal);

    FuzzyRuleConsequent *then_normal2 = new FuzzyRuleConsequent();
    then_normal2->addOutput(normal);

    FuzzyRule *fuzzy_rule_normal2 = new FuzzyRule(2, if_nh3_tinggi_and_ch4_normal_and_co_normal, then_normal2);
    fuzzy->addFuzzyRule(fuzzy_rule_normal2);

    // IF nh3 normal and ch4 tinggi and co normal THEN normal
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_tinggi->joinWithAND(nh3_normal, ch4_tinggi);
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_tinggi_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_tinggi_and_co_normal->joinWithAND(if_nh3_normal_and_ch4_tinggi, co_normal);

    FuzzyRuleConsequent *then_normal3 = new FuzzyRuleConsequent();
    then_normal3->addOutput(normal);

    FuzzyRule *fuzzy_rule_normal3 = new FuzzyRule(3, if_nh3_normal_and_ch4_tinggi_and_co_normal, then_normal3);
    fuzzy->addFuzzyRule(fuzzy_rule_normal3);

    // IF nh3 normal and ch4 normal and co tinggi THEN normal
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_normal_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_normal_and_co_tinggi->joinWithAND(if_nh3_normal_and_ch4_normal, co_tinggi);

    FuzzyRuleConsequent *then_normal4 = new FuzzyRuleConsequent();
    then_normal4->addOutput(normal);

    FuzzyRule *fuzzy_rule_normal4 = new FuzzyRule(4, if_nh3_normal_and_ch4_normal_and_co_tinggi, then_normal4);
    fuzzy->addFuzzyRule(fuzzy_rule_normal4);

    // fuzzy rule with output bahaya
    //  IF nh3 tinggi and ch4 tinggi and co normal THEN bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_tinggi->joinWithAND(nh3_tinggi, ch4_tinggi);
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_tinggi_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_tinggi_and_co_normal->joinWithAND(if_nh3_tinggi_and_ch4_tinggi, co_normal);

    FuzzyRuleConsequent *then_bahaya = new FuzzyRuleConsequent();
    then_bahaya->addOutput(bahaya);

    FuzzyRule *fuzzy_rule_bahaya = new FuzzyRule(5, if_nh3_tinggi_and_ch4_tinggi_and_co_normal, then_bahaya);
    fuzzy->addFuzzyRule(fuzzy_rule_bahaya);

    // IF nh3 tinggi and ch4 normal and co tinggi THEN bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_normal_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_normal_and_co_tinggi->joinWithAND(if_nh3_tinggi_and_ch4_normal, co_tinggi);

    FuzzyRuleConsequent *then_bahaya2 = new FuzzyRuleConsequent();
    then_bahaya2->addOutput(bahaya);

    FuzzyRule *fuzzy_rule_bahaya2 = new FuzzyRule(6, if_nh3_tinggi_and_ch4_normal_and_co_tinggi, then_bahaya2);
    fuzzy->addFuzzyRule(fuzzy_rule_bahaya2);

    // IF nh3 normal and ch4 tinggi and co tinggi THEN bahaya
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_tinggi_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_tinggi_and_co_tinggi->joinWithAND(if_nh3_normal_and_ch4_tinggi, co_tinggi);

    FuzzyRuleConsequent *then_bahaya3 = new FuzzyRuleConsequent();
    then_bahaya3->addOutput(bahaya);

    FuzzyRule *fuzzy_rule_bahaya3 = new FuzzyRule(7, if_nh3_normal_and_ch4_tinggi_and_co_tinggi, then_bahaya3);
    fuzzy->addFuzzyRule(fuzzy_rule_bahaya3);

    // rule with output sangat bahaya
    // IF nh3 normal and ch4 normal and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_normal_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_normal_and_co_sangat_tinggi->joinWithAND(if_nh3_normal_and_ch4_normal, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya = new FuzzyRuleConsequent();
    then_sangat_bahaya->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya = new FuzzyRule(8, if_nh3_normal_and_ch4_normal_and_co_sangat_tinggi, then_sangat_bahaya);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya);

    // IF nh3 normal and ch4 sangat tinggi and co normal THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_sangat_tinggi->joinWithAND(nh3_normal, ch4_sangat_tinggi);
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_sangat_tinggi_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_sangat_tinggi_and_co_normal->joinWithAND(if_nh3_normal_and_ch4_sangat_tinggi, co_normal);

    FuzzyRuleConsequent *then_sangat_bahaya2 = new FuzzyRuleConsequent();
    then_sangat_bahaya2->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya2 = new FuzzyRule(9, if_nh3_normal_and_ch4_sangat_tinggi_and_co_normal, then_sangat_bahaya2);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya2);

    // IF nh3 normal and ch4 tinggi and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_tinggi_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_tinggi_and_co_sangat_tinggi->joinWithAND(if_nh3_normal_and_ch4_tinggi, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya3 = new FuzzyRuleConsequent();
    then_sangat_bahaya3->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya3 = new FuzzyRule(10, if_nh3_normal_and_ch4_tinggi_and_co_sangat_tinggi, then_sangat_bahaya3);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya3);

    // IF nh3 normal and ch4 sangat tinggi and co tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_sangat_tinggi_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_sangat_tinggi_and_co_tinggi->joinWithAND(if_nh3_normal_and_ch4_sangat_tinggi, co_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya4 = new FuzzyRuleConsequent();
    then_sangat_bahaya4->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya4 = new FuzzyRule(11, if_nh3_normal_and_ch4_sangat_tinggi_and_co_tinggi, then_sangat_bahaya4);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya4);

    // IF nh3 normal and ch4 sangat tinggi and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_normal_and_ch4_sangat_tinggi_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_normal_and_ch4_sangat_tinggi_and_co_sangat_tinggi->joinWithAND(if_nh3_normal_and_ch4_sangat_tinggi, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya5 = new FuzzyRuleConsequent();
    then_sangat_bahaya5->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya5 = new FuzzyRule(12, if_nh3_normal_and_ch4_sangat_tinggi_and_co_sangat_tinggi, then_sangat_bahaya5);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya5);

    // IF nh3 tinggi and ch4 tinggi and co tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_tinggi_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_tinggi_and_co_tinggi->joinWithAND(if_nh3_tinggi_and_ch4_tinggi, co_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya6 = new FuzzyRuleConsequent();
    then_sangat_bahaya6->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya6 = new FuzzyRule(13, if_nh3_tinggi_and_ch4_tinggi_and_co_tinggi, then_sangat_bahaya6);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya6);

    // If nh3 tinggi and ch4 normal and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_normal_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_normal_and_co_sangat_tinggi->joinWithAND(if_nh3_tinggi_and_ch4_normal, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya7 = new FuzzyRuleConsequent();
    then_sangat_bahaya7->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya7 = new FuzzyRule(14, if_nh3_tinggi_and_ch4_normal_and_co_sangat_tinggi, then_sangat_bahaya7);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya7);

    // If nh3 tinggi and ch4 sangat tinggi and co normal THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_sangat_tinggi->joinWithAND(nh3_tinggi, ch4_sangat_tinggi);
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_normal->joinWithAND(if_nh3_tinggi_and_ch4_sangat_tinggi, co_normal);

    FuzzyRuleConsequent *then_sangat_bahaya8 = new FuzzyRuleConsequent();
    then_sangat_bahaya8->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya8 = new FuzzyRule(15, if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_normal, then_sangat_bahaya8);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya8);

    // If nh3 tinggi and ch4 tinggi and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_tinggi_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_tinggi_and_co_sangat_tinggi->joinWithAND(if_nh3_tinggi_and_ch4_tinggi, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya9 = new FuzzyRuleConsequent();
    then_sangat_bahaya9->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya9 = new FuzzyRule(16, if_nh3_tinggi_and_ch4_tinggi_and_co_sangat_tinggi, then_sangat_bahaya9);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya9);

    // If nh3 tinggi and ch4 sangat tinggi and co tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_tinggi->joinWithAND(if_nh3_tinggi_and_ch4_sangat_tinggi, co_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya10 = new FuzzyRuleConsequent();
    then_sangat_bahaya10->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya10 = new FuzzyRule(17, if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_tinggi, then_sangat_bahaya10);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya10);

    // If nh3 tinggi and ch4 sangat tinggi and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_sangat_tinggi2 = new FuzzyRuleAntecedent();
    if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_sangat_tinggi2->joinWithAND(if_nh3_tinggi_and_ch4_sangat_tinggi, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya11 = new FuzzyRuleConsequent();
    then_sangat_bahaya11->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya11 = new FuzzyRule(18, if_nh3_tinggi_and_ch4_sangat_tinggi_and_co_sangat_tinggi2, then_sangat_bahaya11);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya11);

    // If nh3 sangat tinggi and ch4 normal and co normal THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_normal = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_normal->joinWithAND(nh3_sangat_tinggi, ch4_normal);
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_normal_and_co_normal2 = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_normal_and_co_normal2->joinWithAND(if_nh3_sangat_tinggi_and_ch4_normal, co_normal);

    FuzzyRuleConsequent *then_sangat_bahaya12 = new FuzzyRuleConsequent();
    then_sangat_bahaya12->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya12 = new FuzzyRule(19, if_nh3_sangat_tinggi_and_ch4_normal_and_co_normal2, then_sangat_bahaya12);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya12);

    // If nh3 sangat tinggi and ch4 normal and co tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_normal_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_normal_and_co_tinggi->joinWithAND(if_nh3_sangat_tinggi_and_ch4_normal, co_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya13 = new FuzzyRuleConsequent();
    then_sangat_bahaya13->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya13 = new FuzzyRule(20, if_nh3_sangat_tinggi_and_ch4_normal_and_co_tinggi, then_sangat_bahaya13);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya13);

    // If nh3 sangat tinggi and ch4 tinggi and co normal THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_tinggi->joinWithAND(nh3_sangat_tinggi, ch4_tinggi);
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_normal->joinWithAND(if_nh3_sangat_tinggi_and_ch4_tinggi, co_normal);

    FuzzyRuleConsequent *then_sangat_bahaya14 = new FuzzyRuleConsequent();
    then_sangat_bahaya14->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya14 = new FuzzyRule(21, if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_normal, then_sangat_bahaya14);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya14);

    // If nh3 sangat tinggi and ch4 tinggi and co tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_tinggi->joinWithAND(if_nh3_sangat_tinggi_and_ch4_tinggi, co_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya15 = new FuzzyRuleConsequent();
    then_sangat_bahaya15->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya15 = new FuzzyRule(22, if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_tinggi, then_sangat_bahaya15);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya15);

    // If nh3 sangat tinggi and ch4 normal and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_normal_and_co_sangat_tinggi2 = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_normal_and_co_sangat_tinggi2->joinWithAND(if_nh3_sangat_tinggi_and_ch4_normal, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya16 = new FuzzyRuleConsequent();
    then_sangat_bahaya16->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya16 = new FuzzyRule(23, if_nh3_sangat_tinggi_and_ch4_normal_and_co_sangat_tinggi2, then_sangat_bahaya16);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya16);

    // If nh3 sangat tinggi and ch4 sangat tinggi and co normal THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_sangat_tinggi->joinWithAND(nh3_sangat_tinggi, ch4_sangat_tinggi);
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_normal = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_normal->joinWithAND(if_nh3_sangat_tinggi_and_ch4_sangat_tinggi, co_normal);

    FuzzyRuleConsequent *then_sangat_bahaya17 = new FuzzyRuleConsequent();
    then_sangat_bahaya17->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya17 = new FuzzyRule(24, if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_normal, then_sangat_bahaya17);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya17);

    // If nh3 sangat tinggi and ch4 tinggi and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_sangat_tinggi->joinWithAND(if_nh3_sangat_tinggi_and_ch4_tinggi, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya18 = new FuzzyRuleConsequent();
    then_sangat_bahaya18->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya18 = new FuzzyRule(25, if_nh3_sangat_tinggi_and_ch4_tinggi_and_co_sangat_tinggi, then_sangat_bahaya18);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya18);

    // If nh3 sangat tinggi and ch4 sangat tinggi and co tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_tinggi->joinWithAND(if_nh3_sangat_tinggi_and_ch4_sangat_tinggi, co_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya19 = new FuzzyRuleConsequent();
    then_sangat_bahaya19->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya19 = new FuzzyRule(26, if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_tinggi, then_sangat_bahaya19);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya19);

    // If nh3 sangat tinggi and ch4 sangat tinggi and co sangat tinggi THEN sangat bahaya
    FuzzyRuleAntecedent *if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_sangat_tinggi = new FuzzyRuleAntecedent();
    if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_sangat_tinggi->joinWithAND(if_nh3_sangat_tinggi_and_ch4_sangat_tinggi, co_sangat_tinggi);

    FuzzyRuleConsequent *then_sangat_bahaya20 = new FuzzyRuleConsequent();
    then_sangat_bahaya20->addOutput(sangat_bahaya);

    FuzzyRule *fuzzy_rule_sangat_bahaya20 = new FuzzyRule(27, if_nh3_sangat_tinggi_and_ch4_sangat_tinggi_and_co_sangat_tinggi, then_sangat_bahaya20);
    fuzzy->addFuzzyRule(fuzzy_rule_sangat_bahaya20);
}

void FuzzyLogic::fuzzy_init()
{
    fuzzy_set_input_output();
    fuzzy_set_rule();
}

void FuzzyLogic::fuzzy_compute(float nh3, float ch4, float co)
{
    fuzzy->setInput(1, nh3);
    fuzzy->setInput(2, ch4);
    fuzzy->setInput(3, co);

    fuzzy->fuzzify();

    Serial.println("input: ");
    Serial.print("\tnh3 normal: ");
    Serial.print(nh3_normal->getPertinence());
    Serial.print(", nh3 tinggi: ");
    Serial.print(nh3_tinggi->getPertinence());
    Serial.print(", nh3 sangat tinggi: ");
    Serial.println(nh3_sangat_tinggi->getPertinence());

    Serial.print("\tch4 normal: ");
    Serial.print(ch4_normal->getPertinence());
    Serial.print(", ch4 tinggi: ");
    Serial.print(ch4_tinggi->getPertinence());
    Serial.print(", ch4 sangat tinggi: ");
    Serial.println(ch4_sangat_tinggi->getPertinence());

    Serial.print("\tco normal: ");
    Serial.print(co_normal->getPertinence());
    Serial.print(", co tinggi: ");
    Serial.print(co_tinggi->getPertinence());
    Serial.print(", co sangat tinggi: ");
    Serial.println(co_sangat_tinggi->getPertinence());

    float output = fuzzy->defuzzify(1);

    Serial.println("\tResult: ");
    Serial.print("\t\t\tRisk : ");
    Serial.println(output);
    Serial.println();
}
