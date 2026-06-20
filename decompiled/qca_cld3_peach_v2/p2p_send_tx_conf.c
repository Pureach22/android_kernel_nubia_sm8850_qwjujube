__int64 __fastcall p2p_send_tx_conf(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x20
  __int64 v11; // x19
  __int64 v12; // x6
  const char *v13; // x2
  __int64 result; // x0
  __int64 v15; // x8
  unsigned int v16; // w7
  __int64 v18; // x0
  _DWORD *v19; // x8
  _QWORD v20[4]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD **)(a1 + 16);
  v21 = 0;
  memset(v20, 0, sizeof(v20));
  if ( !v10 || (v11 = v10[11]) == 0 )
  {
    v13 = "%s: Invalid p2p soc object or start parameters";
LABEL_7:
    result = qdf_trace_msg(0x4Eu, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "p2p_send_tx_conf");
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(v11 + 32) )
  {
    v13 = "%s: no tx confirm callback";
    goto LABEL_7;
  }
  if ( (*(_BYTE *)(a1 + 62) & 1) != 0 )
    v12 = 0;
  else
    v12 = *(int *)(a1 + 40);
  v15 = *(_QWORD *)(a1 + 48);
  v16 = *(_DWORD *)(a1 + 56);
  LODWORD(v20[0]) = *(_DWORD *)(a1 + 24);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, vdev_id:%d, action_cookie:%llx, len:%d, status:%d, buf:%pK",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "p2p_send_tx_conf",
    *v10,
    (a2 & 1) == 0,
    v15,
    v20[0],
    v12,
    __PAIR64__((a2 & 1) == 0, v16),
    v15,
    v21,
    v22);
  if ( a1 && *v10 && (*(_BYTE *)(a1 + 63) & 1) != 0 )
    p2p_random_mac_handle_tx_done();
  v19 = *(_DWORD **)(v11 + 32);
  v18 = *(_QWORD *)(v11 + 40);
  if ( *(v19 - 1) != 366326974 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *))v19)(v18, v20);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
