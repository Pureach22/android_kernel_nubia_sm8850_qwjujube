__int64 __fastcall drv_cmd_get_band(
        __int64 a1,
        __int64 a2,
        const char *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w22
  unsigned __int8 v26; // w0
  int v27; // w8
  __int64 v28; // x19
  unsigned __int64 v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8
  unsigned __int64 v49; // x9
  __int64 result; // x0
  unsigned int v51; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v52[5]; // [xsp+8h] [xbp-28h] BYREF

  v52[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a2 + 8);
  memset(v52, 0, 32);
  v51 = -1;
  ucfg_reg_get_band(v16, &v51, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v51 >= 3 )
  {
    qdf_trace_msg(0x33u, 3u, "%s: Invalid Band %d", v17, v18, v19, v20, v21, v22, v23, v24, "hdd_get_band_helper");
    v25 = -1;
  }
  else
  {
    v25 = dword_AF8B70[v51];
  }
  qdf_mtrace(51, 51, 0xBu, *(_BYTE *)(a1 + 8), v25);
  scnprintf(v52, 32, "%s %d", a3, v25);
  v27 = *(_DWORD *)(a13 + 12);
  if ( v27 > v26 )
    LOBYTE(v27) = v26 + 1;
  v28 = (unsigned __int8)v27;
  if ( (unsigned __int8)v27 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v27);
  }
  else
  {
    v29 = *(_QWORD *)a13;
    _check_object_size(v52, (unsigned __int8)v27, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v39 = v29, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v39 = v29 & ((__int64)(v29 << 8) >> 8);
    if ( 0x8000000000LL - v28 >= v39 )
    {
      v40 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v46 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v46 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v46);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v40);
      v28 = _arch_copy_to_user(v29 & 0xFF7FFFFFFFFFFFFFLL, v52, v28);
      v47 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v49 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v49 - 4096);
      _WriteStatusReg(TTBR1_EL1, v49);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v47);
    }
    if ( !v28 )
    {
      result = 0;
      goto LABEL_15;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "drv_cmd_get_band");
  result = 4294967282LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
