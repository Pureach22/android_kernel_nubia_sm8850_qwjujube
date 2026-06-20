__int64 __fastcall hfi_util_kv_helper_reset(unsigned int *a1)
{
  size_t v1; // x2

  if ( a1 )
  {
    v1 = *a1;
    a1[1] = 0;
    memset(a1 + 4, 0, v1);
    return 0;
  }
  else
  {
    printk(&unk_2733C5, "hfi_util_kv_helper_reset");
    return 4294967274LL;
  }
}
