__int64 __fastcall drm_lspcon_set_mode(__int64 a1, __int64 a2, int a3)
{
  __int64 v6; // x0
  int v7; // w22
  __int64 mode; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  const char *v11; // x4
  __int64 result; // x0
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // [xsp+0h] [xbp-10h] BYREF
  bool v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = a3 == 2;
  v16 = 0;
  v6 = drm_dp_dual_mode_write(a2, 64, v17, 1u);
  if ( (v6 & 0x80000000) != 0 )
  {
    v13 = v6;
    if ( a1 )
      v14 = *(_QWORD *)(a1 + 8);
    else
      v14 = 0;
    dev_err(v14, "[drm] *ERROR* LSPCON mode change failed\n");
  }
  else
  {
    v7 = -200;
    while ( 1 )
    {
      mode = drm_lspcon_get_mode(a1, a2, &v16);
      if ( (_DWORD)mode )
        break;
      if ( v16 == a3 )
      {
        if ( a1 )
          v10 = *(_QWORD *)(a1 + 8);
        else
          v10 = 0;
        if ( a3 == 1 )
          v11 = "LS";
        else
          v11 = "PCON";
        _drm_dev_dbg(0, v10, 2, "LSPCON mode changed to %s\n", v11);
        result = 0;
        goto LABEL_15;
      }
      msleep(10);
      v7 += 10;
      if ( !v7 )
      {
        if ( a1 )
          v9 = *(_QWORD *)(a1 + 8);
        else
          v9 = 0;
        dev_err(v9, "[drm] *ERROR* LSPCON mode change timed out\n");
        result = 4294967186LL;
        goto LABEL_15;
      }
    }
    v13 = mode;
    if ( a1 )
      v15 = *(_QWORD *)(a1 + 8);
    else
      v15 = 0;
    dev_err(v15, "[drm] *ERROR* can't confirm LSPCON mode change\n");
  }
  result = v13;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
