__int64 __fastcall adsp_setup_32b_dma_allocs(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 v3; // x20
  unsigned int v4; // w0
  unsigned int v6; // w19
  __int64 v7; // x8

  if ( *((_BYTE *)a1 + 784) != 1 )
    return 0;
  v2 = of_reserved_mem_device_init_by_idx(*a1, *(_QWORD *)(*a1 + 744LL), 2);
  v3 = *a1;
  if ( v2 )
  {
    v6 = v2;
    dev_err(v3, "Unable to get the CMA area for performing dma_alloc_* calls\n");
    return v6;
  }
  v4 = dma_set_mask(*a1, 0xFFFFFFFFLL);
  if ( v4 )
  {
    v7 = *a1;
    v6 = v4;
    dev_err(v7, "Unable to set the coherent mask to 32-bits!\n");
    return v6;
  }
  dma_set_coherent_mask(v3, 0xFFFFFFFFLL);
  return 0;
}
