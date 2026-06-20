__int64 __fastcall wlan_cp_stats_twt_get_peer_session_params(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  int v4; // w22
  _BYTE *v5; // x1
  _QWORD *peer_by_mac; // x0
  __int64 v7; // x19
  __int64 comp_private_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  unsigned __int64 StatusReg; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  bool v28; // zf
  unsigned int v29; // w9
  int v30; // w8
  unsigned int v31; // w20
  __int64 v32; // x8

  v2 = 0;
  if ( a1 && a2 )
  {
    v4 = *(_DWORD *)(a2 + 20);
    v5 = (_BYTE *)(a2 + 4);
    if ( *(unsigned __int8 *)(a2 + 4) == 255
      && *(unsigned __int8 *)(a2 + 5) == 255
      && *(unsigned __int8 *)(a2 + 6) == 255
      && *(unsigned __int8 *)(a2 + 7) == 255
      && *(unsigned __int8 *)(a2 + 8) == 255
      && *(unsigned __int8 *)(a2 + 9) == 255 )
    {
      return (unsigned int)wlan_cp_stats_twt_get_all_peer_session_params();
    }
    else
    {
      peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, v5, 0x26u);
      if ( peer_by_mac )
      {
        v7 = (__int64)peer_by_mac;
        comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x1Bu);
        if ( !comp_private_obj )
        {
          v31 = 0;
LABEL_31:
          wlan_objmgr_peer_release_ref(v7, 0x26u, v9, v10, v11, v12, v13, v14, v15, v16);
          return v31;
        }
        v17 = comp_private_obj;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 24);
          v27 = *(_DWORD *)(v17 + 60);
          if ( !v27 )
            goto LABEL_28;
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 24);
          *(_QWORD *)(v17 + 32) |= 1uLL;
          v27 = *(_DWORD *)(v17 + 60);
          if ( !v27 )
            goto LABEL_28;
        }
        v28 = v4 == 255 || *(_DWORD *)(v17 + 68) == v4;
        v29 = v27 & 0xFFFFFFFD;
        v30 = v28;
        if ( v29 == 1 && v30 )
        {
          qdf_mem_copy((void *)a2, (const void *)(v17 + 48), 0x34u);
          v31 = 1;
          goto LABEL_29;
        }
LABEL_28:
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: No TWT session for %02x:%02x:%02x:**:**:%02x dialog_id %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "wlan_cp_stats_twt_get_single_peer_session_params",
          *(unsigned __int8 *)(a2 + 4),
          *(unsigned __int8 *)(a2 + 5),
          *(unsigned __int8 *)(a2 + 6),
          *(unsigned __int8 *)(a2 + 9),
          v4);
        v31 = 0;
LABEL_29:
        v32 = *(_QWORD *)(v17 + 32);
        if ( (v32 & 1) != 0 )
        {
          *(_QWORD *)(v17 + 32) = v32 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v17 + 24);
        }
        else
        {
          raw_spin_unlock(v17 + 24);
        }
        goto LABEL_31;
      }
      return 0;
    }
  }
  return v2;
}
