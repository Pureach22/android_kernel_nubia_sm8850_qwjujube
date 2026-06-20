__int64 __fastcall drm_dp_pcon_frl_enable(const char **a1)
{
  __int64 result; // x0
  char v3; // w8
  const char *v4; // x8
  __int64 v5; // x1
  int v6; // w0
  _BYTE v7[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  result = drm_dp_dpcd_read(a1, 0x305Au, (__int64)v7, 1);
  if ( (result & 0x80000000) == 0 )
  {
    v3 = v7[0];
    if ( (v7[0] & 8) != 0 )
    {
      v7[0] |= 0x80u;
      v8[0] = v3 | 0x80;
      v6 = drm_dp_dpcd_write(a1, 0x305Au, (__int64)v8, 1);
      result = v6 & (unsigned int)(v6 >> 31);
    }
    else
    {
      v4 = a1[157];
      if ( v4 )
        v5 = *((_QWORD *)v4 + 1);
      else
        v5 = 0;
      _drm_dev_dbg(0, v5, 2, "%s: PCON in Autonomous mode, can't enable FRL\n", *a1);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
