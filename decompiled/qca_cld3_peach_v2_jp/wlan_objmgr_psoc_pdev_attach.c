__int64 __fastcall wlan_objmgr_psoc_pdev_attach(__int64 a1, __int64 a2)
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
  char v13; // w8
  char v14; // w9
  unsigned int v16; // w20
  __int64 v17; // x8
  unsigned int v25; // w9
  unsigned int v27; // w9

  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 2816);
      *(_QWORD *)(a1 + 2824) |= 1uLL;
      v13 = *(_BYTE *)(a1 + 50);
      if ( (v13 & 1) == 0 )
        goto LABEL_5;
LABEL_10:
      v16 = 16;
      goto LABEL_11;
    }
  }
  raw_spin_lock(a1 + 2816);
  v13 = *(_BYTE *)(a1 + 50);
  if ( (v13 & 1) != 0 )
    goto LABEL_10;
LABEL_5:
  v14 = *(_BYTE *)(a1 + 49);
  *(_QWORD *)(a1 + 64) = a2;
  *(_BYTE *)(a1 + 50) = v13 | 1;
  *(_BYTE *)(a1 + 49) = v14 + 1;
  *(_BYTE *)(a2 + 40) = 0;
  if ( a1 )
  {
    _X8 = (unsigned int *)(a1 + 1680);
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 + 1, _X8) );
    _X8 = (unsigned int *)(a1 + 1684);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 + 1, _X8) );
  }
  else
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: psoc obj is NULL for id:%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_objmgr_psoc_get_ref",
      0);
  }
  v16 = 0;
LABEL_11:
  v17 = *(_QWORD *)(a1 + 2824);
  if ( (v17 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v17 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  return v16;
}
