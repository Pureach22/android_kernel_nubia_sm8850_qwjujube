__int64 __fastcall gsihal_init(unsigned int a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  long double v6; // q0

  if ( gsihal_ctx )
  {
    if ( *(_QWORD *)(gsihal_ctx + 8) != a2 )
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d base address of early init is differnet.\n", "gsihal_init", 23);
      __break(0x800u);
    }
    return 4294967279LL;
  }
  if ( a1 - 14 <= 0xFFFFFFF2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid GSI version %d\n", "gsihal_init", 31, a1);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid memory io mapping addr\n", "gsihal_init", 37);
    return 4294967274LL;
  }
  v5 = _kmalloc_cache_noprof(log_post_write_mmio, 3520, 16);
  gsihal_ctx = v5;
  if ( !v5 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d kzalloc err for gsihal_ctx\n", "gsihal_init", 44);
    return 4294967284LL;
  }
  *(_DWORD *)v5 = a1;
  *(_QWORD *)(v5 + 8) = a2;
  result = gsihal_reg_init(a1);
  if ( (_DWORD)result )
  {
    v6 = dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to initialize gsihal regs\n", "gsihal_init", 53);
    kfree(gsihal_ctx, v6);
    gsihal_ctx = 0;
    return 4294967274LL;
  }
  return result;
}
