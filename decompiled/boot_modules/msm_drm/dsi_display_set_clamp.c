__int64 __fastcall dsi_display_set_clamp(__int64 a1, char a2)
{
  unsigned int v2; // w23
  __int64 *v4; // x24
  char v5; // w21
  __int64 *v6; // x22
  unsigned int v8; // w0
  const char *v9; // x2
  __int64 v11; // x3
  unsigned int v12; // w19
  unsigned int v13; // w8
  const char *v14; // x22
  __int64 v15; // x0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
  v2 = *(_DWORD *)(a1 + 840);
  if ( v2 >= 3 )
  {
    __break(0x5512u);
    return dsi_post_clkon_cb();
  }
  v4 = (__int64 *)(a1 + 168);
  v5 = *(_BYTE *)(a1 + 1218);
  v6 = (__int64 *)(a1 + 168 + 48LL * v2);
  v8 = dsi_ctrl_set_clamp_state(*v6, a2 & 1, v5);
  if ( !v8 )
  {
    v8 = ((__int64 (__fastcall *)(__int64, _QWORD))dsi_phy_set_clamp_state)(v6[3], a2 & 1);
    if ( v8 )
    {
LABEL_7:
      v9 = "*ERROR* [msm-dsi-error]: DSI phy clamp state change(%d) failed\n";
      goto LABEL_8;
    }
    v13 = *(_DWORD *)(a1 + 160);
    if ( v13 )
    {
      if ( (a2 & 1) != 0 )
        v14 = "enabled";
      else
        v14 = "disabled";
      if ( v2 && *v4 )
      {
        v8 = dsi_ctrl_set_clamp_state(*v4, a2 & 1, v5);
        if ( v8 )
        {
LABEL_23:
          v9 = "*ERROR* [msm-dsi-error]: DSI Clamp state change(%d) failed\n";
          goto LABEL_8;
        }
        v8 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_set_clamp_state)(*(_QWORD *)(a1 + 192), a2 & 1);
        if ( v8 )
          goto LABEL_7;
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Clamps %s for ctrl%d\n", v14, 0);
        v13 = *(_DWORD *)(a1 + 160);
      }
      if ( v13 >= 2 && v2 != 1 )
      {
        v15 = *(_QWORD *)(a1 + 216);
        if ( v15 )
        {
          v8 = dsi_ctrl_set_clamp_state(v15, a2 & 1, v5);
          if ( v8 )
            goto LABEL_23;
          v8 = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_set_clamp_state)(*(_QWORD *)(a1 + 240), a2 & 1);
          if ( v8 )
            goto LABEL_7;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Clamps %s for ctrl%d\n", v14, 1);
        }
      }
    }
    *(_BYTE *)(a1 + 1219) = a2 & 1;
    return 0;
  }
  v9 = "*ERROR* [msm-dsi-error]: DSI ctrl clamp state change(%d) failed\n";
LABEL_8:
  v11 = a2 & 1;
  v12 = v8;
  drm_dev_printk(0, &unk_248D72, v9, v11);
  return v12;
}
