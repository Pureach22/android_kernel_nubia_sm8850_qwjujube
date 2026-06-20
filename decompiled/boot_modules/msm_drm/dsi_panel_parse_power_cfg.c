__int64 __fastcall dsi_panel_parse_power_cfg(_QWORD *a1)
{
  __int64 result; // x0
  int v3; // w0
  const char *v4; // x2
  const char *v5; // x20
  unsigned int vreg_data; // w0
  unsigned int v7; // w20

  if ( (*((_BYTE *)a1 + 1274) & 1) != 0 )
    return 0;
  v3 = strcmp((const char *)a1[1], "primary");
  if ( v3 )
    v4 = "qcom,panel-sec-supply-entries";
  else
    v4 = "qcom,panel-supply-entries";
  if ( v3 )
    v5 = "qcom,panel-sec-post-supply-entries";
  else
    v5 = "qcom,panel-post-supply-entries";
  vreg_data = dsi_pwr_of_get_vreg_data(a1 + 227, (__int64)(a1 + 180), v4);
  if ( vreg_data )
  {
    v7 = vreg_data;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to parse vregs\n", *a1);
    return v7;
  }
  if ( *((_BYTE *)a1 + 2232) != 1 )
    return 0;
  result = dsi_pwr_of_get_vreg_data(a1 + 227, (__int64)(a1 + 182), v5);
  if ( (_DWORD)result )
  {
    v7 = result;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to parse post vregs\n", *a1);
    return v7;
  }
  return result;
}
