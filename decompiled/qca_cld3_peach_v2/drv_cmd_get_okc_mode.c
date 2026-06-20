__int64 __fastcall drv_cmd_get_okc_mode(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  unsigned __int8 v16; // w0
  int v17; // w8
  __int64 v18; // x19
  unsigned __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x9
  unsigned int v40; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v41[5]; // [xsp+8h] [xbp-28h] BYREF

  v41[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  memset(v41, 0, 32);
  hdd_get_pmkid_modes(a2, &v40);
  if ( (v40 & 1) != 0
    && (ucfg_cm_get_is_ese_feature_enabled(*a2) & 1) != 0
    && (ucfg_cm_get_is_ft_feature_enabled(*a2) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: PMKID/ESE/11R are supported simultaneously hence this operation is not permitted!",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_get_okc_mode");
    result = 0xFFFFFFFFLL;
  }
  else
  {
    scnprintf(v41, 32, "%s %d", "GETOKCMODE", v40 & 1);
    v17 = *(_DWORD *)(a5 + 12);
    if ( v17 > v16 )
      LOBYTE(v17) = v16 + 1;
    v18 = (unsigned __int8)v17;
    if ( (unsigned __int8)v17 >= 0x21u )
    {
      _copy_overflow(32, (unsigned __int8)v17);
    }
    else
    {
      v19 = *(_QWORD *)a5;
      _check_object_size(v41, (unsigned __int8)v17, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v29 = v19, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v29 = v19 & ((__int64)(v19 << 8) >> 8);
      if ( 0x8000000000LL - v18 >= v29 )
      {
        v30 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v36 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v36 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v36);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v30);
        v18 = _arch_copy_to_user(v19 & 0xFF7FFFFFFFFFFFFFLL, v41, v18);
        v37 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v39 - 4096);
        _WriteStatusReg(TTBR1_EL1, v39);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v37);
      }
      if ( !v18 )
      {
        result = 0;
        goto LABEL_16;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to copy data to user buffer",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "drv_cmd_get_okc_mode");
    result = 4294967282LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
