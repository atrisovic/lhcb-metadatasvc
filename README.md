# LHCb MetaData service

The LHCb MetaData service records the data provenance such as the application name and version when creating an n-tuple.
This repository contains two examples showing how to use the MetaData service and a code snippet to read the metadata from an ntuple. The service is implemented in Gaudi and available from Gaudi version v27r1 and onwards, which correspons to DaVinci v40r0 and later.

## Run the examples

The service is included in python option files with: `ApplicationMgr().ExtSvc += [ 'Gaudi::MetaDataSvc' ]`.

Run the examples with: `lb-run DaVinci/latest gaudirun.py DaVinci_Options.py`

### Example 1

This simple example does not require input files. It is one of the official Gaudi examples found [here](https://gitlab.cern.ch:8443/atlas/Gaudi/blob/master/GaudiExamples/options/TupleEx.py). 

### Example 2

The code for this example is copied from [analysis-case-study](https://github.com/atrisovic/analysis-case-study/tree/master/Step2_getMonteCarlo/D2Kmumu) and [lhcb-starter-kit](https://lhcb.github.io/first-analysis-steps/minimal-dv-job.html).

## Read metadata

The n-tuple produced now has an 'info' file as shown on Figure below.

![](img/image.png)

To avoid problems with ROOT run: `lb-run ROOT bash`, then `root` and:
```
.L read-metadata/readMetaData.C
readMetaData("DV-ntuple.root")
```
