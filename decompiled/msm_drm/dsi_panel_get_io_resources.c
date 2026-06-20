__int64 __fastcall dsi_panel_get_io_resources(__int64 a1, __int64 a2)
{
  _DWORD *v3; // x8
  __int64 v4; // x0
  unsigned int v6; // w0
  __int64 result; // x0
  const char *v8; // x3
  unsigned int v9; // w19

  v3 = *(_DWORD **)(a1 + 1944);
  v4 = *(_QWORD *)(a1 + 1816);
  if ( *(v3 - 1) != -222936480 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64, const char *, _QWORD))v3)(v4, "qcom,platform-reset-gpio", 0);
  if ( (v6 & 0x80000000) != 0 )
    return 0;
  result = msm_dss_get_gpio_io_mem(v6, (_QWORD *)(a2 + 16));
  if ( (_DWORD)result )
  {
    v8 = *(const char **)a1;
    v9 = result;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to retrieve the reset gpio address\n", v8);
    return v9;
  }
  return result;
}
