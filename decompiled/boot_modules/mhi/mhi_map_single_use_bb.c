__int64 __fastcall mhi_map_single_use_bb(__int64 a1, __int64 a2)
{
  void *v3; // x0
  void *v4; // x20
  unsigned int v5; // w8

  v3 = (void *)dma_alloc_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)(a2 + 40), a2 + 32, &print_fmt_mhi_gen_tre[64], 0);
  if ( v3 )
  {
    if ( *(_DWORD *)(a2 + 48) == 1 )
    {
      v4 = v3;
      memcpy(v3, *(const void **)a2, *(_QWORD *)(a2 + 40));
      v3 = v4;
    }
    v5 = 0;
    *(_QWORD *)(a2 + 8) = v3;
  }
  else
  {
    return (unsigned int)-12;
  }
  return v5;
}
