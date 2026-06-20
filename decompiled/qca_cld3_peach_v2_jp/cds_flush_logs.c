__int64 __fastcall cds_flush_logs(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x22
  const char *v14; // x2
  __int64 result; // x0
  char v16; // w23
  unsigned int v17; // w21
  unsigned int v18; // w19
  unsigned int v19; // w20
  unsigned int v20; // w20
  unsigned int v21; // w21
  unsigned int v22; // w23
  char v23; // w24
  char v24; // w22
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x3
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  __int64 v46; // x1
  __int64 v47; // x2
  __int64 v48; // x3

  v13 = gp_cds_context;
  if ( !gp_cds_context )
  {
    v20 = a1;
    v21 = a2;
    v22 = a3;
    v23 = a4;
    v24 = a5;
    printk(&unk_94D98D, "cds_get_global_context", a3, a4);
    a5 = v24;
    v13 = gp_cds_context;
    a1 = v20;
    LOBYTE(a4) = v23;
    a3 = v22;
    a2 = v21;
    if ( !gp_cds_context )
    {
      v14 = "%s: cds context is Invalid";
      goto LABEL_6;
    }
  }
  if ( (*(_BYTE *)(v13 + 144) & 1) == 0 )
  {
    v14 = "%s: Fatal event not enabled";
    goto LABEL_6;
  }
  if ( (*(_BYTE *)(v13 + 16) & 0x1E) != 0 )
  {
    v14 = "%s: un/Load/SSR in progress";
LABEL_6:
    qdf_trace_msg(0x38u, 2u, v14, a6, a7, a8, a9, a10, a11, a12, a13, "cds_flush_logs");
    return 16;
  }
  if ( (*(_BYTE *)(v13 + 120) & 1) != 0 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Bug report already in progress - dropping! type:%d, indicator=%d reason_code=%d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "cds_flush_logs",
      a1,
      a2,
      (unsigned int)a3);
    return 16;
  }
  v16 = a4;
  v17 = a1;
  v18 = a2;
  v19 = a3;
  if ( (unsigned int)cds_set_log_completion(a1, a2, a3, a5 & 1) )
  {
    v14 = "%s: Failed to set log trigger params";
    goto LABEL_6;
  }
  v25 = qdf_trace_msg(
          0x38u,
          8u,
          "%s: Triggering bug report: type:%d, indicator=%d reason_code=%d",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "cds_flush_logs",
          v17,
          v18,
          v19);
  if ( (v16 & 1) != 0 )
    v25 = qdf_trace_dump_all(*(_QWORD *)(v13 + 8), 0, v29, v30, v31, v32, v33, v34, v35, v36, 0, 0x64u, 0);
  if ( v18 == 4 )
  {
    cds_wlan_flush_host_logs_for_fatal(v29, v30, v31, v32, v33, v34, v35, v36, v25, v26, v27, v28);
    return 0;
  }
  result = sme_send_flush_logs_cmd_to_fw(v25);
  if ( (_DWORD)result )
  {
    v45 = qdf_trace_msg(
            0x38u,
            2u,
            "%s: Failed to send flush FW log",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "cds_flush_logs");
    cds_init_log_completion(v45, v46, v47, v48);
    return 16;
  }
  return result;
}
