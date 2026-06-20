_DWORD *__fastcall hfi_util_u32_prop_helper_get_payload_addr(_DWORD *a1)
{
  if ( a1 && *a1 )
    return a1 + 4;
  printk(&unk_261BFB, "hfi_util_u32_prop_helper_get_payload_addr");
  return nullptr;
}
