__int64 __fastcall hal_rx_reo_prev_pn_get_peach(__int64 result, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x8

  v2 = (unsigned int)*(_QWORD *)(result + 8) >> 8;
  *a2 = v2;
  *a2 = v2 | ((unsigned __int64)*(unsigned int *)(result + 12) << 24);
  return result;
}
