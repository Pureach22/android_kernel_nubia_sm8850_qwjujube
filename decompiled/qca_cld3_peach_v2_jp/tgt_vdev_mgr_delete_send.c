__int64 __fastcall tgt_vdev_mgr_delete_send(
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
  __int64 v10; // x20
  __int64 v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x8
  __int64 v14; // x21
  __int64 **v15; // x0
  __int64 v16; // x8
  void (*v17)(void); // x8
  __int64 v18; // x22
  __int64 result; // x0
  __int64 (__fastcall *v20)(__int64, __int64); // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20

  if ( !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid input", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_delete_send");
    return 4;
  }
  v10 = *(_QWORD *)(a1 + 504);
  v11 = *(_QWORD *)(v10 + 152);
  v12 = *(unsigned __int8 *)(v10 + 104);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 || (v14 = *(_QWORD *)(v13 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_14;
  }
  if ( !*(_QWORD *)(v14 + 1424) )
  {
LABEL_14:
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_%d: No Tx Ops", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_vdev_mgr_delete_send", v12);
    return 4;
  }
  v15 = *(__int64 ***)(v13 + 2808);
  if ( v15 )
  {
    if ( *v15 )
    {
      v16 = **v15;
      if ( !v16 )
        goto LABEL_20;
      v17 = *(void (**)(void))(v16 + 24);
      if ( !v17 )
        goto LABEL_20;
      v18 = a2;
      if ( *((_DWORD *)v17 - 1) != -1818723745 )
        __break(0x8228u);
      v17();
    }
    else
    {
      v18 = a2;
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_vdev_detach");
    }
    a2 = v18;
  }
LABEL_20:
  v20 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 1424);
  if ( *((_DWORD *)v20 - 1) != -1866033454 )
    __break(0x8228u);
  result = v20(v10, a2);
  if ( (_DWORD)result )
  {
    v29 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV_%d: Tx Ops Error : %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "tgt_vdev_mgr_delete_send",
      v12,
      (unsigned int)result);
    return v29;
  }
  return result;
}
