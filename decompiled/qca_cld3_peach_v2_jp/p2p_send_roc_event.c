__int64 __fastcall p2p_send_roc_event(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x5
  int v13; // w6
  int v14; // w10
  int v15; // w8
  int v16; // w9
  __int64 v17; // x0
  _DWORD *v18; // x8
  __int64 result; // x0
  const char *v20; // x2
  _DWORD v21[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v22; // [xsp+10h] [xbp-20h]
  int v23; // [xsp+18h] [xbp-18h]
  int v24; // [xsp+1Ch] [xbp-14h]
  int v25; // [xsp+20h] [xbp-10h]
  int v26; // [xsp+24h] [xbp-Ch]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 16);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 88)) == 0 )
  {
    v20 = "%s: Invalid p2p soc object or start parameters";
LABEL_8:
    result = qdf_trace_msg(0x4Eu, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "p2p_send_roc_event");
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(v11 + 16) )
  {
    v20 = "%s: Invalid p2p event callback to up layer";
    goto LABEL_8;
  }
  v12 = *(int *)(a1 + 228);
  v14 = *(_DWORD *)(a1 + 240);
  v13 = *(_DWORD *)(a1 + 244);
  v21[0] = *(_DWORD *)(a1 + 24);
  v21[1] = a2;
  v15 = *(_DWORD *)(a1 + 40);
  v16 = *(_DWORD *)(a1 + 48);
  v22 = v12;
  v23 = v15;
  v24 = v16;
  v25 = v14;
  v26 = v13;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: roc_event: %d, cookie:%llx flag:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "p2p_send_roc_event",
    a2);
  v18 = *(_DWORD **)(v11 + 16);
  v17 = *(_QWORD *)(v11 + 24);
  if ( *(v18 - 1) != 384351953 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _DWORD *))v18)(v17, v21);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
