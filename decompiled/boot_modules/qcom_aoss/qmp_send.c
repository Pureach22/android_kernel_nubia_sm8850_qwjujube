__int64 __fastcall qmp_send(unsigned __int64 a1, char *format, int a3, int a4, int a5, int a6, int a7, int a8, char a9)
{
  unsigned int v11; // w20
  unsigned int v12; // w0
  unsigned int v13; // w21
  __int64 v14; // x22
  int v15; // w0
  __int64 i; // x24
  __int64 v17; // x25
  __int64 v18; // x26
  int v19; // w0
  int v20; // w0
  int v21; // w8
  bool v22; // zf
  __int64 v23; // x0
  char *arg; // [xsp+38h] [xbp-B8h] BYREF
  char **v26; // [xsp+40h] [xbp-B0h]
  __int64 v27; // [xsp+48h] [xbp-A8h]
  __int64 v28; // [xsp+50h] [xbp-A0h]
  __int64 v29; // [xsp+58h] [xbp-98h]
  char *v30; // [xsp+60h] [xbp-90h]
  char **p_arg; // [xsp+68h] [xbp-88h]
  __int64 v32; // [xsp+70h] [xbp-80h]
  __int64 v33; // [xsp+78h] [xbp-78h]
  char s[8]; // [xsp+80h] [xbp-70h] BYREF
  __int64 v35; // [xsp+88h] [xbp-68h]
  __int64 v36; // [xsp+90h] [xbp-60h]
  __int64 v37; // [xsp+98h] [xbp-58h]
  __int64 v38; // [xsp+A0h] [xbp-50h]
  __int64 v39; // [xsp+A8h] [xbp-48h]
  __int64 v40; // [xsp+B0h] [xbp-40h]
  __int64 v41; // [xsp+B8h] [xbp-38h]
  __int64 v42; // [xsp+C0h] [xbp-30h]
  __int64 v43; // [xsp+C8h] [xbp-28h]
  __int64 v44; // [xsp+D0h] [xbp-20h]
  __int64 v45; // [xsp+D8h] [xbp-18h]
  int v46; // [xsp+E0h] [xbp-10h]
  __int64 v47; // [xsp+E8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v30 = nullptr;
  p_arg = nullptr;
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && format )
  {
    if ( (*(_BYTE *)(a1 + 248) & 1) != 0 )
    {
      v11 = -6;
    }
    else
    {
      v46 = 0;
      v44 = 0;
      v45 = 0;
      v42 = 0;
      v43 = 0;
      v40 = 0;
      v41 = 0;
      v38 = 0;
      v39 = 0;
      v36 = 0;
      v37 = 0;
      *(_QWORD *)s = 0;
      v35 = 0;
      v30 = &a9;
      p_arg = &arg;
      v33 = 4294967248LL;
      arg = &a9;
      v26 = &arg;
      v27 = v32;
      v28 = 4294967248LL;
      v12 = vsnprintf(s, 0x64u, format, &arg);
      if ( v12 >= 0x64 )
      {
        __break(0x800u);
        v11 = -22;
      }
      else
      {
        v13 = v12;
        mutex_lock(a1 + 120);
        _iowrite32_copy_full(*(_QWORD *)a1 + *(_QWORD *)(a1 + 80) + 4LL, s, 25);
        writel(100, *(_QWORD *)a1 + *(_QWORD *)(a1 + 80));
        readl(*(_QWORD *)a1 + *(_QWORD *)(a1 + 80));
        mbox_send_message(*(_QWORD *)(a1 + 72), 0);
        mbox_client_txdone(*(_QWORD *)(a1 + 72), 0);
        ipc_log_string(ilc, "[%s]: msg: %.*s\n", "qmp_send", v13, format);
        v14 = ilc;
        v15 = readl(*(_QWORD *)a1 + *(_QWORD *)(a1 + 80));
        ipc_log_string(v14, "[%s]: ack msg size: %u\n", "qmp_message_empty", v15);
        if ( (unsigned int)readl(*(_QWORD *)a1 + *(_QWORD *)(a1 + 80)) )
        {
          v28 = 0;
          v29 = 0;
          v26 = nullptr;
          v27 = 0;
          arg = nullptr;
          init_wait_entry(&arg, 0);
          for ( i = 250; ; i = schedule_timeout() )
          {
            v17 = prepare_to_wait_event(a1 + 96, &arg, 1);
            v18 = ilc;
            v19 = readl(*(_QWORD *)a1 + *(_QWORD *)(a1 + 80));
            ipc_log_string(v18, "[%s]: ack msg size: %u\n", "qmp_message_empty", v19);
            v20 = readl(*(_QWORD *)a1 + *(_QWORD *)(a1 + 80));
            v21 = v20;
            v22 = !i && v20 == 0;
            v23 = v22 ? 1LL : i;
            if ( !v21 || !v23 )
              break;
            if ( v17 )
              goto LABEL_20;
          }
          v17 = v23;
          finish_wait(a1 + 96, &arg);
          if ( !v17 )
          {
            dev_err(*(_QWORD *)(a1 + 8), "ucore did not ack channel\n");
            ipc_log_string(ilc, "[%s]: timed out clearing msg: %.*s\n", "qmp_send", v13, format);
            writel(0, *(_QWORD *)a1 + *(_QWORD *)(a1 + 80));
            v11 = -110;
            goto LABEL_22;
          }
LABEL_20:
          if ( (v17 & 0x8000000000000000LL) == 0 )
            goto LABEL_21;
          dev_err(*(_QWORD *)(a1 + 8), "wait error %ld\n", v17);
          v11 = v17;
        }
        else
        {
LABEL_21:
          ipc_log_string(ilc, "[%s]: ack: %.*s\n", "qmp_send", v13, format);
          v11 = 0;
        }
LABEL_22:
        mutex_unlock(a1 + 120);
      }
    }
  }
  else
  {
    __break(0x800u);
    v11 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
