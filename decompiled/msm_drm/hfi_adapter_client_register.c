__int64 __fastcall hfi_adapter_client_register(__int64 a1, __int64 a2)
{
  __int64 v3; // x2
  bool v4; // zf
  _QWORD *v5; // x1
  int v6; // w0
  void *v8; // x0
  __int64 v9; // x9

  if ( !*(_QWORD *)(a2 + 112) )
  {
    v8 = &unk_26870B;
LABEL_12:
    printk(v8, "hfi_adapter_client_register");
    return 4294967274LL;
  }
  if ( !a1 )
  {
    v8 = &unk_237D3F;
    goto LABEL_12;
  }
  *(_QWORD *)(a2 + 64) = a2 + 64;
  v3 = a1 + 8;
  *(_QWORD *)(a2 + 72) = a2 + 64;
  v4 = a1 + 8 == a2;
  *(_QWORD *)(a2 + 80) = a2 + 80;
  *(_QWORD *)(a2 + 88) = a2 + 80;
  *(_QWORD *)(a2 + 120) = a1;
  v5 = *(_QWORD **)(a1 + 16);
  if ( v4 || v5 == (_QWORD *)a2 || *v5 != v3 )
  {
    _list_add_valid_or_report(a2, v5);
    a1 = v9;
  }
  else
  {
    *(_QWORD *)(a1 + 16) = a2;
    *(_QWORD *)a2 = v3;
    *(_QWORD *)(a2 + 8) = v5;
    *v5 = a2;
  }
  v6 = idr_alloc(a1 + 328, a2, 1, 0, 3264);
  *(_DWORD *)(a2 + 136) = v6;
  if ( v6 < 0 )
  {
    printk(&unk_22DB7F, "hfi_adapter_client_register");
    return 0xFFFFFFFFLL;
  }
  else
  {
    _mutex_init(a2 + 16, "&ctx->lock", &hfi_adapter_client_register___key);
    return 0;
  }
}
