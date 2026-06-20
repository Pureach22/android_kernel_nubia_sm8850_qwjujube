__int64 __fastcall lim_send_hal_msg_del_ts(__int64 a1, unsigned __int8 a2, _BYTE *a3, unsigned int a4, const void *a5)
{
  _WORD *v10; // x0
  _BYTE *v11; // x19
  __int64 session_by_session_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int16 *v21; // x8
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // [xsp+8h] [xbp-38h] BYREF
  _WORD *v32; // [xsp+10h] [xbp-30h]
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = nullptr;
  v10 = (_WORD *)_qdf_mem_malloc(0x4Au, "lim_send_hal_msg_del_ts", 886);
  if ( v10 )
  {
    LOWORD(v31) = 4155;
    v11 = v10;
    v32 = v10;
    HIDWORD(v31) = 0;
    *v10 = a2;
    qdf_mem_copy(v10 + 1, a5, 6u);
    session_by_session_id = pe_find_session_by_session_id(a1, a4);
    if ( !session_by_session_id )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session does Not exist with given sessionId: %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_send_hal_msg_del_ts",
        (unsigned __int8)a4);
      goto LABEL_12;
    }
    v11[8] = *(_BYTE *)(session_by_session_id + 10);
    v21 = (unsigned __int16 *)(a3 + 7);
    if ( (a3[62] & 1) == 0 )
      v21 = (unsigned __int16 *)(a3 + 1);
    v11[9] = (*v21 >> 11) & 7;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1714LL) == 1 && *(_BYTE *)(session_by_session_id + 7041) == 1 )
    {
      qdf_mem_copy(v11 + 10, a3, 0x3Fu);
      v11[73] = 1;
    }
    mac_trace_msg_tx(a1, a4, 4155);
    result = wma_post_ctrl_msg(a1, &v31);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: wma_post_ctrl_msg() failed",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_send_hal_msg_del_ts");
LABEL_12:
      _qdf_mem_free((__int64)v11);
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
