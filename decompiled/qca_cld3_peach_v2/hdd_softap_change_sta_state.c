__int64 __fastcall hdd_softap_change_sta_state(__int64 *a1, _BYTE *a2, unsigned int a3)
{
  __int64 v6; // x22
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 *v16; // x8
  _QWORD *peer_by_mac; // x0
  _QWORD *v18; // x21
  unsigned int v19; // w19
  const char *v20; // x2
  unsigned int v21; // w1

  _ReadStatusReg(SP_EL0);
  v6 = *a1;
  result = ((__int64 (*)(void))hdd_softap_change_per_sta_state)();
  if ( (_DWORD)result )
    goto LABEL_11;
  v16 = *(__int64 **)(v6 + 24);
  if ( !v16 )
  {
    v20 = "%s: hdd ctx is null";
    v21 = 2;
LABEL_8:
    qdf_trace_msg(0x33u, v21, v20, v8, v9, v10, v11, v12, v13, v14, v15, "hdd_softap_change_sta_state");
    result = 0;
    goto LABEL_11;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*v16, a2, 7u);
  if ( !peer_by_mac )
  {
    v20 = "%s: peer is null";
    v21 = 8;
    goto LABEL_8;
  }
  if ( *((_DWORD *)peer_by_mac + 198) | *((unsigned __int16 *)peer_by_mac + 398) )
  {
    v18 = peer_by_mac;
    v19 = hdd_softap_change_per_sta_state(a1, peer_by_mac + 99, a3);
    peer_by_mac = v18;
  }
  else
  {
    v19 = 0;
  }
  wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, v8, v9, v10, v11, v12, v13, v14, v15);
  result = v19;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
