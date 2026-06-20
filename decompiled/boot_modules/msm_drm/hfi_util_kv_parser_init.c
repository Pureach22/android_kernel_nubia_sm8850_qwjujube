__int64 __fastcall hfi_util_kv_parser_init(_QWORD *a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0

  if ( a2 <= 0x1000 && a1 && a3 )
  {
    if ( (a2 & 3) != 0 )
    {
      printk(&unk_2768CC, "hfi_util_kv_parser_init");
      return 4294967274LL;
    }
    else
    {
      result = 0;
      a1[1] = a3;
      *a1 = a2 >> 2;
    }
  }
  else
  {
    printk(&unk_237DF5, "hfi_util_kv_parser_init");
    return 4294967274LL;
  }
  return result;
}
