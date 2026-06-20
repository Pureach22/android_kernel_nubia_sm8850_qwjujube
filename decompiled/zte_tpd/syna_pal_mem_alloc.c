__int64 __fastcall syna_pal_mem_alloc(int a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  void *v5; // x0

  v2 = syna_request_managed_device();
  if ( !v2 )
  {
    v5 = &unk_3BE43;
LABEL_7:
    printk(v5, "syna_pal_mem_alloc", v3);
    return 0;
  }
  if ( a1 <= 0 )
  {
    v5 = &unk_38286;
    goto LABEL_7;
  }
  return devm_kmalloc(v2, (unsigned int)a1, 3520);
}
