__int64 __fastcall lim_process_mlm_assoc_ind(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 session_by_session_id; // x0
  __int64 v13; // x21
  _WORD *v14; // x0
  __int64 v15; // x22
  unsigned __int16 v16; // w1
  __int64 hash_entry; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 (__fastcall *v34)(__int64, __int64 *); // x8
  __int64 result; // x0
  const char *v36; // x2
  __int64 v37; // [xsp+8h] [xbp-38h] BYREF
  __int64 v38; // [xsp+10h] [xbp-30h]
  __int64 v39; // [xsp+18h] [xbp-28h]
  __int64 v40; // [xsp+20h] [xbp-20h]
  __int64 v41; // [xsp+28h] [xbp-18h]
  __int64 v42; // [xsp+30h] [xbp-10h]
  __int64 v43; // [xsp+38h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  if ( !a2 )
  {
    v36 = "%s: Buffer is Pointing to NULL";
LABEL_11:
    result = qdf_trace_msg(0x35u, 2u, v36, a3, a4, a5, a6, a7, a8, a9, a10, "lim_process_mlm_assoc_ind");
    goto LABEL_12;
  }
  session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a2 + 2724));
  if ( !session_by_session_id )
  {
    v36 = "%s: Session Does not exist for given sessionId";
    goto LABEL_11;
  }
  v13 = session_by_session_id;
  v14 = (_WORD *)_qdf_mem_malloc(0xB90u, "lim_process_mlm_assoc_ind", 907);
  if ( !v14 )
  {
    v36 = "%s: call to AllocateMemory failed for eWNI_SME_ASSOC_IND";
    goto LABEL_11;
  }
  v15 = (__int64)v14;
  *v14 = 5141;
  lim_fill_sme_assoc_ind_params();
  v16 = *(_WORD *)(a2 + 6);
  LOWORD(v37) = 5141;
  v38 = v15;
  HIDWORD(v37) = 0;
  hash_entry = dph_get_hash_entry(a1, v16, v13 + 360);
  if ( hash_entry )
  {
    *(_BYTE *)(v15 + 2739) = *(_BYTE *)(hash_entry + 32) & 1;
    *(_BYTE *)(v15 + 2752) = *(_BYTE *)(hash_entry + 656);
    qdf_trace(53, 6u, *(_WORD *)(v13 + 8), 5141);
    lim_diag_event_report(a1, 21, v13, 0);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Create CNF_WAIT_TIMER after received LIM_MLM_ASSOC_IND",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_process_mlm_assoc_ind");
    lim_activate_cnf_timer(a1, *(unsigned __int16 *)(a2 + 6), v13);
    v34 = *(__int64 (__fastcall **)(__int64, __int64 *))(a1 + 12416);
    if ( *((_DWORD *)v34 - 1) != -1829016265 )
      __break(0x8228u);
    result = v34(a1, &v37);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: MLM AssocInd: Station context no longer valid (aid %d)",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "lim_process_mlm_assoc_ind",
      *(unsigned __int16 *)(a2 + 6));
    result = _qdf_mem_free(v15);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
