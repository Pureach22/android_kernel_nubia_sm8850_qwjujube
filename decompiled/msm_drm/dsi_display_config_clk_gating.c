__int64 __fastcall dsi_display_config_clk_gating(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v3; // w22
  _QWORD *v4; // x23
  _QWORD *v5; // x24
  char v6; // w19
  int v8; // w8
  unsigned int v9; // w20
  const char *v10; // x4
  const char *v11; // x5
  const char *v12; // x6
  const char *v13; // x7
  double v14; // d0
  unsigned int v15; // w0
  bool v16; // zf
  unsigned int v17; // w19
  const char *v18; // x4
  unsigned int v19; // w9
  __int64 v20; // x8
  __int64 v21; // x8
  const char *v22; // x4

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1275LL) == 1 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: no dsi clock gating for continuous clock mode\n");
    return 0;
  }
  v3 = *(_DWORD *)(a1 + 836);
  if ( v3 >= 3 )
  {
    __break(0x5512u);
    return dsi_display_set_clamp(a1, a2);
  }
  v4 = (_QWORD *)(a1 + 168);
  v5 = (_QWORD *)(a1 + 168 + 48LL * v3);
  if ( !v5 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid controller\n");
    return 4294967274LL;
  }
  v6 = a2;
  if ( (a2 & 1) != 0 )
  {
    v8 = *(_DWORD *)(a1 + 1612);
    if ( (unsigned int)(v8 - 9) >= 0xFFFFFFF8 )
    {
      if ( v8 == 8 )
        v9 = 0;
      else
        v9 = *(_DWORD *)(a1 + 1612);
    }
    else
    {
      v9 = 5;
    }
    v10 = "Enabling";
  }
  else
  {
    v9 = 7;
    v10 = "Disabling";
  }
  if ( (v9 & 2) != 0 )
    v11 = "yes";
  else
    v11 = "no";
  if ( (v9 & 1) != 0 )
    v12 = "yes";
  else
    v12 = "no";
  if ( (v9 & 4) != 0 )
    v13 = "yes";
  else
    v13 = "no";
  v14 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s clock gating Byte:%s Pixel:%s PHY:%s\n", v10, v11, v12, v13);
  v15 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, double))dsi_ctrl_config_clk_gating)(*v5, v6 & 1, v9, v14);
  if ( v15 )
  {
    v16 = (v6 & 1) == 0;
    v17 = v15;
    if ( v16 )
      v18 = "disable";
    else
      v18 = "enable";
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to %s clk gating for clocks %d, rc=%d\n",
      *(_QWORD *)(a1 + 32),
      v18,
      v9,
      v15);
    return v17;
  }
  v19 = *(_DWORD *)(a1 + 160);
  if ( !v19 )
    return 0;
  v20 = a1;
  if ( v3 && *v4 )
  {
    v9 &= ~4u;
    LODWORD(result) = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_config_clk_gating)(*v4, v6 & 1, v9);
    if ( (_DWORD)result )
    {
LABEL_43:
      if ( (v6 & 1) != 0 )
        v22 = "enable";
      else
        v22 = "disable";
      v17 = result;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to %s clk gating for clocks %d, rc=%d\n",
        *(_QWORD *)(a1 + 32),
        v22,
        v9,
        (unsigned int)result);
      return v17;
    }
    v19 = *(_DWORD *)(a1 + 160);
    v20 = a1;
  }
  if ( v19 < 2 )
    return 0;
  result = 0;
  if ( v3 != 1 )
  {
    v21 = *(_QWORD *)(v20 + 216);
    if ( v21 )
    {
      v9 &= ~4u;
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))dsi_ctrl_config_clk_gating)(v21, v6 & 1, v9);
      if ( (_DWORD)result )
        goto LABEL_43;
    }
  }
  return result;
}
