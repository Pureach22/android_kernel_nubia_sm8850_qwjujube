__int64 __fastcall hfi_kms_init(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = _kvmalloc_node_noprof(192, 0, 3520, 0xFFFFFFFFLL);
  if ( v2 )
  {
    v3 = _kvmalloc_node_noprof(516, 0, 3520, 0xFFFFFFFFLL);
    if ( v3 )
    {
      *(_QWORD *)(v2 + 184) = v3;
      *(_DWORD *)(v2 + 176) = 0;
      *(_QWORD *)(a1 + 6440) = v2;
      memcpy((void *)(a1 + 6448), &hfi_hal_funcs, 0x1E0u);
      *(_QWORD *)v2 = a1;
      return 0;
    }
  }
  else
  {
    printk(&unk_27350F, "hfi_kms_init");
  }
  return 4294967284LL;
}
