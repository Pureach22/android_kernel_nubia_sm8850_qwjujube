__int64 __fastcall hfi_crtc_destroy(__int64 a1)
{
  _QWORD *v1; // x19

  if ( !a1 )
    return printk(&unk_25E167, "hfi_crtc_destroy");
  v1 = *(_QWORD **)(a1 + 8032);
  if ( (unsigned int)hfi_adapter_buffer_dealloc((__int64)(v1 + 11)) )
    printk(&unk_268870, "hfi_crtc_destroy");
  kfree(v1[7]);
  kfree(v1[8]);
  kfree(v1[9]);
  return kfree(v1);
}
