__int64 __fastcall lim_perform_disassoc(
        _DWORD *a1,
        int a2,
        unsigned __int16 a3,
        __int64 a4,
        unsigned __int8 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w9
  __int16 v36; // w8
  char v37; // w10
  __int64 result; // x0
  __int16 v39; // [xsp+4h] [xbp-1Ch] BYREF
  _QWORD v40[3]; // [xsp+8h] [xbp-18h] BYREF

  v40[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v40, 0, 14);
  v39 = 0;
  v17 = dph_lookup_hash_entry(a6, a7, a8, a9, a10, a11, a12, a13, (__int64)a1, a5, &v39, a4 + 360);
  if ( v17 )
  {
    v26 = v17;
    *(_WORD *)(v17 + 34) = 1;
    *(_DWORD *)(v17 + 24) = a3;
    qdf_mem_copy(v40, (const void *)(v17 + 338), 6u);
    v35 = *(_DWORD *)(a4 + 88);
    v36 = *(unsigned __int8 *)(v26 + 24);
    v37 = *(_BYTE *)(a4 + 8);
    LOWORD(v40[1]) = 1;
    HIWORD(v40[0]) = v36;
    BYTE4(v40[1]) = v37;
    if ( v35 == 2 && *(_DWORD *)(a4 + 72) == 10 )
      lim_stop_pmfcomeback_timer(a4);
    lim_update_lost_link_info(a1, a4, a2, v27, v28, v29, v30, v31, v32, v33, v34);
    lim_process_mlm_rsp_messages(a1, 1014, v40);
    result = lim_send_sme_disassoc_ind(a1, v26, a4);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Hash entry not found",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "lim_perform_disassoc");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
