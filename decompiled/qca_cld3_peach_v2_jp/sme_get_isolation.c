__int64 __fastcall sme_get_isolation(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  if ( a3 )
  {
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(a1 + 13048) = a3;
      *(_QWORD *)(a1 + 13056) = a2;
      v25 = 0;
      LOWORD(v24) = 4540;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x34u,
                           0x36u,
                           54,
                           (unsigned __int16 *)&v24,
                           0x1E24u,
                           (__int64)"sme_get_isolation") )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: failed to post WMA_GET_ISOLATION",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "sme_get_isolation");
        v23 = 16;
      }
      else
      {
        v23 = 0;
      }
      qdf_mutex_release(a1 + 12776);
      result = v23;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Indication Call back is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "sme_get_isolation");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
