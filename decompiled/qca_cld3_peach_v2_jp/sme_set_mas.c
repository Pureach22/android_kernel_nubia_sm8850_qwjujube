__int64 __fastcall sme_set_mas(int a1)
{
  _DWORD *v2; // x0
  __int64 v3; // x19
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v14; // [xsp+10h] [xbp-30h]
  __int64 v15; // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = nullptr;
  v2 = (_DWORD *)_qdf_mem_malloc(4u, "sme_set_mas", 8944);
  if ( v2 )
  {
    *v2 = a1;
    v3 = (__int64)v2;
    v14 = v2;
    LODWORD(v13) = 4357;
    result = scheduler_post_message_debug(0x34u, 0x36u, 54, (unsigned __int16 *)&v13, 0x22FEu, (__int64)"sme_set_mas");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WDA_SET_MAS_ENABLE_DISABLE to WMA!",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "sme_set_mas");
      _qdf_mem_free(v3);
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
