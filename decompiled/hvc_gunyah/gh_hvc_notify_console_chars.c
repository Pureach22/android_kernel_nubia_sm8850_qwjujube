__int64 __fastcall gh_hvc_notify_console_chars(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  unsigned __int64 v3; // x27
  __int64 v4; // x0
  unsigned int vm_name; // w0
  unsigned int v7; // w20
  __int64 v8; // x3
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x21
  unsigned int v12; // w20
  __int64 v13; // x3
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 != 1443889280 )
  {
    result = 0;
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v4 = *a3;
  v14 = 0;
  vm_name = gh_rm_get_vm_name(v4, &v14);
  if ( vm_name )
  {
    v7 = vm_name;
    if ( (unsigned int)__ratelimit(&gh_hvc_notify_console_chars__rs, "gh_hvc_notify_console_chars") )
      printk(&unk_970D, *a3, v7, v8);
LABEL_16:
    result = 1;
    goto LABEL_17;
  }
  v10 = raw_spin_lock_irqsave(&fifo_lock);
  if ( v14 < 5 )
  {
    v11 = v10;
    v12 = _kfifo_in(&gh_hvc_data[268 * v14 + 2], a3 + 2, a3[1]);
    v10 = raw_spin_unlock_irqrestore(&fifo_lock, v11);
    if ( (v12 & 0x80000000) != 0 )
    {
      v10 = __ratelimit(&gh_hvc_notify_console_chars__rs_7, "gh_hvc_notify_console_chars");
      if ( (_DWORD)v10 )
        v10 = printk(&unk_9737, a3[1], v14, v12);
    }
    else if ( v12 < a3[1] )
    {
      v10 = __ratelimit(&gh_hvc_notify_console_chars__rs_9, "gh_hvc_notify_console_chars");
      if ( (_DWORD)v10 )
        v10 = printk(&unk_968C, a3[1] - v12, v14, v13);
    }
    if ( v14 <= 4 )
    {
      if ( (unsigned int)hvc_poll(gh_hvc_data[268 * v14]) )
        hvc_kick();
      goto LABEL_16;
    }
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return gh_hvc_vm_state(v10);
}
