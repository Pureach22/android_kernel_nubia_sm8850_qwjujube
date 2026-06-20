__int64 __fastcall sub_4974F0(__int64 a1)
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return wma_is_csa_offload_enabled(a1);
}
