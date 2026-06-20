__int64 __fastcall drv_cmd_p2p_dev_addr(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int v5; // w8
  int v8; // w4
  __int64 v9; // x19
  unsigned __int64 v10; // x21
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

  v5 = *(_DWORD *)(a5 + 12);
  v8 = bswap32(*(_DWORD *)(a2 + 280));
  if ( v5 >= 6 )
    v9 = 6;
  else
    v9 = v5;
  qdf_mtrace(51, 51, 3u, *(_BYTE *)(a1 + 8), v8);
  v10 = *(_QWORD *)a5;
  _check_object_size(a2 + 278, v9, 1);
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
    v9 = _arch_copy_to_user(v10 & 0xFF7FFFFFFFFFFFFFLL, a2 + 278, v9);
    v28 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v30 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v30 - 4096);
    _WriteStatusReg(TTBR1_EL1, v30);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v28);
  }
  if ( !v9 )
    return 0;
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
    "drv_cmd_p2p_dev_addr");
  return 4294967282LL;
}
