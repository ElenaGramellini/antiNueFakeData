#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include <iostream>
#include <set>

int checkPOT() {
  //TFile* origin = new TFile("../checkout_prodgenie_numi_intrinsic_nue_overlay_run1_bank.root"); //run1_intrinsic_nue.root
  TFile* origin = new TFile("run1_intrinsic_nue.root"); 

  // New Trees
  TTree *treeTEval;    origin->GetObject("wcpselection/T_eval"    ,treeTEval   );
  TTree *treeTPOT;     origin->GetObject("wcpselection/T_pot"     ,treeTPOT    );


  std::set<int> setRun0; // defining an empty set

  int run0;
  treeTEval->SetBranchAddress( "run" , &run0 );
  for (int i=0; i<treeTEval->GetEntries(); i++)
    {
      treeTEval->GetEntry(i);
      setRun0.insert(run0);
    }

  // Second TTree
  int run1;
  treeTPOT->SetBranchAddress( "run" , &run1 );
  for (int i=0; i<treeTPOT->GetEntries(); i++)
    {
      treeTPOT->GetEntry(i);
      if (setRun0.find(run1) == setRun0.end()) std::cout<<run1<<"\n";
    }

  return 0;
}



