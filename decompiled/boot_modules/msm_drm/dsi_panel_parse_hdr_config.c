__int64 __fastcall dsi_panel_parse_hdr_config(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, const char *); // x8
  __int64 v3; // x0
  char v4; // w0
  __int64 (__fastcall *v5)(__int64, const char *, __int64, __int64); // x8
  __int64 v6; // x0
  unsigned int v7; // w0
  unsigned int v8; // w20
  __int64 (__fastcall *v9)(__int64, const char *, __int64); // x8
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 (__fastcall *v12)(__int64, const char *, __int64); // x8
  __int64 v13; // x0

  v2 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v3 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v2 - 1) != -834495637 )
    __break(0x8228u);
  v4 = v2(v3, "qcom,mdss-dsi-panel-hdr-enabled");
  *(_DWORD *)(a1 + 1672) = v4 & 1;
  if ( (v4 & 1) != 0 )
  {
    v5 = *(__int64 (__fastcall **)(__int64, const char *, __int64, __int64))(a1 + 1872);
    v6 = *(_QWORD *)(a1 + 1816);
    if ( *((_DWORD *)v5 - 1) != 905330014 )
      __break(0x8228u);
    v7 = v5(v6, "qcom,mdss-dsi-panel-hdr-color-primaries", a1 + 1676, 8);
    if ( v7 )
    {
      v8 = v7;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s:%d, Unable to read color primaries,rc:%u\n",
        "dsi_panel_parse_hdr_config",
        3791,
        v7);
LABEL_17:
      *(_DWORD *)(a1 + 1672) = 0;
      return v8;
    }
    v9 = *(__int64 (__fastcall **)(__int64, const char *, __int64))(a1 + 1848);
    v10 = *(_QWORD *)(a1 + 1816);
    if ( *((_DWORD *)v9 - 1) != 309187163 )
      __break(0x8228u);
    v11 = v9(v10, "qcom,mdss-dsi-panel-peak-brightness", a1 + 1708);
    if ( v11 )
    {
      v8 = v11;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s:%d, Unable to read hdr brightness, rc:%u\n",
        "dsi_panel_parse_hdr_config",
        3801,
        v11);
      goto LABEL_17;
    }
    v12 = *(__int64 (__fastcall **)(__int64, const char *, __int64))(a1 + 1848);
    v13 = *(_QWORD *)(a1 + 1816);
    if ( *((_DWORD *)v12 - 1) != 309187163 )
      __break(0x8228u);
    v8 = v12(v13, "qcom,mdss-dsi-panel-blackness-level", a1 + 1712);
    if ( v8 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s:%d, Unable to read hdr brightness, rc:%u\n",
        "dsi_panel_parse_hdr_config",
        3811,
        v8);
      goto LABEL_17;
    }
  }
  else
  {
    return 0;
  }
  return v8;
}
