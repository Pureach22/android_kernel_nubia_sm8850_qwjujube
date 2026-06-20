__int64 __fastcall hif_force_wake_release(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  unsigned int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  unsigned int v31; // w8
  unsigned int v32; // w8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 31264);
  }
  else
  {
    raw_spin_lock_bh(a1 + 31264);
    *(_QWORD *)(a1 + 31272) |= 1uLL;
  }
  _X9 = (unsigned int *)(a1 + 696);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v31 = __ldxr(_X9);
    v32 = v31 - 1;
  }
  while ( __stlxr(v32, _X9) );
  __dmb(0xBu);
  if ( !v32 )
    hif_write32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 12292, 0);
  v3 = *(_QWORD *)(a1 + 31272);
  if ( (v3 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 31272) = v3 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 31264);
  }
  else
  {
    raw_spin_unlock(a1 + 31264);
  }
  v4 = pld_force_wake_release(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
  if ( v4 )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: pld force wake release failure",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hif_force_wake_release");
    v13 = 31232;
  }
  else
  {
    ++*(_DWORD *)(a1 + 31236);
    v13 = 31240;
  }
  ++*(_DWORD *)(a1 + v13);
  v14 = hif_rtpm_put(4, 7u);
  if ( !v14 )
    return v4;
  v23 = v14;
  qdf_trace_msg(
    0x3Du,
    2u,
    "%s: runtime pm put failure: %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hif_force_wake_release",
    v14);
  return v23;
}
