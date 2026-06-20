__int64 __fastcall sme_wifi_start_logger(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  char v4; // w8
  int v5; // w8
  __int64 v6; // x19
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v3 = _qdf_mem_malloc(0x18u, "sme_wifi_start_logger", 10947);
  if ( v3 )
  {
    *(_DWORD *)(v3 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)v3 = *(_DWORD *)a2;
    v4 = *(_BYTE *)(a2 + 12);
    LOWORD(v16) = 4456;
    *(_BYTE *)(v3 + 12) = v4;
    *(_BYTE *)(v3 + 13) = *(_BYTE *)(a2 + 13);
    v5 = *(_DWORD *)(a2 + 16);
    v17 = v3;
    *(_DWORD *)(v3 + 16) = v5;
    LOBYTE(v5) = *(_BYTE *)(a2 + 20);
    v6 = v3;
    *(_BYTE *)(v3 + 20) = v5;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v16,
               0x2AD3u,
               (__int64)"sme_wifi_start_logger");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: scheduler_post_msg failed!(err=%d)",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "sme_wifi_start_logger",
        (unsigned int)result);
      _qdf_mem_free(v6);
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
