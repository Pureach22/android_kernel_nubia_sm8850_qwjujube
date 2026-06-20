__int64 __fastcall drm_dp_set_phy_test_pattern(_QWORD *a1, __int64 a2, unsigned __int8 a3)
{
  char v4; // w21
  __int64 result; // x0
  int v7; // w22
  _BYTE v8[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(a2 + 5);
  if ( a3 < 0x12u )
  {
    v8[0] = 4 * (v4 & 3);
    result = drm_dp_dpcd_write(a1, 0x102u, (__int64)v8, 1);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
  if ( !*(_BYTE *)(a2 + 4) )
  {
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  v7 = 0;
  while ( 1 )
  {
    v9[0] = v4;
    result = drm_dp_dpcd_write(a1, v7 + 267, (__int64)v9, 1);
    if ( (result & 0x80000000) != 0 )
      break;
    if ( ++v7 >= (unsigned int)*(unsigned __int8 *)(a2 + 4) )
      goto LABEL_8;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
