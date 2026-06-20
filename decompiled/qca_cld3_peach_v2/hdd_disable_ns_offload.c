__int64 __fastcall hdd_disable_ns_offload(
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
  _QWORD *v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  unsigned int v23; // w1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  _WORD v33[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD **)(a1 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_disable_ns_offload");
  if ( (unsigned int)ucfg_pmo_ns_offload_check(*v13, a3) )
  {
    v22 = "%s: Flushing of NS offload not required";
    v23 = 8;
  }
  else
  {
    if ( (unsigned int)ucfg_pmo_flush_ns_offload_req(a2) )
    {
      v22 = "%s: Failed to flush NS Offload";
    }
    else
    {
      if ( !(unsigned int)ucfg_pmo_disable_ns_offload_in_fwr(a2, a3) )
      {
        v33[0] = 0;
        qdf_mem_set(v33, 2u, 0);
        v33[0] = 2;
        host_diag_event_report_payload(2744, 2, v33);
        goto LABEL_9;
      }
      v22 = "%s: Failed to disable NS Offload";
    }
    v23 = 2;
  }
  qdf_trace_msg(0x33u, v23, v22, v14, v15, v16, v17, v18, v19, v20, v21, "hdd_disable_ns_offload");
LABEL_9:
  result = qdf_trace_msg(0x33u, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "hdd_disable_ns_offload");
  _ReadStatusReg(SP_EL0);
  return result;
}
