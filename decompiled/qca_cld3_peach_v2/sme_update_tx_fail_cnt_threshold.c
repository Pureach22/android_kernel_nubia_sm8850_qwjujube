__int64 __fastcall sme_update_tx_fail_cnt_threshold(__int64 a1, unsigned __int8 a2, unsigned int a3)
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
  __int64 v14; // x19
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+10h] [xbp-30h]
  __int64 v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v5 = _qdf_mem_malloc(8u, "sme_update_tx_fail_cnt_threshold", 13800);
  if ( v5 )
  {
    v14 = v5;
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: session_id: %d tx_fail_count: %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "sme_update_tx_fail_cnt_threshold",
      a2,
      a3);
    *(_BYTE *)v14 = a2;
    *(_DWORD *)(v14 + 4) = a3;
    qdf_mem_set(&v25, 0x30u, 0);
    LODWORD(v25) = 4495;
    v26 = v14;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v25,
               0x35F7u,
               (__int64)"sme_update_tx_fail_cnt_threshold");
    if ( (_DWORD)result )
    {
      v24 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post Tx fail count message to WDA",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_update_tx_fail_cnt_threshold");
      _qdf_mem_free(v14);
      result = v24;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
