__int64 __fastcall drm_dp_pcon_frl_configure_1(_QWORD *a1, int a2, char a3)
{
  __int64 result; // x0
  char v7; // w8
  int v8; // w0
  _BYTE v9[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x305Au, (__int64)v9, 1);
  if ( (result & 0x80000000) == 0 )
  {
    result = 4294967274LL;
    v7 = v9[0] & 0xEF | (16 * (a3 == 16));
    v9[0] = v7;
    if ( a2 <= 23 )
    {
      switch ( a2 )
      {
        case 0:
LABEL_18:
          v10[0] = v7;
          v8 = drm_dp_dpcd_write(a1, 0x305Au, (__int64)v10, 1);
          result = v8 & (unsigned int)(v8 >> 31);
          break;
        case 9:
          v7 |= 1u;
          goto LABEL_17;
        case 18:
          v7 |= 2u;
          goto LABEL_17;
      }
    }
    else if ( a2 > 39 )
    {
      if ( a2 == 40 )
      {
        v7 |= 5u;
        goto LABEL_17;
      }
      if ( a2 == 48 )
      {
        v7 |= 6u;
        goto LABEL_17;
      }
    }
    else
    {
      if ( a2 == 24 )
      {
        v7 |= 3u;
        goto LABEL_17;
      }
      if ( a2 == 32 )
      {
        v7 |= 4u;
LABEL_17:
        v9[0] = v7;
        goto LABEL_18;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
