__int64 __fastcall dp_connector_get_info(__int64 a1, __int64 a2, __int64 a3)
{
  void (__fastcall *v5)(__int64, char **); // x8
  const char *v6; // x21
  int v7; // w22
  char v8; // w8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  s1[0] = nullptr;
  if ( a2 && a3 && *(_QWORD *)a3 )
  {
    *(_DWORD *)a2 = 10;
    v5 = *(void (__fastcall **)(__int64, char **))(a3 + 320);
    if ( *((_DWORD *)v5 - 1) != 988268915 )
      __break(0x8228u);
    v5(a3, s1);
    v6 = s1[0];
    if ( s1[0] )
    {
      v7 = 1;
      if ( strcmp(s1[0], "primary") )
      {
        if ( !strcmp(v6, "secondary") )
          v7 = 2;
        else
          v7 = 1;
      }
    }
    else
    {
      v7 = 1;
    }
    *(_QWORD *)(a2 + 12) = 1;
    v8 = *(_BYTE *)(a3 + 32);
    *(_QWORD *)(a2 + 4) = 0x100000009LL;
    *(_BYTE *)(a2 + 24) = v8;
    if ( *(_BYTE *)(a3 + 34) == 1 && (*(_DWORD *)(a2 + 56) = v7, *(_DWORD *)a2 = 14, *(_BYTE *)(a3 + 73) != 1) )
    {
      result = 0;
      *(_BYTE *)(a2 + 24) = 1;
    }
    else
    {
      result = 0;
      *(_DWORD *)(a2 + 4) = 13;
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24B695, "dp_connector_get_info");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
