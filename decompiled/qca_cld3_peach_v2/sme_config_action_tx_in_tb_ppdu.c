__int64 __fastcall sme_config_action_tx_in_tb_ppdu(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 21632);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  if ( !cm_is_vdevid_connected(v5, a2) )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: STA is not connected, Session_id: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "sme_config_action_tx_in_tb_ppdu",
      a2);
    result = 4294967274LL;
    goto LABEL_7;
  }
  v14 = _qdf_mem_malloc(4u, "sme_config_action_tx_in_tb_ppdu", 11972);
  if ( !v14 )
    goto LABEL_5;
  *(_BYTE *)(v14 + 2) = a2;
  v15 = v14;
  *(_WORD *)v14 = 5270;
  *(_BYTE *)(v14 + 3) = a3;
  v26 = v14;
  LOWORD(v25) = 5270;
  result = scheduler_post_message_debug(
             0x34u,
             0x35u,
             53,
             (unsigned __int16 *)&v25,
             0x2ECFu,
             (__int64)"sme_config_action_tx_in_tb_ppdu");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to send CFG_ACTION_FRAME_IN_TB_PPDU to PE %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "sme_config_action_tx_in_tb_ppdu",
      (unsigned int)result);
    _qdf_mem_free(v15);
LABEL_5:
    result = 4294967291LL;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
