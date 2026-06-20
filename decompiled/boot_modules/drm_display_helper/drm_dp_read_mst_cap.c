__int64 __fastcall drm_dp_read_mst_cap(_QWORD *a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  bool v3; // zf
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a2 >= 0x12u )
  {
    v4[0] = 0;
    v3 = drm_dp_dpcd_read(a1, 0x21u, (__int64)v4, 1) == 1;
    result = 0;
    if ( v3 )
    {
      if ( (v4[0] & 1) != 0 )
        result = 1;
      else
        result = v4[0] & 2;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
