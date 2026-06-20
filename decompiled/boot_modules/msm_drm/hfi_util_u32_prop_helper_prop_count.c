__int64 __fastcall hfi_util_u32_prop_helper_prop_count(__int64 a1)
{
  if ( a1 && *(_QWORD *)(a1 + 8) )
    return *(unsigned int *)(a1 + 4);
  printk(&unk_261BFB, "hfi_util_u32_prop_helper_prop_count");
  return 0;
}
