__int64 __fastcall drm_dp_dpcd_probe(_QWORD *a1, unsigned int a2)
{
  int v4; // w20
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x1
  int v8; // w8
  _BYTE v10[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v4 = drm_dp_dpcd_access(a1, 9, a2, v10, 1);
  if ( !v4 )
  {
    __break(0x800u);
    v5 = a1[157];
    if ( v5 )
      goto LABEL_6;
    goto LABEL_13;
  }
  v5 = a1[157];
  if ( v4 < 1 )
  {
    if ( v5 )
    {
LABEL_6:
      v7 = *(_QWORD *)(v5 + 8);
LABEL_14:
      _drm_dev_dbg(0, v7, 8, "%s: 0x%05x AUX %s (ret=%3d)\n", *a1, a2, "->", (unsigned int)v4);
      goto LABEL_15;
    }
LABEL_13:
    v7 = 0;
    goto LABEL_14;
  }
  if ( v5 )
    v6 = *(_QWORD *)(v5 + 8);
  else
    v6 = 0;
  if ( (unsigned int)v4 >= 0x14 )
    v8 = 20;
  else
    v8 = v4;
  _drm_dev_dbg(0, v6, 8, "%s: 0x%05x AUX %s (ret=%3d) %*ph\n", *a1, a2, "->", (unsigned int)v4, v8, v10);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v4 & (unsigned int)(v4 >> 31);
}
