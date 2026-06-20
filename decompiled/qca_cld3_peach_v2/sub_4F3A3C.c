__int64 __fastcall sub_4F3A3C(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int16 *v3; // x19

  __stxr(0, v3);
  return wma_set_txrx_fw_stats_level(a1, a2, a3);
}
