__int64 __fastcall dsi_display_ext_get_mode_info(int a1, __int64 a2, int a3, _DWORD *s, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  int v10; // w8
  int v11; // w8

  result = 4294967274LL;
  if ( a2 && s && a6 && *(_DWORD *)(a6 + 24) )
  {
    memset(s, 0, 0x388u);
    v10 = drm_mode_vrefresh(a2);
    result = 0;
    *s = v10;
    s[1] = *(unsigned __int16 *)(a2 + 20);
    if ( *(_DWORD *)(a6 + 24) > (unsigned int)*(unsigned __int16 *)(a2 + 4) )
      v11 = 1;
    else
      v11 = 2;
    s[9] = v11;
    s[10] = 0;
    s[11] = v11;
    s[15] = 0;
  }
  return result;
}
