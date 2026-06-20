__int64 __fastcall drv_cmd_get_opportunistic_rssi_diff(__int64 a1, __int64 *a2, const char *a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x0
  unsigned __int8 v8; // w0
  int v9; // w8
  __int64 v10; // x19
  unsigned __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x9
  __int64 result; // x0
  _BYTE v33[4]; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v34[5]; // [xsp+8h] [xbp-28h] BYREF

  v34[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *a2;
  v33[0] = 0;
  memset(v34, 0, 32);
  ucfg_cm_get_roam_opportunistic_scan_threshold_diff(v7, v33);
  scnprintf(v34, 32, "%s %d", a3, v33[0]);
  v9 = *(_DWORD *)(a5 + 12);
  if ( v9 > v8 )
    LOBYTE(v9) = v8 + 1;
  v10 = (unsigned __int8)v9;
  if ( (unsigned __int8)v9 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v9);
  }
  else
  {
    v11 = *(_QWORD *)a5;
    _check_object_size(v34, (unsigned __int8)v9, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v21 = v11, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v21 = v11 & ((__int64)(v11 << 8) >> 8);
    if ( 0x8000000000LL - v10 >= v21 )
    {
      v22 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v28 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v22);
      v10 = _arch_copy_to_user(v11 & 0xFF7FFFFFFFFFFFFFLL, v34, v10);
      v29 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v31 - 4096);
      _WriteStatusReg(TTBR1_EL1, v31);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v29);
    }
    if ( !v10 )
    {
      result = 0;
      goto LABEL_12;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "drv_cmd_get_opportunistic_rssi_diff");
  result = 4294967282LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
