__int64 __fastcall gh_hvc_put_work_fn(__int64 a1)
{
  unsigned int *v1; // x23
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x2
  __int64 v6; // x3
  void *v7; // x0
  _DWORD *v8; // x20
  __int64 v9; // x22
  int v10; // w21
  unsigned __int16 v11; // [xsp+Ch] [xbp-F4h] BYREF
  _QWORD v12[28]; // [xsp+10h] [xbp-F0h] BYREF
  int v13; // [xsp+F0h] [xbp-10h]
  __int64 v14; // [xsp+F8h] [xbp-8h]

  v1 = (unsigned int *)(a1 - 2104);
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(a1 - 2104);
  v11 = 0;
  v13 = 0;
  memset(v12, 0, sizeof(v12));
  result = ghd_rm_get_vmid(v3, &v11);
  if ( (_DWORD)result )
  {
    if ( (gh_hvc_put_work_fn___already_done & 1) == 0 )
    {
      v5 = *v1;
      v6 = (unsigned int)result;
      gh_hvc_put_work_fn___already_done = 1;
      v7 = &unk_95BA;
LABEL_4:
      result = printk(v7, "gh_hvc_put_work_fn", v5, v6);
    }
  }
  else
  {
    v8 = (_DWORD *)(a1 - 1048);
    if ( *(_DWORD *)(a1 - 1048) != *(_DWORD *)(a1 - 1044) )
    {
      while ( 1 )
      {
        v9 = raw_spin_lock_irqsave(&fifo_lock);
        v10 = _kfifo_out(v8, v12, 228);
        result = raw_spin_unlock_irqrestore(&fifo_lock, v9);
        if ( v10 > 0 )
        {
          result = gh_rm_console_write(v11, v12, (unsigned int)v10);
          if ( (_DWORD)result )
            break;
        }
        if ( *v8 == *(_DWORD *)(a1 - 1044) )
          goto LABEL_11;
      }
      if ( (gh_hvc_put_work_fn___already_done_1 & 1) == 0 )
      {
        v5 = *v1;
        v6 = (unsigned int)result;
        v7 = &unk_95EE;
        gh_hvc_put_work_fn___already_done_1 = 1;
        goto LABEL_4;
      }
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
