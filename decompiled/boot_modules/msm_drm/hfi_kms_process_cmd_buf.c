__int64 __fastcall hfi_kms_process_cmd_buf(_QWORD *a1, __int64 a2)
{
  _QWORD *v3; // x20
  __int64 result; // x0
  unsigned int v5; // w19

  if ( (_drm_debug & 4) != 0 )
  {
    v3 = a1;
    _drm_dev_dbg(0, 0, 0, "process cmd-buf called\n");
    a1 = v3;
  }
  if ( (unsigned int)hfi_adapter_unpack_cmd_buf(a1, a2) )
    printk(&unk_2206DA, "hfi_kms_process_cmd_buf");
  result = hfi_adapter_release_cmd_buf(a2);
  if ( (_DWORD)result )
  {
    v5 = result;
    printk(&unk_211EE2, "hfi_kms_process_cmd_buf");
    return v5;
  }
  return result;
}
