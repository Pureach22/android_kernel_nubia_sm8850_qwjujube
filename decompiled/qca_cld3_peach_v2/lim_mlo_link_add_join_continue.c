__int64 __fastcall lim_mlo_link_add_join_continue(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        unsigned int a11)
{
  _QWORD *context; // x0
  __int64 v14; // x19
  __int64 session_by_vdev_id; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  __int64 v44; // x0
  char v45; // w8
  __int64 v46; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v47[2]; // [xsp+10h] [xbp-10h] BYREF

  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0x1000001F4LL;
  v47[0] = 0;
  context = _cds_get_context(53, (__int64)"lim_mlo_link_add_join_continue", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    goto LABEL_13;
  v14 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id(context, a10);
  if ( !session_by_vdev_id )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: no find session by vdev %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_mlo_link_add_join_continue",
      (unsigned __int8)a10);
LABEL_13:
    result = 4;
    goto LABEL_14;
  }
  v24 = session_by_vdev_id;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev %d limMlmState %d recfg_rsp_status %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "lim_mlo_link_add_join_continue",
    (unsigned __int8)a10,
    *(unsigned int *)(session_by_vdev_id + 72),
    a11);
  v33 = *(unsigned int *)(v24 + 72);
  if ( (_DWORD)v33 != 10 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: unexpected limMlmState %d vdev %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_mlo_link_add_join_continue",
      v33,
      (unsigned __int8)a10);
    goto LABEL_13;
  }
  if ( a11 || (result = lim_mlo_link_recfg_add_process_assoc_rsp(v14, v24), (_DWORD)result) )
  {
    BYTE6(v46) = *(_BYTE *)(v24 + 8);
    qdf_trace(53, 0xAu, 0, 1010);
    lim_process_mlm_assoc_cnf(v14, (unsigned int *)&v46, v35, v36, v37, v38, v39, v40, v41, v42);
    v43 = *(_QWORD *)(v24 + 128);
    if ( v43 )
    {
      _qdf_mem_free(v43);
      *(_QWORD *)(v24 + 128) = 0;
    }
    v44 = *(_QWORD *)(v24 + 112);
    if ( v44 )
    {
      _qdf_mem_free(v44);
      *(_QWORD *)(v24 + 112) = 0;
    }
    v45 = *(_BYTE *)(v24 + 8);
    LODWORD(v47[0]) = 502;
    BYTE6(v47[0]) = v45;
    WORD2(v47[0]) = 1;
    qdf_trace(53, 0xAu, 0, 1005);
    lim_process_mlm_join_cnf(v14, (__int64)v47);
    result = 16;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
