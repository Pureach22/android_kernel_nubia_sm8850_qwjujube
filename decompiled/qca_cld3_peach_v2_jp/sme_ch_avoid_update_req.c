__int64 __fastcall sme_ch_avoid_update_req(__int64 a1)
{
  __int64 result; // x0
  _DWORD *v3; // x0
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = nullptr;
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v3 = (_DWORD *)_qdf_mem_malloc(4u, "sme_ch_avoid_update_req", 8812);
    if ( v3 )
    {
      *v3 = 0;
      v4 = (__int64)v3;
      v15 = v3;
      LOWORD(v14) = 4334;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x34u,
                           0x36u,
                           54,
                           (unsigned __int16 *)&v14,
                           0x227Au,
                           (__int64)"sme_ch_avoid_update_req") )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Post WMA_CH_AVOID_UPDATE_REQ fail",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "sme_ch_avoid_update_req");
        _qdf_mem_free(v4);
        v13 = 16;
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      v13 = 2;
    }
    qdf_mutex_release(a1 + 12776);
    result = v13;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
