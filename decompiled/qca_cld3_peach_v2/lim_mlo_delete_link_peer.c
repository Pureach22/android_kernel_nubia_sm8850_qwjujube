__int64 __fastcall lim_mlo_delete_link_peer(
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x21
  __int64 result; // x0
  _QWORD *peer_by_mac; // x0
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(53, (__int64)"lim_mlo_delete_link_peer", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v33 = "%s: mac ctx is null";
    goto LABEL_11;
  }
  if ( !a1 )
  {
    v33 = "%s: pe session is null";
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v33 = "%s: sta ds is null";
    goto LABEL_11;
  }
  v21 = context;
  result = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a1 + 16), v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (result & 1) != 0 && *(_DWORD *)(a2 + 1080) | *(unsigned __int16 *)(a2 + 1084) )
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(v21[2703], (_BYTE *)(a2 + 350), 7u);
    if ( peer_by_mac )
    {
      v24 = (__int64)peer_by_mac;
      v25 = wlan_mlo_link_peer_delete(peer_by_mac);
      result = wlan_objmgr_peer_release_ref(v24, 7u, v25, v26, v27, v28, v29, v30, v31, v32);
      goto LABEL_12;
    }
    v33 = "%s: peer is null";
LABEL_11:
    result = qdf_trace_msg(0x35u, 2u, v33, v13, v14, v15, v16, v17, v18, v19, v20, "lim_mlo_delete_link_peer");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
