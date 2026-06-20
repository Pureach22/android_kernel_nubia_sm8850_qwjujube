__int64 __fastcall qiib_poll(__int64 a1, void (**a2)(void), __int64 a3)
{
  __int64 v3; // x21
  unsigned int v4; // w19
  void (*v5)(void); // x8
  __int64 v6; // x0
  int v7; // w4
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x0

  v3 = *(_QWORD *)(a1 + 32);
  if ( v3 )
  {
    if ( (*(_BYTE *)(v3 + 256) & 1) != 0 )
    {
      return 0x2000;
    }
    else
    {
      if ( a2 )
      {
        v5 = *a2;
        if ( *a2 )
        {
          if ( *((_DWORD *)v5 - 1) != -442429149 )
            __break(0x8228u);
          v5();
          __dmb(0xBu);
        }
      }
      v6 = raw_spin_lock_irqsave(v3 + 208);
      v7 = *(_DWORD *)(v3 + 204);
      v8 = v6;
      if ( v7 )
      {
        v9 = *(_QWORD *)(qiib_info + 88);
        if ( v9 )
          ipc_log_string(v9, "%s set POLLIN on [%s] count[%d]\n", "qiib_poll", *(const char **)(v3 + 24), v7);
        v4 = 1;
        *(_DWORD *)(v3 + 204) = 0;
      }
      else
      {
        v4 = 0;
      }
      raw_spin_unlock_irqrestore(v3 + 208, v8);
      if ( *(_BYTE *)(v3 + 256) == 1 )
      {
        v4 |= 0x2000u;
        v10 = *(_QWORD *)(qiib_info + 88);
        if ( v10 )
          ipc_log_string(
            v10,
            "%s set POLLRDHUP on [%s] count[%d]\n",
            "qiib_poll",
            *(const char **)(v3 + 24),
            *(_DWORD *)(v3 + 204));
      }
    }
  }
  else
  {
    printk(&unk_7670, "qiib_poll", a3);
    ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s on NULL device\n", "qiib_poll");
    return 8;
  }
  return v4;
}
