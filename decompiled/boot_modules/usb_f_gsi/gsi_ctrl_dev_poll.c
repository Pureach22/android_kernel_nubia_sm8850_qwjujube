__int64 __fastcall gsi_ctrl_dev_poll(__int64 a1, _DWORD **a2)
{
  __int64 v2; // x23
  __int64 v3; // x22
  __int64 v4; // x19
  char *v6; // x21
  char v7; // w23
  __int64 v8; // x22
  _DWORD *v9; // x8
  __int64 v10; // x19
  unsigned int v11; // w20

  v2 = **(unsigned int **)(a1 + 32);
  if ( (unsigned int)v2 < 7 )
  {
    v3 = v2 << 6;
    v4 = a1;
    v6 = (char *)&inst_status + 64 * v2;
    a1 = mutex_lock(v6);
    if ( (((unsigned __int64)(unsigned int)v2 << 6) | 0x30) <= 0x180 )
    {
      v7 = v6[48];
      a1 = mutex_unlock(v6);
      if ( (v7 & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&gsi_ctrl_dev_poll__rs, "gsi_ctrl_dev_poll") )
        {
          printk(&unk_1045C, "gsi_ctrl_dev_poll");
          return 16;
        }
        return 16;
      }
      if ( (v3 | 0x38uLL) <= 0x180 )
      {
        v8 = *(_QWORD *)(*((_QWORD *)v6 + 7) + 176LL);
        if ( v8 != -1056 )
        {
          if ( a2 )
          {
            v9 = *a2;
            if ( *a2 )
            {
              if ( *(v9 - 1) != -442429149 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, __int64, _DWORD **))v9)(v4, v8 + 1240, a2);
              __dmb(0xBu);
            }
          }
          v10 = raw_spin_lock_irqsave(v8 + 1304);
          if ( *(_QWORD *)(v8 + 1264) == v8 + 1264 )
          {
            v11 = 0;
          }
          else
          {
            if ( v8 )
              ipc_log_string(
                *(_QWORD *)(v8 + 1344),
                "%s sets POLLIN for %s",
                "gsi_ctrl_dev_poll",
                (const char *)(v8 + 1056));
            v11 = 65;
          }
          raw_spin_unlock_irqrestore(v8 + 1304, v10);
          return v11;
        }
        return 16;
      }
    }
    __break(1u);
  }
  __break(0x5512u);
  return gsi_ctrl_dev_ioctl(a1);
}
