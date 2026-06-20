__int64 _md_callback()
{
  if ( g_core )
    return _md_dump_hfi_queues(g_core);
  else
    return 4294967277LL;
}
