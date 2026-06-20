__int64 __fastcall sme_gateway_param_update(__int64 a1, __int64 *a2)
{
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x10
  int v9; // w11
  __int64 v10; // x19
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  __int64 v21; // [xsp+10h] [xbp-30h]
  __int64 v22; // [xsp+18h] [xbp-28h]
  __int64 v23; // [xsp+20h] [xbp-20h]
  __int64 v24; // [xsp+28h] [xbp-18h]
  __int64 v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v3 = _qdf_mem_malloc(0x34u, "sme_gateway_param_update", 12613);
  if ( v3 )
  {
    v4 = a2[2];
    v5 = *a2;
    *(_QWORD *)(v3 + 8) = a2[1];
    *(_QWORD *)(v3 + 16) = v4;
    *(_QWORD *)v3 = v5;
    v7 = a2[4];
    v6 = a2[5];
    v8 = a2[3];
    v9 = *((_DWORD *)a2 + 12);
    v10 = v3;
    *(_QWORD *)(v3 + 24) = v8;
    *(_QWORD *)(v3 + 32) = v7;
    *(_QWORD *)(v3 + 40) = v6;
    *(_DWORD *)(v3 + 48) = v9;
    v21 = v3;
    LODWORD(v20) = 4367;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v20,
               0x3150u,
               (__int64)"sme_gateway_param_update");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_GW_PARAM_UPDATE_REQ message to HAL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "sme_gateway_param_update");
      _qdf_mem_free(v10);
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
