__int64 __fastcall drm_dp_psr_setup_time(__int64 a1)
{
  unsigned __int64 v1; // x8

  v1 = ((unsigned __int64)*(unsigned __int8 *)(a1 + 1) >> 1) & 7;
  if ( (_DWORD)v1 == 7 )
    return 4294967274LL;
  else
    return drm_dp_psr_setup_time_psr_setup_time_us[v1];
}
