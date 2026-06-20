__int64 __fastcall htc_process_credit_rpt(__int64 a1, int *a2, int a3)
{
  int v3; // w20
  unsigned __int64 StatusReg; // x8
  int v7; // w22
  unsigned __int64 v8; // x27
  int v9; // w8
  __int64 v10; // x23
  int v11; // w28
  int v12; // w8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 result; // x0

  v3 = a3;
  if ( (dword_B804 & 0x100) != 0 )
    qdf_trace_msg(56, 2, "%s: +htc_process_credit_rpt, Credit Report Entries:%d\n", "htc_process_credit_rpt", a3);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2992);
    if ( v3 >= 1 )
      goto LABEL_7;
LABEL_24:
    v7 = 0;
    goto LABEL_25;
  }
  raw_spin_lock_bh(a1 + 2992);
  *(_QWORD *)(a1 + 3000) |= 1uLL;
  if ( v3 < 1 )
    goto LABEL_24;
LABEL_7:
  v7 = 0;
  v8 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v9 = *a2;
    if ( (unsigned __int8)*a2 >= 9u )
      break;
    v10 = a1 + 8 + 328LL * (unsigned __int8)*a2;
    v11 = BYTE1(v9);
    if ( *(_WORD *)(v10 + 4) == 256 )
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))htc_credit_record)(
        1,
        *(_DWORD *)(v10 + 288) + (unsigned int)BYTE1(v9),
        *(unsigned int *)(v10 + 120));
    v12 = *(_DWORD *)(v10 + 288) + v11;
    *(_DWORD *)(v10 + 288) = v12;
    if ( v12 && *(_DWORD *)(v10 + 120) )
    {
      v13 = *(_QWORD *)(a1 + 3000);
      if ( (v13 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 3000) = v13 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2992);
      }
      else
      {
        raw_spin_unlock(a1 + 2992);
      }
      htc_try_send(a1, (_DWORD *)v10, 0);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v8 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v8 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 2992);
      }
      else
      {
        raw_spin_lock_bh(a1 + 2992);
        *(_QWORD *)(a1 + 3000) |= 1uLL;
      }
    }
    --v3;
    v7 += v11;
    ++a2;
    if ( !v3 )
      goto LABEL_25;
  }
  printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 2952, "false");
LABEL_25:
  if ( (dword_B804 & 0x100) != 0 )
    qdf_trace_msg(56, 2, "%s:   Report indicated %d credits to distribute\n", "htc_process_credit_rpt", v7);
  v14 = *(_QWORD *)(a1 + 3000);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3000) = v14 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 2992);
    if ( (dword_B804 & 0x100) == 0 )
      return result;
  }
  else
  {
    result = raw_spin_unlock(a1 + 2992);
    if ( (dword_B804 & 0x100) == 0 )
      return result;
  }
  return qdf_trace_msg(56, 2, "%s: -htc_process_credit_rpt\n", "htc_process_credit_rpt");
}
