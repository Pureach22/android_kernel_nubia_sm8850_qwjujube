__int64 __fastcall dp_mon_pdev_detach(
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
  __int64 v10; // x20
  __int64 v11; // x23
  __int64 v12; // x8
  _QWORD *v13; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  void (__fastcall *v30)(_QWORD); // x8
  void (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x23
  void (__fastcall *v35)(_QWORD); // x8
  void (__fastcall *v36)(_QWORD); // x8
  const char *v37; // x2
  double (__fastcall *v39)(_QWORD); // x8

  if ( !a1 )
  {
    v37 = "%s: pdev is NULL";
LABEL_28:
    qdf_trace_msg(0x92u, 2u, v37, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_pdev_detach");
    return 16;
  }
  v10 = *(_QWORD *)(a1 + 96456);
  if ( !v10 )
  {
    v37 = "%s: Monitor pdev is NULL";
    goto LABEL_28;
  }
  v11 = *(_QWORD *)(a1 + 8);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 20112)) == 0 || (v13 = *(_QWORD **)(v12 + 416)) == nullptr )
  {
    v37 = "%s: Monitor ops is NULL";
    goto LABEL_28;
  }
  wlan_minidump_remove(a2, a3, a4, a5, a6, a7, a8, a9, *(_QWORD *)(a1 + 96456), 39328, *(_QWORD *)(v11 + 16));
  wlan_minidump_remove(v14, v15, v16, v17, v18, v19, v20, v21, *(_QWORD *)(v11 + 20112), 456, *(_QWORD *)(v11 + 16));
  v30 = (void (__fastcall *)(_QWORD))v13[127];
  if ( v30 )
  {
    if ( *((_DWORD *)v30 - 1) != -1557217772 )
      __break(0x8228u);
    v30(a1);
  }
  v31 = (void (__fastcall *)(_QWORD))v13[99];
  if ( v31 )
  {
    if ( *((_DWORD *)v31 - 1) != -1557217772 )
      __break(0x8228u);
    v31(a1);
  }
  v32 = *(_QWORD *)(a1 + 8);
  if ( v32 && (v33 = *(_QWORD *)(v32 + 20112)) != 0 && (v34 = *(_QWORD *)(v33 + 416)) != 0 )
  {
    v35 = *(void (__fastcall **)(_QWORD))(v34 + 704);
    if ( v35 )
    {
      if ( *((_DWORD *)v35 - 1) != -1557217772 )
        __break(0x8228u);
      v35(a1);
    }
    v36 = *(void (__fastcall **)(_QWORD))(v34 + 712);
    if ( v36 )
    {
      if ( *((_DWORD *)v36 - 1) != -1557217772 )
        __break(0x8228u);
      v36(a1);
    }
  }
  else
  {
    qdf_trace_msg(0x92u, 2u, "%s: mon_ops is NULL", v22, v23, v24, v25, v26, v27, v28, v29, "dp_mon_rings_free");
  }
  v39 = (double (__fastcall *)(_QWORD))v13[10];
  if ( v39 )
  {
    if ( *((_DWORD *)v39 - 1) != -1557217772 )
      __break(0x8228u);
    v22 = v39(a1);
  }
  dp_context_free_mem(*(_QWORD *)(a1 + 8), 0xAu, v10, v22, v23, v24, v25, v26, v27, v28, v29);
  *(_QWORD *)(a1 + 96456) = 0;
  return 0;
}
