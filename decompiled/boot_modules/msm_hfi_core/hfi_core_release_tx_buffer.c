__int64 __fastcall hfi_core_release_tx_buffer(unsigned int *a1, _QWORD *a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30

  if ( a1 && a2 )
    return put_tx_buffer(drv_data, *a1, a2, a3, a5);
  printk(&unk_1905C, "hfi_core_release_tx_buffer", 378, v5, a5);
  return 4294967274LL;
}
