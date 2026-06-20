__int64 __fastcall pmo_tgt_send_wow_patterns_to_fw(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        unsigned int a7,
        char a8)
{
  __int64 v12; // x28
  __int64 comp_private_obj; // x19
  _DWORD *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w21
  __int64 v37; // x20
  bool v38; // zf
  char v39; // w8
  __int64 v40; // x20
  unsigned __int64 v41; // x8
  __int64 v43; // x20
  char StatusReg; // w8
  unsigned __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x0
  unsigned __int64 v48; // x8
  __int64 v49; // x8
  unsigned __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x9

  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v18 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(v12, 4u) + 184);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_add_wow_pattern is null",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "pmo_tgt_send_wow_patterns_to_fw");
    return 29;
  }
  if ( *(v18 - 1) != 1331945470 )
    __break(0x8228u);
  v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD, __int64, _QWORD, _QWORD))v18)(
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8 & 1);
  if ( !v27 )
  {
    if ( (a8 & 1) != 0 )
    {
      v43 = *(_QWORD *)comp_private_obj;
      v38 = *(_BYTE *)(*(_QWORD *)comp_private_obj + 955LL) == 1;
      StatusReg = _ReadStatusReg(DAIF);
      if ( v38 )
      {
        if ( StatusReg < 0
          || (v45 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v45 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v45 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 1056);
          v46 = *(_QWORD *)(comp_private_obj + 1064);
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 1056);
          v46 = *(_QWORD *)(comp_private_obj + 1064) | 1LL;
          *(_QWORD *)(comp_private_obj + 1064) = v46;
        }
        ++*(_BYTE *)(comp_private_obj + 1031);
        if ( (v46 & 1) != 0 )
        {
          *(_QWORD *)(comp_private_obj + 1064) = v46 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(comp_private_obj + 1056);
          return 0;
        }
        v47 = comp_private_obj + 1056;
      }
      else
      {
        if ( StatusReg < 0
          || (v50 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v50 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v50 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v43 + 1040);
        }
        else
        {
          raw_spin_lock_bh(v43 + 1040);
          *(_QWORD *)(v43 + 1048) |= 1uLL;
        }
        ++*(_BYTE *)(*(_QWORD *)comp_private_obj + 945LL);
        v51 = *(_QWORD *)comp_private_obj;
        v52 = *(_QWORD *)(*(_QWORD *)comp_private_obj + 1048LL);
        if ( (v52 & 1) != 0 )
        {
          *(_QWORD *)(v51 + 1048) = v52 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v51 + 1040);
          return 0;
        }
        v47 = v51 + 1040;
      }
      raw_spin_unlock(v47);
    }
    return 0;
  }
  v36 = v27;
  if ( (a8 & 1) == 0 )
  {
    v37 = *(_QWORD *)comp_private_obj;
    v38 = *(_BYTE *)(*(_QWORD *)comp_private_obj + 955LL) == 1;
    v39 = _ReadStatusReg(DAIF);
    if ( v38 )
    {
      v40 = comp_private_obj + 1056;
      if ( v39 < 0
        || (v41 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v41 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v41 + 16) & 0xFF00) != 0 )
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
      if ( v39 < 0
        || (v48 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v48 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v48 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v37 + 1040);
      }
      else
      {
        raw_spin_lock_bh(v37 + 1040);
        *(_QWORD *)(v37 + 1048) |= 1uLL;
      }
      --*(_BYTE *)(*(_QWORD *)comp_private_obj + 944LL);
      v40 = *(_QWORD *)comp_private_obj + 1040LL;
    }
    v49 = *(_QWORD *)(v40 + 8);
    if ( (v49 & 1) != 0 )
    {
      *(_QWORD *)(v40 + 8) = v49 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v40);
    }
    else
    {
      raw_spin_unlock(v40);
    }
  }
  qdf_trace_msg(
    0x4Du,
    2u,
    "%s: Failed to send wow pattern event",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "pmo_tgt_send_wow_patterns_to_fw");
  return v36;
}
