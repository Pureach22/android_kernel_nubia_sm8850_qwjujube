__int64 __fastcall pmo_tgt_del_wow_pattern(__int64 a1, unsigned int a2, char a3)
{
  __int64 v6; // x23
  __int64 comp_private_obj; // x19
  _DWORD *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v18; // x21
  int v19; // w9
  char StatusReg; // w8
  unsigned __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x20
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x9
  unsigned __int64 v29; // x8
  __int64 v30; // x8

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v8 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(v6, 4u) + 192);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: del_wow_pattern is null",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "pmo_tgt_del_wow_pattern");
    return 29;
  }
  if ( *(v8 - 1) != -988222069 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD))v8)(a1, a2) )
    return 16;
  v18 = *(_QWORD *)comp_private_obj;
  v19 = *(unsigned __int8 *)(*(_QWORD *)comp_private_obj + 955LL);
  StatusReg = _ReadStatusReg(DAIF);
  if ( (a3 & 1) != 0 )
  {
    if ( v19 )
    {
      if ( StatusReg < 0
        || (v21 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v21 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v21 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1056);
        v22 = *(_QWORD *)(comp_private_obj + 1064);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1056);
        v22 = *(_QWORD *)(comp_private_obj + 1064) | 1LL;
        *(_QWORD *)(comp_private_obj + 1064) = v22;
      }
      --*(_BYTE *)(comp_private_obj + 1031);
      if ( (v22 & 1) != 0 )
      {
        *(_QWORD *)(comp_private_obj + 1064) = v22 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(comp_private_obj + 1056);
        return 0;
      }
      v23 = comp_private_obj + 1056;
    }
    else
    {
      if ( StatusReg < 0
        || (v26 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v26 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v18 + 1040);
      }
      else
      {
        raw_spin_lock_bh(v18 + 1040);
        *(_QWORD *)(v18 + 1048) |= 1uLL;
      }
      --*(_BYTE *)(*(_QWORD *)comp_private_obj + 945LL);
      v27 = *(_QWORD *)comp_private_obj;
      v28 = *(_QWORD *)(*(_QWORD *)comp_private_obj + 1048LL);
      if ( (v28 & 1) != 0 )
      {
        *(_QWORD *)(v27 + 1048) = v28 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 1040);
        return 0;
      }
      v23 = v27 + 1040;
    }
  }
  else
  {
    if ( v19 )
    {
      v24 = comp_private_obj + 1056;
      if ( StatusReg < 0
        || (v25 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v25 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v25 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1056);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1056);
        *(_QWORD *)(comp_private_obj + 1064) |= 1uLL;
      }
      --*(_BYTE *)(comp_private_obj + 1030);
    }
    else
    {
      if ( StatusReg < 0
        || (v29 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v29 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v18 + 1040);
      }
      else
      {
        raw_spin_lock_bh(v18 + 1040);
        *(_QWORD *)(v18 + 1048) |= 1uLL;
      }
      --*(_BYTE *)(*(_QWORD *)comp_private_obj + 944LL);
      v24 = *(_QWORD *)comp_private_obj + 1040LL;
    }
    v30 = *(_QWORD *)(v24 + 8);
    if ( (v30 & 1) != 0 )
    {
      *(_QWORD *)(v24 + 8) = v30 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v24);
      return 0;
    }
    v23 = v24;
  }
  raw_spin_unlock(v23);
  return 0;
}
