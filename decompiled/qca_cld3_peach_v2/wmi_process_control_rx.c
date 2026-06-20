__int64 __fastcall wmi_process_control_rx(
        __int64 a1,
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
  __int64 v11; // x23
  unsigned int v12; // w9
  unsigned int v13; // w22
  unsigned int v15; // w10
  int *v16; // x9
  int v17; // w4
  __int64 v18; // x10
  __int64 v19; // x21
  int v20; // t1
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x8
  int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x23
  unsigned __int64 v33; // x8
  __int64 (__fastcall *v34)(_QWORD); // x8
  unsigned int *v35; // x9
  _QWORD *v36; // x25
  unsigned int **v37; // x24
  unsigned int v38; // w8
  unsigned __int64 v39; // x8
  __int64 v40; // x9
  __int64 result; // x0
  __int64 (__fastcall *v42)(_QWORD); // x8
  unsigned int *v43; // x9
  unsigned int v44; // w8
  unsigned int *v45; // x9
  unsigned int v46; // w8
  __int64 v47; // x8
  unsigned __int64 v48; // x8
  __int64 v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x21
  _QWORD *v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x8
  int v69; // w9
  __int64 v70; // x20
  __int64 *v71; // x8
  int v72; // w9
  __int64 v73; // x8
  unsigned int v80; // w9
  __int64 v81; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v82; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v83)(); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v84)(); // [xsp+20h] [xbp-20h]
  __int64 v85; // [xsp+28h] [xbp-18h]
  __int64 v86; // [xsp+30h] [xbp-10h]
  __int64 v87; // [xsp+38h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 760);
  v12 = *(_DWORD *)(v11 + 3112);
  v13 = **(_DWORD **)(a2 + 224) & 0xFFFFFF;
  if ( !v12 )
    goto LABEL_27;
  v15 = v12 >= 0x100 ? 256 : *(_DWORD *)(v11 + 3112);
  v16 = *(int **)(a1 + 40);
  v17 = 0;
  v18 = 8LL * v15;
  v19 = 0;
  while ( 1 )
  {
    v20 = *v16++;
    if ( v20 == v13 )
    {
      if ( *(_QWORD *)(*(_QWORD *)(a1 + 48) + v19) )
        break;
    }
    v19 += 8;
    ++v17;
    if ( v18 == v19 )
      goto LABEL_27;
  }
  if ( (_DWORD)v19 == -8 )
  {
LABEL_27:
    result = qdf_trace_msg(
               0x31u,
               8u,
               "%s: no handler registered for event id 0x%x",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wmi_process_control_rx",
               v13);
    if ( !a2 )
      goto LABEL_29;
    goto LABEL_28;
  }
  qdf_mtrace(
    49,
    54,
    **(_DWORD **)(a2 + 224) & 0x7F | ((unsigned __int8)(**(_DWORD **)(a2 + 224) >> 12) << 7),
    0xFFu,
    v17);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11 + 5168);
    v22 = *(_QWORD *)(v11 + 5176);
  }
  else
  {
    raw_spin_lock_bh(v11 + 5168);
    v22 = *(_QWORD *)(v11 + 5176) | 1LL;
    *(_QWORD *)(v11 + 5176) = v22;
  }
  v23 = *(_DWORD *)(*(_QWORD *)(a1 + 56) + v19);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 5176) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 5168);
  }
  else
  {
    raw_spin_unlock(v11 + 5168);
  }
  if ( *(_BYTE *)(a1 + 680) != 1 )
    goto LABEL_41;
  v32 = *(_QWORD *)(a2 + 224);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v33 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v33 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 664);
  }
  else
  {
    raw_spin_lock_bh(a1 + 664);
    *(_QWORD *)(a1 + 672) |= 1uLL;
  }
  v34 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 728) + 3536LL);
  if ( *((_DWORD *)v34 - 1) != -1896783675 )
    __break(0x8228u);
  if ( (v34(v13) & 1) != 0 )
  {
    v35 = *(unsigned int **)(a1 + 648);
    v36 = (_QWORD *)(a1 + 632);
    v37 = (unsigned int **)(a1 + 648);
    v38 = *v35;
    if ( wmi_diag_log_max_entry <= *v35 )
    {
      *v35 = 0;
      v38 = **v37;
    }
    *(_DWORD *)(*(_QWORD *)(a1 + 632) + 32LL * v38) = v13;
    qdf_mem_copy(
      (void *)(*(_QWORD *)(a1 + 632) + 32LL * **(unsigned int **)(a1 + 648) + 4),
      (const void *)(v32 + *(unsigned int *)(*(_QWORD *)(a1 + 760) + 7852LL)),
      (unsigned int)wmi_record_max_length);
    __isb(0xFu);
    v39 = _ReadStatusReg(CNTVCT_EL0);
    v40 = 640;
  }
  else
  {
    v42 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 728) + 3528LL);
    if ( *((_DWORD *)v42 - 1) != -1896783675 )
      __break(0x8228u);
    if ( (v42(v13) & 1) != 0 )
    {
      v43 = *(unsigned int **)(a1 + 616);
      v36 = (_QWORD *)(a1 + 600);
      v37 = (unsigned int **)(a1 + 616);
      v44 = *v43;
      if ( wmi_mgmt_rx_log_max_entry <= *v43 )
      {
        *v43 = 0;
        v44 = **v37;
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 600) + 32LL * v44) = v13;
      qdf_mem_copy(
        (void *)(*(_QWORD *)(a1 + 600) + 32LL * **(unsigned int **)(a1 + 616) + 4),
        (const void *)(v32 + *(unsigned int *)(*(_QWORD *)(a1 + 760) + 7852LL)),
        (unsigned int)wmi_record_max_length);
      __isb(0xFu);
      v39 = _ReadStatusReg(CNTVCT_EL0);
      v40 = 608;
    }
    else
    {
      v45 = *(unsigned int **)(a1 + 520);
      v36 = (_QWORD *)(a1 + 504);
      v37 = (unsigned int **)(a1 + 520);
      v46 = *v45;
      if ( wmi_event_log_max_entry <= *v45 )
      {
        *v45 = 0;
        v46 = **v37;
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 504) + 32LL * v46) = v13;
      qdf_mem_copy(
        (void *)(*(_QWORD *)(a1 + 504) + 32LL * **(unsigned int **)(a1 + 520) + 4),
        (const void *)(v32 + *(unsigned int *)(*(_QWORD *)(a1 + 760) + 7852LL)),
        (unsigned int)wmi_record_max_length);
      __isb(0xFu);
      v39 = _ReadStatusReg(CNTVCT_EL0);
      v40 = 512;
    }
  }
  *(_QWORD *)(*v36 + 32LL * (**v37)++ + 24) = v39;
  ++*(_DWORD *)(a1 + v40);
  v47 = *(_QWORD *)(a1 + 672);
  if ( (v47 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 664);
LABEL_41:
    if ( v23 <= 1 )
      goto LABEL_42;
    goto LABEL_48;
  }
  *(_QWORD *)(a1 + 672) = v47 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 664);
  if ( v23 <= 1 )
  {
LABEL_42:
    if ( !v23 )
    {
      result = wmi_process_fw_event_worker_thread_ctx(a1, (_QWORD *)a2);
      goto LABEL_29;
    }
    if ( v23 == 1 )
    {
      result = _wmi_control_rx((__int64 *)a1, a2, v24, v25, v26, v27, v28, v29, v30, v31);
      goto LABEL_29;
    }
    goto LABEL_61;
  }
