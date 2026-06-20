__int64 __fastcall wlan_ipa_set_peer_id(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        int *a5,
        unsigned __int8 a6)
{
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w9
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  *(_WORD *)(a2 + 2) = 48;
  v12 = _qdf_mem_malloc(0x30u, "wlan_ipa_set_peer_id", 3773);
  if ( !v12 )
    return 2;
  v13 = v12;
  if ( *(_DWORD *)(a1 + 1096) == 1 && *(_QWORD *)(a1 + 1088) == a3 && *(unsigned __int8 *)(a1 + 1116) == a6 )
  {
    v14 = a1 + 1064;
    v15 = a3;
    if ( a1 == -1064 )
      goto LABEL_17;
    goto LABEL_16;
  }
  if ( *(_DWORD *)(a1 + 1224) != 1 || *(_QWORD *)(a1 + 1216) != a3 || *(unsigned __int8 *)(a1 + 1244) != a6 )
  {
    v15 = a3;
    if ( *(_DWORD *)(a1 + 1352) != 1 )
      goto LABEL_17;
    v15 = a3;
    if ( *(_QWORD *)(a1 + 1344) != a3 )
      goto LABEL_17;
    v15 = a3;
    if ( *(unsigned __int8 *)(a1 + 1372) != a6 )
      goto LABEL_17;
    v14 = a1 + 1320;
    v15 = a3;
    if ( a1 == -1320 )
      goto LABEL_17;
    goto LABEL_16;
  }
  v14 = a1 + 1192;
  v15 = a3;
  if ( a1 != -1192 )
LABEL_16:
    v15 = *(_QWORD *)(v14 + 24);
LABEL_17:
  _wlan_ipa_set_msg_ifname(v15 + 296, a4, v12);
  *(_DWORD *)(v13 + 36) = 0;
  *(_BYTE *)(v13 + 32) = 1;
  *(_BYTE *)(v13 + 40) = 0;
  v16 = *a5;
  *(_WORD *)(v13 + 45) = *((_WORD *)a5 + 2);
  *(_DWORD *)(v13 + 41) = v16;
  result = ipa_send_msg(a2, v13, wlan_ipa_msg_free_fn);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: %s: Evt: %d send ipa msg fail",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_ipa_set_peer_id",
      a3 + 296,
      a4);
    _qdf_mem_free(v13);
    return 16;
  }
  else
  {
    ++*(_QWORD *)(a1 + 3552);
  }
  return result;
}
