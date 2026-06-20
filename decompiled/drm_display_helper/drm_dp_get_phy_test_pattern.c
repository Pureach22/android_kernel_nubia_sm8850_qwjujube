__int64 __fastcall drm_dp_get_phy_test_pattern(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // w8
  int v7; // w8
  __int64 v8; // x2
  _QWORD *v9; // x0
  unsigned int v10; // w1
  __int64 v11; // x3
  _BYTE v12[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v12[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x219u, (__int64)v13, 1);
  if ( (result & 0x80000000) == 0 )
  {
    if ( v13[0] == 1 )
    {
      v5 = 1000000;
    }
    else if ( v13[0] == 2 )
    {
      v5 = 2000000;
    }
    else
    {
      v5 = v13[0] == 4 ? 1350000 : 27000 * v13[0];
    }
    *(_DWORD *)a2 = v5;
    result = drm_dp_dpcd_read(a1, 0x220u, (__int64)v12, 1);
    if ( (result & 0x80000000) == 0 )
    {
      v6 = v12[0];
      *(_BYTE *)(a2 + 4) = v12[0] & 0x1F;
      if ( v6 < 0 )
        *(_BYTE *)(a2 + 18) = 1;
      result = drm_dp_dpcd_read(a1, 0x248u, a2 + 5, 1);
      if ( (result & 0x80000000) == 0 )
      {
        v7 = *(unsigned __int8 *)(a2 + 5);
        if ( v7 == 5 )
        {
          v8 = a2 + 6;
          v9 = a1;
          v10 = 586;
          v11 = 2;
        }
        else
        {
          if ( v7 != 4 )
          {
LABEL_18:
            result = 0;
            goto LABEL_19;
          }
          v8 = a2 + 8;
          v9 = a1;
          v10 = 592;
          v11 = 10;
        }
        result = drm_dp_dpcd_read(v9, v10, v8, v11);
        if ( (result & 0x80000000) == 0 )
          goto LABEL_18;
      }
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
