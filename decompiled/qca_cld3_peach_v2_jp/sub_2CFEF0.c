__int64 sub_2CFEF0()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return cds_is_driver_recovering();
}
