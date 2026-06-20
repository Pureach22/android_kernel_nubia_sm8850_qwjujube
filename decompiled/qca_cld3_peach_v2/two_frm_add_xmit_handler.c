__int64 __fastcall two_frm_add_xmit_handler(
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
  __int64 v9; // x8
  _QWORD *v10; // x19
  __int64 v12; // x9
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8

  if ( (unsigned int)*(char *)(a1 + 3024) >= 7 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: unexpected curr_state_idx %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_link_recfg_get_curr_tran_req");
  }
  else
  {
    v9 = a1 + 312LL * *(char *)(a1 + 3024);
    v10 = (_QWORD *)(v9 + 840);
    if ( v9 != -840 )
    {
      qdf_mem_set((void *)(a1 + 152), 0x80u, 0);
      v12 = v10[14];
      *(_QWORD *)(a1 + 120) = v10[13];
      *(_QWORD *)(a1 + 128) = v12;
      v14 = v10[16];
      *(_QWORD *)(a1 + 136) = v10[15];
      *(_QWORD *)(a1 + 144) = v14;
      v15 = v10[10];
      *(_QWORD *)(a1 + 88) = v10[9];
      *(_QWORD *)(a1 + 96) = v15;
      v16 = v10[12];
      *(_QWORD *)(a1 + 104) = v10[11];
      *(_QWORD *)(a1 + 112) = v16;
      v17 = v10[6];
      *(_QWORD *)(a1 + 56) = v10[5];
      *(_QWORD *)(a1 + 64) = v17;
      v18 = v10[8];
      *(_QWORD *)(a1 + 72) = v10[7];
      *(_QWORD *)(a1 + 80) = v18;
      v19 = v10[2];
      *(_QWORD *)(a1 + 24) = v10[1];
      *(_QWORD *)(a1 + 32) = v19;
      v20 = v10[4];
      *(_QWORD *)(a1 + 40) = v10[3];
      *(_QWORD *)(a1 + 48) = v20;
      return 0;
    }
  }
  qdf_trace_msg(0x8Fu, 2u, "%s: curr tran ctx null", a2, a3, a4, a5, a6, a7, a8, a9, "two_frm_add_xmit_handler");
  return 4;
}
