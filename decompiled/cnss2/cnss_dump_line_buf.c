__int64 __fastcall cnss_dump_line_buf(char *a1, int a2, char a3)
{
  char *v6; // x0
  __int64 v7; // x7
  char *v8; // x21
  unsigned __int64 StatusReg; // x22
  const char *v10; // x1
  unsigned int v11; // w23
  unsigned int v13; // w0
  __int64 v14; // x7
  unsigned __int64 v15; // x8
  const char *v16; // x1
  int v17; // w9
  const char *v18; // x8
  char v19; // [xsp+0h] [xbp-20h]
  char v20; // [xsp+Ch] [xbp-14h]
  char *stringp[2]; // [xsp+10h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = a1;
  v6 = strsep(stringp, "\n");
  if ( v6 )
  {
    v8 = v6;
    v20 = a3;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( stringp[0] )
    {
      if ( *v8 )
      {
        v10 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v10 = "soft_irq";
          else
            v10 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(cnss_ipc_log_context, v10, "cnss_dump_line_buf", 7u, 7u, "%s\n", (__int64)v8, v7, v19);
      }
      v8 = strsep(stringp, "\n");
      if ( !v8 )
        goto LABEL_11;
    }
    v13 = strlen(v8);
    v11 = v13;
    if ( v13 )
    {
      if ( v8 - a1 < 4 || (v20 & 1) != 0 )
      {
        v15 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
        {
          v16 = "irq";
        }
        else
        {
          v17 = *(_DWORD *)(v15 + 16);
          v18 = (const char *)(v15 + 2320);
          if ( (v17 & 0xFF00) != 0 )
            v16 = "soft_irq";
          else
            v16 = v18;
        }
        cnss_debug_ipc_log_print(cnss_ipc_log_context, v16, "cnss_dump_line_buf", 7u, 7u, "%s\n", (__int64)v8, v14, v19);
      }
      else
      {
        memmove(a1, v8, v13);
      }
    }
  }
  else
  {
LABEL_11:
    v11 = 0;
  }
  memset(&a1[v11], 0, a2 - v11);
  _ReadStatusReg(SP_EL0);
  return v11;
}
