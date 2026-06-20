void __fastcall handle_session_error(__int64 a1, __int64 a2)
{
  char **v2; // x20
  __int64 *inst; // x0
  unsigned int *v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x8
  unsigned int v17; // w9

  if ( a2 )
  {
    v2 = off_6C000;
    inst = cvp_get_inst(*(_QWORD *)(cvp_driver + 48), *(__int64 **)(a2 + 8));
    if ( inst )
    {
      v4 = (unsigned int *)inst;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_90C62, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      raw_spin_lock(v4 + 44);
      if ( cvp_error_count <= 65534 )
        goto LABEL_23;
      while ( 1 )
      {
        raw_spin_unlock(v4 + 44);
        v4[3815] = cvp_error_count | 0x10020000;
        cvp_print_inst(2, v4);
        if ( v4[82] != 9 )
        {
          if ( (msm_cvp_sw_dbg_buf_dump & 1) != 0 )
          {
            v5 = ((__int64 (__fastcall *)(unsigned int *))eva_kmd_session_dump)(v4);
            v6 = eva_kmd_debug_log_dump(v5);
            v2 = *((char ***)v2[145] + 6);
            if ( v2 )
            {
              if ( !*((_DWORD *)v2 + 344) )
              {
                eva_cmd_msg_queue_dump(v6);
                ++*((_DWORD *)v2 + 344);
              }
            }
          }
          v7 = raw_spin_lock_irqsave(v4 + 72);
          v4[73] = 1;
          raw_spin_unlock_irqrestore(v4 + 72, v7);
          _wake_up(v4 + 74, 3, 0, 0);
        }
        if ( msm_cvp_session_error_recovery )
          break;
        __break(0x800u);
LABEL_23:
        _X8 = &cvp_error_count;
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr((unsigned int *)&cvp_error_count);
        while ( __stxr(v17 + 1, (unsigned int *)&cvp_error_count) );
      }
      cvp_put_inst(v4);
    }
    else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_884B3, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), "warn");
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    printk(&unk_93D99, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
  }
}
