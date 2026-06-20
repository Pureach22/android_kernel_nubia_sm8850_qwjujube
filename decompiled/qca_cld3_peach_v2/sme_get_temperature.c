__int64 __fastcall sme_get_temperature(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  unsigned int v16; // w20
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( a3 )
    {
      *(_QWORD *)(a1 + 13168) = a2;
      *(_QWORD *)(a1 + 13176) = a3;
    }
    else if ( !*(_QWORD *)(a1 + 13176) )
    {
      v15 = "%s: Indication Call back did not registered";
      goto LABEL_9;
    }
    v18 = 0;
    LOWORD(v17) = 4348;
    if ( !(unsigned int)scheduler_post_message_debug(
                          0x34u,
                          0x36u,
                          54,
                          (unsigned __int16 *)&v17,
                          0x2981u,
                          (__int64)"sme_get_temperature") )
    {
      v16 = 0;
LABEL_10:
      qdf_mutex_release(a1 + 12848);
      result = v16;
      goto LABEL_11;
    }
    v15 = "%s: Post Get Temperature msg fail";
LABEL_9:
    qdf_trace_msg(0x34u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "sme_get_temperature");
    v16 = 16;
    goto LABEL_10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
