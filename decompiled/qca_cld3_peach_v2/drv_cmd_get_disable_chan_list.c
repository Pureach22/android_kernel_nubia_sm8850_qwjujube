__int64 __fastcall drv_cmd_get_disable_chan_list(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w8
  __int64 v16; // x21
  __int64 v17; // x8
  unsigned __int64 v18; // x23
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w22
  unsigned __int64 v29; // x19
  unsigned int *v30; // x28
  unsigned int v31; // t1
  unsigned __int8 v32; // w0
  int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  unsigned __int64 v43; // x19
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v53; // x9
  unsigned __int64 v54; // x9
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v63; // x9
  __int64 result; // x0
  _BYTE s[512]; // [xsp+10h] [xbp-210h] BYREF
  __int64 v66; // [xsp+210h] [xbp-10h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Received Command to get disable Channels list",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "drv_cmd_get_disable_chan_list");
  v15 = *(_DWORD *)(a5 + 12);
  if ( v15 >= 0x200 )
    v16 = 512;
  else
    v16 = v15;
  qdf_mutex_acquire(a2 + 3624);
  v17 = *(_QWORD *)(a2 + 3616);
  if ( !v17 || !*(_DWORD *)v17 || !*(_QWORD *)(v17 + 8) )
  {
    qdf_mutex_release(a2 + 3624);
LABEL_22:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: disable channel list is not yet programmed",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "drv_cmd_get_disable_chan_list");
    result = 4294967274LL;
    goto LABEL_23;
  }
  v18 = (unsigned __int8)*(_DWORD *)v17;
  v20 = scnprintf(s, v16, "%s %hhu", "GET_DISABLE_CHANNEL_LIST", (unsigned __int8)*(_DWORD *)v17);
  v28 = v19;
  if ( (_DWORD)v18 && v19 < (int)v16 - 1 )
  {
    v29 = 1;
    v30 = *(unsigned int **)(*(_QWORD *)(a2 + 3616) + 8LL);
    do
    {
      v31 = *v30;
      v30 += 3;
      v32 = wlan_reg_freq_to_chan(*(_QWORD *)(a2 + 8), v31, v20, v21, v22, v23, v24, v25, v26, v27);
      v20 = scnprintf(&s[v28], (unsigned int)v16 - v28, " %d", v32);
      v28 += v33;
      if ( v29 >= v18 )
        break;
      ++v29;
    }
    while ( v28 < (int)v16 - 1 );
  }
  qdf_mutex_release(a2 + 3624);
  if ( !v28 )
    goto LABEL_22;
  v42 = (int)(v28 + 1);
  if ( v28 + 1 >= 0x201 )
  {
    _copy_overflow(512, (int)(v28 + 1));
  }
  else
  {
    v43 = *(_QWORD *)a5;
    _check_object_size(s, v42, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v53 = v43, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v53 = v43 & ((__int64)(v43 << 8) >> 8);
    if ( 0x8000000000LL - v42 >= v53 )
    {
      v54 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v60 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v60 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v60);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v54);
      v42 = _arch_copy_to_user(v43 & 0xFF7FFFFFFFFFFFFFLL, s, v42);
      v61 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v63 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v63 - 4096);
      _WriteStatusReg(TTBR1_EL1, v63);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v61);
    }
    if ( !v42 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: data:%s",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "drv_cmd_get_disable_chan_list",
        s);
      result = 0;
      goto LABEL_23;
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed to copy data to user buffer",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "drv_cmd_get_disable_chan_list");
  result = 4294967282LL;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
