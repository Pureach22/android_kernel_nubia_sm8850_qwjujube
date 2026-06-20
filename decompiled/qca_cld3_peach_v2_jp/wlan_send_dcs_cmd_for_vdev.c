__int64 __fastcall wlan_send_dcs_cmd_for_vdev(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
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
  __int64 v16; // x23
  unsigned int dcs_mode; // w0
  __int64 v19; // x22
  __int64 v20; // x8
  unsigned int v21; // w23
  int v22; // w24
  _DWORD *v23; // x8

  if ( !a1 )
  {
    v15 = "%s: psoc is null";
LABEL_11:
    qdf_trace_msg(0x74u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_send_dcs_cmd_for_vdev");
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
    goto LABEL_10;
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
LABEL_10:
    v15 = "%s: dcs pdev private object is null";
    goto LABEL_11;
  }
  v16 = comp_private_obj + 384LL * a2;
  if ( !v16 )
    goto LABEL_10;
  dcs_mode = wlan_get_dcs_mode(a1, (unsigned __int8)a3);
  if ( dcs_mode >= 4 )
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: Invalid mode %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_send_dcs_cmd_for_vdev",
      dcs_mode);
    return 29;
  }
  v19 = *(_QWORD *)(a1 + 2128);
  if ( !v19 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: tx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "target_if_dcs_get_tx_ops");
    goto LABEL_20;
  }
  if ( !*(_QWORD *)(v19 + 368) )
  {
LABEL_20:
    v15 = "%s: dcs_cmd_send_for_vdev tx_ops is null";
    goto LABEL_11;
  }
  v20 = v16 + dcs_mode;
  v21 = *(unsigned __int8 *)(v16 + 1);
  v22 = *(unsigned __int8 *)(v20 + 49);
  qdf_trace_msg(
    0x74u,
    8u,
    "%s: vdev %d mode %d enable: %u pdev_id %u mode ini %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_send_dcs_cmd_for_vdev",
    (unsigned __int8)a3,
    dcs_mode,
    v22 & v21,
    a2,
    v22);
  v23 = *(_DWORD **)(v19 + 368);
  if ( *(v23 - 1) != -981433165 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v23)(a1, a3, v22 & v21);
}
