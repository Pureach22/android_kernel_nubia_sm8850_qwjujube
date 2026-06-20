__int64 __fastcall tdls_process_set_offchan_mode(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x1
  const char *v30; // x2
  unsigned int v31; // w20
  unsigned int v33; // w0
  void (__fastcall *v34)(_QWORD); // x8
  __int64 v35; // x0

  qdf_trace_msg(
    0,
    8u,
    "%s: TDLS offchan mode to be configured %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "tdls_process_set_offchan_mode",
    *((unsigned __int8 *)a1 + 8));
  if ( !*a1 )
  {
    v30 = "%s: NULL vdev";
    goto LABEL_10;
  }
  v18 = *(_QWORD *)(*a1 + 216LL);
  if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
  {
    v30 = "%s: can't get psoc";
LABEL_10:
    qdf_trace_msg(0, 2u, v30, v10, v11, v12, v13, v14, v15, v16, v17, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v19, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_11:
    v31 = 16;
    goto LABEL_12;
  }
  v29 = *((unsigned __int8 *)a1 + 8);
  if ( *(unsigned __int16 *)(comp_private_obj + 202) >= 2u && (_DWORD)v29 == 1 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: Reject off chan enable, Connected peer count %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "tdls_process_set_offchan_mode");
    goto LABEL_11;
  }
  v33 = tdls_set_tdls_offchannelmode(*a1, v29);
  v34 = (void (__fastcall *)(_QWORD))a1[2];
  v31 = v33;
  if ( v34 )
  {
    v35 = *a1;
    if ( *((_DWORD *)v34 - 1) != 1458356883 )
      __break(0x8228u);
    v34(v35);
  }
LABEL_12:
  _qdf_mem_free((__int64)a1);
  return v31;
}
