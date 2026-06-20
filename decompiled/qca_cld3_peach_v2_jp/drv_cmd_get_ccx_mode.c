__int64 __fastcall drv_cmd_get_ccx_mode(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  char is_ese_feature_enabled; // w19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  unsigned __int8 v17; // w0
  int v18; // w8
  __int64 v19; // x19
  unsigned __int64 v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v40; // x9
  unsigned int v41; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v42[5]; // [xsp+8h] [xbp-28h] BYREF

  v42[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  is_ese_feature_enabled = ucfg_cm_get_is_ese_feature_enabled(*a2);
  memset(v42, 0, 32);
  v41 = 0;
  hdd_get_pmkid_modes(a2, &v41);
  if ( (is_ese_feature_enabled & 1) != 0 && (v41 & 3) != 0 && (ucfg_cm_get_is_ft_feature_enabled(*a2) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: PMKID/ESE/11R are supported simultaneously hence this operation is not permitted!",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "drv_cmd_get_ccx_mode");
    result = 0xFFFFFFFFLL;
  }
  else
  {
    scnprintf(v42, 32, "%s %d", "GETCCXMODE", is_ese_feature_enabled & 1);
    v18 = *(_DWORD *)(a5 + 12);
    if ( v18 > v17 )
      LOBYTE(v18) = v17 + 1;
    v19 = (unsigned __int8)v18;
    if ( (unsigned __int8)v18 >= 0x21u )
    {
      _copy_overflow(32, (unsigned __int8)v18);
    }
    else
    {
      v20 = *(_QWORD *)a5;
      _check_object_size(v42, (unsigned __int8)v18, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v30 = v20, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v30 = v20 & ((__int64)(v20 << 8) >> 8);
      if ( 0x8000000000LL - v19 >= v30 )
      {
        v31 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v37 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v37 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v37);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v31);
        v19 = _arch_copy_to_user(v20 & 0xFF7FFFFFFFFFFFFFLL, v42, v19);
        v38 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v40 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v40 - 4096);
        _WriteStatusReg(TTBR1_EL1, v40);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v38);
      }
      if ( !v19 )
      {
        result = 0;
        goto LABEL_16;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to copy data to user buffer",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "drv_cmd_get_ccx_mode");
    result = 4294967282LL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
