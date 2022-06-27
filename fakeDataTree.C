#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include <iostream>


int fakeDataTree() {
  int option = 4;
  TFile* origin = new TFile(("set"+std::to_string(option)+".root").c_str()); 
  // New Trees
  TTree *treeTEval;    origin->GetObject("wcpselection/T_eval"    ,treeTEval   );
  TTree *treeTPOT;     origin->GetObject("wcpselection/T_pot"     ,treeTPOT    );
  TTree *treeT_PFeval; origin->GetObject("wcpselection/T_PFeval"  ,treeT_PFeval);
  TTree *treeBDT;      origin->GetObject("wcpselection/T_BDTvars" ,treeBDT     );
  TTree *treeKINEvars; origin->GetObject("wcpselection/T_KINEvars",treeKINEvars);


  // Outfile
  TFile* outFile   = new TFile(("fakeData"+std::to_string(option)+".root").c_str(),"RECREATE");  
  TTree *newTreeTEval = treeTEval->CloneTree(0);
  
  // First TTree
  //int run0;
  int   truth_nuPdg;  
  float truth_nuEnergy;  
  float weight_spline;
 
  treeTEval->SetBranchAddress( "truth_nuPdg"   , &truth_nuPdg );
  treeTEval->SetBranchAddress( "truth_nuEnergy", &truth_nuEnergy );
  treeTEval->SetBranchAddress( "weight_spline" , &weight_spline );
  
  std::cout<<"Number of enties "<<treeTEval->GetEntries()<<" \n";
  for (int i=0; i<treeTEval->GetEntries(); i++)
    {
      if (i % 1000 == 0) std::cout<<"At entry "<<i<<"\n";
      treeTEval->GetEntry(i);
      if (option == 0)
	{
	  newTreeTEval->Fill();
	}
      else if (option == 1)
	{
	  if ( truth_nuPdg ==  12) weight_spline  *= 0.5;
	  if ( truth_nuPdg == -12) weight_spline  *= 2.0;
	  newTreeTEval->Fill();
	}
      else if (option == 2)
	{
	  if ( truth_nuPdg == -12) weight_spline  *= 0.5;
	  if ( truth_nuPdg ==  12) weight_spline  *= 2.0;
	  newTreeTEval->Fill();
	}
      else if (option == 3)
	{
	  if ( truth_nuPdg == 12 || truth_nuPdg == -12 ) weight_spline  *= 3.;
	  newTreeTEval->Fill();
	}
      else if (option == 4)
	{
	  if ( truth_nuPdg == 12 || truth_nuPdg == -12 )
	    {
	      double calculatedWeight = -0.0007*truth_nuEnergy + 1.571;
	      if (calculatedWeight < 0.3 ) calculatedWeight = 0.3;
	      weight_spline  *= calculatedWeight;
	    }
	  newTreeTEval->Fill();
	}
      else
	{std::cout << "Not a valid option\n"; return 1;}
    }


  // Write up files
  TDirectory *newdirE = outFile->mkdir("wcpselection" );
  // Write out file
  outFile -> cd();
  newdirE->cd();
  treeT_PFeval->CloneTree(0);
  treeBDT     ->CloneTree(0);
  treeKINEvars->CloneTree(0);
  treeTPOT    ->CloneTree(0);
  newdirE->WriteObject(newTreeTEval,"T_eval"    );
  newdirE->WriteObject(treeTPOT    ,"T_pot"     );
  newdirE->WriteObject(treeT_PFeval,"T_PFeval"  );
  newdirE->WriteObject(treeBDT     ,"T_BDTvars" );
  newdirE->WriteObject(treeKINEvars,"T_KINEvars");

  outFile->Close();
  delete outFile;
  return 0;
}

