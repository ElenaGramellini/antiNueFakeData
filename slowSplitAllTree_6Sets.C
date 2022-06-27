#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include <iostream>
#include <set>

int slowSplitAllTree_6Sets() {
  //TFile* origin = new TFile("../checkout_prodgenie_numi_intrinsic_nue_overlay_run1_bank.root"); //run1_intrinsic_nue.root
  TFile* origin = new TFile("run1_intrinsic_nue.root"); 

  // New Trees
  TTree *treeTEval;    origin->GetObject("wcpselection/T_eval"    ,treeTEval   );
  TTree *treeTPOT;     origin->GetObject("wcpselection/T_pot"     ,treeTPOT    );
  TTree *treeT_PFeval; origin->GetObject("wcpselection/T_PFeval"  ,treeT_PFeval);
  TTree *treeBDT;      origin->GetObject("wcpselection/T_BDTvars" ,treeBDT     );
  TTree *treeKINEvars; origin->GetObject("wcpselection/T_KINEvars",treeKINEvars);


  // Write output
  TFile* out0File   = new TFile("set0.root","RECREATE");
  TFile* out1File   = new TFile("set1.root","RECREATE");
  TFile* out2File   = new TFile("set2.root","RECREATE");
  TFile* out3File   = new TFile("set3.root","RECREATE");  
  TFile* out4File   = new TFile("set4.root","RECREATE");
  TFile* out5File   = new TFile("set5.root","RECREATE");

  // Trees
  TTree *out0Teval  = treeTEval   ->CloneTree(0);
  TTree *out0POT    = treeTPOT    ->CloneTree(0);
  TTree *out0PFeval = treeT_PFeval->CloneTree(0);
  TTree *out0BDT    = treeBDT     ->CloneTree(0);
  TTree *out0KINE   = treeKINEvars->CloneTree(0);

  TTree *out1Teval  = treeTEval   ->CloneTree(0);
  TTree *out1POT    = treeTPOT    ->CloneTree(0);
  TTree *out1PFeval = treeT_PFeval->CloneTree(0);
  TTree *out1BDT    = treeBDT     ->CloneTree(0);
  TTree *out1KINE   = treeKINEvars->CloneTree(0);

  TTree *out2Teval  = treeTEval   ->CloneTree(0);
  TTree *out2POT    = treeTPOT    ->CloneTree(0);
  TTree *out2PFeval = treeT_PFeval->CloneTree(0);
  TTree *out2BDT    = treeBDT     ->CloneTree(0);
  TTree *out2KINE   = treeKINEvars->CloneTree(0);

  TTree *out3Teval  = treeTEval   ->CloneTree(0);
  TTree *out3POT    = treeTPOT    ->CloneTree(0);
  TTree *out3PFeval = treeT_PFeval->CloneTree(0);
  TTree *out3BDT    = treeBDT     ->CloneTree(0);
  TTree *out3KINE   = treeKINEvars->CloneTree(0);

  TTree *out4Teval  = treeTEval   ->CloneTree(0);
  TTree *out4POT    = treeTPOT    ->CloneTree(0);
  TTree *out4PFeval = treeT_PFeval->CloneTree(0);
  TTree *out4BDT    = treeBDT     ->CloneTree(0);
  TTree *out4KINE   = treeKINEvars->CloneTree(0);

  TTree *out5Teval  = treeTEval   ->CloneTree(0);
  TTree *out5POT    = treeTPOT    ->CloneTree(0);
  TTree *out5PFeval = treeT_PFeval->CloneTree(0);
  TTree *out5BDT    = treeBDT     ->CloneTree(0);
  TTree *out5KINE   = treeKINEvars->CloneTree(0);

  std::set<int> setRun0; // defining an empty set
  std::set<int> setRun1; // defining an empty set
  std::set<int> setRun2; // defining an empty set
  std::set<int> setRun3; // defining an empty set
  std::set<int> setRun4; // defining an empty set
  std::set<int> setRun5; // defining an empty set

  setRun0.clear();
  setRun1.clear();
  setRun2.clear();
  setRun3.clear();
  setRun4.clear();
  setRun5.clear();

  int count0 = 0;
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  int count4 = 0;
  int count5 = 0;
    
  // First TTree
  int setLimit = 150;
  int run0 = 0;
  
  treeTEval->SetBranchAddress( "run" , &run0 );
  std::cout<<"TEval "<<treeTEval->GetEntries()<<"\n";
  for (int i=0; i<treeTEval->GetEntries(); i++)
    {
      if (i % 10000 == 0) std::cout<<" "<<i<<"\n";
      treeTEval->GetEntry(i);
      if (setRun0.find(run0) != setRun0.end())  {out0Teval->Fill(); count0++; continue;}
      else if (setRun1.find(run0) != setRun1.end())  {out1Teval->Fill(); count1++; continue;}
      else if (setRun2.find(run0) != setRun2.end())  {out2Teval->Fill(); count2++; continue;}
      else if (setRun3.find(run0) != setRun3.end())  {out3Teval->Fill(); count3++; continue;}
      else if (setRun4.find(run0) != setRun4.end())  {out4Teval->Fill(); count4++; continue;}
      else if (setRun5.find(run0) != setRun5.end())  {out5Teval->Fill(); count5++; continue;}

      if (count0 < setLimit) { out0Teval->Fill(); count0++;  setRun0.insert(run0); }
      else if (count1 < setLimit) { out1Teval->Fill(); count1++; setRun1.insert(run0);}
      else if (count2 < setLimit) { out2Teval->Fill(); count2++; setRun2.insert(run0);}
      else if (count3 < setLimit) { out3Teval->Fill(); count3++; setRun3.insert(run0);}
      else if (count4 < setLimit) { out4Teval->Fill(); count4++; setRun4.insert(run0);}
      else { out5Teval->Fill(); count5++; setRun5.insert(run0); }
      
      /*
      if (i < setLimit) { out0Teval->Fill(); count0++;  setRun0.insert(run0); }
      else if (setLimit < i && i < 2*setLimit) { out1Teval->Fill(); count1++; setRun1.insert(run0);}
      else if (2*setLimit < i && i < 3*setLimit)  { out2Teval->Fill(); count2++; setRun2.insert(run0);}
      else if (3*setLimit < i && i < 4*setLimit)  { out3Teval->Fill(); count3++; setRun3.insert(run0);}
      else if (4*setLimit < i && i < 5*setLimit)  { out4Teval->Fill(); count4++; setRun4.insert(run0);}
      else { out5Teval->Fill(); count5++; setRun5.insert(run0); }
      */
    }

  std::cout<<"Set number of events "<< count0 << " "<<count1<<" "<< count2 << " "<<count3<<" "<< count4 << " "<<count5<<" \n";
  int run2 = 0;
  treeT_PFeval->SetBranchAddress( "run" , &run2 );
  std::cout<<"TEval "<<treeT_PFeval->GetEntries()<<"\n";
  for (int i=0; i<treeT_PFeval->GetEntries(); i++)
    {
      if (i % 10000 == 0) std::cout<<" "<<i<<"\n";
      treeT_PFeval->GetEntry(i);
      if (setRun0.find(run2) != setRun0.end())  {out0PFeval->Fill(); continue;}
      else if (setRun1.find(run2) != setRun1.end())  {out1PFeval->Fill(); continue;}
      else if (setRun2.find(run2) != setRun2.end())  {out2PFeval->Fill(); continue;}
      else if (setRun3.find(run2) != setRun3.end())  {out3PFeval->Fill(); continue;}
      else if (setRun4.find(run2) != setRun4.end())  {out4PFeval->Fill(); continue;}
      else { out5PFeval->Fill(); }
    }

  
  int run3 = 0;
  treeBDT->SetBranchAddress( "run" , &run3 );
  std::cout<<"TEval "<<treeBDT->GetEntries()<<"\n";
  for (int i=0; i<treeBDT->GetEntries(); i++)
    {
      if (i % 10000 == 0) std::cout<<" "<<i<<"\n";
      treeBDT->GetEntry(i);
      if (setRun0.find(run3) != setRun0.end())  {out0BDT->Fill(); continue;}
      else if (setRun1.find(run3) != setRun1.end())  {out1BDT->Fill(); continue;}
      else if (setRun2.find(run3) != setRun2.end())  {out2BDT->Fill(); continue;}
      else if (setRun3.find(run3) != setRun3.end())  {out3BDT->Fill(); continue;}
      else if (setRun4.find(run3) != setRun4.end())  {out4BDT->Fill(); continue;}
      else { out5BDT->Fill(); }
    }


  int run4 = 0;
  treeKINEvars->SetBranchAddress( "run" , &run4 );
  std::cout<<"TEval "<<treeKINEvars->GetEntries()<<"\n";
  for (int i=0; i<treeKINEvars->GetEntries(); i++)
    {
      
      if (i % 10000 == 0) std::cout<<" "<<i<<"\n";
      treeKINEvars->GetEntry(i);
      if (setRun0.find(run4) != setRun0.end())  {out0KINE->Fill(); continue;}
      else if (setRun1.find(run4) != setRun1.end())  {out1KINE->Fill(); continue;}
      else if (setRun2.find(run4) != setRun2.end())  {out2KINE->Fill(); continue;}
      else if (setRun3.find(run4) != setRun3.end())  {out3KINE->Fill(); continue;}
      else if (setRun4.find(run4) != setRun4.end())  {out4KINE->Fill(); continue;}
      else { out5KINE->Fill(); }
	    
    }


  

  // Second TTree
  int run1 = 0 ;
  int dummyCounter = 0;
  treeTPOT->SetBranchAddress( "run" , &run1 );
  for (int i=0; i<treeTPOT->GetEntries(); i++)
    {
      treeTPOT->GetEntry(i);
      if (setRun0.find(run1) != setRun0.end())  {out0POT->Fill();}
      else if (setRun1.find(run1) != setRun1.end())  {out1POT->Fill();}
      else if (setRun2.find(run1) != setRun2.end())  {out2POT->Fill();}
      else if (setRun3.find(run1) != setRun3.end())  {out3POT->Fill();}
      else if (setRun4.find(run1) != setRun4.end())  {out4POT->Fill();}
      else {out5POT->Fill();}
    }

  if (setRun0.find(6100) != setRun0.end()) std::cout<< "I fucking found it! \n" ;
  if (setRun1.find(6100) != setRun1.end()) std::cout<< "I fucking found it again! \n" ;
  
  /*
  std::cout<<"Set size "<<setRun1.size()<<"\n";
  set<int>::iterator itr;
  for (itr = setRun1.begin();  itr != setRun1.end(); itr++)
    {
      std::cout<<"In the loop ";
      std::cout << *itr << " \n";
    }
  */
  
  // Write up files
  TDirectory *newdir0 = out0File->mkdir("wcpselection" );
  out0File->cd();
  newdir0->cd();
  out0Teval  ->SetDirectory(0);
  out0POT    ->SetDirectory(0);
  out0PFeval ->SetDirectory(0);
  out0BDT    ->SetDirectory(0);
  out0KINE   ->SetDirectory(0);
  newdir0->WriteObject(out0Teval ,"T_eval"    );
  newdir0->WriteObject(out0POT   ,"T_pot"     );
  newdir0->WriteObject(out0PFeval,"T_PFeval"  );
  newdir0->WriteObject(out0BDT   ,"T_BDTvars" );
  newdir0->WriteObject(out0KINE  ,"T_KINEvars");
  delete out0File;


  TDirectory *newdir1 = out1File->mkdir("wcpselection" );
  out1File->cd();
  newdir1->cd();
  out1Teval  ->SetDirectory(0);
  out1POT    ->SetDirectory(0);
  out1PFeval ->SetDirectory(0);
  out1BDT    ->SetDirectory(0);
  out1KINE   ->SetDirectory(0);
  newdir1->WriteObject(out1Teval ,"T_eval"    );
  newdir1->WriteObject(out1POT   ,"T_pot"     );
  newdir1->WriteObject(out1PFeval,"T_PFeval"  );
  newdir1->WriteObject(out1BDT   ,"T_BDTvars" );
  newdir1->WriteObject(out1KINE  ,"T_KINEvars");
  delete out1File;


  TDirectory *newdir2 = out2File->mkdir("wcpselection" );
  out2File->cd();
  newdir2->cd();
  out2Teval  ->SetDirectory(0);
  out2POT    ->SetDirectory(0);
  out2PFeval ->SetDirectory(0);
  out2BDT    ->SetDirectory(0);
  out2KINE   ->SetDirectory(0);
  newdir2->WriteObject(out2Teval ,"T_eval"    );
  newdir2->WriteObject(out2POT   ,"T_pot"     );
  newdir2->WriteObject(out2PFeval,"T_PFeval"  );
  newdir2->WriteObject(out2BDT   ,"T_BDTvars" );
  newdir2->WriteObject(out2KINE  ,"T_KINEvars");
  delete out2File;

  
  TDirectory *newdir3 = out3File->mkdir("wcpselection" );
  out3File->cd();
  newdir3->cd();
  out3Teval  ->SetDirectory(0);
  out3POT    ->SetDirectory(0);
  out3PFeval ->SetDirectory(0);
  out3BDT    ->SetDirectory(0);
  out3KINE   ->SetDirectory(0);
  newdir3->WriteObject(out3Teval ,"T_eval"    );
  newdir3->WriteObject(out3POT   ,"T_pot"     );
  newdir3->WriteObject(out3PFeval,"T_PFeval"  );
  newdir3->WriteObject(out3BDT   ,"T_BDTvars" );
  newdir3->WriteObject(out3KINE  ,"T_KINEvars");
  delete out3File;

  TDirectory *newdir4 = out4File->mkdir("wcpselection" );
  out4File->cd();
  newdir4->cd();
  out4Teval  ->SetDirectory(0);
  out4POT    ->SetDirectory(0);
  out4PFeval ->SetDirectory(0);
  out4BDT    ->SetDirectory(0);
  out4KINE   ->SetDirectory(0);
  newdir4->WriteObject(out4Teval ,"T_eval"    );
  newdir4->WriteObject(out4POT   ,"T_pot"     );
  newdir4->WriteObject(out4PFeval,"T_PFeval"  );
  newdir4->WriteObject(out4BDT   ,"T_BDTvars" );
  newdir4->WriteObject(out4KINE  ,"T_KINEvars");
  delete out4File;

  
  TDirectory *newdir5 = out5File->mkdir("wcpselection" );
  out5File->cd();
  newdir5->cd();
  out5Teval  ->SetDirectory(0);
  out5POT    ->SetDirectory(0);
  out5PFeval ->SetDirectory(0);
  out5BDT    ->SetDirectory(0);
  out5KINE   ->SetDirectory(0);
  newdir5->WriteObject(out5Teval ,"T_eval"    );
  newdir5->WriteObject(out5POT   ,"T_pot"     );
  newdir5->WriteObject(out5PFeval,"T_PFeval"  );
  newdir5->WriteObject(out5BDT   ,"T_BDTvars" );
  newdir5->WriteObject(out5KINE  ,"T_KINEvars");
  delete out5File;

  return 0;
}



