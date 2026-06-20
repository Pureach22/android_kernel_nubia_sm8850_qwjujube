__int64 __fastcall hfi_util_kv_helper_get_payload_addr(__int64 a1)
{
  if ( a1 && *(_DWORD *)(a1 + 4) )
    return a1 + 16;
  printk(&unk_248BE9, "hfi_util_kv_helper_get_payload_addr");
  return 0;
}
