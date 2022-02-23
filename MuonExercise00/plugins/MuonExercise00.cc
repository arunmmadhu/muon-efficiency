// -*- C++ -*-
//
// Package:    DASExercises/MuonExercise0
// Class:      MuonExercise0
//
/**\class MuonExercise00 MuonExercise00.cc DASExercises/MuonExercise00/plugins/MuonExercise00.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Jian Wang
//         Created:  Wed, 27 Nov 2019 09:09:57 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/CSCRecHit/interface/CSCSegmentCollection.h"
#include "DataFormats/CSCRecHit/interface/CSCRecHit2DCollection.h"
#include "RecoLocalMuon/CSCValidation/src/CSCValidation.h"

#include "DataFormats/CSCDigi/interface/CSCALCTDigiCollection.h"
#include "DataFormats/CSCDigi/interface/CSCALCTDigi.h"

#include "DataFormats/CSCDigi/interface/CSCCLCTDigiCollection.h"
#include "DataFormats/CSCDigi/interface/CSCCLCTDigi.h"

#include "TH2F.h"

using namespace edm;
using namespace std;

//
// class declaration
//



class MuonExercise00 : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit MuonExercise00(const edm::ParameterSet&);
      ~MuonExercise00();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
      EDGetTokenT<CSCSegmentCollection>           theCSCSegmentToken;
      EDGetTokenT<CSCRecHit2DCollection>          theCSCRecHitToken;
      EDGetTokenT<CSCCorrelatedLCTDigiCollection> theCorrelatedLCTDigiToken;
      EDGetTokenT<CSCALCTDigiCollection>          ALCTToken;
      EDGetTokenT<CSCCLCTDigiCollection>          CLCTToken;

      TH1F *nSeg, *nHit, *Qhit, *StID, *StID1, *CorrelatedLCTC1Test1, *CorrelatedLCTC1Test2, *CorrelatedLCTC2Test1, *CorrelatedLCTC2Test2, *CorrelatedLCTC1C2, *C1C2HitDistance, *C1C2HitDistanceX, *C1C2HitDistanceY;
      TH1F *nCorrelatedLCTC1Test1, *nCorrelatedLCTC1Test2, *nCorrelatedLCTC2Test1, *nCorrelatedLCTC2Test2, *C1Test2ALCT, *C2Test2ALCT, *C1Test2CLCT, *C2Test2CLCT;
      TH2F *C1Test1xy, *C1Test2xy, *C2Test1xy, *C2Test2xy, *C1Test2xyNos, *C2Test2xyNos, *C1Test2xyNosIsValid, *C2Test2xyNosIsValid, *C1Test2xyNosTransf, *C2Test2xyNosTransf;
      TH2F *C1Test1xy_1, *C1Test2xy_1, *C2Test1xy_1, *C2Test2xy_1, *C1Test2xyNos_LCT1, *C2Test2xyNos_LCT1, *C1Test2xyNos_LCT2, *C2Test2xyNos_LCT2;
      
      //CSCValHists *histos;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MuonExercise00::MuonExercise00(const edm::ParameterSet& iConfig)
 :
  theCSCSegmentToken(consumes<CSCSegmentCollection>(iConfig.getUntrackedParameter<edm::InputTag>("cscSegments"))),
  theCSCRecHitToken(consumes<CSCRecHit2DCollection>(iConfig.getUntrackedParameter<edm::InputTag>("cscRecHits"))),
  theCorrelatedLCTDigiToken(consumes<CSCCorrelatedLCTDigiCollection>(iConfig.getUntrackedParameter<edm::InputTag>("corrlctDigiTag"))),
  ALCTToken(consumes<CSCALCTDigiCollection>(iConfig.getUntrackedParameter<edm::InputTag>("alctDigiTag"))),
  CLCTToken(consumes<CSCCLCTDigiCollection>(iConfig.getUntrackedParameter<edm::InputTag>("clctDigiTag")))
{
   //now do what ever initialization is needed

   Service<TFileService> fs; // a CMSSW framework to store histograms
   nSeg = fs->make<TH1F>("nSeg", "Number of CSC segments", 5, -0.5, 4.5 );
   nHit = fs->make<TH1F>("nHit", "Number of RecHits per segment", 8, -0.5, 7.5 );
   Qhit = fs->make<TH1F>("Qhit", "ADC charge of each RecHit", 50, 0, 2000 );
   
   StID = fs->make<TH1F>("StID", "Chamber Id of each event", 50, 0.5, 50.5 );
   StID1 = fs->make<TH1F>("StID1", "Station Id of each event", 50, 0.5, 50.5 );
   
   CorrelatedLCTC1Test1 = fs->make<TH1F>("CorrelatedLCTC1Test1", "ME1/1 Correlated LCT Digi Found, Test 27", 2, -0.5, 1.5 );
   CorrelatedLCTC1Test2 = fs->make<TH1F>("CorrelatedLCTC1Test2", "ME1/1 Correlated LCT Digi Found, Test 40", 2, -0.5, 1.5 );
   CorrelatedLCTC2Test1 = fs->make<TH1F>("CorrelatedLCTC2Test1", "ME2/1 Correlated LCT Digi Found, Test 27", 2, -0.5, 1.5 );
   CorrelatedLCTC2Test2 = fs->make<TH1F>("CorrelatedLCTC2Test2", "ME2/1 Correlated LCT Digi Found, Test 40", 2, -0.5, 1.5 );
   
   nCorrelatedLCTC1Test1 = fs->make<TH1F>("nCorrelatedLCTC1Test1", "ME1/1 Correlated LCT Digi Found, Test 27", 3, -0.5, 2.5 );
   nCorrelatedLCTC1Test2 = fs->make<TH1F>("nCorrelatedLCTC1Test2", "ME1/1 Correlated LCT Digi Found, Test 40", 3, -0.5, 2.5 );
   nCorrelatedLCTC2Test1 = fs->make<TH1F>("nCorrelatedLCTC2Test1", "ME2/1 Correlated LCT Digi Found, Test 27", 3, -0.5, 2.5 );
   nCorrelatedLCTC2Test2 = fs->make<TH1F>("nCorrelatedLCTC2Test2", "ME2/1 Correlated LCT Digi Found, Test 40", 3, -0.5, 2.5 );
   
   CorrelatedLCTC1C2 = fs->make<TH1F>("CorrelatedLCTC1C2", "ME1/1 and ME2/1 Correlated LCT Digi Found, Test 40", 2, -0.5, 1.5 );
   
   C1C2HitDistance = fs->make<TH1F>("C1C2HitDistance", "Distance between hits in chamber 1 and chamber 2 after linear trans", 100, 0., 1.0 );
   C1C2HitDistanceX = fs->make<TH1F>("C1C2HitDistanceX", "X Distance between hits in chamber 1 and chamber 2 after linear trans", 100, -0.5, 0.5 );
   C1C2HitDistanceY = fs->make<TH1F>("C1C2HitDistanceY", "Y Distance between hits in chamber 1 and chamber 2 after linear trans", 100, -0.5, 0.5 );
   
   C1C2HitDistanceX->SetXTitle("Minimum x_{c2,transformed}-x_{c1,transformed}");
   C1C2HitDistanceY->SetXTitle("Minimum y_{c2,transformed}-y_{c1,transformed}");
   
   C1Test2ALCT = fs->make<TH1F>("C1Test2ALCT", "Test 40, ALCT Occupancy", 40, 10.5, 50.5 );
   C2Test2ALCT = fs->make<TH1F>("C2Test2ALCT", "Test 40, ALCT Occupancy", 90, 10.5, 100.5 );
   C1Test2CLCT = fs->make<TH1F>("C1Test2CLCT", "Test 40, CLCT Occupancy", 100, -0.5, 99.5 );
   C2Test2CLCT = fs->make<TH1F>("C2Test2CLCT", "Test 40, CLCT Occupancy", 121, -0.5, 120.5 );
   
   C1Test1xy = fs->make<TH2F>("C1Test1xy", "ME1/1 x-y coordinates, Test 27", 125, -50., 50., 100, -100., 100. );
   C1Test2xy = fs->make<TH2F>("C1Test2xy", "ME1/1 x-y coordinates, Test 40", 125, -50., 50., 100, -100., 100. );
   C2Test1xy = fs->make<TH2F>("C2Test1xy", "ME2/1 x-y coordinates, Test 27", 125, -50., 50., 100, -100., 100. );
   C2Test2xy = fs->make<TH2F>("C2Test2xy", "ME2/1 x-y coordinates, Test 40", 125, -50., 50., 100, -100., 100. );
   
   C1Test2xyNos = fs->make<TH2F>("C1Test2xyNos", "ME1/1 x-y coordinates, Test 40", 100, -0.5, 99.5, 40, 10.5, 50.5 );
   C2Test2xyNos = fs->make<TH2F>("C2Test2xyNos", "ME2/1 x-y coordinates, Test 40", 121, -0.5, 120.5, 90, 10.5, 100.5 );
   
   C1Test2xyNos->SetXTitle("Half-Strip");
   C1Test2xyNos->SetYTitle("WG");
   C2Test2xyNos->SetXTitle("Half-Strip");
   C2Test2xyNos->SetYTitle("WG");
   
   C1Test2xyNosIsValid = fs->make<TH2F>("C1Test2xyNosIsValid", "ME1/1 x-y coordinates, Test 40", 100, -0.5, 99.5, 40, 10.5, 50.5 );
   C2Test2xyNosIsValid = fs->make<TH2F>("C2Test2xyNosIsValid", "ME2/1 x-y coordinates, Test 40", 121, -0.5, 120.5, 90, 10.5, 100.5 );
   
   C1Test2xyNosIsValid->SetXTitle("Half-Strip");
   C1Test2xyNosIsValid->SetYTitle("WG");
   C2Test2xyNosIsValid->SetXTitle("Half-Strip");
   C2Test2xyNosIsValid->SetYTitle("WG");
   
   C1Test2xyNos_LCT1 = fs->make<TH2F>("C1Test2xyNos_LCT1", "ME1/1 x-y coordinates, Test 40", 100, -0.5, 99.5, 40, 10.5, 50.5 );
   C2Test2xyNos_LCT1 = fs->make<TH2F>("C2Test2xyNos_LCT1", "ME2/1 x-y coordinates, Test 40", 121, -0.5, 120.5, 90, 10.5, 100.5 );
   
   C1Test2xyNos_LCT1->SetXTitle("Half-Strip");
   C1Test2xyNos_LCT1->SetYTitle("WG");
   C2Test2xyNos_LCT1->SetXTitle("Half-Strip");
   C2Test2xyNos_LCT1->SetYTitle("WG");
   
   C1Test2xyNos_LCT2 = fs->make<TH2F>("C1Test2xyNos_LCT2", "ME1/1 x-y coordinates, Test 40", 100, -0.5, 99.5, 40, 10.5, 50.5 );
   C2Test2xyNos_LCT2 = fs->make<TH2F>("C2Test2xyNos_LCT2", "ME2/1 x-y coordinates, Test 40", 121, -0.5, 120.5, 90, 10.5, 100.5 );
   
   C1Test2xyNos_LCT2->SetXTitle("Half-Strip");
   C1Test2xyNos_LCT2->SetYTitle("WG");
   C2Test2xyNos_LCT2->SetXTitle("Half-Strip");
   C2Test2xyNos_LCT2->SetYTitle("WG");
   
   C1Test2xyNosTransf = fs->make<TH2F>("C1Test2xyNosTransf", "ME1/1 x-y coordinates, Test 40", 100, 0., 2., 100, 0., 2. );
   C2Test2xyNosTransf = fs->make<TH2F>("C2Test2xyNosTransf", "ME2/1 x-y coordinates, Test 40", 100, 0., 2., 100, 0., 2. );
   
   C1Test2xyNosTransf->SetXTitle("matrix[0][0]*(xcoord-xorigin)+matrix[0][1]*(ycoord-yorigin)");
   C1Test2xyNosTransf->SetYTitle("matrix[1][0]*(xcoord-xorigin)+matrix[1][1]*(ycoord-yorigin)");
   C2Test2xyNosTransf->SetXTitle("matrix[0][0]*(xcoord-xorigin)+matrix[0][1]*(ycoord-yorigin)");
   C2Test2xyNosTransf->SetYTitle("matrix[1][0]*(xcoord-xorigin)+matrix[1][1]*(ycoord-yorigin)");
   
   
   
   C1Test1xy_1 = fs->make<TH2F>("C1Test1xy_1", "ME1/1 x-y coordinates, Test 27", 125, -50., 50., 100, -100., 100. );
   C1Test2xy_1 = fs->make<TH2F>("C1Test2xy_1", "ME1/1 x-y coordinates, Test 40", 125, -50., 50., 100, -100., 100. );
   C2Test1xy_1 = fs->make<TH2F>("C2Test1xy_1", "ME2/1 x-y coordinates, Test 27", 125, -50., 50., 100, -100., 100. );
   C2Test2xy_1 = fs->make<TH2F>("C2Test2xy_1", "ME2/1 x-y coordinates, Test 40", 125, -50., 50., 100, -100., 100. );

}


MuonExercise00::~MuonExercise00()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
int n_correlatedlcts_c1_tot = 0;
int n_correlatedlcts_c2_tot = 0;
void
MuonExercise00::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

   Handle<CSCSegmentCollection> cscSegments;
   iEvent.getByToken(theCSCSegmentToken, cscSegments);
   
   edm::Handle<CSCRecHit2DCollection> recHits;
   iEvent.getByToken(theCSCRecHitToken, recHits);
   
   nSeg->Fill(cscSegments->size());
   
   if(cscSegments->size()>=1){
   
   CSCSegmentCollection::const_iterator seg = cscSegments->begin();
   
   
   
   
   

   vector<CSCRecHit2D> theRecHits = seg->specificRecHits();
   
   
   int hitsPS = 0;
   
   if(cscSegments->size()>0){
   
   for(vector<CSCRecHit2D>::const_iterator iRH = theRecHits.begin(); iRH != theRecHits.end(); iRH++) {

      double rHSumQ = 0;
      for (int i = 0; i < 3; i++){
         for (int j = 0; j < 3; j++){
            rHSumQ += (*iRH).adcs(i,j);
         }
      }
      Qhit->Fill(rHSumQ);
      
      hitsPS+= 1;

   }
   nHit->Fill(hitsPS);
   }
   
   
    // -----------------------
    
    // loop over segments
    
    // -----------------------
    
    int iSegment = 0;
    if(cscSegments->size()>0){
    for (CSCSegmentCollection::const_iterator dSiter = cscSegments->begin(); dSiter != cscSegments->end(); dSiter++) {
    
      iSegment++;
    
      //
    
      CSCDetId id = (CSCDetId)(*dSiter).cscDetId();
    
      int kEndcap = id.endcap();
    
      int kRing = id.ring();
    
      int kStation = id.station();
      
      int kChamber = id.chamber();
      
      StID->Fill(kChamber);
      //StID1->Fill(kStation);
    
    
      //
    
      float chisq = (*dSiter).chi2();
    
      int nhits = (*dSiter).nRecHits();
    
      int nDOF = 2 * nhits - 4;
    
      LocalPoint localPos = (*dSiter).localPosition();
    
      float segX = localPos.x();
    
      float segY = localPos.y();
    
      LocalVector segDir = (*dSiter).localDirection();
    
      double theta = segDir.theta();
    
    
      // Fill histos
      if(kChamber==1){
        C1Test1xy->Fill(segX,segY);
        C1Test2xy->Fill(segX,segY);
      }
      if(kChamber==36){
        C2Test1xy->Fill(segX,segY);
        C2Test2xy->Fill(segX,segY);
      }
      
      
    }  // end segment loop
    } //end if statement
    
    // Get the RecHits collection :

    //edm::Handle<CSCRecHit2DCollection> recHits;
    //iEvent.getByToken(theCSCRecHitToken, recHits);
    
    if(recHits->size()>0){
    for (CSCRecHit2DCollection::const_iterator recIt = recHits->begin(); recIt != recHits->end(); recIt++) {
      
      CSCDetId idrec = (CSCDetId)(*recIt).cscDetId();
      
      int kEndcap = idrec.endcap();
    
      int kRing = idrec.ring();
    
      int kStation = idrec.station();
      
      int kChamber = idrec.chamber();
      
      StID1->Fill(kStation);
      
      // Store rechit as a Local Point:

      LocalPoint rhitlocal = (*recIt).localPosition();
  
      float xreco = rhitlocal.x();
  
      float yreco = rhitlocal.y();
      
      // Fill histos
      if(kChamber==1){
        C1Test1xy_1->Fill(xreco,yreco);
        C1Test2xy_1->Fill(xreco,yreco);
      }
      if(kChamber==36){
        C2Test1xy_1->Fill(xreco,yreco);
        C2Test2xy_1->Fill(xreco,yreco);
      }
      
    } // end RecHit loop
    } //end if statement
    
    } // end of if(cscSegments->size()>=1)
    
    
    
    
    edm::Handle<CSCCorrelatedLCTDigiCollection> corrlctDigiTag;
    iEvent.getByToken(theCorrelatedLCTDigiToken, corrlctDigiTag);
    
    //For 7962
    // For chamber 1 and 2
    float mat1[2][2];
    float determinant1 = 0;
    
    //enter lower left coordinates here
    float xor_1=41.62;
    float yor_1=35.45;
    
    //top-left coordinate first then bottom-right
    
    float x1_1=41.62-xor_1;
    float y1_1=42.73-yor_1;
    float x2_1=89.10-xor_1;
    float y2_1=35.45-yor_1;
    
    mat1[0][0]=x2_1; //x-coord of bottom-right point translated wrt origin
    mat1[0][1]=x1_1; //x-coord of top-left point
    mat1[1][0]=y2_1; //y-coord of bottom-right point
    mat1[1][1]=y1_1; //y-coord of top-left point
    
    determinant1 = mat1[0][0]*mat1[1][1]-mat1[0][1]*mat1[1][0];
    
    float matinv1[2][2];
    
    matinv1[0][0]=mat1[1][1]/determinant1;
    matinv1[0][1]=-1*mat1[0][1]/determinant1;
    matinv1[1][0]=-1*mat1[1][0]/determinant1;
    matinv1[1][1]=mat1[0][0]/determinant1;
    
    float mat2[2][2];
    float determinant2 = 0;
    
    float xor_2=2.21;
    float yor_2=56.86;
    
    float x1_2=5.56-xor_2;
    float y1_2=65.39-yor_2;
    float x2_2=28.29-xor_2;
    float y2_2=56.86-yor_2;
      
    mat2[0][0]=x2_2; //x-coord of bottom-right point translated wrt origin
    mat2[0][1]=x1_2; //x-coord of top-left point
    mat2[1][0]=y2_2; //y-coord of bottom-right point
    mat2[1][1]=y1_2; //y-coord of top-left point
    
    determinant2 = mat2[0][0]*mat2[1][1]-mat2[0][1]*mat2[1][0];
    
    float matinv2[2][2];
    
    matinv2[0][0]=mat2[1][1]/determinant2;
    matinv2[0][1]=-1*mat2[0][1]/determinant2;
    matinv2[1][0]=-1*mat2[1][0]/determinant2;
    matinv2[1][1]=mat2[0][0]/determinant2;
    
    
    
    
    int n_correlatedlcts = 0;
    int n_correlatedlcts_c1 = 0;
    int n_correlatedlcts_c2 = 0;
    
    std::vector<float> xcoord_c1;
    std::vector<float> xcoord_c2;
    std::vector<float> ycoord_c1;
    std::vector<float> ycoord_c2;
    
    bool C1LCTinFV(false); //chamber 1 lct inside fiducial volume
    bool C2LCTinFV(false); //chamber 2 lct inside fiducial volume
    
    float C1xcoordtransf = 99.0;
    float C1ycoordtransf = 99.0;
    float C2xcoordtransf = -99.0;
    float C2ycoordtransf = -99.0;
    
    float minC1C2dist = 999.0;
    float minC1C2distX = 999.0;
    float minC1C2distY = 999.0;
    
    for (CSCCorrelatedLCTDigiCollection::DigiRangeIterator j = corrlctDigiTag->begin(); j != corrlctDigiTag->end(); j++) {
    
      const CSCCorrelatedLCTDigiCollection::Range& range = (*j).second;
      
      const CSCDetId &id = (*j).first;
      
      //CSCDetId id = (CSCDetId)(*seg).cscDetId();
      int kStation = id.station();
      int kChamber = id.chamber();
      
      
      for (CSCCorrelatedLCTDigiCollection::const_iterator digiIt = range.first; digiIt != range.second; ++digiIt) {
      
        
        if ((*digiIt).isValid()) {
          
          float xcoord=(*digiIt).getStrip();
          float ycoord=(*digiIt).getKeyWG();
          
          
          n_correlatedlcts++;
          if(kChamber==1){
            
            
            n_correlatedlcts_c1++;
            xcoord_c1.push_back(xcoord);
            ycoord_c1.push_back(ycoord);
            C1Test2xyNos->Fill(xcoord,ycoord);
            
            float xcoordtransf=matinv1[0][0]*(xcoord-xor_1)+matinv1[0][1]*(ycoord-yor_1);
            float ycoordtransf=matinv1[1][0]*(xcoord-xor_1)+matinv1[1][1]*(ycoord-yor_1);
            
            if(sqrt(pow(xcoordtransf-C2xcoordtransf,2)+pow(ycoordtransf-C2ycoordtransf,2))<minC1C2dist){
              C1xcoordtransf=xcoordtransf;
              C1ycoordtransf=ycoordtransf;
              
              minC1C2distX=C2xcoordtransf-C1xcoordtransf;
              minC1C2distY=C2ycoordtransf-C1ycoordtransf;
              
              minC1C2dist=sqrt(pow(xcoordtransf-C2xcoordtransf,2)+pow(ycoordtransf-C2ycoordtransf,2));
            }
            
            
            C1Test2xyNosTransf->Fill(xcoordtransf,ycoordtransf);
            
            if(0.0<xcoordtransf&&xcoordtransf<1.0&&0.0<ycoordtransf&&ycoordtransf<1.0){
              C1LCTinFV=true;
            }
          }
          
          if(kChamber==36){
            
            
            n_correlatedlcts_c2++;
            xcoord_c2.push_back(xcoord);
            ycoord_c2.push_back(ycoord);
            //CorrelatedLCTC1C2->Fill(1);
            C2Test2xyNos->Fill(xcoord,ycoord);
            
            float xcoordtransf=matinv2[0][0]*(xcoord-xor_2)+matinv2[0][1]*(ycoord-yor_2);
            float ycoordtransf=matinv2[1][0]*(xcoord-xor_2)+matinv2[1][1]*(ycoord-yor_2);
            
            
            if(sqrt(pow(C1xcoordtransf-xcoordtransf,2)+pow(C1ycoordtransf-ycoordtransf,2))<minC1C2dist){
              C2xcoordtransf=xcoordtransf;
              C2ycoordtransf=ycoordtransf;
              
              minC1C2distX=C2xcoordtransf-C1xcoordtransf;
              minC1C2distY=C2ycoordtransf-C1ycoordtransf;
              
              minC1C2dist=sqrt(pow(C1xcoordtransf-xcoordtransf,2)+pow(C1ycoordtransf-ycoordtransf,2));
            }
            
            
            C2Test2xyNosTransf->Fill(xcoordtransf,ycoordtransf);
            
            if(0.0<xcoordtransf&&xcoordtransf<1.0&&0.0<ycoordtransf&&ycoordtransf<1.0){
              C2LCTinFV=true;
            }
          }
  
          //histos->fill1DHist(
  
          //    (*digiIt).getBX(), "CorrelatedLCTS_getBX", "CorrelatedLCT.getBX()", 11, -0.5, 10.5, "TimeMonitoring");
  
        }
  
      }
  
    }// End CSCCorrelatedLCTDigiCollection loop
    
    
    n_correlatedlcts_c1_tot+=n_correlatedlcts_c1;
    n_correlatedlcts_c2_tot+=n_correlatedlcts_c2;
    
    C1C2HitDistance->Fill(minC1C2dist);
    C1C2HitDistanceX->Fill(minC1C2distX);
    C1C2HitDistanceY->Fill(minC1C2distY);
    
    int c_ref(2);// whether the reference chamber is 1. ME11 or 2. ME21
    
    if(c_ref==1){// For ME11 reference chamber
      if(n_correlatedlcts_c1==1&&C1LCTinFV){
       CorrelatedLCTC1C2->Fill(0);
       if(n_correlatedlcts_c2>=1&&C2LCTinFV){
         CorrelatedLCTC1C2->Fill(1);
       }
      }
      
      //validating the cuts
      if(n_correlatedlcts_c1==1&&C1LCTinFV){
       for (CSCCorrelatedLCTDigiCollection::DigiRangeIterator j = corrlctDigiTag->begin(); j != corrlctDigiTag->end(); j++) {
      
        const CSCCorrelatedLCTDigiCollection::Range& range = (*j).second;
        const CSCDetId &id = (*j).first;
        
        int kStation = id.station();
        int kChamber = id.chamber();
        
        for (CSCCorrelatedLCTDigiCollection::const_iterator digiIt = range.first; digiIt != range.second; ++digiIt) {
        
          
          if ((*digiIt).isValid()) {
            
            float xcoord=(*digiIt).getStrip();
            float ycoord=(*digiIt).getKeyWG();
            
            
            n_correlatedlcts++;
            if(kChamber==1){
              C1Test2xyNosIsValid->Fill(xcoord,ycoord);
            }
            
            if(kChamber==36){
              C2Test2xyNosIsValid->Fill(xcoord,ycoord);
            }
          }
    
        }
    
       }
      
      
        if(n_correlatedlcts_c2==1){
          for(unsigned int i = 0; i < xcoord_c2.size(); i++){
            C2Test2xyNos_LCT1->Fill(xcoord_c2.at(i),ycoord_c2.at(i));
          }
        }
        
        if(n_correlatedlcts_c2>1){
          for(unsigned int i = 0; i < xcoord_c2.size(); i++){
            C2Test2xyNos_LCT2->Fill(xcoord_c2.at(i),ycoord_c2.at(i));
          }
        }
      
      }// if(n_correlatedlcts_c1==1&&C1LCTinFV)
      
    }//if(c_ref==1)
    
    
    if(c_ref==2){// For ME21 reference chamber
      
      if(n_correlatedlcts_c2==1&&C2LCTinFV){
       CorrelatedLCTC1C2->Fill(1);
       if(n_correlatedlcts_c1>=1){//if(n_correlatedlcts_c1>=1&&C1LCTinFV)
         CorrelatedLCTC1C2->Fill(0);
       }
      }
      
      //validating the cuts
      if(n_correlatedlcts_c2==1&&C2LCTinFV){
       for (CSCCorrelatedLCTDigiCollection::DigiRangeIterator j = corrlctDigiTag->begin(); j != corrlctDigiTag->end(); j++) {
      
        const CSCCorrelatedLCTDigiCollection::Range& range = (*j).second;
        const CSCDetId &id = (*j).first;
        
        int kStation = id.station();
        int kChamber = id.chamber();
        
        for (CSCCorrelatedLCTDigiCollection::const_iterator digiIt = range.first; digiIt != range.second; ++digiIt) {
        
          
          if ((*digiIt).isValid()) {
            
            float xcoord=(*digiIt).getStrip();
            float ycoord=(*digiIt).getKeyWG();
            
            
            n_correlatedlcts++;
            if(kChamber==1){
              C1Test2xyNosIsValid->Fill(xcoord,ycoord);
            }
            
            if(kChamber==36){
              C2Test2xyNosIsValid->Fill(xcoord,ycoord);
            }
          }
    
        }
    
       }
      
      
        if(n_correlatedlcts_c1==1){
          for(unsigned int i = 0; i < xcoord_c1.size(); i++){
            C1Test2xyNos_LCT1->Fill(xcoord_c1.at(i),ycoord_c1.at(i));
          }
        }
        
        if(n_correlatedlcts_c1>1){
          for(unsigned int i = 0; i < xcoord_c1.size(); i++){
            C1Test2xyNos_LCT2->Fill(xcoord_c1.at(i),ycoord_c1.at(i));
          }
        }
      
      }// if(n_correlatedlcts_c2==1&&C2LCTinFV)
      
    }//if(c_ref==2)
    
    
    
    
    nCorrelatedLCTC1Test1->Fill(n_correlatedlcts_c1);
    nCorrelatedLCTC1Test2->Fill(n_correlatedlcts_c1);
    nCorrelatedLCTC2Test1->Fill(n_correlatedlcts_c2);
    nCorrelatedLCTC2Test2->Fill(n_correlatedlcts_c2);
    
    int n1_correlatedlcts_c1=(n_correlatedlcts_c1>0)?1:0;
    int n1_correlatedlcts_c2=(n_correlatedlcts_c2>0)?1:0;
    
    CorrelatedLCTC1Test1->Fill(n1_correlatedlcts_c1);
    CorrelatedLCTC1Test2->Fill(n1_correlatedlcts_c1);
    CorrelatedLCTC2Test1->Fill(n1_correlatedlcts_c2);
    CorrelatedLCTC2Test2->Fill(n1_correlatedlcts_c2);
    
    
    edm::Handle<CSCALCTDigiCollection> alctDigiTag;
    iEvent.getByToken(ALCTToken, alctDigiTag);
    
    for (CSCALCTDigiCollection::DigiRangeIterator j = alctDigiTag->begin(); j != alctDigiTag->end(); j++) {
    
        const CSCALCTDigiCollection::Range& range = (*j).second;
    
        const CSCDetId& idALCT = (*j).first;
        
        int kStation = idALCT.station();
        int kChamber = idALCT.chamber();
    
        for (CSCALCTDigiCollection::const_iterator digiIt = range.first; digiIt != range.second; ++digiIt) {
    
          // Valid digi in the chamber (or in neighbouring chamber)
    
          if ((*digiIt).isValid()) {
          
            float ycoord=(*digiIt).getKeyWG();
            
            if(kChamber==1){
              C1Test2ALCT->Fill(ycoord);
            }
            
            if(kChamber==36){
              C2Test2ALCT->Fill(ycoord);
            }
    
          }
    
        }
    }
    
    edm::Handle<CSCCLCTDigiCollection> clctDigiTag;
    iEvent.getByToken(CLCTToken, clctDigiTag);
    
    for (CSCCLCTDigiCollection::DigiRangeIterator j = clctDigiTag->begin(); j != clctDigiTag->end(); j++) {
    
        const CSCCLCTDigiCollection::Range& range = (*j).second;
    
        const CSCDetId& idCLCT = (*j).first;
        
        int kStation = idCLCT.station();
        int kChamber = idCLCT.chamber();
    
        for (CSCCLCTDigiCollection::const_iterator digiIt = range.first; digiIt != range.second; ++digiIt) {
    
          // Valid digi in the chamber (or in neighbouring chamber)
    
          if ((*digiIt).isValid()) {
          
            float xcoord=(*digiIt).getStrip();
            
            if(kChamber==1){
              C1Test2CLCT->Fill(xcoord);
            }
            
            if(kChamber==36){
              C2Test2CLCT->Fill(xcoord);
            }
          }
    
        }
    }
   
}


// ------------ method called once each job just before starting event loop  ------------
void
MuonExercise00::beginJob()
{

}

// ------------ method called once each job just after ending the event loop  ------------
void
MuonExercise00::endJob()
{
  std::cout << "No. of correlated LCTs in ME1/1: " <<n_correlatedlcts_c1_tot << " No. of correlated LCTs in ME2/1: " <<n_correlatedlcts_c2_tot << std::endl;
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MuonExercise00::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MuonExercise00);
