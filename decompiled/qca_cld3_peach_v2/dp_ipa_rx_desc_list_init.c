__int64 __fastcall dp_ipa_rx_desc_list_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 v9; // x20
  __int64 v10; // x19
  int v11; // w8
  unsigned int v12; // w21
  unsigned __int16 free_desc_list; // w20
  unsigned __int64 StatusReg; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 *v23; // x8
  int v24; // w3
  int v25; // w4
  int v26; // w5
  int v27; // w6
  int v28; // w7
  __int64 v29; // x8
  __int64 result; // x0
  char v31; // w10
  __int64 *v32; // x9
  __int64 v33; // x10
  char v34; // [xsp+0h] [xbp-20h]
  __int64 v35; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v36[2]; // [xsp+10h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 1);
  v10 = *(_QWORD *)(a1 + 8);
  v35 = 0;
  v36[0] = 0;
  if ( v9 >= 5 )
    __break(0x5512u);
  v11 = *(unsigned __int16 *)(v10 + 17920);
  v12 = 64 - v11;
  *(_BYTE *)(v10 + 20102) = 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp_ctrl: num of desc required: %u",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_ipa_rx_desc_list_init",
    (unsigned __int16)(64 - v11));
  free_desc_list = dp_rx_get_free_desc_list(
                     v10,
                     (unsigned int)v9,
                     v10 + 120LL * (unsigned int)v9 + 12416,
                     v12,
                     v36,
                     &v35);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v10 + 17904);
    v23 = (__int64 *)v36[0];
    if ( !v36[0] )
      goto LABEL_6;
  }
  else
  {
    raw_spin_lock_bh(v10 + 17904);
    *(_QWORD *)(v10 + 17912) |= 1uLL;
    v23 = (__int64 *)v36[0];
    if ( !v36[0] )
      goto LABEL_6;
  }
  do
  {
    v31 = *((_BYTE *)v23 + 30);
    v32 = (__int64 *)*v23;
    *v23 = 0;
    *((_BYTE *)v23 + 30) = v31 & 0xFE;
    *v23 = *(_QWORD *)(v10 + 17888);
    v33 = *(_QWORD *)(v10 + 17896);
    *(_QWORD *)(v10 + 17888) = v23;
    if ( !v33 || !*v23 )
      *(_QWORD *)(v10 + 17896) = v23;
    ++*(_WORD *)(v10 + 17920);
    v23 = v32;
    v36[0] = v32;
  }
  while ( v32 );
LABEL_6:
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp_ctrl: num of desc allocated: %u",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "dp_ipa_rx_desc_list_init",
    free_desc_list);
  wlan_ipa_log_message(
    (int)"dp_ipa_rx_desc_list_init",
    (int)"opt_dp_ctrl: num of desc allocated: %u",
    free_desc_list,
    v24,
    v25,
    v26,
    v27,
    v28,
    v34);
  v29 = *(_QWORD *)(v10 + 17912);
  if ( (v29 & 1) != 0 )
  {
    *(_QWORD *)(v10 + 17912) = v29 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v10 + 17904);
  }
  else
  {
    result = raw_spin_unlock(v10 + 17904);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
