__int64 __fastcall sub_6462B4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, double a5, __n128 a6)
{
  _WORD *v6; // x20

  *v6 = a6.n128_u16[0];
  return hal_rx_fst_detach(a1, a2, a3, a4);
}
