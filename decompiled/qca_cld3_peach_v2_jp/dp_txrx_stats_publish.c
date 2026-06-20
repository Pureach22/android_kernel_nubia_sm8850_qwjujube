__int64 __fastcall dp_txrx_stats_publish(
        __int64 a1,
        char a2,
        void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v11; // x19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x4
  const char *v23; // x2
  int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // [xsp+0h] [xbp-40h]

  if ( a2 )
    return 0;
  v11 = *(unsigned __int8 **)(a1 + 72);
  if ( !v11 )
    return 0;
  if ( v11[95600] == 1 )
  {
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: pdev%d: prev req pending\n",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_txrx_stats_publish",
      *v11);
    return 0;
  }
  dp_aggregate_pdev_stats(*(_QWORD **)(a1 + 72));
  *((_QWORD *)v11 + 11949) = 0;
  v11[95600] = 1;
  qdf_event_reset((__int64)(v11 + 95288));
  if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int8 *, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, _BYTE))dp_h2t_ext_stats_msg_send)(
                       v11,
                       1,
                       0,
                       0,
                       0,
                       0,
                       0,
                       8,
                       0) )
  {
    v22 = *v11;
    v23 = "%s: pdev%d: tx stats req failed\n";
LABEL_10:
    qdf_trace_msg(0x45u, 3u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "dp_txrx_stats_publish", v22);
    goto LABEL_11;
  }
  LOBYTE(v33) = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int8 *, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, int))dp_h2t_ext_stats_msg_send)(
                       v11,
                       2,
                       0,
                       0,
                       0,
                       0,
                       0,
                       8,
                       v33) )
  {
    v22 = *v11;
    v23 = "%s: pdev%d: rx stats req failed\n";
    goto LABEL_10;
  }
  if ( (v11[95324] & 1) != 0 || (v24 = qdf_wait_single_event((__int64)(v11 + 95288), 0x64u)) == 0 )
  {
    qdf_mem_copy(a3, v11 + 384, 0x16BB8u);
    result = 1;
    goto LABEL_12;
  }
  if ( v24 == 15 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: pdev%d: fw stats timeout. TLVs rcvd 0x%llx\n",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "dp_txrx_stats_publish",
      *v11,
      *((_QWORD *)v11 + 11949));
LABEL_11:
  result = 0;
LABEL_12:
  v11[95600] = 0;
  return result;
}
