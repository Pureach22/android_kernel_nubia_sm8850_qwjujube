__int64 __fastcall target_if_ndp_event_dispatcher(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w4
  __int64 v12; // x20
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 (__fastcall *v24)(_QWORD); // x8
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
  const char *v35; // x2

  v9 = *a1;
  if ( v9 > 0x11 || ((1 << v9) & 0x29EA0) == 0 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: invalid msg type %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_ndp_event_dispatcher");
    v26 = 4;
    goto LABEL_17;
  }
  v12 = **((_QWORD **)a1 + 1);
  if ( !v12 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_ndp_event_dispatcher");
    v26 = 29;
    goto LABEL_17;
  }
  v13 = *(_QWORD *)(v12 + 152);
  if ( v13 && (v14 = *(_QWORD *)(v13 + 80)) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v14, 0xFu);
    if ( comp_private_obj )
    {
      v24 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 264);
      if ( *((_DWORD *)v24 - 1) != 1685785071 )
        __break(0x8228u);
      v26 = v24(a1);
      goto LABEL_14;
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc private object is null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "nan_psoc_get_rx_ops");
    v35 = "%s: nan_rx_ops is null";
  }
  else
  {
    v35 = "%s: psoc is null";
  }
  qdf_trace_msg(0x49u, 2u, v35, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_ndp_event_dispatcher");
  v26 = 29;
LABEL_14:
  wlan_objmgr_vdev_release_ref(v12, 0x14u, v25, v27, v28, v29, v30, v31, v32, v33, v34);
LABEL_17:
  _qdf_mem_free(*((_QWORD *)a1 + 1));
  *((_QWORD *)a1 + 1) = 0;
  return v26;
}
