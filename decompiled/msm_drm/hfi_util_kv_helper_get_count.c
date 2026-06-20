__int64 __fastcall hfi_util_kv_helper_get_count(__int64 a1)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 4);
  printk(&unk_2733C5, "hfi_util_kv_helper_get_count");
  return 0;
}
