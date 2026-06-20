__int64 __fastcall nommu_get_gpuaddr(__int64 a1, _QWORD *a2)
{
  _DWORD *v2; // x8
  unsigned int v3; // w9
  __int64 v4; // x8

  v2 = (_DWORD *)a2[7];
  v3 = v2[2];
  if ( v3 < 2 || (nommu_get_gpuaddr___already_done & 1) != 0 )
  {
    if ( v3 > 1 )
    {
      return 4294967274LL;
    }
    else
    {
      v4 = *(unsigned int *)(*(_QWORD *)v2 + 8LL)
         + (((**(_QWORD **)v2 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
         + 0x5000000000LL;
      a2[3] = v4;
      if ( v4 )
      {
        *a2 = a1;
        return 0;
      }
      else
      {
        return 4294967284LL;
      }
    }
  }
  else
  {
    nommu_get_gpuaddr___already_done = 1;
    _warn_printk("Attempt to map non-contiguous memory with NOMMU\n");
    __break(0x800u);
    return 4294967274LL;
  }
}
