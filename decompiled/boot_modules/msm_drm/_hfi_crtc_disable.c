__int64 __fastcall hfi_crtc_disable(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  _DWORD *payload_addr; // x21
  unsigned int size; // w0

  if ( !a3 || !a4 )
    return printk(&unk_25E18E, "_hfi_crtc_disable");
  v4 = *(_QWORD *)(a3 + 8032);
  mutex_lock(v4 + 8);
  hfi_util_u32_prop_helper_reset(*(unsigned int **)(v4 + 56));
  payload_addr = hfi_util_u32_prop_helper_get_payload_addr(*(_DWORD **)(v4 + 56));
  size = hfi_util_u32_prop_helper_get_size(*(_QWORD *)(v4 + 56));
  if ( (unsigned int)hfi_adapter_add_set_property(a1, 33554433, a2, 2u, (__int64)payload_addr, size, 4) )
    printk(&unk_273493, "_hfi_crtc_disable");
  return mutex_unlock(v4 + 8);
}
