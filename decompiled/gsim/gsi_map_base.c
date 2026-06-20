__int64 __fastcall gsi_map_base(__int64 a1, unsigned int a2, unsigned int a3)
{
  if ( gsi_ctx )
  {
    *(_QWORD *)gsi_ctx = devm_ioremap(*(_QWORD *)(gsi_ctx + 8), a1, a2);
    if ( *(_QWORD *)gsi_ctx )
    {
      gsihal_init(a3);
      return 0;
    }
    else
    {
      dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d failed to map access to GSI HW\n", "gsi_map_base", 1310);
      return 4294967292LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_map_base", 1302);
    return 4294967288LL;
  }
}
