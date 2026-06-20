__int64 __fastcall hfi_adapter_buffer_dealloc(__int64 a1)
{
  __int64 result; // x0
  unsigned int v2; // w19

  if ( !*(_DWORD *)(a1 + 16) )
    return 0;
  if ( *(_QWORD *)(a1 + 40) && *(_QWORD *)(a1 + 32) )
  {
    result = hfi_core_deallocate_shared_mem(a1 + 24);
    if ( (_DWORD)result )
    {
      v2 = result;
      printk(&unk_27330B, "hfi_adapter_buffer_dealloc");
      return v2;
    }
  }
  else
  {
    printk(&unk_26FBC3, "hfi_adapter_buffer_dealloc");
    return 4294967274LL;
  }
  return result;
}
