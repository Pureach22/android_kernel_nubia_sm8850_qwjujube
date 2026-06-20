__int64 __fastcall sme_qos_buffer_cmd(
        __int64 *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 *v22; // x1
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x8
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x10
  __int64 v33; // x11
  __int64 v34; // x0

  qdf_trace_msg(0x34u, 8u, "%s: Invoked", a3, a4, a5, a6, a7, a8, a9, a10, "sme_qos_buffer_cmd");
  v12 = (__int64 *)_qdf_mem_malloc(0x90u, "sme_qos_buffer_cmd", 5884);
  if ( !v12 )
    return 2;
  v21 = a1[3];
  v22 = v12;
  v23 = *a1;
  v24 = a1[1];
  v12[4] = a1[2];
  v12[5] = v21;
  v12[2] = v23;
  v12[3] = v24;
  v25 = a1[7];
  v26 = a1[4];
  v27 = a1[5];
  v12[8] = a1[6];
  v12[9] = v25;
  v12[6] = v26;
  v12[7] = v27;
  v28 = a1[11];
  v29 = a1[8];
  v30 = a1[9];
  v12[12] = a1[10];
  v12[13] = v28;
  v12[10] = v29;
  v12[11] = v30;
  v31 = a1[15];
  v32 = a1[12];
  v33 = a1[13];
  v12[16] = a1[14];
  v12[17] = v31;
  v12[14] = v32;
  v12[15] = v33;
  v34 = qword_91F2D8 + 3040LL * *((unsigned __int8 *)a1 + 16) + 2944;
  if ( (a2 & 1) != 0 )
    csr_ll_insert_head(v34, v22, 1, v13, v14, v15, v16, v17, v18, v19, v20);
  else
    csr_ll_insert_tail(v34, v22, 1, v13, v14, v15, v16, v17, v18, v19, v20);
  return 0;
}
