__int64 __fastcall csr_roam_process_wm_status_change_command(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x4
  __int64 v13; // x9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  __int64 v23; // [xsp+0h] [xbp-10h] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[6];
  if ( (unsigned int)v12 > 5 )
  {
    WORD2(v23) = 0;
    LODWORD(v23) = 0;
  }
  else
  {
    v13 = *(_QWORD *)(a1 + 17296);
    WORD2(v23) = 0;
    LODWORD(v23) = 0;
    if ( v13 + 96LL * (unsigned int)v12 )
      goto LABEL_6;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: session %d not found",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "csr_roam_process_wm_status_change_command",
    v23,
    v24);
  csr_roam_wm_status_change_complete(a1, a2[6]);
  v12 = a2[6];
LABEL_6:
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: vdev %d type %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "csr_roam_process_wm_status_change_command",
    v12,
    a2[8],
    v23);
  if ( a2[8] > 1 )
  {
    qdf_trace_msg(
      0x34u,
      3u,
      "%s: gets an unknown command %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "csr_roam_process_wm_status_change_command");
    result = csr_roam_wm_status_change_complete(a1, a2[6]);
  }
  else
  {
    qdf_mem_copy(&v23, (char *)a2 + 54, 6u);
    result = csr_get_peer_stats(a1, a2[6], (unsigned int)v23 | ((unsigned __int64)WORD2(v23) << 32));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
