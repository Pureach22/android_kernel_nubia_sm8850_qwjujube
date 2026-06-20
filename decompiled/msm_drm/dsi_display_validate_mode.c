__int64 __fastcall dsi_display_validate_mode(__int64 a1, _BYTE *a2, char a3)
{
  __int64 v6; // x0
  unsigned int v7; // w8
  unsigned int v8; // w9
  unsigned int v9; // w21
  unsigned int v10; // w0
  __int64 v11; // x3
  const char *v12; // x2
  _QWORD dest[25]; // [xsp+8h] [xbp-C8h] BYREF

  dest[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(dest, 0, 192);
  if ( a1 && a2 )
  {
    mutex_lock(a1 + 72);
    memcpy(dest, a2, 0xC0u);
    v6 = *(_QWORD *)(a1 + 264);
    if ( *(_BYTE *)(v6 + 1280) == 1 && (v7 = *(_DWORD *)(v6 + 1284), v7 >= 2) )
    {
      v8 = dest[0];
    }
    else
    {
      v8 = dest[0];
      if ( *(_BYTE *)(dest[23] + 3400LL) == 1 )
        *(_WORD *)(dest[23] + 2506LL) = dest[0];
      v7 = *(_DWORD *)(a1 + 160);
    }
    LODWORD(dest[1]) /= v7;
    HIDWORD(dest[1]) /= v7;
    LODWORD(dest[0]) = v8 / v7;
    HIDWORD(dest[0]) /= v7;
    LODWORD(dest[2]) /= v7;
    LODWORD(dest[19]) /= v7;
    v10 = dsi_panel_validate_mode();
    if ( v10 )
    {
      v11 = *(_QWORD *)(a1 + 32);
      v9 = v10;
      v12 = "*ERROR* [msm-dsi-error]: [%s] panel mode validation failed, rc=%d\n";
LABEL_17:
      drm_dev_printk(0, &unk_248D72, v12, v11, v9);
LABEL_18:
      mutex_unlock(a1 + 72);
      goto LABEL_19;
    }
    if ( *(_DWORD *)(a1 + 160) )
    {
      v9 = dsi_ctrl_validate_timing(*(_QWORD *)(a1 + 168), (__int64)dest);
      if ( v9 )
      {
LABEL_14:
        v11 = *(_QWORD *)(a1 + 32);
        v12 = "*ERROR* [msm-dsi-error]: [%s] ctrl mode validation failed, rc=%d\n";
        goto LABEL_17;
      }
      v9 = dsi_phy_validate_mode(*(_QWORD *)(a1 + 192), (__int64)dest);
      if ( v9 )
        goto LABEL_16;
      if ( *(_DWORD *)(a1 + 160) >= 2u )
      {
        v9 = dsi_ctrl_validate_timing(*(_QWORD *)(a1 + 216), (__int64)dest);
        if ( v9 )
          goto LABEL_14;
        v9 = dsi_phy_validate_mode(*(_QWORD *)(a1 + 240), (__int64)dest);
        if ( v9 )
        {
LABEL_16:
          v11 = *(_QWORD *)(a1 + 32);
          v12 = "*ERROR* [msm-dsi-error]: [%s] phy mode validation failed, rc=%d\n";
          goto LABEL_17;
        }
      }
    }
    if ( (a3 & 1) != 0 && (a2[156] & 1) != 0 && (dsi_display_validate_mode_seamless(a1, a2) & 1) != 0 )
    {
      v9 = 1;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] seamless not possible rc=%d\n",
        *(_QWORD *)(a1 + 32),
        1);
    }
    else
    {
      v9 = 0;
    }
    goto LABEL_18;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  v9 = -22;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v9;
}
