void fuzzyset () {

////======================INPUT========================================

  ///---Fuzzy INPUT MQ pertama yang pin 34
  FuzzyInput *Mqa = new FuzzyInput(1);
  Mqa->addFuzzySet(normal_mqA);
  Mqa->addFuzzySet(bocor_sedangA);
  Mqa->addFuzzySet(banyak_mqA);
  //Memasukan Data dari Fuzzy input ke Dalam Logika Fuzzy
  fuzzy->addFuzzyInput(Mqa);

  ///---Fuzzy INPUT MQ Kedua yang pin 35 bodong wkwk gnti ya nanti 
  FuzzyInput *Mqb = new FuzzyInput(2);
  Mqb->addFuzzySet(normal_mqB);
  Mqb->addFuzzySet(bocor_sedangB);
  Mqb->addFuzzySet(banyak_mqB);
  //Memasukan Data dari Fuzzy input ke Dalam Logika Fuzzy 
  fuzzy->addFuzzyInput(Mqb);

  ///----Fuzzy INPUT Pressure ini 
  FuzzyInput *sensorPressure = new FuzzyInput(3);
  sensorPressure->addFuzzySet(Rendah);
  sensorPressure->addFuzzySet(Sedang);
  sensorPressure->addFuzzySet(Tinggi);

  fuzzy->addFuzzyInput(sensorPressure);


///======================OUTPUT========================================

 ///----Fuzzy OUTPUT LED ini 
  FuzzyOutput *LED = new FuzzyOutput(1);
  LED->addFuzzySet(Off);
  LED->addFuzzySet(On);

  fuzzy->addFuzzyOutput(LED);
 


  //----Fuzzy OUTPUT Buzzer ini 
  FuzzyOutput *sBuzzer = new FuzzyOutput(2);
  sBuzzer ->addFuzzySet(mati);
  sBuzzer ->addFuzzySet(nyala);


  fuzzy->addFuzzyOutput(sBuzzer);

  //----Fuzzy OUTPUT Relay Valve ini----------------------------------------
  FuzzyOutput *Valve = new FuzzyOutput(3);
  Valve ->addFuzzySet(Open);
  Valve ->addFuzzySet(Closed);

  fuzzy->addFuzzyOutput(Valve);

 //// mungkin ini untuk relay reaktor fuzzy->addFuzzyOutput(Reaktor);

}