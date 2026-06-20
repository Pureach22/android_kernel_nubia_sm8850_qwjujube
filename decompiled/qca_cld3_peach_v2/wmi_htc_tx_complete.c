__int64 __fastcall wmi_htc_tx_complete(
        _DWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w8
  __int64 v12; // x20
  __int64 v13; // x8
  __int64 v14; // x23
  _DWORD *v15; // x21
  __int64 v16; // x8
  __int64 v17; // x25
  unsigned __int64 v18; // x12
  __int64 v19; // x9
  unsigned int v20; // w22
  __int64 v21; // x8
  char StatusReg; // w10
  __int64 v23; // x24
  unsigned __int64 v24; // x8
  __int64 v25; // x26
  __int64 (__fastcall *v26)(_QWORD); // x8
  unsigned int *v27; // x9
  unsigned int **v28; // x27
  unsigned int v29; // w8
  __int64 v30; // x8
  __int64 result; // x0
  __int64 (__fastcall *v32)(_QWORD); // x8
  __int64 system_time; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int *v42; // x9
  unsigned int v43; // w8
  __int64 v44; // x8
  int v45; // w8
  __int64 v46; // x0
  unsigned int v53; // w10

  v10 = *(_DWORD *)(a2 + 48);
  v12 = *(_QWORD *)(a2 + 96);
  if ( a1[1302] == v10 )
  {
    v13 = 0;
  }
  else if ( a1[1303] == v10 )
  {
    v13 = 1;
  }
  else
  {
    if ( a1[1304] != v10 )
      return qdf_trace_msg(
               0x31u,
               2u,
               "%s: Unable to get wmi handle",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wmi_htc_tx_complete");
    v13 = 2;
  }
  v14 = *(_QWORD *)&a1[2 * v13 + 1296];
  if ( !v14 )
    return qdf_trace_msg(
             0x31u,
             2u,
             "%s: Unable to get wmi handle",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wmi_htc_tx_complete");
  v15 = *(_DWORD **)(v12 + 224);
  if ( *(_BYTE *)(v14 + 680) == 1 )
  {
    v16 = (__int64)((_QWORD)v15 << 8) >> 8;
    v17 = *(_QWORD *)(v12 + 40);
    v18 = (unsigned __int64)(v16 + 0x8000000000LL) >> 38;
    v19 = memstart_addr + v16 + 0x8000000000LL;
    v20 = *v15 & 0xFFFFFF;
    v21 = v16 - kimage_voffset;
    StatusReg = _ReadStatusReg(DAIF);
    if ( v18 )
      v23 = v21;
    else
      v23 = v19;
    if ( StatusReg < 0
      || (v24 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v24 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v14 + 664);
    }
    else
    {
      raw_spin_lock_bh(v14 + 664);
      *(_QWORD *)(v14 + 672) |= 1uLL;
    }
    v25 = *(unsigned int *)(*(_QWORD *)(v14 + 760) + 7848LL);
    v26 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v14 + 728) + 3528LL);
    if ( *((_DWORD *)v26 - 1) != -1896783675 )
      __break(0x8228u);
    if ( (v26(v20) & 1) != 0 )
    {
      v27 = *(unsigned int **)(v14 + 584);
      v28 = (unsigned int **)(v14 + 584);
      v29 = *v27;
      if ( wmi_mgmt_tx_cmpl_log_max_entry <= *v27 )
      {
        *v27 = 0;
        v29 = **v28;
      }
      *(_DWORD *)(*(_QWORD *)(v14 + 568) + 32LL * v29) = v20;
      qdf_mem_copy(
        (void *)(*(_QWORD *)(v14 + 568) + 32LL * **(unsigned int **)(v14 + 584) + 4),
        (char *)v15 + v25,
        (unsigned int)wmi_record_max_length);
      __isb(0xFu);
      *(_QWORD *)(*(_QWORD *)(v14 + 568) + 32LL * **(unsigned int **)(v14 + 584) + 24) = _ReadStatusReg(CNTVCT_EL0);
      v30 = 576;
    }
    else
    {
      v32 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v14 + 728) + 3544LL);
      if ( v32 )
      {
        if ( *((_DWORD *)v32 - 1) != -1896783675 )
          __break(0x8228u);
        if ( (v32(v20) & 1) != 0 )
        {
          system_time = qdf_mc_timer_get_system_time();
          qdf_trace_msg(
            0x31u,
            4u,
            "%s: Tx completion received for WMI_FORCE_FW_HANG_CMDID, current_time:%ld",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wmi_htc_tx_complete",
            system_time);
        }
      }
      v42 = *(unsigned int **)(v14 + 456);
      v28 = (unsigned int **)(v14 + 456);
      v43 = *v42;
      if ( wmi_cmd_cmpl_log_max_entry <= *v42 )
      {
        *v42 = 0;
        v43 = **v28;
      }
      *(_DWORD *)(*(_QWORD *)(v14 + 440) + 48LL * v43) = v20;
      qdf_mem_copy(
        (void *)(*(_QWORD *)(v14 + 440) + 48LL * **(unsigned int **)(v14 + 456) + 4),
        (char *)v15 + v25,
        (unsigned int)wmi_record_max_length);
      __isb(0xFu);
      *(_QWORD *)(*(_QWORD *)(v14 + 440) + 48LL * **(unsigned int **)(v14 + 456) + 24) = _ReadStatusReg(CNTVCT_EL0);
      *(_QWORD *)(*(_QWORD *)(v14 + 440) + 48LL * **(unsigned int **)(v14 + 456) + 32) = v17;
      *(_QWORD *)(*(_QWORD *)(v14 + 440) + 48LL * **(unsigned int **)(v14 + 456) + 40) = v23;
      v30 = 448;
    }
    ++**v28;
    ++*(_DWORD *)(v14 + v30);
    v44 = *(_QWORD *)(v14 + 672);
    if ( (v44 & 1) != 0 )
    {
      *(_QWORD *)(v14 + 672) = v44 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v14 + 664);
      if ( (*(_BYTE *)(v12 + 68) & 4) == 0 )
        goto LABEL_34;
LABEL_36:
      v45 = *(unsigned __int16 *)(v12 + 66);
      goto LABEL_37;
    }
    raw_spin_unlock(v14 + 664);
  }
  if ( (*(_BYTE *)(v12 + 68) & 4) != 0 )
    goto LABEL_36;
LABEL_34:
  v45 = 0;
LABEL_37:
  qdf_mem_set(v15, (unsigned int)(*(_DWORD *)(v12 + 112) + v45), 0);
  v46 = wbuff_buff_put(v12);
  if ( v46 )
    _qdf_nbuf_free(v46);
  result = _qdf_mem_free(a2);
  _X8 = (unsigned int *)(v14 + 24);
  __asm { PRFM            #0x11, [X8] }
  do
    v53 = __ldxr(_X8);
  while ( __stxr(v53 - 1, _X8) );
  return result;
}
