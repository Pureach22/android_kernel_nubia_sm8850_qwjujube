__int64 __fastcall wlan_objmgr_psoc_try_get_ref(
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  unsigned int v30; // w9
  unsigned int v32; // w9
  __int64 v33; // x8

  if ( a1 )
  {
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
    if ( *(_DWORD *)(a1 + 2792) == 1 )
    {
      _X8 = (unsigned int *)(a1 + 1680);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 + 1, _X8) );
      if ( a2 < 0x6E )
        _X8 = (unsigned int *)(a1 + 4LL * a2 + 1684);
      else
        __break(0x5512u);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 + 1, _X8) );
      v33 = *(_QWORD *)(a1 + 2824);
      if ( (v33 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 2824) = v33 & 0xFFFFFFFFFFFFFFFELL;
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
      v14 = *(_QWORD *)(a1 + 2824);
      if ( (v14 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 2824) = v14 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2816);
      }
      else
      {
        raw_spin_unlock(a1 + 2816);
      }
      v23 = *(unsigned __int8 *)(a1 + 56);
      *(_BYTE *)(a1 + 56) = v23 + 1;
      if ( !v23 )
        qdf_trace_msg(
          0x57u,
          2u,
          "%s: [Ref id: %d] psoc is not in Created state(%d)",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_objmgr_psoc_try_get_ref",
          a2,
          *(unsigned int *)(a1 + 2792));
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: psoc obj is NULL for id:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_psoc_try_get_ref",
      a2);
    return 16;
  }
}
