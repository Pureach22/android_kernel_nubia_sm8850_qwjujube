__int64 __fastcall wlan_objmgr_pdev_vdev_attach(__int64 a1, _QWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v15; // x8
  unsigned int v22; // w9
  unsigned int v25; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1240);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1240);
    *(_QWORD *)(a1 + 1248) |= 1uLL;
  }
  if ( *(unsigned __int8 *)(a1 + 41) >= (unsigned int)*(unsigned __int8 *)(a1 + 42) )
  {
    v13 = *(_QWORD *)(a1 + 1248);
    if ( (v13 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1248) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1240);
    }
    else
    {
      raw_spin_unlock(a1 + 1240);
    }
    return 16;
  }
  else
  {
    qdf_list_insert_back((_QWORD *)(a1 + 48), a2);
    if ( a1 )
    {
      _X8 = (unsigned int *)(a1 + 88);
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr(_X8);
      while ( __stxr(v22 + 1, _X8) );
      _X8 = (unsigned int *)(a1 + 92);
      __asm { PRFM            #0x11, [X8] }
      do
        v25 = __ldxr(_X8);
      while ( __stxr(v25 + 1, _X8) );
    }
    else
    {
      qdf_trace_msg(0x57u, 2u, "%s: pdev obj is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_objmgr_pdev_get_ref");
    }
    v15 = *(_QWORD *)(a1 + 1248);
    ++*(_BYTE *)(a1 + 41);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1248) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1240);
    }
    else
    {
      raw_spin_unlock(a1 + 1240);
    }
    return 0;
  }
}
