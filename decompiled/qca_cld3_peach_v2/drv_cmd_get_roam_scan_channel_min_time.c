__int64 __fastcall drv_cmd_get_roam_scan_channel_min_time(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x0
  unsigned int v8; // w1
  unsigned __int16 neighbor_scan_min_chan_time; // w21
  unsigned __int8 v10; // w0
  unsigned __int8 v11; // w3
  __int64 v12; // x19
  unsigned __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x9
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  __int64 result; // x0
  _QWORD v35[5]; // [xsp+8h] [xbp-28h] BYREF

  v35[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *a2;
  v8 = *(unsigned __int8 *)(a1 + 8);
  memset(v35, 0, 32);
  neighbor_scan_min_chan_time = ucfg_cm_get_neighbor_scan_min_chan_time(v7, v8);
  scnprintf(v35, 32, "%s %d", "GETROAMSCANCHANNELMINTIME", neighbor_scan_min_chan_time);
  v11 = *(_BYTE *)(a1 + 8);
  if ( *(_DWORD *)(a5 + 12) > (int)v10 )
    LOBYTE(v12) = v10 + 1;
  else
    LOBYTE(v12) = *(_DWORD *)(a5 + 12);
  qdf_mtrace(51, 51, 0x3Du, v11, neighbor_scan_min_chan_time);
  v12 = (unsigned __int8)v12;
  if ( (unsigned __int8)v12 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v12);
  }
  else
  {
    v13 = *(_QWORD *)a5;
    _check_object_size(v35, (unsigned __int8)v12, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v23 = v13, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v23 = v13 & ((__int64)(v13 << 8) >> 8);
    if ( 0x8000000000LL - (unsigned __int64)(unsigned __int8)v12 >= v23 )
    {
      v24 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v30 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v30 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v30);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v24);
      v12 = _arch_copy_to_user(v13 & 0xFF7FFFFFFFFFFFFFLL, v35, (unsigned __int8)v12);
      v31 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v33 - 4096);
      _WriteStatusReg(TTBR1_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v31);
    }
    if ( !v12 )
    {
      result = 0;
      goto LABEL_13;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "drv_cmd_get_roam_scan_channel_min_time");
  result = 4294967282LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
