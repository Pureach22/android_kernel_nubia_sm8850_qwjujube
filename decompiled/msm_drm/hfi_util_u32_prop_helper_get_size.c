__int64 __fastcall hfi_util_u32_prop_helper_get_size(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 8);
    if ( v1 )
      return (unsigned int)(v1 - a1 - 16);
  }
  printk(&unk_261BFB, "hfi_util_u32_prop_helper_get_size");
  return 0;
}
