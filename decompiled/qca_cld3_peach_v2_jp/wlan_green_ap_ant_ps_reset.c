__int64 *__fastcall wlan_green_ap_ant_ps_reset(
        __int64 *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  const char *v21; // x2
  __int64 (__fastcall *v22)(_QWORD); // x8

  v9 = *result;
  if ( !*result || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v21 = "%s: pdev context obtained is NULL";
LABEL_8:
    qdf_trace_msg(0x5Du, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_green_ap_tx_ops");
    v20 = "%s: green ap tx ops obtained are NULL";
    return (__int64 *)qdf_trace_msg(
                        0x5Du,
                        2u,
                        v20,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        "wlan_green_ap_ant_ps_reset");
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    v21 = "%s: tx_ops is NULL";
    goto LABEL_8;
  }
  if ( !*(_QWORD *)(v11 + 1856) )
    return result;
  if ( (unsigned int)wlan_util_is_vdev_active(*result, 0x27u) )
  {
    v20 = "%s: Green AP tried to enable IRQs when invalid";
    return (__int64 *)qdf_trace_msg(
                        0x5Du,
                        2u,
                        v20,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        "wlan_green_ap_ant_ps_reset");
  }
  v22 = *(__int64 (__fastcall **)(_QWORD))(v11 + 1856);
  if ( *((_DWORD *)v22 - 1) != -2099273483 )
    __break(0x8228u);
  return (__int64 *)v22(v9);
}
