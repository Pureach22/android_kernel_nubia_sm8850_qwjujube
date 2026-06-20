__int64 __fastcall sme_set_max_tx_power_per_band(int a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v4 = _qdf_mem_malloc(8u, "sme_set_max_tx_power_per_band", 6344);
  if ( v4 )
  {
    *(_BYTE *)(v4 + 4) = a2;
    *(_DWORD *)v4 = a1;
    v5 = v4;
    v16 = v4;
    LODWORD(v15) = 4298;
    qdf_trace(52, 0xFBu, 255, 4298);
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v15,
               0x18D7u,
               (__int64)"sme_set_max_tx_power_per_band");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_SET_MAX_TX_POWER_PER_BAND_REQ",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "sme_set_max_tx_power_per_band");
      _qdf_mem_free(v5);
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
