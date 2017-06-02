from DecayTreeTuple.Configuration import *
from Configurables import DecayTreeTuple, LoKi__Hybrid__TupleTool, TupleToolDecay, TupleToolTrigger, TupleToolTISTOS, TupleToolSelResults, TupleToolTrackInfo, TupleToolEventInfo, TupleToolVtxIsoln, TupleToolTrackIsolation, TupleToolAngles, TupleToolRecoStats
from Gaudi.Configuration import *

# include MetaDataSvc
ApplicationMgr().ExtSvc += [ 'Gaudi::MetaDataSvc' ]

stream = 'AllStreams'
line = 'D2XMuMu_KOSLine'

dtt = DecayTreeTuple('D2KmumuOSTuple')
dtt.Inputs = ['/Event/{0}/Phys/{1}/Particles'.format(stream, line)]

dtt.Decay = '[D+ -> ^K+ ^mu+ ^mu-]CC'
dtt.addBranches({"D" :  "[D+ -> K+ mu+ mu-]CC"} )

from Configurables import DaVinci

# Configure DaVinci
DaVinci().UserAlgorithms += [dtt]
DaVinci().InputType = 'DST'
DaVinci().TupleFile = 'DV-ntuple.root'
DaVinci().PrintFreq = 1000
DaVinci().DataType = '2011'
DaVinci().Simulation = True
DaVinci().Lumi = DaVinci().Simulation
DaVinci().EvtMax = -1
DaVinci().CondDBtag = 'Sim08-20130503-vc-md100'
DaVinci().DDDBtag = 'Sim08-20130503'

from GaudiConf import IOHelper

# Use the local input data
IOHelper().inputFiles([
    './00024919_00000001_1.allstreams.dst'
], clear=True)
