__int64 __fastcall sme_set_max_tx_power(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  qdf_trace(52, 0x3Eu, 255, 0);
  v7 = _qdf_mem_malloc(0x14u, "sme_set_max_tx_power", 6388);
  if ( v7 )
  {
    *(_DWORD *)v7 = a2;
    *(_DWORD *)(v7 + 6) = a3;
    *(_WORD *)(v7 + 4) = WORD2(a2);
    *(_WORD *)(v7 + 10) = WORD2(a3);
    *(_BYTE *)(v7 + 12) = a4;
    v8 = v7;
    v19 = v7;
    LODWORD(v18) = 4226;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v18,
               0x1903u,
               (__int64)"sme_set_max_tx_power");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_SET_MAX_TX_POWER_REQ message to WMA",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "sme_set_max_tx_power");
      _qdf_mem_free(v8);
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
