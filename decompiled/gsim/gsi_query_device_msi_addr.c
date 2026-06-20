__int64 __fastcall gsi_query_device_msi_addr(_QWORD *a1)
{
  __int64 v1; // x9

  if ( gsi_ctx )
  {
    if ( *(_BYTE *)(gsi_ctx + 28666) == 1 )
      v1 = *(_QWORD *)(gsi_ctx + 28672);
    else
      v1 = 0;
    *a1 = v1;
    return 0;
  }
  else
  {
    printk(&unk_2DEB9, "gsi_query_device_msi_addr", 5667);
    return 4294967288LL;
  }
}
