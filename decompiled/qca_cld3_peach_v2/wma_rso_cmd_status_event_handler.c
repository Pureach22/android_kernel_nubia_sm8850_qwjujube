__int64 __fastcall wma_rso_cmd_status_event_handler(unsigned __int8 a1, int a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  char v13; // w8
  __int64 result; // x0
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
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
  v4 = _qdf_mem_malloc(8u, "wma_rso_cmd_status_event_handler", 3480);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_10;
  }
  *(_DWORD *)v4 = a1;
  if ( a2 == 4 )
  {
    v13 = 1;
  }
  else
  {
    if ( a2 != 5 )
      goto LABEL_8;
    v13 = 0;
  }
  *(_BYTE *)(v4 + 4) = v13;
LABEL_8:
  v15 = v4;
  v25 = v4;
  LOWORD(v24) = 5256;
  HIDWORD(v24) = 0;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Post RSO cmd status to SME",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wma_rso_cmd_status_event_handler");
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)&v24,
             0xDA8u,
             (__int64)"wma_rso_cmd_status_event_handler");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: fail to post RSO cmd status to SME",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wma_rso_cmd_status_event_handler");
    _qdf_mem_free(v15);
    result = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
