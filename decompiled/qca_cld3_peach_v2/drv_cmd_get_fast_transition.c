__int64 __fastcall drv_cmd_get_fast_transition(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  char is_ft_feature_enabled; // w0
  unsigned __int8 v7; // w0
  int v8; // w8
  __int64 v9; // x19
  unsigned __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x9
  __int64 result; // x0
  _QWORD v32[5]; // [xsp+8h] [xbp-28h] BYREF

  v32[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  is_ft_feature_enabled = ucfg_cm_get_is_ft_feature_enabled(*a2);
  memset(v32, 0, 32);
  scnprintf(v32, 32, "%s %d", "GETFASTTRANSITION", is_ft_feature_enabled & 1);
  v8 = *(_DWORD *)(a5 + 12);
  if ( v8 > v7 )
    LOBYTE(v8) = v7 + 1;
  v9 = (unsigned __int8)v8;
  if ( (unsigned __int8)v8 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v8);
  }
  else
  {
    v10 = *(_QWORD *)a5;
    _check_object_size(v32, (unsigned __int8)v8, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = v10, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v20 = v10 & ((__int64)(v10 << 8) >> 8);
    if ( 0x8000000000LL - v9 >= v20 )
    {
      v21 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v27 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v21);
      v9 = _arch_copy_to_user(v10 & 0xFF7FFFFFFFFFFFFFLL, v32, v9);
      v28 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v30 - 4096);
      _WriteStatusReg(TTBR1_EL1, v30);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v28);
    }
    if ( !v9 )
    {
      result = 0;
      goto LABEL_12;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "drv_cmd_get_fast_transition");
  result = 4294967282LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
