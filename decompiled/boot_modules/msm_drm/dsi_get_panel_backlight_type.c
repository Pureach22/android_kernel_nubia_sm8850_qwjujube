const char *__fastcall dsi_get_panel_backlight_type(__int64 a1, char *s1)
{
  bool v3; // zf
  _DWORD *v4; // x9
  __int64 v5; // x0
  const char *v6; // x1
  const char *result; // x0
  const char *v8; // x19

  v3 = strcmp(s1, "primary") == 0;
  v4 = *(_DWORD **)(a1 + 1832);
  v5 = *(_QWORD *)(a1 + 1816);
  if ( v3 )
    v6 = "qcom,mdss-dsi-bl-pmic-control-type";
  else
    v6 = "qcom,mdss-dsi-sec-bl-pmic-control-type";
  if ( *(v4 - 1) != -1612502898 )
    __break(0x8229u);
  result = (const char *)((__int64 (__fastcall *)(__int64, const char *, _QWORD))v4)(v5, v6, 0);
  if ( result )
  {
    v8 = result;
    if ( !strcmp(result, "bl_ctrl_pwm") )
    {
      return (_BYTE *)(&_ksymtab___SCK__tp_func_tracing_mark_write + 1);
    }
    else if ( !strcmp(v8, "bl_ctrl_wled") )
    {
      return (_BYTE *)(&_ksymtab___SCK__tp_func_tracing_mark_write + 2);
    }
    else if ( !strcmp(v8, "bl_ctrl_dcs") )
    {
      return (_BYTE *)(&_ksymtab___SCK__tp_func_tracing_mark_write + 3);
    }
    else
    {
      return (const char *)(4 * (unsigned int)(strcmp(v8, "bl_ctrl_external") == 0));
    }
  }
  return result;
}
