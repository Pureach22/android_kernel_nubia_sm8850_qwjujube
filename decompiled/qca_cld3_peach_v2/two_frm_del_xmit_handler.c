__int64 __fastcall two_frm_del_xmit_handler(
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
      qdf_mem_set((void *)(a1 + 24), 0x80u, 0);
      v12 = v10[30];
      *(_QWORD *)(a1 + 248) = v10[29];
      *(_QWORD *)(a1 + 256) = v12;
      v14 = v10[32];
      *(_QWORD *)(a1 + 264) = v10[31];
      *(_QWORD *)(a1 + 272) = v14;
      v15 = v10[26];
      *(_QWORD *)(a1 + 216) = v10[25];
      *(_QWORD *)(a1 + 224) = v15;
      v16 = v10[28];
      *(_QWORD *)(a1 + 232) = v10[27];
      *(_QWORD *)(a1 + 240) = v16;
      v17 = v10[22];
      *(_QWORD *)(a1 + 184) = v10[21];
      *(_QWORD *)(a1 + 192) = v17;
      v18 = v10[24];
      *(_QWORD *)(a1 + 200) = v10[23];
      *(_QWORD *)(a1 + 208) = v18;
      v19 = v10[18];
      *(_QWORD *)(a1 + 152) = v10[17];
      *(_QWORD *)(a1 + 160) = v19;
      v20 = v10[20];
      *(_QWORD *)(a1 + 168) = v10[19];
      *(_QWORD *)(a1 + 176) = v20;
      return 0;
    }
  }
  qdf_trace_msg(0x8Fu, 2u, "%s: curr tran ctx null", a2, a3, a4, a5, a6, a7, a8, a9, "two_frm_del_xmit_handler");
  return 4;
}
