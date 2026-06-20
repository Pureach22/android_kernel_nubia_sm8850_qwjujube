__int64 __fastcall tgt_vdev_mgr_create_send(
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
  __int64 v10; // x19
  __int64 v11; // x8
  unsigned int v12; // w20
  __int64 v13; // x21
  __int64 v14; // x8
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x0
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 **v36; // x0
  __int64 v37; // x8
  __int64 (*v38)(void); // x8

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_create_send");
    goto LABEL_13;
  }
  v10 = *(_QWORD *)(a1 + 520);
  v11 = *(_QWORD *)(v10 + 216);
  v12 = *(unsigned __int8 *)(v10 + 168);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_11;
  }
  v15 = *(__int64 (__fastcall **)(_QWORD))(v14 + 1400);
  if ( !v15 )
  {
LABEL_11:
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_%d No Tx Ops", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_create_send", v12);
LABEL_13:
    result = 4;
    goto LABEL_14;
  }
  v16 = *(_QWORD *)(a1 + 520);
  if ( *((_DWORD *)v15 - 1) != 763817083 )
    __break(0x8228u);
  v17 = v15(v16);
  if ( v17 )
  {
    v26 = v17;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d PSOC_%d Tx Ops Error : %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "tgt_vdev_mgr_create_send",
      v12,
      *(unsigned __int8 *)(v13 + 48),
      v17);
    result = v26;
    goto LABEL_14;
  }
  wlan_util_vdev_get_cdp_txrx_opmode(v10);
  wlan_util_vdev_get_cdp_txrx_subtype(v10);
  v36 = *(__int64 ***)(v13 + 2808);
  if ( !v36 )
  {
LABEL_23:
    result = 16;
    goto LABEL_14;
  }
  if ( !*v36 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v28, v29, v30, v31, v32, v33, v34, v35, "cdp_vdev_attach");
    goto LABEL_23;
  }
  v37 = **v36;
  if ( !v37 )
    goto LABEL_23;
  v38 = *(__int64 (**)(void))(v37 + 16);
  if ( !v38 )
    goto LABEL_23;
  if ( *((_DWORD *)v38 - 1) != -738885604 )
    __break(0x8228u);
  result = v38();
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
