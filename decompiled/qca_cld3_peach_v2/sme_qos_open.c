__int64 __fastcall sme_qos_open(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  __int64 i; // x22
  __int64 v28; // x20
  __int64 v29; // x24
  int *v30; // x9
  _DWORD *v31; // x8
  int v32; // w10
  int *v33; // x9
  _DWORD *v34; // x8
  int v35; // w10
  int *v36; // x9
  _DWORD *v37; // x8
  int v38; // w10
  int *v39; // x9
  _DWORD *v40; // x8
  int v41; // w10
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  qdf_trace_msg(0x34u, 8u, "%s: Initializing SME-QoS module", a2, a3, a4, a5, a6, a7, a8, a9, "sme_qos_open");
  qdf_mem_set(&sessionInfo, 0x4740u, 0);
  qword_91F2D8 = (__int64)&sessionInfo;
  qdf_mem_set(&def_QoSInfo, 0x130u, 0);
  qword_91F338 = (__int64)&def_QoSInfo;
  sme_qos_cb = a1;
  dword_91F340 = 1;
  byte_91F344 = 1;
  if ( (unsigned int)csr_ll_open((__int64)&unk_91F2E0, v10, v11, v12, v13, v14, v15, v16, v17) )
  {
    qdf_trace_msg(0x34u, 2u, "%s: cannot initialize Flow List", v18, v19, v20, v21, v22, v23, v24, v25, "sme_qos_open");
  }
  else
  {
    v26 = 0;
    for ( i = 2944; ; i += 3040 )
    {
      v28 = qword_91F2D8 + i;
      *(_BYTE *)(qword_91F2D8 + i - 2944) = v26;
      v29 = qword_91F2D8 + i;
      qdf_mem_set((void *)(qword_91F2D8 + i - 2940), 0x2D8u, 0);
      v30 = (int *)(qword_91F2D8 + i - 2936);
      v31 = (_DWORD *)(qword_91F2D8 + i - 2932);
      v32 = *v30;
      *v30 = 1;
      *v31 = v32;
      qdf_mem_set((void *)(v29 - 2212), 0x2D8u, 0);
      v33 = (int *)(qword_91F2D8 + i - 2208);
      v34 = (_DWORD *)(qword_91F2D8 + i - 2204);
      v35 = *v33;
      *v33 = 1;
      *v34 = v35;
      qdf_mem_set((void *)(v29 - 1484), 0x2D8u, 0);
      v36 = (int *)(qword_91F2D8 + i - 1480);
      v37 = (_DWORD *)(qword_91F2D8 + i - 1476);
      v38 = *v36;
      *v36 = 1;
      *v37 = v38;
      qdf_mem_set((void *)(v29 - 756), 0x2D8u, 0);
      v39 = (int *)(qword_91F2D8 + i - 752);
      v40 = (_DWORD *)(qword_91F2D8 + i - 748);
      v41 = *v39;
      *v39 = 1;
      *v40 = v41;
      if ( (unsigned int)csr_ll_open(v28, v42, v43, v44, v45, v46, v47, v48, v49) )
        break;
      if ( ++v26 == 6 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: done initializing SME-QoS module",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "sme_qos_open");
        return 0;
      }
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: cannot initialize cmd list for session %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "sme_qos_open",
      (unsigned int)v26);
  }
  qword_91F2D8 = 0;
  qword_91F338 = 0;
  return 16;
}
