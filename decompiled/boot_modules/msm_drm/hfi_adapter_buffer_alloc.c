__int64 __fastcall hfi_adapter_buffer_alloc(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x1
  unsigned int shared_mem; // w0
  __int64 v5; // x8
  __int64 v6; // x9
  void *v8; // x0
  unsigned int v9; // w19

  v1 = *(_DWORD *)(a1 + 16);
  if ( !v1 )
  {
    v8 = &unk_22DC10;
LABEL_10:
    printk(v8, "hfi_adapter_buffer_alloc");
    return 4294967274LL;
  }
  v3 = (v1 + 4095) & 0xFFFFF000;
  *(_DWORD *)(a1 + 20) = v3;
  shared_mem = hfi_core_allocate_shared_mem(a1 + 24, v3, 1, 3);
  if ( shared_mem )
  {
    v9 = shared_mem;
    printk(&unk_2732C9, "hfi_adapter_buffer_alloc");
    return v9;
  }
  v5 = *(_QWORD *)(a1 + 32);
  v6 = *(_QWORD *)(a1 + 40);
  *(_QWORD *)a1 = v6;
  *(_QWORD *)(a1 + 8) = v5;
  if ( !v6 || !v5 )
  {
    v8 = &unk_23B4C1;
    goto LABEL_10;
  }
  return 0;
}
