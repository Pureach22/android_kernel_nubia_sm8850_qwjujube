__int64 __fastcall sme_qos_setup_req(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6,
        unsigned int *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w21
  __int64 v31; // x8
  unsigned int v32; // w26
  int v33; // w8
  const char *v34; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  qdf_trace_msg(
    0x34u,
    8u,
    "%s: QoS Setup requested by client on session %d",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "sme_qos_setup_req",
    a2);
  if ( !(unsigned int)sme_acquire_global_lock(a1 + 12768) )
  {
    if ( a1 && a2 <= 5 && (v31 = *(_QWORD *)(a1 + 17224)) != 0 && (*(_BYTE *)(v31 + 96LL * a2 + 1) & 1) != 0 )
    {
      if ( (*(_BYTE *)(qword_856120 + 3040LL * a2 + 1) & 1) != 0 )
      {
        v32 = dword_856188;
        if ( dword_856188 == -2 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Software Test made the flow counter wrap, QoS may no longer be functional",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "sme_qos_assign_flow_id");
          v33 = 1;
        }
        else
        {
          v33 = dword_856188 + 1;
        }
        dword_856188 = v33;
        *a7 = v32;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: QoS request on session %d assigned Flow ID %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "sme_qos_setup_req",
          a2,
          v32);
        v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _BYTE))sme_qos_internal_setup_req)(
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                *a7,
                0,
                0);
        goto LABEL_12;
      }
      v34 = "%s: Supplied Session ID %d is inactive";
    }
    else
    {
      v34 = "%s: Supplied Session ID %d is invalid";
    }
    v30 = 2;
    qdf_trace_msg(0x34u, 2u, v34, v22, v23, v24, v25, v26, v27, v28, v29, "sme_qos_setup_req", a2);
LABEL_12:
    sme_release_global_lock(a1 + 12768);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: QoS setup return status on session %d is %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "sme_qos_setup_req",
      a2,
      v30);
    return v30;
  }
  return 2;
}
