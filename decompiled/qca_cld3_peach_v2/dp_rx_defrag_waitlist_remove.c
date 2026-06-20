__int64 __fastcall dp_rx_defrag_waitlist_remove(
        unsigned __int16 *a1,
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
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  _QWORD *v24; // x12
  _QWORD *v25; // x13
  __int64 v26; // x0
  __int64 v27; // x8

  v12 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 8LL);
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Removing TID %u to waitlist for peer %pK peer_id = %d ",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_rx_defrag_waitlist_remove",
    a2,
    a1,
    a1[4]);
  if ( a2 >= 0x11 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: TID out of bounds: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_rx_defrag_waitlist_remove",
      a2);
    v26 = printk(
            &unk_AAA255,
            "0",
            "dp_rx_defrag_waitlist_remove",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_defrag.c");
    dump_stack(v26);
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v12 + 13184);
    v22 = *(_QWORD *)(v12 + 13160);
    if ( !v22 )
      goto LABEL_16;
  }
  else
  {
    raw_spin_lock_bh(v12 + 13184);
    *(_QWORD *)(v12 + 13192) |= 1uLL;
    v22 = *(_QWORD *)(v12 + 13160);
    if ( !v22 )
      goto LABEL_16;
  }
  do
  {
    v23 = *(_QWORD *)(v22 + 8);
    if ( *(unsigned __int16 **)(v22 + 112) == a1 && *(_DWORD *)v22 == a2 )
    {
      v24 = *(_QWORD **)(v22 + 16);
      v25 = (_QWORD *)(v23 + 16);
      if ( !v23 )
        v25 = (_QWORD *)(v12 + 13168);
      *v25 = v24;
      *v24 = *(_QWORD *)(v22 + 8);
      *(_QWORD *)(v22 + 8) = 0;
      *(_QWORD *)(v22 + 16) = 0;
      if ( v12 )
        --*(_DWORD *)(v12 + 13664);
    }
    v22 = v23;
  }
  while ( v23 );
LABEL_16:
  v27 = *(_QWORD *)(v12 + 13192);
  if ( (v27 & 1) == 0 )
    return raw_spin_unlock(v12 + 13184);
  *(_QWORD *)(v12 + 13192) = v27 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v12 + 13184);
}
