__int64 _gsi_allocate_msis()
{
  int v0; // w0
  int virq; // w0
  __int64 v2; // x7
  __int64 v3; // x6
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x7
  int v8; // w0
  unsigned __int64 v10; // x19
  unsigned __int64 v13; // x9
  unsigned __int64 v20; // x9

  v0 = platform_device_msi_init_and_alloc_irqs(
         *(_QWORD *)(gsi_ctx + 8),
         *(unsigned int *)(gsi_ctx + 28680),
         _gsi_msi_write_msg);
  if ( v0 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d error allocating platform MSIs - %d\n", "__gsi_allocate_msis", 1428, v0);
  }
  else
  {
    if ( !*(_DWORD *)(gsi_ctx + 28680) )
      return 0;
    virq = msi_domain_get_virq(*(_QWORD *)(gsi_ctx + 8), 0, 0);
    v3 = gsi_ctx;
    *(_DWORD *)(gsi_ctx + 28728) = virq;
    if ( (*(_QWORD *)(v3 + 28688) & 1) != 0 )
    {
      v6 = 0;
LABEL_14:
      dev_err(*(_QWORD *)(v3 + 8), "%s:%d MSI %lu already allocated\n", "__gsi_request_msi_irq", 1388, v6);
    }
    else
    {
      v4 = devm_request_threaded_irq(
             *(_QWORD *)(v3 + 8),
             *(unsigned int *)(v3 + 28728),
             gsi_msi_isr,
             0,
             0,
             "gsi_msi",
             v3,
             v2);
      v5 = gsi_ctx;
      if ( !v4 )
      {
        while ( 1 )
        {
          _X8 = (unsigned __int64 *)(v5 + 28688);
          __asm { PRFM            #0x11, [X8] }
          do
            v13 = __ldxr(_X8);
          while ( __stxr(v13 | 1, _X8) );
          if ( *(_DWORD *)(gsi_ctx + 28680) < 2u )
            return 0;
          v6 = 1;
          *(_DWORD *)(gsi_ctx + 28732) = msi_domain_get_virq(*(_QWORD *)(gsi_ctx + 8), 0, 1);
          v3 = gsi_ctx;
          if ( (*(_QWORD *)(gsi_ctx + 28688) & 2) != 0 )
            goto LABEL_14;
          v8 = devm_request_threaded_irq(
                 *(_QWORD *)(gsi_ctx + 8),
                 *(unsigned int *)(gsi_ctx + 28732),
                 gsi_msi_isr,
                 0,
                 0,
                 "gsi_msi",
                 gsi_ctx,
                 v7);
          v5 = gsi_ctx;
          if ( v8 )
          {
            v6 = 1;
            goto LABEL_17;
          }
          _X8 = (unsigned __int64 *)(gsi_ctx + 28688);
          __asm { PRFM            #0x11, [X8] }
          do
            v20 = __ldxr(_X8);
          while ( __stxr(v20 | 2, _X8) );
          if ( *(_DWORD *)(gsi_ctx + 28680) < 3u )
            return 0;
          msi_domain_get_virq(*(_QWORD *)(gsi_ctx + 8), 0, 2);
          __break(0x5512u);
        }
      }
      v6 = 0;
LABEL_17:
      dev_err(
        *(_QWORD *)(v5 + 8),
        "%s:%d failed to register msi irq %u idx %lu\n",
        "__gsi_request_msi_irq",
        1402,
        *(_DWORD *)(v5 + 4 * v6 + 28728),
        v6);
    }
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d error requesting IRQ for MSI %lu\n", "__gsi_allocate_msis", 1458, v6);
    v10 = ((unsigned __int64)*(unsigned int *)(gsi_ctx + 28680) + 63) >> 3;
    platform_device_msi_free_irqs_all(*(_QWORD *)(gsi_ctx + 8));
    memset((void *)(gsi_ctx + 28688), 0, v10 & 0x3FFFFFF8);
  }
  return 0xFFFFFFFFLL;
}