LABEL_48:
  if ( v23 == 2 )
  {
    v85 = 0;
    v86 = 0;
    v83 = nullptr;
    v84 = nullptr;
    v81 = 0;
    v82 = nullptr;
    v59 = (_QWORD *)_qdf_mem_malloc(0x10u, "wmi_process_fw_event_sched_thread_ctx", 2576);
    if ( !v59 )
    {
      result = qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s: malloc failed",
                 v60,
                 v61,
                 v62,
                 v63,
                 v64,
                 v65,
                 v66,
                 v67,
                 "wmi_process_fw_event_sched_thread_ctx");
      if ( !a2 )
        goto LABEL_29;
      goto LABEL_28;
    }
    *v59 = a1;
    v59[1] = a2;
    v68 = *(_QWORD *)(a1 + 744);
    v69 = **(_DWORD **)(a2 + 224) & 0xFFFFFF;
    if ( *(_DWORD *)(v68 + 308) == v69 || *(_DWORD *)(v68 + 140) == v69 )
    {
      _X8 = (unsigned int *)(a1 + 848);
      __asm { PRFM            #0x11, [X8] }
      do
        v80 = __ldxr(_X8);
      while ( __stxr(v80 + 1, _X8) );
    }
    v70 = (__int64)v59;
    v82 = v59;
    v83 = wmi_process_fw_event_handler;
    HIDWORD(v81) = 0;
    v84 = wmi_discard_fw_event;
    result = scheduler_post_message_debug(
               0x49u,
               0x49u,
               73,
               (unsigned __int16 *)&v81,
               0xA27u,
               (__int64)"wmi_process_fw_event_sched_thread_ctx");
    if ( (_DWORD)result )
    {
      if ( a2 )
        _qdf_nbuf_free(a2);
      result = _qdf_mem_free(v70);
    }
  }
  else
  {
    if ( v23 != 3 )
    {
LABEL_61:
      result = qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s: Invalid event context %d",
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 "wmi_process_control_rx",
                 (unsigned int)v23);
      if ( !a2 )
        goto LABEL_29;
      goto LABEL_28;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v48 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v48 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v48 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 176);
    }
    else
    {
      raw_spin_lock_bh(a1 + 176);
      *(_QWORD *)(a1 + 184) |= 1uLL;
    }
    if ( *(_DWORD *)(a1 + 208) >= 0x3E8u )
    {
      v49 = *(_QWORD *)(a1 + 184);
      if ( (v49 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 184) = v49 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a1 + 176);
      }
      else
      {
        result = raw_spin_unlock(a1 + 176);
      }
      ++*(_DWORD *)(a1 + 264);
      v58 = jiffies;
      if ( wmi_process_rx_diag_event_worker_thread_ctx___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x31u,
                   8u,
                   "%s: Rx diag events dropped count: %d",
                   v50,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55,
                   v56,
                   v57,
                   "wmi_process_rx_diag_event_worker_thread_ctx");
        wmi_process_rx_diag_event_worker_thread_ctx___last_ticks = v58;
      }
      if ( !a2 )
        goto LABEL_29;
LABEL_28:
      result = _qdf_nbuf_free(a2);
      goto LABEL_29;
    }
    *(_QWORD *)a2 = 0;
    v71 = (__int64 *)(a1 + 192);
    if ( *(_QWORD *)(a1 + 192) )
      v71 = *(__int64 **)(a1 + 200);
    *v71 = a2;
    v72 = *(_DWORD *)(a1 + 208);
    v73 = *(_QWORD *)(a1 + 184);
    *(_QWORD *)(a1 + 200) = a2;
    *(_DWORD *)(a1 + 208) = v72 + 1;
    if ( (v73 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 184) = v73 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 176);
    }
    else
    {
      raw_spin_unlock(a1 + 176);
    }
    result = queue_work_on(32, *(_QWORD *)(a1 + 168), a1 + 216);
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
