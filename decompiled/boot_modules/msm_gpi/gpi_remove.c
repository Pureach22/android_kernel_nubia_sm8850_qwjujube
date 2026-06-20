__int64 __fastcall gpi_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w20
  __int64 v4; // x23
  __int64 v5; // x0

  v1 = *(_QWORD *)(a1 + 168);
  of_dma_controller_free(*(_QWORD *)(*(_QWORD *)(v1 + 392) + 744LL));
  v2 = dma_async_device_unregister(v1);
  if ( *(_DWORD *)(v1 + 424) )
  {
    v3 = 0;
    do
    {
      if ( (*(_DWORD *)(v1 + 428) & (1 << v3)) != 0 || (*(_DWORD *)(v1 + 432) & (1 << v3)) != 0 )
      {
        v4 = *(_QWORD *)(v1 + 464) + 1480LL * (int)v3;
        gpi_free_chan_resources(v4 + 8);
        gpi_free_chan_resources(v4 + 400);
        v2 = *(_QWORD *)(v4 + 1056);
        if ( v2 )
          v2 = ipc_log_context_destroy();
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)(v1 + 424) );
  }
  if ( arr_idx >= 6 )
  {
    __break(0x5512u);
    return gpi_alloc_smem_region(v2);
  }
  else
  {
    v5 = *(_QWORD *)(v1 + 472);
    arr_idx = 0;
    if ( v5 )
      ipc_log_context_destroy();
    return debugfs_remove(pdentry);
  }
}
