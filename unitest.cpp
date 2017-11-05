#include "neuron.h"
#include "gtest/gtest.h"

TEST (NeuronTest, UpdatePotential)
{
Neuron n1;

n1.setJext(0);
n1.update(1,1.0);

EXPECT_EQ(20*(1-std::exp(-0.1/20.0)),n1.getPot());
}

TEST (NeuronTest, Spikes)
{
  Neuron n1;
  Neuron n2;
  bool isSpiking(false);
  int time(1);
  while (isSpiking==false){
  isSpiking=n1.update(time,1.01);
  ++time;
  }

  EXPECT_GT(refractory_count,0);
  EXPECT_EQ(0,n1.getPot());

 time=1;
  while(n2.getPot()<20.0){
    isSpiking=n2.update(time,1.01);
  }
  EXPECT_TRUE(isSpiking);
}

TEST (NeuronTest, Buffer)
{
  Neuron n1;
  Neuron n2;
  bool isSpiking(false);
  int time;
  while (isSpiking==false){
  isSpiking=n1.update(time,1.01);
  ++time;
  }
  n2.receive(time,n1.getJ());
  EXPECT_EQ(0,n2.getBufferValue(time%(n2.getD()+1)]);
  EXPECT_EQ(n1.getJ(),n2.getBufferValue((time+n2.getD())%(n2.getD()+1)]));
}

int main(int argc,char**argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
