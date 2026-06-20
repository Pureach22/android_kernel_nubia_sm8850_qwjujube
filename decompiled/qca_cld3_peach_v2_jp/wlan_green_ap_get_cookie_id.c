__int64 __fastcall wlan_green_ap_get_cookie_id(__int64 a1, int a2)
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
  unsigned int v14; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v30; // w8
  __int64 v31; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 88);
  }
  else
  {
    raw_spin_lock_bh(a1 + 88);
    *(_QWORD *)(a1 + 96) |= 1uLL;
  }
  v13 = 108;
  if ( !a2 )
    v13 = 112;
  v14 = *(_DWORD *)(a1 + v13);
  if ( a2 )
    _X22 = (unsigned int *)(a1 + 108);
  else
    _X22 = (unsigned int *)(a1 + 112);
  if ( v14 >= 0x80 )
  {
    qdf_trace_msg(
      0x5Du,
      8u,
      "%s: Cookie id Max limit reached",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_green_ap_get_cookie_id");
    if ( a2 )
      *(_DWORD *)(a1 + 108) = 1;
    else
      *(_DWORD *)(a1 + 112) = 0;
    v14 = *_X22;
  }
  __asm { PRFM            #0x11, [X22] }
  do
    v30 = __ldxr(_X22);
  while ( __stxr(v30 + 2, _X22) );
  v31 = *(_QWORD *)(a1 + 96);
  if ( (v31 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 96) = v31 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 88);
  }
  else
  {
    raw_spin_unlock(a1 + 88);
  }
  qdf_trace_msg(
    0x5Du,
    8u,
    "%s: Cookie id : %x",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_green_ap_get_cookie_id",
    v14);
  return v14;
}
