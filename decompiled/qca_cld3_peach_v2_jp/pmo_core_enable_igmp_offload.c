__int64 __fastcall pmo_core_enable_igmp_offload(__int64 a1, _DWORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 comp_private_obj; // x0
  _QWORD *v14; // x21
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x9
  int v25; // w22
  int v26; // w8
  __int64 v27; // x8

  if ( (unsigned int)wlan_vdev_is_up() )
    return 4;
  if ( *(_DWORD *)(a1 + 16) )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: igmp offload supported in STA mode",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "pmo_core_enable_igmp_offload");
    return 4;
  }
  else
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    v14 = (_QWORD *)comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v14[133] |= 1uLL;
    }
    if ( (*(_BYTE *)(*v14 + 96LL) & 1) != 0 )
    {
      v24 = v14[133];
      v25 = *(_DWORD *)(*v14 + 92LL);
      if ( (v24 & 1) != 0 )
      {
        v14[133] = v24 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v14 + 132);
      }
      else
      {
        raw_spin_unlock(v14 + 132);
      }
      v26 = *(unsigned __int8 *)(a1 + 104);
      a2[2] = v25;
      *a2 = v26;
      return pmo_tgt_send_igmp_offload_req(a1, a2);
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: igmp offload not supported",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "pmo_core_enable_igmp_offload");
      v27 = v14[133];
      if ( (v27 & 1) != 0 )
      {
        v14[133] = v27 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v14 + 132);
      }
      else
      {
        raw_spin_unlock(v14 + 132);
      }
      return 11;
    }
  }
}
