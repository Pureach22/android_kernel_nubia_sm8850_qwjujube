__int64 __fastcall dp_pdev_set_default_reo(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w5
  __int64 v10; // x4
  __int64 result; // x0

  v9 = *a1;
  v10 = *((_QWORD *)a1 + 1);
  if ( v9 == 2 )
  {
    result = wlan_cfg_radio2_default_reo_get(*(_QWORD *)(v10 + 40));
    goto LABEL_7;
  }
  if ( v9 == 1 )
  {
    result = wlan_cfg_radio1_default_reo_get(*(_QWORD *)(v10 + 40));
    goto LABEL_7;
  }
  if ( !*a1 )
  {
    result = wlan_cfg_radio0_default_reo_get(*(_QWORD *)(v10 + 40));
LABEL_7:
    *((_DWORD *)a1 + 23757) = (unsigned __int8)result;
    return result;
  }
  return qdf_trace_msg(
           0x7Cu,
           2u,
           "%s: %pK: Invalid pdev_id %d for reo selection",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "dp_pdev_set_default_reo",
           v10);
}
