__int64 __fastcall wlan_mlme_get_sta_ch_width(__int64 a1, unsigned int *a2, unsigned int *a3)
{
  __int64 result; // x0
  __int64 v5; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  unsigned int v10; // w21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w22

  result = 4;
  if ( !a2 )
    return result;
  v5 = *(_QWORD *)(a1 + 120);
  if ( !v5 || (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return result;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v5 + 760);
      v9 = *(_QWORD *)(v5 + 768) | 1LL;
      *(_QWORD *)(v5 + 768) = v9;
      v10 = *(_DWORD *)(v5 + 72);
      if ( (v9 & 1) == 0 )
        goto LABEL_8;
LABEL_16:
      *(_QWORD *)(v5 + 768) = v9 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v5 + 760);
      goto LABEL_9;
    }
  }
  raw_spin_lock(v5 + 760);
  v9 = *(_QWORD *)(v5 + 768);
  v10 = *(_DWORD *)(v5 + 72);
  if ( (v9 & 1) != 0 )
    goto LABEL_16;
LABEL_8:
  raw_spin_unlock(v5 + 760);
LABEL_9:
  if ( v10 - 7 > 0x17 )
    v19 = 0;
  else
    v19 = dword_9FDB70[v10 - 7];
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: phymode: %d, ch_width: %d ",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_mlme_get_ch_width_from_phymode",
    v10,
    v19);
  result = 0;
  *a2 = v19;
  if ( a3 )
    *a3 = v10;
  return result;
}
