__int64 __fastcall sme_send_limit_off_channel_params(__int64 a1, char a2, char a3, int a4, int a5, char a6)
{
  __int64 v11; // x0
  __int64 v12; // x19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v11 = _qdf_mem_malloc(0x10u, "sme_send_limit_off_channel_params", 14953);
  if ( v11 )
  {
    *(_BYTE *)v11 = a2;
    *(_BYTE *)(v11 + 1) = a3 & 1;
    *(_DWORD *)(v11 + 4) = a4;
    *(_DWORD *)(v11 + 8) = a5;
    v12 = v11;
    *(_BYTE *)(v11 + 12) = a6 & 1;
    v23 = v11;
    LODWORD(v22) = 4518;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v22,
               0x3A7Au,
               (__int64)"sme_send_limit_off_channel_params");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_SET_LIMIT_OFF_CHAN to WMA",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_send_limit_off_channel_params");
      _qdf_mem_free(v12);
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
