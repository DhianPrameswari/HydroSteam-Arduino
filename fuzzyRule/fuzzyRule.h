void fuzzyrule() {
// ------------------------Rule 1-----------------------------------------
  FuzzyRuleAntecedent *normal_normal1 = new FuzzyRuleAntecedent();
  normal_normal1->joinWithOR(normal_mqA, normal_mqB);

  FuzzyRuleAntecedent *p_rendah1 = new FuzzyRuleAntecedent();
  p_rendah1->joinSingle(Rendah);

  FuzzyRuleAntecedent *normal_normal_rendah1 = new FuzzyRuleAntecedent();
  normal_normal_rendah1->joinWithAND(normal_normal1, p_rendah1);

  FuzzyRuleConsequent *On_mati_Open1 = new FuzzyRuleConsequent();
  On_mati_Open1->addOutput(On);
  On_mati_Open1->addOutput(mati);
  On_mati_Open1->addOutput(Open);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, normal_normal_rendah1, On_mati_Open1);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // ------------------------Rule 2-----------------------------------------
  FuzzyRuleAntecedent *normal_normal2 = new FuzzyRuleAntecedent();
  normal_normal2->joinWithOR(normal_mqA, normal_mqB);

  FuzzyRuleAntecedent *p_sedang1 = new FuzzyRuleAntecedent();
  p_sedang1->joinSingle(Sedang);

  FuzzyRuleAntecedent *normal_normal_sedang1 = new FuzzyRuleAntecedent();
  normal_normal_sedang1->joinWithAND(normal_normal2, p_sedang1);

  FuzzyRuleConsequent *Off_mati_Open2 = new FuzzyRuleConsequent();
  Off_mati_Open2->addOutput(Off);
  Off_mati_Open2->addOutput(mati);
  Off_mati_Open2->addOutput(Open);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, normal_normal_sedang1, Off_mati_Open2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // ------------------------Rule 3-----------------------------------------
  FuzzyRuleAntecedent *normal_normal3 = new FuzzyRuleAntecedent();
  normal_normal3->joinWithOR(normal_mqA, normal_mqB);

  FuzzyRuleAntecedent *p_tinggi1 = new FuzzyRuleAntecedent();
  p_tinggi1->joinSingle(Tinggi);

  FuzzyRuleAntecedent *normal_normal_tinggi1 = new FuzzyRuleAntecedent();
  normal_normal_tinggi1->joinWithAND(normal_normal3, p_tinggi1);

  FuzzyRuleConsequent *On_nyala_Open3 = new FuzzyRuleConsequent();
  On_nyala_Open3->addOutput(On);
  On_nyala_Open3->addOutput(nyala);
  On_nyala_Open3->addOutput(Open);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, normal_normal_tinggi1, On_nyala_Open3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  // ------------------------Rule 4-----------------------------------------
  FuzzyRuleAntecedent *high_high1 = new FuzzyRuleAntecedent();
  high_high1->joinWithOR(banyak_mqA, banyak_mqB);

  //FuzzyRuleAntecedent *p_rendah1 = new FuzzyRuleAntecedent();
  //p_rendah1->joinSingle(Rendah);

  FuzzyRuleAntecedent *high_high_rendah2 = new FuzzyRuleAntecedent();
  high_high_rendah2->joinWithAND(high_high1, p_rendah1);

  FuzzyRuleConsequent *On_nyala_Closed4 = new FuzzyRuleConsequent();
  On_nyala_Closed4->addOutput(On);
  On_nyala_Closed4->addOutput(nyala);
  On_nyala_Closed4->addOutput(Closed);

  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, high_high_rendah2, On_nyala_Closed4);
  fuzzy->addFuzzyRule(fuzzyRule4);

  // ------------------------Rule 5-----------------------------------------
  FuzzyRuleAntecedent *high_high2 = new FuzzyRuleAntecedent();
  high_high2->joinWithOR(banyak_mqA, banyak_mqB);

  //FuzzyRuleAntecedent *p_sedang1 = new FuzzyRuleAntecedent();
  //p_sedang1->joinSingle(Sedang);

  FuzzyRuleAntecedent *high_high_sedang2 = new FuzzyRuleAntecedent();
  high_high_sedang2->joinWithAND(high_high2, p_sedang1);

  FuzzyRuleConsequent *On_nyala_Closed5 = new FuzzyRuleConsequent();
  On_nyala_Closed5->addOutput(On);
  On_nyala_Closed5->addOutput(nyala);
  On_nyala_Closed5->addOutput(Closed);

  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, high_high_sedang2, On_nyala_Closed5);
  fuzzy->addFuzzyRule(fuzzyRule5);

  // ------------------------Rule 6-----------------------------------------
  FuzzyRuleAntecedent *high_high3 = new FuzzyRuleAntecedent();
  high_high3->joinWithOR(banyak_mqA, banyak_mqB);

  //FuzzyRuleAntecedent *p_tinggi1 = new FuzzyRuleAntecedent(); // Ini mungkin perlu diperbaiki, sesuai dengan logika aplikasi Anda.
  //p_tinggi1->joinSingle(Tinggi);

  FuzzyRuleAntecedent *high_high_tinggi2 = new FuzzyRuleAntecedent();
  high_high_tinggi2->joinWithAND(high_high3, p_tinggi1);

  FuzzyRuleConsequent *On_nyala_Closed6 = new FuzzyRuleConsequent();
  On_nyala_Closed6->addOutput(On);
  On_nyala_Closed6->addOutput(nyala);
  On_nyala_Closed6->addOutput(Closed);

  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, high_high_tinggi2, On_nyala_Closed6);
  fuzzy->addFuzzyRule(fuzzyRule6);
  // ------------------------Rule 7-----------------------------------------
  FuzzyRuleAntecedent *sedang_sedang1 = new FuzzyRuleAntecedent();
  sedang_sedang1->joinWithOR(bocor_sedangA, bocor_sedangB);

  //FuzzyRuleAntecedent *p_rendah3 = new FuzzyRuleAntecedent();
  //p_rendah3->joinSingle(Rendah);

  FuzzyRuleAntecedent *sedang_sedang_rendah3 = new FuzzyRuleAntecedent();
  sedang_sedang_rendah3->joinWithAND(sedang_sedang1, p_rendah1);

  FuzzyRuleConsequent *On_mati_Open7 = new FuzzyRuleConsequent();
  On_mati_Open7->addOutput(On);
  On_mati_Open7->addOutput(mati);
  On_mati_Open7->addOutput(Open);

  FuzzyRule *fuzzyRule7 = new FuzzyRule(7, sedang_sedang_rendah3, On_mati_Open7);
  fuzzy->addFuzzyRule(fuzzyRule7);

  // ------------------------Rule 8-----------------------------------------
  FuzzyRuleAntecedent *sedang_sedang2 = new FuzzyRuleAntecedent();
  sedang_sedang2->joinWithOR(bocor_sedangA, bocor_sedangB);

  //FuzzyRuleAntecedent *p_sedang3 = new FuzzyRuleAntecedent();
  //p_sedang3->joinSingle(Sedang);

  FuzzyRuleAntecedent *sedang_sedang_sedang3 = new FuzzyRuleAntecedent();
  sedang_sedang_sedang3->joinWithAND(sedang_sedang2, p_sedang1);

  FuzzyRuleConsequent *Off_mati_Open8 = new FuzzyRuleConsequent();
  Off_mati_Open8->addOutput(Off);
  Off_mati_Open8->addOutput(mati);
  Off_mati_Open8->addOutput(Open);

  FuzzyRule *fuzzyRule8 = new FuzzyRule(8, sedang_sedang_sedang3, Off_mati_Open8);
  fuzzy->addFuzzyRule(fuzzyRule8);

  // ------------------------Rule 9-----------------------------------------
  FuzzyRuleAntecedent *sedang_sedang3 = new FuzzyRuleAntecedent();
  sedang_sedang3->joinWithOR(bocor_sedangA, bocor_sedangB);

  //FuzzyRuleAntecedent *p_tinggi3 = new FuzzyRuleAntecedent();
  //p_tinggi3->joinSingle(Tinggi);

  FuzzyRuleAntecedent *sedang_sedang_tinggi3 = new FuzzyRuleAntecedent();
  sedang_sedang_tinggi3->joinWithAND(sedang_sedang3, p_tinggi1);

  FuzzyRuleConsequent *Off_nyala_Open9 = new FuzzyRuleConsequent();
  Off_nyala_Open9->addOutput(Off);
  Off_nyala_Open9->addOutput(nyala);
  Off_nyala_Open9->addOutput(Open);

  FuzzyRule *fuzzyRule9 = new FuzzyRule(9, sedang_sedang_tinggi3, Off_nyala_Open9);
  fuzzy->addFuzzyRule(fuzzyRule9);
}