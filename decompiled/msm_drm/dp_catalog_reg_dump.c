__int64 __fastcall dp_catalog_reg_dump(__int64 a1, const char *a2, _QWORD *a3, _DWORD *a4)
{
  _QWORD *v4; // x21
  void (__fastcall *v9)(_QWORD); // x8
  _DWORD *v10; // x8
  __int64 v11; // x0
  void *v12; // x22
  __int64 v13; // x25
  size_t v14; // x23
  __int64 v15; // x21
  size_t v16; // x24
  _DWORD *v17; // x25
  int v18; // w0
  __int64 ipc_log_context; // x0
  __int64 v21; // x0
  unsigned int v22; // w19
  __int64 v23; // x0
  void (__fastcall *v24)(_QWORD); // x8

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_reg_dump");
    return 4294967274LL;
  }
  v4 = *(_QWORD **)(a1 - 32);
  v9 = (void (__fastcall *)(_QWORD))v4[107];
  if ( *((_DWORD *)v9 - 1) != -1887062843 )
    __break(0x8228u);
  v9(v4);
  v10 = (_DWORD *)v4[106];
  if ( *(v10 - 1) != -816176389 )
    __break(0x8228u);
  v11 = ((__int64 (__fastcall *)(_QWORD *, const char *))v10)(v4, a2);
  if ( v11 )
  {
    v12 = *(void **)(v11 + 8);
    v13 = v11;
    if ( v12 )
    {
      v14 = *(unsigned int *)(v11 + 16);
      if ( (_DWORD)v14 )
      {
        if ( *(_BYTE *)(a1 + 1224) == 104 && *(_BYTE *)(a1 + 1225) == 119 && !*(_BYTE *)(a1 + 1226)
          || !strcmp((const char *)(a1 + 1224), "all") )
        {
          v15 = *(_QWORD *)(v13 + 24);
          memset(v12, 0, v14);
          if ( (unsigned int)v14 >= 4 )
          {
            v16 = v14 >> 2;
            v17 = v12;
            do
            {
              v18 = readl_relaxed_0(v15);
              --v16;
              v15 += 4;
              *v17++ = v18;
            }
            while ( v16 );
          }
        }
        *a3 = v12;
        *a4 = v14;
        return 0;
      }
    }
    v23 = get_ipc_log_context(v11);
    ipc_log_string(v23, "[e][%-4d]no buffer available\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_226316, "dp_catalog_reg_dump");
    v22 = -12;
  }
  else
  {
    v21 = get_ipc_log_context(0);
    ipc_log_string(v21, "[e][%-4d]IO %s not found\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), a2);
    printk(&unk_255E78, "dp_catalog_reg_dump");
    v22 = -22;
  }
  v24 = (void (__fastcall *)(_QWORD))v4[108];
  if ( *((_DWORD *)v24 - 1) != 680055959 )
    __break(0x8228u);
  v24(v4);
  return v22;
}
