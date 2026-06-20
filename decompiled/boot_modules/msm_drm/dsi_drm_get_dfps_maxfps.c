__int64 __fastcall dsi_drm_get_dfps_maxfps(__int64 result)
{
  _DWORD *v1; // x8

  if ( result )
  {
    v1 = *(_DWORD **)(result + 264);
    if ( v1 && v1[338] == 1 && v1[340] == 4 )
      return (unsigned int)v1[342];
    else
      return 0;
  }
  return result;
}
