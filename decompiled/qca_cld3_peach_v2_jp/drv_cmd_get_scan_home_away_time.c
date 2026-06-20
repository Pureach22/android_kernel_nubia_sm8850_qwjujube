__int64 __fastcall drv_cmd_get_scan_home_away_time(__int64 a1, __int64 *a2, const char *a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x0
  unsigned int v9; // w1
  unsigned int roam_scan_home_away_time; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  unsigned __int8 v20; // w0
  int v21; // w8
  __int64 v22; // x19
  unsigned __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x9
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v43; // x9
  unsigned __int16 v44; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v45[5]; // [xsp+8h] [xbp-28h] BYREF

  v45[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a2;
  v9 = *(unsigned __int8 *)(a1 + 8);
  v44 = 0;
  memset(v45, 0, 32);
  roam_scan_home_away_time = ucfg_cm_get_roam_scan_home_away_time(v8, v9, &v44);
  if ( roam_scan_home_away_time )
  {
    result = qdf_status_to_os_return(roam_scan_home_away_time);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev_id: %u, scan home away time: %u",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "drv_cmd_get_scan_home_away_time",
      *(unsigned __int8 *)(a1 + 8),
      v44);
    scnprintf(v45, 32, "%s %d", a3, v44);
    v21 = *(_DWORD *)(a5 + 12);
    if ( v21 > v20 )
      LOBYTE(v21) = v20 + 1;
    v22 = (unsigned __int8)v21;
    if ( (unsigned __int8)v21 >= 0x21u )
    {
      _copy_overflow(32, (unsigned __int8)v21);
    }
    else
    {
      v23 = *(_QWORD *)a5;
      _check_object_size(v45, (unsigned __int8)v21, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v33 = v23, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v33 = v23 & ((__int64)(v23 << 8) >> 8);
      if ( 0x8000000000LL - v22 >= v33 )
      {
        v34 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v40 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v40 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v40);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v34);
        v22 = _arch_copy_to_user(v23 & 0xFF7FFFFFFFFFFFFFLL, v45, v22);
        v41 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v43 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v43 - 4096);
        _WriteStatusReg(TTBR1_EL1, v43);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v41);
      }
      if ( !v22 )
      {
        result = 0;
        goto LABEL_14;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to copy data to user buffer",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "drv_cmd_get_scan_home_away_time");
    result = 4294967282LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
