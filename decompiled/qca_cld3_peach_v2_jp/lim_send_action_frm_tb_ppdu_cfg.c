__int64 __fastcall lim_send_action_frm_tb_ppdu_cfg(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  __int64 v22; // x19
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // [xsp+8h] [xbp-38h] BYREF
  __int64 v33; // [xsp+10h] [xbp-30h]
  __int64 v34; // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v35)(); // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+28h] [xbp-18h]
  __int64 v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = nullptr;
  v32 = 0;
  v33 = 0;
  if ( !pe_find_session_by_vdev_id(a1, a2, a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: pe session does not exist for vdev_id %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_send_action_frm_tb_ppdu_cfg",
      a2);
    goto LABEL_6;
  }
  v21 = _qdf_mem_malloc(0x15u, "lim_send_action_frm_tb_ppdu_cfg", 6671);
  if ( !v21 )
  {
LABEL_6:
    result = 16;
    goto LABEL_7;
  }
  *(_BYTE *)v21 = a2;
  *(_BYTE *)(v21 + 1) = a3;
  v22 = v21;
  *(_DWORD *)(v21 + 16) = -962592641;
  *(_BYTE *)(v21 + 20) = -1;
  *(_BYTE *)(v21 + 2) = 5;
  *(_QWORD *)(v21 + 8) = v21 + 16;
  LODWORD(v32) = 4530;
  v33 = v21;
  v35 = lim_send_action_frm_tb_ppdu_cfg_flush_cb;
  result = scheduler_post_message_debug(
             0x35u,
             0x36u,
             54,
             (unsigned __int16 *)&v32,
             0x1A2Cu,
             (__int64)"lim_send_action_frm_tb_ppdu_cfg");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Not able to post WMA_SET_IE_INFO to WDA",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "lim_send_action_frm_tb_ppdu_cfg");
    _qdf_mem_free(v22);
    goto LABEL_6;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
