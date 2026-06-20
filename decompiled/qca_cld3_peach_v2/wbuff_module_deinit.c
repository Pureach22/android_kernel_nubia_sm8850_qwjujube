__int64 wbuff_module_deinit()
{
  if ( wbuff != 1 )
    return 4;
  wbuff = 0;
  if ( qword_933E78 )
  {
    debugfs_remove(qword_933E78);
    qword_933E78 = 0;
  }
  if ( byte_933810 == 1 )
    wbuff_module_deregister(&unk_933828);
  if ( byte_933B38 == 1 )
    wbuff_module_deregister(&unk_933B50);
  _qdf_frag_cache_drain((__int64)&unk_933E60);
  return 0;
}
