__int64 __fastcall target_if_nan_event_dispatcher(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 *v31; // x8

  v10 = **(_QWORD **)(a1 + 8);
  if ( v10 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 0xFu);
    if ( comp_private_obj )
    {
      v12 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 256);
      if ( *((_DWORD *)v12 - 1) != 1685785071 )
        __break(0x8228u);
      v13 = v12(a1);
      if ( !a1 )
        goto LABEL_12;
      goto LABEL_10;
    }
    v22 = "%s: psoc private object is null";
  }
  else
  {
    v22 = "%s: psoc is null";
  }
  qdf_trace_msg(0x53u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "nan_psoc_get_rx_ops");
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: nan_rx_ops is null",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "target_if_nan_event_dispatcher");
  v13 = 29;
  if ( !a1 )
  {
LABEL_12:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Empty message for NAN Discovery event",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_nan_event_flush_cb");
    return v13;
  }
LABEL_10:
  v31 = *(__int64 **)(a1 + 8);
  if ( !v31 )
    goto LABEL_12;
  wlan_objmgr_psoc_release_ref(*v31, 0x14u, v14, v15, v16, v17, v18, v19, v20, v21);
  _qdf_mem_free(*(_QWORD *)(a1 + 8));
  *(_QWORD *)(a1 + 8) = 0;
  return v13;
}
