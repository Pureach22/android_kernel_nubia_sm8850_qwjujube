__int64 __fastcall sme_set_miracast(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v12; // x0
  __int64 v13; // x21
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v24; // [xsp+10h] [xbp-30h]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = nullptr;
  if ( a1 )
  {
    v12 = (_DWORD *)_qdf_mem_malloc(4u, "sme_set_miracast", 8905);
    if ( v12 )
    {
      v13 = (__int64)v12;
      *v12 = a2;
      v24 = v12;
      LODWORD(v23) = 4358;
      result = scheduler_post_message_debug(
                 0x34u,
                 0x36u,
                 54,
                 (unsigned __int16 *)&v23,
                 0x22D7u,
                 (__int64)"sme_set_miracast");
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post WDA_SET_MAS_ENABLE_DISABLE to WMA!",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "sme_set_miracast");
        _qdf_mem_free(v13);
        result = 16;
      }
      else
      {
        *(_BYTE *)(a1 + 13184) = a2;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Invalid pointer", a3, a4, a5, a6, a7, a8, a9, a10, "sme_set_miracast");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
