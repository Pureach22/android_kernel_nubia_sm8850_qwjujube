__int64 __fastcall wlan_objmgr_pdev_try_get_ref(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  unsigned int v31; // w9
  unsigned int v33; // w9
  __int64 v34; // x8

  if ( a1 )
  {
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
    if ( *(_DWORD *)(a1 + 1224) == 1 )
    {
      _X8 = (unsigned int *)(a1 + 88);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 + 1, _X8) );
      if ( a2 < 0x6E )
        _X8 = (unsigned int *)(a1 + 4LL * a2 + 92);
      else
        __break(0x5512u);
      __asm { PRFM            #0x11, [X8] }
      do
        v33 = __ldxr(_X8);
      while ( __stxr(v33 + 1, _X8) );
      v34 = *(_QWORD *)(a1 + 1248);
      if ( (v34 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 1248) = v34 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 1240);
      }
      else
      {
        raw_spin_unlock(a1 + 1240);
      }
      return 0;
    }
    else
    {
      v14 = *(_QWORD *)(a1 + 1248);
      v15 = *(unsigned __int8 *)(a1 + 40);
      if ( (v14 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 1248) = v14 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 1240);
      }
      else
      {
        raw_spin_unlock(a1 + 1240);
      }
      v24 = *(unsigned __int8 *)(a1 + 43);
      *(_BYTE *)(a1 + 43) = v24 + 1;
      if ( !v24 )
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: [Ref id: %d] pdev [%d] is not in Created(st:%d)",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wlan_objmgr_pdev_try_get_ref",
          a2,
          v15,
          *(unsigned int *)(a1 + 1224));
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: pdev obj is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_objmgr_pdev_try_get_ref");
    return 16;
  }
}
