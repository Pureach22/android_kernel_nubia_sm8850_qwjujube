__int64 __fastcall dsi_display_phy_enable(__int64 a1, unsigned int a2)
{
  char v3; // w21
  unsigned int v4; // w23
  _QWORD *v5; // x24
  __int64 v6; // x22
  int v7; // w0
  unsigned int v8; // w20
  unsigned int v9; // w8

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 64) & 1) != 0 )
      v3 = 1;
    else
      v3 = *(_BYTE *)(a1 + 1641);
  }
  else
  {
    v3 = 0;
  }
  v4 = *(_DWORD *)(a1 + 836);
  if ( v4 >= 3 )
  {
    __break(0x5512u);
    JUMPOUT(0x1DF4BC);
  }
  v5 = (_QWORD *)(a1 + 168);
  v6 = a1 + 168 + 48LL * v4;
  v7 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, __int64, _QWORD))dsi_phy_enable)(
         *(_QWORD *)(v6 + 24),
         a1 + 888,
         a2,
         1,
         v3 & 1);
  if ( v7 )
  {
    v8 = v7;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI PHY, skip_op=%d rc=%d\n",
      *(const char **)(a1 + 32),
      v3 & 1,
      v7);
    return v8;
  }
  v9 = *(_DWORD *)(a1 + 160);
  if ( !v9 )
    return 0;
  if ( v4 && *v5 )
  {
    v8 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64, _QWORD))dsi_phy_enable)(
           *(_QWORD *)(a1 + 192),
           a1 + 888,
           2,
           1,
           v3 & 1);
    if ( v8 )
    {
LABEL_18:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI PHY, skip_op: %d rc=%d\n",
        *(const char **)(a1 + 32),
        v3 & 1,
        v8);
      ((void (__fastcall *)(_QWORD, _QWORD))dsi_phy_disable)(*(_QWORD *)(v6 + 24), v3 & 1);
      return v8;
    }
    v9 = *(_DWORD *)(a1 + 160);
  }
  if ( v9 < 2 )
    return 0;
  v8 = 0;
  if ( v4 != 1 )
  {
    if ( *(_QWORD *)(a1 + 216) )
    {
      v8 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64, _QWORD))dsi_phy_enable)(
             *(_QWORD *)(a1 + 240),
             a1 + 888,
             2,
             1,
             v3 & 1);
      if ( v8 )
        goto LABEL_18;
    }
  }
  return v8;
}
