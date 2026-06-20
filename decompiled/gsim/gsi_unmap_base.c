__int64 gsi_unmap_base()
{
  __int64 v0; // x0
  __int64 result; // x0

  if ( gsi_ctx )
  {
    v0 = *(_QWORD *)(gsi_ctx + 8);
    if ( *(_QWORD *)gsi_ctx )
    {
      devm_iounmap(v0);
      result = 0;
      *(_QWORD *)gsi_ctx = 0;
    }
    else
    {
      dev_err(v0, "%s:%d access to GSI HW has not been mapped\n", "gsi_unmap_base", 1334);
      return 4294967290LL;
    }
  }
  else
  {
    printk(&unk_2DEB9, "gsi_unmap_base", 1329);
    return 4294967288LL;
  }
  return result;
}
