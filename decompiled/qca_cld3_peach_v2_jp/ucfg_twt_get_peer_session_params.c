__int64 __fastcall ucfg_twt_get_peer_session_params(__int64 a1, __int64 a2)
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
  _DWORD *v27; // x8
  int v28; // w9
  bool v29; // zf
  unsigned int v30; // w10
  _BOOL4 v31; // w9
  unsigned int v32; // w20
  __int64 v33; // x8

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
      return (unsigned int)ucfg_twt_get_all_peer_session_params();
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
          v32 = 0;
LABEL_32:
          wlan_objmgr_peer_release_ref(v7, 0x26u, v9, v10, v11, v12, v13, v14, v15, v16);
          return v32;
        }
        v17 = comp_private_obj;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 24);
          v27 = *(_DWORD **)(v17 + 8);
          if ( !v27 )
            goto LABEL_29;
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 24);
          *(_QWORD *)(v17 + 32) |= 1uLL;
          v27 = *(_DWORD **)(v17 + 8);
          if ( !v27 )
            goto LABEL_29;
        }
        v28 = v27[11];
        if ( v28 )
        {
          v29 = v4 == 255 || v27[13] == v4;
          v30 = v28 & 0xFFFFFFFD;
          v31 = v29;
          if ( v30 == 1 && v31 )
          {
            qdf_mem_copy((void *)a2, v27 + 8, 0x34u);
            v32 = 1;
            goto LABEL_30;
          }
        }
LABEL_29:
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: No TWT session for %02x:%02x:%02x:**:**:%02x dialog_id %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "ucfg_twt_get_single_peer_session_params",
          *(unsigned __int8 *)(a2 + 4),
          *(unsigned __int8 *)(a2 + 5),
          *(unsigned __int8 *)(a2 + 6),
          *(unsigned __int8 *)(a2 + 9),
          v4);
        v32 = 0;
LABEL_30:
        v33 = *(_QWORD *)(v17 + 32);
        if ( (v33 & 1) != 0 )
        {
          *(_QWORD *)(v17 + 32) = v33 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v17 + 24);
        }
        else
        {
          raw_spin_unlock(v17 + 24);
        }
        goto LABEL_32;
      }
      return 0;
    }
  }
  return v2;
}
