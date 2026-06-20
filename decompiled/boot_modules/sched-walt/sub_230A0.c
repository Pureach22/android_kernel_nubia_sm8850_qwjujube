__int64 sub_230A0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return should_boost_bus_dcvs();
}
