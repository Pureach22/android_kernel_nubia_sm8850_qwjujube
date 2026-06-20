__int64 __fastcall sme_handle_bcn_recv_start(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x8
  __int64 v14; // x21
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v28; // x2
  unsigned int v29; // w24
  unsigned int v30; // w0
  unsigned int v31; // w19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  if ( a2 > 5 || (v13 = *(_QWORD *)(a1 + 17296), (v14 = v13 + 96LL * a2) == 0) )
  {
    v28 = "%s: vdev_id %d not found";
LABEL_11:
    qdf_trace_msg(0x34u, 2u, v28, a5, a6, a7, a8, a9, a10, a11, a12, "sme_handle_bcn_recv_start", a2);
    return 16;
  }
  if ( !a1 || !v13 || (*(_BYTE *)(v13 + 96LL * a2 + 1) & 1) == 0 )
  {
    v28 = "%s: CSR session not valid: %d";
    goto LABEL_11;
  }
  v18 = qdf_mutex_acquire(a1 + 12848);
  if ( !v18 )
  {
    if ( *(_BYTE *)(v14 + 51) == 1 )
    {
      qdf_mutex_release(a1 + 12848);
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Beacon receive already started",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "sme_handle_bcn_recv_start");
      return 0;
    }
    *(_BYTE *)(v14 + 51) = 1;
    *(_BYTE *)(v14 + 52) = a4 & 1;
    qdf_mutex_release(a1 + 12848);
    v18 = 0;
  }
  v29 = v18;
  v30 = wma_cli_set_command(a2, 146, a3, 1);
  if ( !v30 )
    return v29;
  v31 = v30;
  if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    *(_WORD *)(v14 + 51) = 0;
    qdf_mutex_release(a1 + 12848);
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: wmi_vdev_param_nth_beacon_to_host %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "sme_handle_bcn_recv_start",
    v31);
  return qdf_status_from_os_return(v31);
}
