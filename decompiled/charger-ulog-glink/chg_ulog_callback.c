__int64 __fastcall chg_ulog_callback(_BYTE *a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x2
  int v7; // w8
  bool v8; // zf
  __int64 v9; // x8
  __int64 v10; // x20
  char *v11; // x0
  char *v12; // x2
  char *v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned int *)(a2 + 8);
  if ( (_DWORD)v5 == 24 || (_DWORD)v5 == 35 )
  {
    if ( a3 == 8204 )
    {
      memcpy(a1 + 224, (const void *)(a2 + 12), 0x2000u);
      v7 = *(_DWORD *)(a2 + 8);
      v14[0] = a1 + 224;
      v8 = v7 == 35;
      v9 = 24;
      if ( v8 )
        v9 = 32;
      v10 = *(_QWORD *)&a1[v9];
      if ( a1[224] )
      {
        a1[8415] = 0;
        v11 = strsep(v14, "\n");
        if ( v11 )
        {
          v12 = v11;
          do
          {
            ipc_log_string(v10, &unk_6E8F, v12);
            v12 = strsep(v14, "\n");
          }
          while ( v12 );
        }
      }
      else if ( a1[8433] == 1 )
      {
        a1[8433] = 0;
      }
    }
    else
    {
      printk(&unk_6DE0, "handle_ulog_message", 8204);
    }
    goto LABEL_16;
  }
  if ( (_DWORD)v5 == 25 )
  {
LABEL_16:
    complete(a1 + 88);
    goto LABEL_17;
  }
  printk(&unk_7008, "chg_ulog_callback", v5);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return 0;
}
