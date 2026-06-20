__int64 __fastcall dsi_panel_parse_dms_info(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, const char *); // x8
  __int64 v3; // x0
  char v4; // w8
  __int64 result; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  const char *v8; // x0
  const char *v9; // x20

  v2 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v3 = *(_QWORD *)(a1 + 1816);
  *(_DWORD *)(a1 + 2184) = 0;
  if ( *((_DWORD *)v2 - 1) != -834495637 )
    __break(0x8228u);
  v4 = v2(v3, "qcom,dynamic-mode-switch-enabled");
  result = 0;
  if ( (v4 & 1) != 0 )
  {
    v6 = *(_DWORD **)(a1 + 1832);
    v7 = *(_QWORD *)(a1 + 1816);
    if ( *(v6 - 1) != -1612502898 )
      __break(0x8228u);
    v8 = (const char *)((__int64 (__fastcall *)(__int64, const char *, _QWORD))v6)(
                         v7,
                         "qcom,dynamic-mode-switch-type",
                         0);
    v9 = v8;
    if ( v8 && (result = strcmp(v8, "dynamic-resolution-switch-immediate"), !(_DWORD)result) )
    {
      *(_DWORD *)(a1 + 2184) = 1;
    }
    else
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] unsupported dynamic switch mode: %s\n",
        *(const char **)a1,
        v9);
      return 4294967274LL;
    }
  }
  return result;
}
