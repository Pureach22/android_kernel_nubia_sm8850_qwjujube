__int64 __fastcall wma_antenna_isolation_event_handler(
        __int64 a1,
        __int64 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  __int64 v29; // x8
  __int64 v30; // x19
  unsigned int v31; // w9
  unsigned int v32; // w9
  unsigned int v33; // w9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  __int64 v43; // [xsp+8h] [xbp-38h] BYREF
  __int64 v44; // [xsp+10h] [xbp-30h]
  __int64 v45; // [xsp+18h] [xbp-28h]
  __int64 v46; // [xsp+20h] [xbp-20h]
  __int64 v47; // [xsp+28h] [xbp-18h]
  __int64 v48; // [xsp+30h] [xbp-10h]
  __int64 v49; // [xsp+38h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: handle %pK param %pK len %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_antenna_isolation_event_handler",
    a1,
    a2,
    a3);
  if ( !_cds_get_context(53, (__int64)"wma_antenna_isolation_event_handler", v12, v13, v14, v15, v16, v17, v18, v19) )
  {
    v42 = "%s: Invalid mac context";
LABEL_8:
    qdf_trace_msg(0x36u, 2u, v42, v20, v21, v22, v23, v24, v25, v26, v27, "wma_antenna_isolation_event_handler");
    result = 4294967274LL;
    goto LABEL_9;
  }
  result = _qdf_mem_malloc(4u, "wma_antenna_isolation_event_handler", 2131);
  if ( !result )
    goto LABEL_9;
  if ( !a2 )
  {
    v42 = "%s: Invalid isolation event";
    goto LABEL_8;
  }
  v29 = *a2;
  v30 = result;
  v31 = *(_DWORD *)result & 0xFFFFFF00 | *(unsigned __int8 *)(*a2 + 4);
  *(_DWORD *)result = v31;
  v32 = v31 & 0xFFFF00FF | ((unsigned __int8)BYTE1(*(_DWORD *)(v29 + 4)) << 8);
  *(_DWORD *)result = v32;
  v33 = v32 & 0xFF00FFFF | ((unsigned __int8)BYTE2(*(_DWORD *)(v29 + 4)) << 16);
  *(_DWORD *)result = v33;
  *(_DWORD *)result = *(_DWORD *)(v29 + 4) & 0xFF000000 | v33 & 0xFFFFFF;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: chain1 %d chain2 %d chain3 %d chain4 %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wma_antenna_isolation_event_handler");
  v44 = v30;
  LOWORD(v43) = 5275;
  HIDWORD(v43) = 0;
  result = scheduler_post_message_debug(
             0x36u,
             0x34u,
             52,
             (unsigned __int16 *)&v43,
             0x86Du,
             (__int64)"wma_antenna_isolation_event_handler");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: could not post peer info rsp msg to SME",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wma_antenna_isolation_event_handler");
    _qdf_mem_free(v30);
    result = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
