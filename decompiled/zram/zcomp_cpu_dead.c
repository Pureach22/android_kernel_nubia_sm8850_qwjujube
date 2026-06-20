__int64 __fastcall zcomp_cpu_dead(unsigned int a1, __int64 a2)
{
  _QWORD *v2; // x19
  unsigned __int64 v3; // x0

  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    return zcomp_destroy();
  }
  else
  {
    v2 = (_QWORD *)(_per_cpu_offset[a1] + *(_QWORD *)(a2 - 16));
    v3 = v2[1];
    if ( v3 )
    {
      if ( v3 <= 0xFFFFFFFFFFFFF000LL )
        crypto_destroy_tfm(v3);
    }
    vfree(*v2);
    *v2 = 0;
    v2[1] = 0;
    return 0;
  }
}
