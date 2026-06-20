__int64 __fastcall drm_dp_get_pcon_max_frl_bw(__int64 a1, __int64 a2)
{
  int v2; // w8

  v2 = ((*(unsigned __int8 *)(a2 + 2) >> 2) & 7) - 1;
  if ( (unsigned int)v2 > 5 )
    return 0;
  else
    return dword_1D7C0[v2];
}
