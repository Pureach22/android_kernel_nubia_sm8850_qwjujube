__int64 __fastcall drv_cmd_get_country(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  double v6; // d0
  int v7; // w0
  int v8; // w19
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  signed int v16; // w8
  __int64 v17; // x19
  unsigned __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v38; // x9
  __int64 result; // x0
  __int16 v40; // [xsp+Ch] [xbp-24h] BYREF
  char v41; // [xsp+Eh] [xbp-22h]
  _QWORD v42[2]; // [xsp+10h] [xbp-20h] BYREF
  int v43; // [xsp+20h] [xbp-10h]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  v42[0] = 0;
  v42[1] = 0;
  v41 = 0;
  v40 = 0;
  qdf_mem_copy(&v40, (const void *)(a2 + 618), 2u);
  v41 = 0;
  v6 = scnprintf(v42, 20, "%s %s", "GETCOUNTRYREV", (const char *)&v40);
  v8 = v7;
  qdf_trace_msg(0x33u, 8u, "%s: buf = %s", v6, v9, v10, v11, v12, v13, v14, v15, "drv_cmd_get_country", v42);
  v16 = *(_DWORD *)(a5 + 12);
  if ( v16 >= v8 + 1 )
    v16 = v8 + 1;
  v17 = v16;
  if ( (unsigned int)v16 >= 0x15 )
  {
    _copy_overflow(20, v16);
  }
  else
  {
    v18 = *(_QWORD *)a5;
    _check_object_size(v42, v16, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v28 = v18, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v28 = v18 & ((__int64)(v18 << 8) >> 8);
    if ( 0x8000000000LL - v17 >= v28 )
    {
      v29 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v35 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v35 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v35);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v29);
      v17 = _arch_copy_to_user(v18 & 0xFF7FFFFFFFFFFFFFLL, v42, v17);
      v36 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v38 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v38 - 4096);
      _WriteStatusReg(TTBR1_EL1, v38);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v36);
    }
    if ( !v17 )
    {
      result = 0;
      goto LABEL_12;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "drv_cmd_get_country");
  result = 4294967282LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
