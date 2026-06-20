__int64 __fastcall csr_roam_process_command(
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
  __int64 v10; // x19
  __int64 v11; // x9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x23
  const char *v25; // x22
  const char *v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w1
  __int64 v36; // x21
  __int64 result; // x0
  __int64 v38; // [xsp+0h] [xbp-10h] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2[6];
  if ( (unsigned int)v10 <= 5
    && (v11 = *(_QWORD *)(a1 + 17224), WORD2(v38) = 0, LODWORD(v38) = 0, v11 + 96LL * (unsigned int)v10) )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Roam Reason: %d sessionId: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "csr_roam_process_command",
      a2[8],
      (unsigned int)v10);
    v22 = a2[8];
    if ( v22 - 1 <= 1 )
    {
      v23 = a1;
      v24 = a1 + 17172;
      if ( *(_DWORD *)(a1 + 17172 + 4 * v10) != 2 )
      {
        v25 = mac_trace_getcsr_roam_state(2u);
        v26 = mac_trace_getcsr_roam_state(*(_DWORD *)(v24 + 4 * v10));
        qdf_trace_msg(
          0x34u,
          8u,
          "CSR RoamState[%d]: [ %s <== %s ]",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          (unsigned int)v10,
          v25,
          v26);
        if ( *(_DWORD *)(v24 + 4 * v10) == 2 )
          csr_roam_substate_change(a1, 0, v10, v14, v15, v16, v17, v18, v19, v20, v21);
        *(_DWORD *)(v24 + 4 * v10) = 2;
        v23 = a1;
        v22 = a2[8];
      }
      if ( v22 == 2 )
        v35 = 4;
      else
        v35 = 2;
      v36 = v23;
      csr_roam_substate_change(v23, v35, v10, v14, v15, v16, v17, v18, v19, v20, v21);
      qdf_mem_copy(&v38, a2 + 9, 6u);
      csr_get_peer_stats(v36, (unsigned int)v10, (unsigned int)v38 | ((unsigned __int64)WORD2(v38) << 32));
    }
    result = 0;
  }
  else
  {
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
      "csr_roam_process_command",
      (unsigned int)v10,
      v38,
      v39);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
