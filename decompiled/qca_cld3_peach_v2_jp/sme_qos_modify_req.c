__int64 __fastcall sme_qos_modify_req(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  qdf_trace_msg(
    0x34u,
    8u,
    "%s: QoS Modify requested by client for Flow %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_qos_modify_req",
    a3);
  if ( (unsigned int)sme_acquire_global_lock(a1 + 12768) )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Unable to obtain lock", v14, v15, v16, v17, v18, v19, v20, v21, "sme_qos_modify_req");
    return 202;
  }
  else
  {
    v23 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))sme_qos_internal_modify_req)(a1, a2, a3, 0);
    sme_release_global_lock(a1 + 12768);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: QoS Modify return status on Flow %d is %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "sme_qos_modify_req",
      a3,
      v23);
    return v23;
  }
}
