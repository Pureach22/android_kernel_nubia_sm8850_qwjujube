void *__fastcall handle_session_timeout(__int64 a1, char a2)
{
  void *result; // x0
  __int64 v5; // x23
  __int64 *v6; // x21
  int v7; // w22
  __int64 v8; // x0
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x1
  __int64 v12; // x2
  void *v13; // x0
  unsigned __int64 v14; // x8
  const char *v15; // x3
  unsigned __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x27
  __int64 v19; // x22
  unsigned __int64 v20; // x21
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned int v33; // w9
  _DWORD s[190]; // [xsp+8h] [xbp-308h] BYREF
  __int64 v35; // [xsp+300h] [xbp-10h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  v5 = *(_QWORD *)(cvp_driver + 48);
  if ( !v5 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_39;
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(unsigned int *)(StatusReg + 1800);
    v12 = *(unsigned int *)(StatusReg + 1804);
    v13 = &unk_83C86;
    goto LABEL_15;
  }
  v6 = *(__int64 **)(v5 + 256);
  if ( !v6 )
  {
    if ( ((unsigned __int8)msm_cvp_debug & (msm_cvp_debug_out == 0)) == 0 )
      goto LABEL_39;
    v14 = _ReadStatusReg(SP_EL0);
    v11 = *(unsigned int *)(v14 + 1800);
    v12 = *(unsigned int *)(v14 + 1804);
    v13 = &unk_93332;
LABEL_15:
    v15 = (const char *)&unk_8E7CE;
    goto LABEL_16;
  }
  if ( ((unsigned __int8)msm_cvp_debug & (msm_cvp_debug_out == 0)) != 0 )
  {
    v25 = _ReadStatusReg(SP_EL0);
    printk(&unk_8649E, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
  }
  result = cvp_get_inst_validate(*(_QWORD *)(a1 + 128), (__int64 *)a1);
  if ( !result )
  {
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      goto LABEL_39;
    v16 = _ReadStatusReg(SP_EL0);
    v11 = *(unsigned int *)(v16 + 1800);
    v12 = *(unsigned int *)(v16 + 1804);
    v13 = &unk_925B4;
    v15 = "warn";
LABEL_16:
    result = (void *)printk(v13, v11, v12, v15);
    goto LABEL_39;
  }
  raw_spin_lock(a1 + 176);
  v7 = *(unsigned __int16 *)(a1 + 15262);
  v8 = raw_spin_unlock(a1 + 176);
  if ( v7 == 4097 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_884F1, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    }
  }
  else
  {
    v17 = ktime_get(v8);
    v18 = *v6;
    v19 = v17;
    if ( *v6 )
    {
      v20 = *(_QWORD *)(v18 + 1024);
      if ( v20 )
      {
        raw_spin_lock(v18 + 1016);
        v21 = (unsigned __int128)(*(__int64 *)(v5 + 51312) * (__int128)(__int64)0xBCE4217D2849CB25LL) >> 64;
        *(_DWORD *)(v5 + 51320) = *(_DWORD *)(v20 + 48);
        v20 = (v21 >> 18) + ((unsigned __int64)v21 >> 63) + v19 / 1000000;
        raw_spin_unlock(v18 + 1016);
      }
    }
    else
    {
      v20 = 0;
    }
    if ( (unsigned __int64)(*(_QWORD *)(v5 + 51304) / -1000000LL + v19 / 1000000) > 0x1F4
      || v20 >= 0x1F5 && *(_DWORD *)(v5 + 51320) == *(_DWORD *)(v5 + 51324) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v26 = _ReadStatusReg(SP_EL0);
        printk(&unk_91933, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), &unk_8E7CE);
      }
      s[0] = 0;
      handle_sys_error(8, s);
    }
    else
    {
      raw_spin_lock(a1 + 176);
      if ( cvp_error_count <= 65534 )
        goto LABEL_41;
      while ( 1 )
      {
        raw_spin_unlock(a1 + 176);
        *(_DWORD *)(a1 + 15260) = cvp_error_count | 0x10040000;
        cvp_print_inst(2, a1);
        if ( (msm_cvp_sw_dbg_buf_dump & 1) != 0 )
        {
          v22 = ((__int64 (__fastcall *)(__int64))eva_kmd_session_dump)(a1);
          v23 = eva_kmd_debug_log_dump(v22);
          if ( !*(_DWORD *)(v5 + 1376) )
          {
            eva_cmd_msg_queue_dump(v23);
            ++*(_DWORD *)(v5 + 1376);
          }
        }
        v24 = raw_spin_lock_irqsave(a1 + 288);
        *(_DWORD *)(a1 + 292) = 1;
        raw_spin_unlock_irqrestore(a1 + 288, v24);
        _wake_up(a1 + 296, 3, 0, 0);
        if ( msm_cvp_session_error_recovery )
          break;
        __break(0x800u);
LABEL_41:
        _X8 = &cvp_error_count;
        __asm { PRFM            #0x11, [X8] }
        do
          v33 = __ldxr((unsigned int *)&cvp_error_count);
        while ( __stxr(v33 + 1, (unsigned int *)&cvp_error_count) );
      }
      if ( (a2 & 1) != 0 )
        msm_cvp_session_flush_stop(a1);
    }
  }
  result = cvp_put_inst((unsigned int *)a1);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
