__int64 __fastcall wlan_dcs_cmd_send(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  const char *v15; // x2
  unsigned __int8 *v16; // x8
  __int64 v17; // x22
  unsigned int v18; // w23
  int v19; // w24
  _DWORD *v20; // x8

  if ( !a1 )
  {
    v15 = "%s: psoc is null";
LABEL_14:
    qdf_trace_msg(0x74u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_dcs_cmd_send");
    return 29;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: dcs psoc object is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_dcs_get_pdev_private_obj");
    goto LABEL_13;
  }
  if ( a2 >= 3 )
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: invalid pdev_id: %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_dcs_get_pdev_private_obj",
      a2);
LABEL_13:
    v15 = "%s: dcs pdev private object is null";
    goto LABEL_14;
  }
  v16 = (unsigned __int8 *)(comp_private_obj + 384LL * a2);
  if ( !v16 )
    goto LABEL_13;
  v17 = *(_QWORD *)(a1 + 2128);
  if ( !v17 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: tx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_dcs_get_tx_ops");
    return 0;
  }
  if ( !*(_QWORD *)(v17 + 360) )
    return 0;
  v18 = v16[1];
  v19 = *v16;
  qdf_trace_msg(
    0x74u,
    8u,
    "%s: dcs_enable: %u, pdev_id: %u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_dcs_cmd_send",
    v19 & v18,
    a2);
  v20 = *(_DWORD **)(v17 + 360);
  if ( *(v20 - 1) != 1198943331 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v20)(a1, a2, a3 & 1, v19 & v18);
}
