__int64 __fastcall tgt_sap_suspend_param_send(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x19
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 (*v24)(void); // x8
  unsigned int *v25; // x8
  unsigned int v26; // w21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  if ( a2 )
  {
    v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 67);
    if ( !v11 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d: vdev not found",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "tgt_sap_suspend_param_send",
        *a2);
      return 16;
    }
    v20 = *(_QWORD *)(v11 + 216);
    v21 = v11;
    if ( v20 && (v22 = *(_QWORD *)(v20 + 80)) != 0 && (v23 = *(_QWORD *)(v22 + 2128)) != 0 )
    {
      if ( *(_QWORD *)(v23 + 1448) )
      {
        v24 = *(__int64 (**)(void))(v23 + 1648);
        if ( *((_DWORD *)v24 - 1) != -1415574805 )
          __break(0x8228u);
        v26 = v24();
        if ( v26 )
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: VDEV_%d: Tx Ops Error : %d",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "tgt_sap_suspend_param_send",
            *a2,
            v26);
        goto LABEL_14;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: tx_ops is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_vdev_mgr_get_tx_ops");
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV: No Tx Ops",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tgt_sap_suspend_param_send");
    v26 = 4;
LABEL_14:
    wlan_objmgr_vdev_release_ref(v21, 0x43u, v25, v27, v28, v29, v30, v31, v32, v33, v34);
    return v26;
  }
  qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_sap_suspend_param_send");
  return 4;
}
