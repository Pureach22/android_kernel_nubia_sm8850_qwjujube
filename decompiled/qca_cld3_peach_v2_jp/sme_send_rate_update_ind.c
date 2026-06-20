__int64 __fastcall sme_send_rate_update_ind(__int64 a1, _QWORD *a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x8
  unsigned int v11; // w21
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
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
  v4 = (_QWORD *)_qdf_mem_malloc(0x28u, "sme_send_rate_update_ind", 8590);
  if ( !v4 )
  {
    v11 = 16;
    goto LABEL_14;
  }
  v5 = (__int64)v4;
  *v4 = *a2;
  v7 = a2[3];
  v6 = a2[4];
  v8 = a2[1];
  v9 = a2[2];
  v4[3] = v7;
  v4[4] = v6;
  v4[1] = v8;
  v4[2] = v9;
  if ( (_DWORD)v7 == 722 )
  {
    v10 = 28;
  }
  else
  {
    if ( *((_DWORD *)v4 + 4) != 722 )
      goto LABEL_8;
    v10 = 20;
  }
  *(_DWORD *)((char *)v4 + v10) = 10;
LABEL_8:
  v12 = qdf_mutex_acquire(a1 + 12776);
  if ( v12 )
  {
    v11 = v12;
    _qdf_mem_free(v5);
  }
  else
  {
    LOWORD(v22) = 4287;
    v23 = v5;
    qdf_trace(52, 0xFBu, 255, 4287);
    if ( (unsigned int)scheduler_post_message_debug(
                         0x34u,
                         0x36u,
                         54,
                         (unsigned __int16 *)&v22,
                         0x21A9u,
                         (__int64)"sme_send_rate_update_ind") )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_RATE_UPDATE_IND to WMA!",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_send_rate_update_ind");
      _qdf_mem_free(v5);
      v11 = 16;
    }
    else
    {
      v11 = 0;
    }
    qdf_mutex_release(a1 + 12776);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v11;
}
