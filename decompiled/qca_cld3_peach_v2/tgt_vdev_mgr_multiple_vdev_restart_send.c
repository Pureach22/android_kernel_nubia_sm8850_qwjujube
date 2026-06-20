_QWORD *__fastcall tgt_vdev_mgr_multiple_vdev_restart_send(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x19
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  unsigned int *v26; // x8
  unsigned int v27; // w20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  if ( !a2 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid input",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_vdev_mgr_multiple_vdev_restart_send");
    return &off_0 + 4;
  }
  result = wlan_objmgr_get_vdev_by_id_from_pdev(a1, **(_DWORD **)(a2 + 56), 0x31u);
  if ( !result )
    return result;
  v21 = result[27];
  v22 = (__int64)result;
  if ( !v21 || (v23 = *(_QWORD *)(v21 + 80)) == 0 || (v24 = *(_QWORD *)(v23 + 2128)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: tx_ops is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_14;
  }
  v25 = *(__int64 (__fastcall **)(__int64, __int64))(v24 + 1512);
  if ( !v25 )
  {
LABEL_14:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: No Tx Ops",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_vdev_mgr_multiple_vdev_restart_send",
      *(unsigned __int8 *)(v22 + 168));
    wlan_objmgr_vdev_release_ref(v22, 0x31u, v36, v37, v38, v39, v40, v41, v42, v43, v44);
    return &off_0 + 4;
  }
  if ( *((_DWORD *)v25 - 1) != 1113181441 )
    __break(0x8228u);
  v27 = v25(a1, a2);
  if ( v27 )
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Tx Ops Error: %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "tgt_vdev_mgr_multiple_vdev_restart_send",
      v27);
  wlan_objmgr_vdev_release_ref(v22, 0x31u, v26, v28, v29, v30, v31, v32, v33, v34, v35);
  return (_QWORD *)v27;
}
