__int64 __fastcall hdd_disable_arp_offload(
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
  __int64 result; // x0
  _WORD v25[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD **)(a1 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_disable_arp_offload");
  if ( (unsigned int)ucfg_pmo_check_arp_offload(*v13, a3) )
  {
    v22 = "%s: Flushing of ARP offload not required";
    v23 = 8;
  }
  else if ( (unsigned int)ucfg_pmo_flush_arp_offload_req(a2) )
  {
    v22 = "%s: Failed to flush arp Offload";
    v23 = 2;
  }
  else
  {
    if ( !(unsigned int)ucfg_pmo_disable_arp_offload_in_fwr(a2, a3) )
    {
      v25[0] = 0;
      qdf_mem_set(v25, 2u, 0);
      v25[0] = 0;
      result = host_diag_event_report_payload(2744, 2, v25);
      goto LABEL_8;
    }
    v22 = "%s: fail to disable arp offload";
    v23 = 4;
  }
  result = qdf_trace_msg(0x33u, v23, v22, v14, v15, v16, v17, v18, v19, v20, v21, "hdd_disable_arp_offload");
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
