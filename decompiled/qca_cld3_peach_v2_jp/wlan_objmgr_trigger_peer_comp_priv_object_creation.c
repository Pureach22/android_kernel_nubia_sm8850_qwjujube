__int64 __fastcall wlan_objmgr_trigger_peer_comp_priv_object_creation(__int64 a1, unsigned int a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 v10; // x9
  __int64 (__fastcall *v11)(__int64, __int64); // x8
  __int64 v12; // x1
  __int64 v13; // x20
  unsigned __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  int v24; // w8
  int v25; // w20
  unsigned int v26; // w21
  __int64 v27; // x8
  __int64 v28; // [xsp+8h] [xbp-28h]

  if ( a2 > 0x35 )
    return 38;
  v28 = v3;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 760);
  }
  else
  {
    raw_spin_lock_bh(a1 + 760);
    *(_QWORD *)(a1 + 768) |= 1uLL;
  }
  v8 = *(_QWORD *)(a1 + 768);
  if ( *(_QWORD *)(a1 + 8LL * a2 + 104) )
  {
    if ( (v8 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 768) = v8 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 760);
    }
    else
    {
      raw_spin_unlock(a1 + 760);
    }
    return 16;
  }
  v9 = a2;
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 768) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 760);
  }
  else
  {
    raw_spin_unlock(a1 + 760);
  }
  v10 = g_umac_glb_obj + 8LL * a2;
  v11 = *(__int64 (__fastcall **)(__int64, __int64))(v10 + 8248);
  if ( !v11 )
    return 16;
  v12 = *(_QWORD *)(v10 + 8680);
  if ( *((_DWORD *)v11 - 1) != 154176445 )
    __break(0x8228u);
  v13 = a1 + 536;
  *(_DWORD *)(a1 + 536 + 4 * v9) = v11(a1, v12);
  if ( *(_DWORD *)(a1 + 752) != 1 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v14 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v14 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 760);
  }
  else
  {
    raw_spin_lock_bh(a1 + 760);
    *(_QWORD *)(a1 + 768) |= 1uLL;
  }
  v23 = 0;
  while ( 1 )
  {
    v24 = *(_DWORD *)(v13 + 4 * v23);
    if ( v24 != 40 )
    {
      if ( v24 == 2 || v24 == 16 )
      {
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: Peer comp object(id:%d) alloc fail",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_objmgr_peer_object_status",
          v2,
          v28);
        v25 = 0;
        v26 = 16;
        goto LABEL_32;
      }
      goto LABEL_24;
    }
    if ( !*(_QWORD *)(v13 + 8 * v23 - 432) )
      break;
LABEL_24:
    if ( ++v23 == 54 )
    {
      v25 = 0;
      v26 = 0;
      goto LABEL_32;
    }
  }
  v26 = 40;
  v25 = 1;
LABEL_32:
  v27 = *(_QWORD *)(a1 + 768);
  if ( (v27 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 768) = v27 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 760);
    result = v26;
    if ( v25 )
    {
LABEL_34:
      *(_DWORD *)(a1 + 752) = 3;
      return 40;
    }
  }
  else
  {
    raw_spin_unlock(a1 + 760);
    result = v26;
    if ( v25 )
      goto LABEL_34;
  }
  return result;
}
