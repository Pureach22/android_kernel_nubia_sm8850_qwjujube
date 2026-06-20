__int64 __fastcall dsi_display_phy_sw_reset(__int64 a1)
{
  unsigned int v1; // w20
  __int64 *v2; // x21
  __int64 result; // x0
  const char *v5; // x3
  unsigned int v6; // w19
  unsigned int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x8

  if ( a1 && ((*(_BYTE *)(a1 + 64) & 1) != 0 || (*(_BYTE *)(a1 + 1641) & 1) != 0) )
    goto LABEL_6;
  v1 = *(_DWORD *)(a1 + 840);
  if ( v1 >= 2 )
  {
    __break(0x5512u);
    return dsi_pre_clkoff_cb();
  }
  v2 = (__int64 *)(a1 + 168);
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 168 + 48LL * v1 + 24) + 120LL) == 1 )
  {
LABEL_6:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: cont splash/trusted vm use case, phy sw reset not required\n");
    return 0;
  }
  LODWORD(result) = dsi_ctrl_phy_sw_reset(v2[6 * v1]);
  if ( (_DWORD)result )
    goto LABEL_8;
  v7 = *(_DWORD *)(a1 + 160);
  if ( !v7 )
    return 0;
  v8 = a1;
  if ( v1 && *v2 )
  {
    LODWORD(result) = dsi_ctrl_phy_sw_reset(*v2);
    if ( (_DWORD)result )
    {
LABEL_8:
      v5 = *(const char **)(a1 + 32);
      v6 = result;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to reset phy, rc=%d\n", v5, result);
      return v6;
    }
    v7 = *(_DWORD *)(a1 + 160);
    v8 = a1;
  }
  if ( v7 < 2 )
    return 0;
  result = 0;
  if ( v1 != 1 )
  {
    v9 = *(_QWORD *)(v8 + 216);
    if ( v9 )
    {
      result = dsi_ctrl_phy_sw_reset(v9);
      if ( (_DWORD)result )
        goto LABEL_8;
    }
  }
  return result;
}
