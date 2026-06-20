__int64 __fastcall dsi_display_set_ulps(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  long double v6; // q0
  __int64 v7; // x8
  unsigned int v9; // w21
  _QWORD *v10; // x22
  _QWORD *v11; // x23
  int v12; // w0
  unsigned int v13; // w8
  unsigned int v14; // w0
  int v15; // w3
  unsigned int v16; // w19
  unsigned int v17; // w8
  __int64 v18; // x0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
  *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: checking ulps req validity\n");
  v7 = *(_QWORD *)(a1 + 264);
  if ( *(_DWORD *)(v7 + 1968) )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: ESD recovery sequence underway\n", "dsi_display_is_ulps_req_valid");
LABEL_4:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: skipping ULPS config, enable=%d\n", "dsi_display_set_ulps", a2 & 1);
    return 0;
  }
  if ( (*(_BYTE *)(v7 + 1961) & 1) == 0 && (*(_BYTE *)(v7 + 1962) & 1) == 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: ULPS feature is not enabled\n", "dsi_display_is_ulps_req_valid");
    goto LABEL_4;
  }
  if ( (*(_BYTE *)(v7 + 1973) & 1) == 0 && (*(_BYTE *)(v7 + 1962) & 1) == 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: panel not yet initialized\n", "dsi_display_is_ulps_req_valid");
    goto LABEL_4;
  }
  if ( (a2 & 1) != 0 )
  {
    if ( *(_BYTE *)(a1 + 1218) )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: ULPS already enabled\n", *(double *)&v6);
      goto LABEL_4;
    }
    if ( (*(_BYTE *)(a1 + 64) & 1) != 0 || *(_BYTE *)(a1 + 1641) == 1 )
      goto LABEL_4;
  }
  else if ( (*(_BYTE *)(a1 + 1218) & 1) == 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: ULPS already disabled\n", *(double *)&v6);
    goto LABEL_4;
  }
  v9 = *(_DWORD *)(a1 + 840);
  if ( v9 < 3 )
  {
    v10 = (_QWORD *)(a1 + 168);
    v11 = (_QWORD *)(a1 + 168 + 48LL * v9);
    v12 = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD, long double))dsi_phy_set_ulps)(
            v11[3],
            a1 + 888,
            a2 & 1,
            *(unsigned __int8 *)(a1 + 1219),
            v6);
    if ( v12 == 2 )
      goto LABEL_28;
    if ( v12 != 1 )
    {
      if ( !v12 )
      {
        v13 = *(_DWORD *)(a1 + 160);
        if ( v13 )
        {
          if ( !v9 || !*v10 )
          {
LABEL_24:
            if ( v13 >= 2
              && v9 != 1
              && *(_QWORD *)(a1 + 216)
              && (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))dsi_phy_set_ulps)(
                                 *(_QWORD *)(a1 + 240),
                                 a1 + 888,
                                 a2 & 1,
                                 *(unsigned __int8 *)(a1 + 1219)) == 2 )
            {
              goto LABEL_28;
            }
            goto LABEL_46;
          }
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))dsi_phy_set_ulps)(
                               *(_QWORD *)(a1 + 192),
                               a1 + 888,
                               a2 & 1,
                               *(unsigned __int8 *)(a1 + 1219)) != 2 )
          {
            v13 = *(_DWORD *)(a1 + 160);
            goto LABEL_24;
          }
LABEL_28:
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Ulps PHY state change(%d) failed\n", a2 & 1);
          return 4294967274LL;
        }
      }
LABEL_46:
      *(_BYTE *)(a1 + 1218) = a2 & 1;
      return 0;
    }
    v14 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_ctrl_set_ulps)(*v11, a2 & 1);
    if ( !v14 )
    {
      v17 = *(_DWORD *)(a1 + 160);
      if ( !v17 )
        goto LABEL_46;
      if ( v9 && *v10 )
      {
        v14 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_ctrl_set_ulps)(*v10, a2 & 1);
        if ( v14 )
          goto LABEL_36;
        v17 = *(_DWORD *)(a1 + 160);
      }
      if ( v17 < 2 )
        goto LABEL_46;
      if ( v9 == 1 )
        goto LABEL_46;
      v18 = *(_QWORD *)(a1 + 216);
      if ( !v18 )
        goto LABEL_46;
      v14 = ((__int64 (__fastcall *)(__int64, _QWORD))dsi_ctrl_set_ulps)(v18, a2 & 1);
      if ( !v14 )
        goto LABEL_46;
    }
LABEL_36:
    v15 = a2 & 1;
    v16 = v14;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Ulps controller state change(%d) failed\n", v15);
    return v16;
  }
  __break(0x5512u);
  return dsi_display_config_clk_gating(v4, v5);
}
