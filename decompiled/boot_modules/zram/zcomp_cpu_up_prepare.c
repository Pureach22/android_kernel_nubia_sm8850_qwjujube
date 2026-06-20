__int64 __fastcall zcomp_cpu_up_prepare(unsigned int a1, __int64 a2)
{
  __int64 *v2; // x19
  __int64 v3; // x0
  unsigned __int64 v4; // x1
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x21

  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &zcomp_strm_init__alloc_tag;
    v3 = vzalloc_noprof(0x2000);
    *(_QWORD *)(StatusReg + 80) = v7;
  }
  else
  {
    v2 = (__int64 *)(_per_cpu_offset[a1] + *(_QWORD *)(a2 - 16));
    v2[1] = crypto_alloc_base(*(_QWORD *)(a2 - 8), 2, 15);
    v3 = vzalloc_noprof(0x2000);
  }
  v4 = v2[1];
  *v2 = v3;
  if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( v3 )
      return 0;
    crypto_destroy_tfm(v4);
    v3 = *v2;
  }
  vfree(v3);
  *v2 = 0;
  v2[1] = 0;
  printk(&unk_B646);
  return 4294967284LL;
}
