__int64 __fastcall wma_create_peer(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  _QWORD *context; // x0
  _QWORD *v23; // x20
  __int64 result; // x0
  _QWORD *peer_by_mac; // x0
  __int64 v26; // x8
  __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _QWORD v36[3]; // [xsp+8h] [xbp-18h] BYREF

  v36[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_create_peer", a8, a9, a10, a11, a12, a13, a14, a15);
  v36[0] = 0;
  v36[1] = 0;
  if ( !context )
    goto LABEL_5;
  v23 = context;
  result = wma_add_peer(a1, a2, a3, a4, a5, a6, a7 & 1);
  if ( !(_DWORD)result )
  {
    peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), a2, 8u);
    if ( peer_by_mac )
    {
      v26 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned __int8)a5;
      v27 = (__int64)peer_by_mac;
      ++*(_DWORD *)(v26 + 244);
      wma_peer_setup_fill_info(*(_QWORD *)(a1 + 24), peer_by_mac, v36);
      wma_peer_tbl_trans_add_entry(v27, 1, (__int64)v36);
      v28 = wma_cdp_peer_setup(v23, a5, v27, v36);
      wlan_objmgr_peer_release_ref(v27, 8u, v28, v29, v30, v31, v32, v33, v34, v35);
      result = 0;
      goto LABEL_6;
    }
LABEL_5:
    result = 16;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
