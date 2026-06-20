__int64 __fastcall wlan_objmgr_psoc_peer_detach(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  _WORD *v5; // x21
  char v6; // w22
  unsigned __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v19; // x8
  __int64 v20; // x8
  int v21; // w8
  __int64 v22; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  v5 = (_WORD *)(a1 + 58);
  if ( *(_WORD *)(a1 + 58) )
  {
    v6 = *(_BYTE *)(a2 + 53);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1664);
      if ( !a2 )
        goto LABEL_11;
    }
    else
    {
      raw_spin_lock_bh(a1 + 1664);
      *(_QWORD *)(a1 + 1672) |= 1uLL;
      if ( !a2 )
      {
LABEL_11:
        v8 = *(_QWORD *)(a1 + 1672);
        if ( (v8 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1672) = v8 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1664);
          v9 = *(_QWORD *)(a1 + 2824);
          if ( (v9 & 1) == 0 )
            goto LABEL_13;
        }
        else
        {
          raw_spin_unlock(a1 + 1664);
          v9 = *(_QWORD *)(a1 + 2824);
          if ( (v9 & 1) == 0 )
          {
LABEL_13:
            raw_spin_unlock(a1 + 2816);
LABEL_14:
            qdf_trace_msg(
              0x57u,
              2u,
              "%s: Failed to detach peer",
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              "wlan_objmgr_psoc_peer_detach");
            return 16;
          }
        }
        *(_QWORD *)(a1 + 2824) = v9 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2816);
        goto LABEL_14;
      }
    }
    if ( (unsigned int)qdf_list_remove_node(a1 + 24LL * (v6 & 0x3F) + 128, (_QWORD *)a2) )
      goto LABEL_11;
    v20 = *(_QWORD *)(a1 + 1672);
    if ( (v20 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1672) = v20 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1664);
    }
    else
    {
      raw_spin_unlock(a1 + 1664);
    }
    v21 = *(_DWORD *)(a2 + 68);
    if ( v21 == 11 || v21 == 8 )
      v5 = (_WORD *)(a1 + 62);
    v22 = *(_QWORD *)(a1 + 2824);
    --*v5;
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 0;
  }
  else
  {
    v19 = *(_QWORD *)(a1 + 2824);
    if ( (v19 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return 16;
  }
}
