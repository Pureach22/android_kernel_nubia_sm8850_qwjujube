__int64 __fastcall drv_cmd_get_scan_channel_time(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x0
  unsigned int v8; // w1
  unsigned __int16 neighbor_scan_max_chan_time; // w0
  __int64 v10; // x4
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int8 v19; // w0
  int v20; // w8
  __int64 v21; // x19
  unsigned __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v42; // x9
  __int64 result; // x0
  _QWORD v44[5]; // [xsp+8h] [xbp-28h] BYREF

  v44[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *a2;
  v8 = *(unsigned __int8 *)(a1 + 8);
  memset(v44, 0, 32);
  neighbor_scan_max_chan_time = ucfg_cm_get_neighbor_scan_max_chan_time(v7, v8);
  v10 = *(unsigned __int8 *)(a1 + 8);
  LOWORD(a1) = neighbor_scan_max_chan_time;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev_id: %u, scan channel time: %u",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "drv_cmd_get_scan_channel_time",
    v10,
    neighbor_scan_max_chan_time);
  scnprintf(v44, 32, "%s %d", "GETSCANCHANNELTIME", (unsigned __int16)a1);
  v20 = *(_DWORD *)(a5 + 12);
  if ( v20 > v19 )
    LOBYTE(v20) = v19 + 1;
  v21 = (unsigned __int8)v20;
  if ( (unsigned __int8)v20 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v20);
  }
  else
  {
    v22 = *(_QWORD *)a5;
    _check_object_size(v44, (unsigned __int8)v20, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v32 = v22, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v32 = v22 & ((__int64)(v22 << 8) >> 8);
    if ( 0x8000000000LL - v21 >= v32 )
    {
      v33 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v39 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v39 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v39);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v33);
      v21 = _arch_copy_to_user(v22 & 0xFF7FFFFFFFFFFFFFLL, v44, v21);
      v40 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v42 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v42 - 4096);
      _WriteStatusReg(TTBR1_EL1, v42);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v40);
    }
    if ( !v21 )
    {
      result = 0;
      goto LABEL_12;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "drv_cmd_get_scan_channel_time");
  result = 4294967282LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
