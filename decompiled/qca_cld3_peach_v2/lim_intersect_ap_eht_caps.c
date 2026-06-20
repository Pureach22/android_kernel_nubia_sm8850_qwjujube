__int64 __fastcall lim_intersect_ap_eht_caps(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  int v5; // w0
  __int64 result; // x0

  if ( a4 && *(_BYTE *)(a4 + 2612) )
    v5 = a4 + 2612;
  else
    v5 = a3 + 2740;
  result = lim_intersect_eht_caps(v5, (int)a2 + 284);
  *(_BYTE *)(a2 + 280) = 1;
  return result;
}
