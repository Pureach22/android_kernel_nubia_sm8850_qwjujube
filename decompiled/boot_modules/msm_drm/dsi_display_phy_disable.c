__int64 __fastcall dsi_display_phy_disable(__int64 a1)
{
  char v2; // w21
  unsigned int v3; // w22
  int v4; // w0
  int v5; // w0
  unsigned int v6; // w20

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
      v2 = 1;
    else
      v2 = *(_BYTE *)(a1 + 1641);
  }
  else
  {
    v2 = 0;
  }
  v3 = *(_DWORD *)(a1 + 836);
  if ( v3 >= 3 )
  {
    __break(0x5512u);
    return dsi_display_phy_sw_reset();
  }
  else
  {
    if ( *(_DWORD *)(a1 + 160) )
    {
      if ( v3 )
      {
        if ( *(_QWORD *)(a1 + 168) )
        {
          v4 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_disable)(*(_QWORD *)(a1 + 192), v2 & 1);
          if ( v4 )
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI PHY, skip_op=%d rc=%d\n",
              *(const char **)(a1 + 32),
              v2 & 1,
              v4);
        }
      }
      if ( *(_DWORD *)(a1 + 160) >= 2u && v3 != 1 )
      {
        if ( *(_QWORD *)(a1 + 216) )
        {
          v5 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_disable)(*(_QWORD *)(a1 + 240), v2 & 1);
          if ( v5 )
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI PHY, skip_op=%d rc=%d\n",
              *(const char **)(a1 + 32),
              v2 & 1,
              v5);
        }
      }
    }
    v6 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_disable)(*(_QWORD *)(a1 + 168 + 48LL * v3 + 24), v2 & 1);
    if ( v6 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI PHY, skip_op=%d rc=%d\n",
        *(const char **)(a1 + 32),
        v2 & 1,
        v6);
    return v6;
  }
}
