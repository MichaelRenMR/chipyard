package chipyard

import freechips.rocketchip.config.{Config}

// ---------------------
// BOOM Configs
// ---------------------
class C8B1MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(8) ++
  new freechips.rocketchip.subsystem.WithNBanks(1) ++
  new chipyard.MegaBoomConfig)

class C8B2MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(8) ++
  new freechips.rocketchip.subsystem.WithNBanks(2) ++
  new chipyard.MegaBoomConfig)

class C8B4MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(8) ++
  new freechips.rocketchip.subsystem.WithNBanks(4) ++
  new chipyard.MegaBoomConfig)


class C4B1MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(4) ++
  new freechips.rocketchip.subsystem.WithNBanks(1) ++
  new chipyard.MegaBoomConfig)

class C4B2MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(4) ++
  new freechips.rocketchip.subsystem.WithNBanks(2) ++
  new chipyard.MegaBoomConfig)


class C1B2MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(1) ++
  new freechips.rocketchip.subsystem.WithNBanks(2) ++
  new chipyard.MegaBoomConfig)

class C1B4MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(1) ++
  new freechips.rocketchip.subsystem.WithNBanks(4) ++
  new chipyard.MegaBoomConfig)

class C1B8MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(1) ++
  new freechips.rocketchip.subsystem.WithNBanks(8) ++
  new chipyard.MegaBoomConfig)



class C4B8MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(4) ++
  new freechips.rocketchip.subsystem.WithNBanks(8) ++
  new chipyard.MegaBoomConfig)

class C2B8MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(2) ++
  new freechips.rocketchip.subsystem.WithNBanks(8) ++
  new chipyard.MegaBoomConfig)

class C2B4MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(2) ++
  new freechips.rocketchip.subsystem.WithNBanks(4) ++
  new chipyard.MegaBoomConfig)

class C8B8MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(8) ++
  new freechips.rocketchip.subsystem.WithNBanks(8) ++
  new chipyard.MegaBoomConfig)

class C4B4MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(4) ++
  new freechips.rocketchip.subsystem.WithNBanks(4) ++
  new chipyard.MegaBoomConfig)

class C2B2MegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(2) ++
  new freechips.rocketchip.subsystem.WithNBanks(2) ++
  new chipyard.MegaBoomConfig)

class DualChannelMegaBoomConfig extends Config(
  new freechips.rocketchip.subsystem.WithNMemoryChannels(2) ++
  new chipyard.MegaBoomConfig)

class SmallBoomConfig extends Config(
  new boom.common.WithNSmallBooms(1) ++                          // small boom config
  new chipyard.config.AbstractConfig)

class MediumBoomConfig extends Config(
  new boom.common.WithNMediumBooms(1) ++                         // medium boom config
  new chipyard.config.AbstractConfig)

class LargeBoomConfig extends Config(
  new boom.common.WithNLargeBooms(1) ++                          // large boom config
  new chipyard.config.AbstractConfig)

class MegaBoomConfig extends Config(
  new boom.common.WithNMegaBooms(1) ++                           // mega boom config
  new chipyard.config.AbstractConfig)

class DualSmallBoomConfig extends Config(
  new boom.common.WithNSmallBooms(2) ++                          // 2 boom cores
  new chipyard.config.AbstractConfig)

class HwachaLargeBoomConfig extends Config(
  new chipyard.config.WithHwachaTest ++
  new hwacha.DefaultHwachaConfig ++                              // use Hwacha vector accelerator
  new boom.common.WithNLargeBooms(1) ++
  new chipyard.config.AbstractConfig)

class LoopbackNICLargeBoomConfig extends Config(
  new chipyard.harness.WithLoopbackNIC ++                        // drive NIC IOs with loopback
  new icenet.WithIceNIC ++                                       // build a NIC
  new boom.common.WithNLargeBooms(1) ++
  new chipyard.config.AbstractConfig)

class DromajoBoomConfig extends Config(
  new chipyard.harness.WithSimDromajoBridge ++                   // attach Dromajo
  new chipyard.config.WithTraceIO ++                             // enable the traceio
  new boom.common.WithNSmallBooms(1) ++
  new chipyard.config.AbstractConfig)
