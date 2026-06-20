__int64 __fastcall cvp_fence_thread(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x19
  __int64 v7; // x8
  unsigned int v8; // w25
  __int64 v9; // x24
  __int64 *v10; // x28
  __int64 v11; // x24
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x21
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 (__fastcall *v17)(__int64, __int64, __int64 *, int *); // x8
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // x0
  int v20; // w8
  bool v21; // zf
  __int64 (__fastcall *v22)(__int64, __int64, __int64 *, int *); // x8
  void (__fastcall *v23)(__int64, __int64 *); // x8
  __int64 **v24; // x8
  __int64 *v25; // x9
  int v26; // w21
  __int64 *v28; // [xsp+18h] [xbp-168h] BYREF
  int v29; // [xsp+20h] [xbp-160h] BYREF
  int v30; // [xsp+24h] [xbp-15Ch] BYREF
  __int64 v31; // [xsp+28h] [xbp-158h] BYREF
  _QWORD s[42]; // [xsp+30h] [xbp-150h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = _ReadStatusReg(SP_EL0);
  s[40] = *(_QWORD *)(StatusReg + 1808);
  v29 = 0;
  if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_9510F, "synx", v6 + 2320, a4);
    if ( !a1 )
      goto LABEL_81;
  }
  else if ( !a1 )
  {
    goto LABEL_81;
  }
  v7 = *(_QWORD *)(a1 + 128);
  if ( v7 && *(_QWORD *)(v7 + 256) )
  {
    v8 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
          printk(&unk_894DC, "synx", v6 + 2320, a4);
        v28 = nullptr;
        if ( (cvp_fence_wait(a1 + 15272, &v28, &v29) & 1) == 0 )
        {
          memset(s, 0, 40);
          init_wait_entry(s, 0);
          while ( 1 )
          {
            v9 = prepare_to_wait_event(a1 + 15344, s, 1);
            if ( (cvp_fence_wait(a1 + 15272, &v28, &v29) & 1) != 0 )
              break;
            if ( v9 )
              goto LABEL_16;
            schedule();
          }
          finish_wait(a1 + 15344, s);
        }
LABEL_16:
        if ( v29 != 2 )
          goto LABEL_83;
        v10 = v28;
        if ( v28 )
          break;
        usleep_range_state(100, 200, 2);
      }
      v11 = v28[38];
      if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
        printk(&unk_91582, "synx", v6 + 2320, *(unsigned int *)(v11 + 4));
      v31 = 0;
      v30 = 2;
      memset(s, 0, 0x13Cu);
      if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_8F5D7, "synx", v6 + 2320, "cvp_fence_proc");
        v12 = *(_QWORD *)(a1 + 128);
        if ( v12 )
        {
LABEL_25:
          v13 = *((_DWORD *)v10 + 7);
          v14 = *(_QWORD *)(v12 + 256);
          v31 = *(_QWORD *)(v11 + 32);
          if ( v13 == -1329939778 )
            goto LABEL_26;
          v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, int *))(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL)
                                                                             + 32LL);
          if ( *((_DWORD *)v17 - 1) != 1433238509 )
            __break(0x8228u);
          v8 = v17(a1, 1, v10, &v30);
          if ( v8 )
          {
            msm_cvp_unmap_frame(a1, *(_QWORD *)(v11 + 32));
            goto LABEL_63;
          }
          if ( v14 && (v18 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 88)) != nullptr )
          {
            v19 = *(_QWORD *)(a1 + 320);
            if ( *((_DWORD *)v18 - 1) != -1882757197 )
              __break(0x8228u);
            v8 = v18(v19, v11);
          }
          else
          {
            v8 = 0;
          }
          if ( v8 )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_915BC, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
LABEL_61:
            v20 = 4;
            goto LABEL_62;
          }
          v12 = *(_QWORD *)(a1 + 128);
LABEL_26:
          v15 = _msecs_to_jiffies(*(unsigned int *)(v12 + 1024));
          v16 = cvp_wait_process_message(a1, a1 + 232, &v31, v15, s);
          if ( v16 )
          {
            v8 = v16;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_84F0E, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
            goto LABEL_61;
          }
          v8 = s[8];
          if ( LODWORD(s[8]) )
          {
            if ( LODWORD(s[8]) != 4107 )
            {
              if ( LODWORD(s[8]) == 4123 )
              {
                if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
                  printk(&unk_923B2, "synx", v6 + 2320, "cvp_fence_proc");
              }
              else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              {
                printk(&unk_8BE19, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
              }
              v8 = 0;
              goto LABEL_61;
            }
            if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
              printk(&unk_8DE69, "info", v6 + 2320, "cvp_fence_proc");
            v8 = 0;
            v20 = 2;
LABEL_62:
            v30 = v20;
          }
LABEL_63:
          v21 = *((_DWORD *)v10 + 7) == -17958194;
          v10[39] = (__int64)s;
          if ( v21 )
          {
            v22 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, int *))(*(_QWORD *)(*(_QWORD *)(a1 + 128)
                                                                                           + 272LL)
                                                                               + 32LL);
            if ( *((_DWORD *)v22 - 1) != 1433238509 )
              __break(0x8228u);
            v8 = v22(a1, 2, v10, &v30);
          }
          goto LABEL_68;
        }
      }
      else
      {
        v12 = *(_QWORD *)(a1 + 128);
        if ( v12 )
          goto LABEL_25;
      }
      v8 = -22;
LABEL_68:
      mutex_lock(a1 + 15272);
      v23 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 272LL) + 16LL);
      if ( *((_DWORD *)v23 - 1) != -746362046 )
        __break(0x8228u);
      v23(a1, v10);
      v24 = (__int64 **)v10[1];
      if ( *v24 == v10 && (v25 = (__int64 *)*v10, *(__int64 **)(*v10 + 8) == v10) )
      {
        v25[1] = (__int64)v24;
        *v24 = v25;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
      }
      *v10 = (__int64)v10;
      v10[1] = (__int64)v10;
      v26 = *(_DWORD *)(a1 + 15320);
      v29 = v26;
      mutex_unlock(a1 + 15272);
      if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
        printk(&unk_8C6EF, "synx", v6 + 2320, *(unsigned int *)(v11 + 4));
      kfree(v10[38]);
      v10[38] = 0;
      kfree(v10);
      if ( v8 && v26 != 2 )
        goto LABEL_83;
    }
  }
LABEL_81:
  v8 = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_894AF, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
    if ( (msm_cvp_debug & 0x80) == 0 )
      goto LABEL_86;
  }
  else
  {
LABEL_83:
    if ( (msm_cvp_debug & 0x80) == 0 )
      goto LABEL_86;
  }
  if ( !msm_cvp_debug_out )
    printk(&unk_8DE50, "synx", v6 + 2320, a4);
LABEL_86:
  cvp_put_inst(a1);
  _ReadStatusReg(SP_EL0);
  return v8;
}
