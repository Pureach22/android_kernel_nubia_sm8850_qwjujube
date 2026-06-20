__int64 __fastcall wlan_objmgr_peer_try_get_ref(
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
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  unsigned int v29; // w9
  __int64 v30; // x8

  if ( a1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 768);
    }
    else
    {
      raw_spin_lock_bh(a1 + 768);
      *(_QWORD *)(a1 + 776) |= 1uLL;
    }
    if ( *(_DWORD *)(a1 + 760) == 1 )
    {
      _X8 = (unsigned int *)(a1 + 104);
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 + 1, _X8) );
      v30 = *(_QWORD *)(a1 + 776);
      if ( (v30 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 776) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 768);
      }
      else
      {
        raw_spin_unlock(a1 + 768);
      }
      return 0;
    }
    else
    {
      v13 = *(_QWORD *)(a1 + 776);
      if ( (v13 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 776) = v13 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 768);
      }
      else
      {
        raw_spin_unlock(a1 + 768);
      }
      v22 = *(unsigned __int8 *)(a1 + 108);
      *(_BYTE *)(a1 + 108) = v22 + 1;
      if ( !v22 )
        qdf_trace_msg(
          0x57u,
          8u,
          "%s: peer(%02x:%02x:%02x:**:**:%02x) not in Created st(%d)",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_objmgr_peer_try_get_ref",
          *(unsigned __int8 *)(a1 + 48),
          *(unsigned __int8 *)(a1 + 49),
          *(unsigned __int8 *)(a1 + 50),
          *(unsigned __int8 *)(a1 + 53),
          *(_DWORD *)(a1 + 760));
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: peer obj is NULL for %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_peer_try_get_ref",
      a2);
    return 16;
  }
}
