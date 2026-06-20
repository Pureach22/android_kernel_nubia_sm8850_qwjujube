__int64 __fastcall drm_dp_read_lttpr_phy_caps(_QWORD *a1, unsigned __int8 *a2, int a3, __int64 a4)
{
  unsigned int v4; // w23
  unsigned int v5; // w22
  __int64 v7; // x20
  __int64 result; // x0

  v4 = *a2;
  v5 = 80 * a3 + 982992;
  if ( v4 < 0x14 )
    v7 = 1;
  else
    v7 = 3;
  result = drm_dp_dpcd_read(a1, v5, a4, v7);
  if ( (result & 0x80000000) != 0 )
    return result;
  if ( (_DWORD)v7 != (_DWORD)result )
  {
    __break(0x800u);
    if ( v4 <= 0x13 )
      goto LABEL_7;
    return 0;
  }
  if ( v4 > 0x13 )
    return 0;
LABEL_7:
  result = drm_dp_dpcd_read(a1, v5 | (unsigned int)v7, a4 + v7, v7);
  if ( (result & 0x80000000) == 0 )
  {
    if ( (_DWORD)v7 != (_DWORD)result )
      __break(0x800u);
    result = drm_dp_dpcd_read(a1, v5 | (2 * v7), a4 + 2 * v7, v7);
    if ( (result & 0x80000000) == 0 )
    {
      if ( (_DWORD)v7 != (_DWORD)result )
      {
        __break(0x800u);
        return 0;
      }
      return 0;
    }
  }
  return result;
}
