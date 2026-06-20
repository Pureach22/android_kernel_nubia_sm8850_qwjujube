__int64 __fastcall lim_send_edca_pifs_param(__int64 a1, const void *a2, char a3)
{
  _BYTE *v6; // x0
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD v26[7]; // [xsp+8h] [xbp-38h] BYREF

  v26[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v26[2], 0, 32);
  v6 = (_BYTE *)_qdf_mem_malloc(6u, "lim_send_edca_pifs_param", 529);
  if ( v6 )
  {
    v7 = (__int64)v6;
    *v6 = a3;
    qdf_mem_copy(v6 + 1, a2, 5u);
    v26[0] = 4552;
    v26[1] = v7;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending WMA_UPDATE_EDCA_PIFS_PARAM_IND",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_send_edca_pifs_param");
    mac_trace_msg_tx(a1, 255, 4552);
    v16 = wma_post_ctrl_msg(a1, v26);
    if ( v16 )
    {
      _qdf_mem_free(v7);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting WMA_UPDATE_EDCA_PIFS_PARAM_IND failed, reason=%X",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_send_edca_pifs_param",
        v16);
    }
  }
  else
  {
    v16 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
