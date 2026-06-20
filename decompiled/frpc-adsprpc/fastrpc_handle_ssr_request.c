__int64 __fastcall fastrpc_handle_ssr_request(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  unsigned int v8; // w0
  __int64 v9; // x4
  __int64 v10; // x5
  unsigned int v11; // w0
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x2
  void *v15; // x0

  v6 = *(_QWORD *)(a1 + 32);
  if ( !v6 )
    return printk(&unk_23BF4, "fastrpc_handle_ssr_request", *(unsigned int *)(a1 + 40), a4, a5, a6);
  v8 = rproc_shutdown(*(_QWORD *)(a1 + 32));
  if ( v8 )
  {
    v14 = v8;
    v15 = &unk_23FF8;
  }
  else
  {
    v11 = rproc_boot(v6);
    if ( !v11 )
      return printk(&unk_242B4, "fastrpc_handle_ssr_request", v12, v13, v9, v10);
    v14 = v11;
    v15 = &unk_259D9;
  }
  return printk(v15, "fastrpc_handle_ssr_request", v14, v6, v9, v10);
}
