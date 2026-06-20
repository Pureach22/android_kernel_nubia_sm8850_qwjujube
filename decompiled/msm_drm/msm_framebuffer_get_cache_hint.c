__int64 __fastcall msm_framebuffer_get_cache_hint(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  if ( !a1 )
    return 4294967274LL;
  *a2 = a1[50];
  *a3 = a1[51];
  *a4 = a1[52];
  return 0;
}
