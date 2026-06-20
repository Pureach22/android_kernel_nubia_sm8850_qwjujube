__int64 __fastcall target_if_dp_active_traffic_map(
        __int64 a1,
        __int64 a2,
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
  _QWORD *peer_by_mac; // x0
  __int64 v14; // x20
  unsigned int active; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  const char *v25; // x2
  __int64 v26; // [xsp+Ch] [xbp-14h] BYREF
  int v27; // [xsp+14h] [xbp-Ch]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v26 = 0;
  if ( !a1 || !a2 )
  {
    v25 = "%s: Invalid params";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dp_active_traffic_map");
    result = 4294967274LL;
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(a1 + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v25 = "%s: Invalid wmi handle";
    goto LABEL_9;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, (_BYTE *)(a2 + 4), 0x61u);
  if ( !peer_by_mac )
  {
    v25 = "%s: Peer not found in the list";
    goto LABEL_9;
  }
  v14 = (__int64)peer_by_mac;
  qdf_mem_copy(&v26, (const void *)(a2 + 4), 6u);
  v27 = *(_DWORD *)(a2 + 12);
  active = wmi_unified_peer_active_traffic_map_send(v11);
  wlan_objmgr_peer_release_ref(v14, 0x61u, v16, v17, v18, v19, v20, v21, v22, v23);
  result = active;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
