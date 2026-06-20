void __fastcall handle_sys_error(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  char ***v3; // x23
  char ***v4; // x22
  char **v5; // x21
  int v6; // w8
  char v7; // w9
  char **v8; // x20
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x3
  char **v12; // x8
  char **v13; // x0
  __int64 v14; // x0
  __int64 v15; // x21
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x1
  __int64 v19; // x2
  void *v20; // x0
  unsigned __int64 v21; // x8
  __int64 *j; // x21
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  _QWORD *i; // x21
  char **v26; // x8
  char **v27; // x0
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned int v39; // w9
  unsigned __int64 v40; // [xsp+8h] [xbp-18h]
  int v41; // [xsp+14h] [xbp-Ch]
  char ***v42; // [xsp+18h] [xbp-8h]

  if ( !a2 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return;
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(unsigned int *)(StatusReg + 1800);
    v19 = *(unsigned int *)(StatusReg + 1804);
    v20 = &unk_925F0;
LABEL_41:
    printk(v20, v18, v19, &unk_8E7CE);
    return;
  }
  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( !v2 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return;
    v21 = _ReadStatusReg(SP_EL0);
    v18 = *(unsigned int *)(v21 + 1800);
    v19 = *(unsigned int *)(v21 + 1804);
    v20 = &unk_83CAF;
    goto LABEL_41;
  }
  v3 = *(char ****)(v2 + 256);
  mutex_lock(*(_QWORD *)(cvp_driver + 48));
  v4 = (char ***)&unk_1000;
  v5 = off_6C000;
  if ( *(_DWORD *)(v2 + 304) )
  {
    v41 = *(_DWORD *)(v2 + 304);
    v6 = *(_DWORD *)(v2 + 1260);
    v7 = msm_cvp_debug;
    *(_DWORD *)(v2 + 304) = 0;
    *(_DWORD *)(v2 + 1260) = v6 + 1;
    if ( (v7 & 2) != 0 && !msm_cvp_debug_out )
    {
      v28 = _ReadStatusReg(SP_EL0);
      printk(&unk_904C2, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), "warn");
    }
    mutex_lock(v2 + 48);
    v8 = *v3;
    if ( *v3 )
    {
      v9 = _print_sfr_msg();
      if ( v3 )
      {
        v12 = v3[20];
        if ( v12 )
        {
          v13 = *v3;
          if ( *((_DWORD *)v12 - 1) != -1066802076 )
            __break(0x8228u);
          v9 = ((__int64 (__fastcall *)(char **))v12)(v13);
        }
      }
      if ( cvp_error_count <= 65534 )
        goto LABEL_83;
      while ( 1 )
      {
        v42 = v3;
        if ( *((_DWORD *)v8 + 8) == -2147483629 )
        {
          if ( ((_BYTE)v4[499] & 2) != 0 && !*((_DWORD *)v5 + 366) )
          {
            v30 = _ReadStatusReg(SP_EL0);
            printk(&unk_828E9, *(unsigned int *)(v30 + 1800), *(unsigned int *)(v30 + 1804), "warn");
          }
          v9 = msm_cvp_noc_error_info(v2);
        }
        else
        {
          for ( i = *(_QWORD **)(v2 + 280); i != (_QWORD *)(v2 + 280); i = (_QWORD *)*i )
            v9 = ((__int64 (__fastcall *)(_QWORD *, __int64))msm_cvp_print_inst_bufs)(i, 1);
        }
        if ( (msm_cvp_sw_dbg_buf_dump & 1) != 0 )
        {
          v14 = eva_kmd_debug_log_dump(v9);
          eva_cmd_msg_queue_dump(v14);
        }
        v15 = *(_QWORD *)(v2 + 280);
        if ( v15 != v2 + 280 )
        {
          v3 = (char ***)&unk_3468;
          v40 = _ReadStatusReg(SP_EL0);
          do
          {
            cvp_print_inst(1, v15);
            if ( *(_DWORD *)(v15 + 328) != 9 )
            {
              raw_spin_lock(v15 + 176);
              *(_DWORD *)(v15 + 15260) = cvp_error_count | 0x10010000;
              raw_spin_unlock(v15 + 176);
              change_cvp_inst_state(v15, 9u);
              if ( (msm_cvp_sw_dbg_buf_dump & 1) != 0 )
                ((void (__fastcall *)(__int64))eva_kmd_session_dump)(v15);
              if ( (unsigned int)cvp_clean_session_queues(v15) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_8EE0A, *(unsigned int *)(v40 + 1800), *(unsigned int *)(v40 + 1804), &unk_8E7CE);
              complete(v15 + 12936);
              complete(v15 + 12968);
              complete(v15 + 13000);
              complete(v15 + 13032);
              complete(v15 + 13064);
              complete(v15 + 13096);
              complete(v15 + 13128);
              complete(v15 + 13160);
              complete(v15 + 13192);
              complete(v15 + 13224);
              complete(v15 + 13256);
              complete(v15 + 13288);
              complete(v15 + 13320);
              complete(v15 + 13352);
              complete(v15 + 13384);
              complete(v15 + 13416);
              complete(v15 + 13448);
              complete(v15 + 13480);
              complete(v15 + 13512);
              complete(v15 + 13544);
              v16 = raw_spin_lock_irqsave(v15 + 288);
              *(_DWORD *)(v15 + 292) = 1;
              raw_spin_unlock_irqrestore(v15 + 288, v16);
              _wake_up(v15 + 296, 3, 0, 0);
            }
            if ( (*(_BYTE *)(v2 + 1268) & 1) == 0 && *((_DWORD *)v8 + 8) != -2147483629 )
              ((void (__fastcall *)(__int64, _QWORD))msm_cvp_print_inst_bufs)(v15, 0);
            v15 = *(_QWORD *)v15;
          }
          while ( v15 != v2 + 280 );
        }
        for ( j = (__int64 *)qword_6CF48; j != &qword_6CF48; j = (__int64 *)*j )
        {
          if ( (*(_BYTE *)(v2 + 1268) & 1) == 0 && *((_DWORD *)v8 + 8) != -2147483629 )
            msm_cvp_print_frpc_bufs((__int64)j, 1, 0);
        }
        if ( *(_BYTE *)(v2 + 1268) == 1 )
        {
          v4 = v42;
          *(_BYTE *)(v2 + 1268) = 0;
          v8 = off_6C000;
          v5 = (char **)&unk_1000;
        }
        else
        {
          v4 = v42;
          v8 = off_6C000;
          v5 = (char **)&unk_1000;
          if ( *(_BYTE *)(v2 + 984) )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v31 = _ReadStatusReg(SP_EL0);
              printk(&unk_8E7D2, *(unsigned int *)(v31 + 1800), *(unsigned int *)(v31 + 1804), &unk_8E7CE);
            }
            __break(0x800u);
          }
        }
        if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_8A1E7, "core", v10, v11);
          if ( !v4 )
            goto LABEL_77;
        }
        else if ( !v4 )
        {
          goto LABEL_77;
        }
        v26 = v4[2];
        if ( v26 )
        {
          v27 = *v4;
          if ( *((_DWORD *)v26 - 1) != -1066802076 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(char **))v26)(v27) )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v32 = _ReadStatusReg(SP_EL0);
              printk(&unk_851C6, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
            }
            *(_DWORD *)(v2 + 304) = v41;
            mutex_unlock(v2 + 48);
            goto LABEL_75;
          }
        }
LABEL_77:
        mutex_unlock(v2 + 48);
        v9 = mutex_unlock(v2);
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v29 = _ReadStatusReg(SP_EL0);
          v9 = printk(&unk_864E9, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), "warn");
        }
        if ( *(_BYTE *)(v2 + 1045) != 1 )
          return;
        __break(0x800u);
LABEL_83:
        _X8 = &cvp_error_count;
        __asm { PRFM            #0x11, [X8] }
        do
          v39 = __ldxr((unsigned int *)&cvp_error_count);
        while ( __stxr(v39 + 1, (unsigned int *)&cvp_error_count) );
      }
    }
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v24 = _ReadStatusReg(SP_EL0);
      printk(&unk_878FB, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), "warn");
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v23 = _ReadStatusReg(SP_EL0);
    printk(&unk_8F88C, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
  }
LABEL_75:
  mutex_unlock(v2);
}
