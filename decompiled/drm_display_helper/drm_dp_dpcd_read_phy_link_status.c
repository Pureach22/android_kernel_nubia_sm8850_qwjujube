__int64 __fastcall drm_dp_dpcd_read_phy_link_status(_QWORD *a1, int a2, __int64 a3)
{
  __int64 result; // x0
  __int16 v5; // w8

  if ( a2 )
  {
    result = drm_dp_dpcd_read(a1, 80 * a2 + 983008, a3, 5);
    if ( (result & 0x80000000) == 0 )
    {
      if ( (_DWORD)result != 5 )
        __break(0x800u);
      v5 = *(_WORD *)(a3 + 3);
      *(_BYTE *)(a3 + 3) = 0;
      *(_WORD *)(a3 + 4) = v5;
      return 0;
    }
  }
  else
  {
    result = drm_dp_dpcd_read(a1, 0x202u, a3, 6);
    if ( (result & 0x80000000) == 0 )
    {
      if ( (_DWORD)result == 6 )
      {
        return 0;
      }
      else
      {
        __break(0x800u);
        return 0;
      }
    }
  }
  return result;
}
