__int64 __fastcall target_if_vdev_get_ch_width(
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
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int16 v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int16 v36; // w8
  const char *v37; // x2
  const char *v38; // x2

  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v37 = "%s: psoc is NULL";
LABEL_17:
    qdf_trace_msg(0x56u, 2u, v37, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_get_ch_width");
    return 8;
  }
  v11 = *(_QWORD *)(v10 + 2136);
  if ( !v11 )
  {
    v37 = "%s: rx_ops is null";
    goto LABEL_17;
  }
  v12 = *(__int64 (**)(void))(v11 + 288);
  if ( *((_DWORD *)v12 - 1) != 1246236989 )
    __break(0x8228u);
  result = v12();
  if ( (_DWORD)result == 3 )
  {
    v23 = *(_QWORD *)(a1 + 216);
    if ( v23 && (v24 = *(_QWORD *)(v23 + 80)) != 0 )
    {
      v25 = *(_QWORD *)(v24 + 2136);
      if ( v25 )
      {
        v26 = *(__int64 (__fastcall **)(_QWORD))(v25 + 280);
        if ( *((_DWORD *)v26 - 1) != -810236724 )
          __break(0x8228u);
        v27 = v26(a1);
        v36 = v27;
        if ( (v27 & 0x8000) == 0 )
        {
          if ( v27 )
            return 4;
          else
            return 3;
        }
        goto LABEL_23;
      }
      v38 = "%s: rx_ops is null";
    }
    else
    {
      v38 = "%s: psoc is NULL";
    }
    qdf_trace_msg(0x56u, 2u, v38, v15, v16, v17, v18, v19, v20, v21, v22, "target_if_vdev_get_chan_freq_seg2");
    v36 = -22;
LABEL_23:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid value for cfreq2 %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "target_if_vdev_get_ch_width",
      (unsigned int)v36);
    return 8;
  }
  return result;
}
