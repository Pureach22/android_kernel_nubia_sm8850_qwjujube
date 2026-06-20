__int64 __fastcall wma_get_arp_stats_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _DWORD *v20; // x9
  __int64 v21; // x8
  int v22; // w12
  int v23; // w11
  int v24; // w13
  int v25; // w10
  int v26; // w11
  int v27; // w10
  _QWORD *v28; // x19
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 result; // x0
  const char *v32; // x2
  _DWORD v33[9]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v34; // [xsp+2Ch] [xbp-14h]
  int v35; // [xsp+34h] [xbp-Ch]
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v34 = 0;
  context = _cds_get_context(53, (__int64)"wma_get_arp_stats_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    goto LABEL_14;
  v20 = (_DWORD *)context[1796];
  if ( !v20 )
  {
    v32 = "%s: Callback not registered";
LABEL_13:
    qdf_trace_msg(0x36u, 2u, v32, v12, v13, v14, v15, v16, v17, v18, v19, "wma_get_arp_stats_handler");
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( !a10 )
  {
    v32 = "%s: invalid pointer";
    goto LABEL_13;
  }
  v21 = *a10;
  if ( !*a10 )
  {
    v32 = "%s: Invalid get arp stats data event";
    goto LABEL_13;
  }
  v22 = *(_DWORD *)(v21 + 12);
  v23 = *(_DWORD *)(v21 + 16);
  v24 = *(_DWORD *)(v21 + 20);
  v33[1] = *(_DWORD *)(v21 + 8);
  v25 = *(_DWORD *)(v21 + 4);
  v33[3] = v23;
  v33[4] = v24;
  v33[2] = v22;
  v33[0] = v25;
  v26 = *(_DWORD *)(v21 + 28);
  v33[5] = *(_DWORD *)(v21 + 24);
  v33[6] = v26;
  v27 = *(_DWORD *)(v21 + 36);
  v33[7] = *(_DWORD *)(v21 + 32);
  v33[8] = v27;
  if ( *(_WORD *)(v21 + 46) == 715 )
  {
    LOBYTE(v34) = 1;
    v28 = context;
    HIDWORD(v34) = *(_DWORD *)(v21 + 48);
    v35 = *(_DWORD *)(v21 + 52);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: tcp_ack_recvd %d icmpv4_rsp_recvd %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_get_arp_stats_handler");
    v20 = (_DWORD *)v28[1796];
    context = v28;
  }
  v29 = context[1795];
  v30 = context[1595];
  if ( *(v20 - 1) != 1616261756 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _DWORD *, __int64))v20)(v30, v33, v29);
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
