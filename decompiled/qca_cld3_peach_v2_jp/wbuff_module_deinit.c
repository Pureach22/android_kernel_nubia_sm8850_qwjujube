__int64 wbuff_module_deinit()
{
  if ( wbuff != 1 )
    return 4;
  wbuff = 0;
  if ( qword_86A548 )
  {
    debugfs_remove(qword_86A548);
    qword_86A548 = 0;
  }
  if ( byte_869EE0 == 1 )
    wbuff_module_deregister(&unk_869EF8);
  if ( byte_86A208 == 1 )
    wbuff_module_deregister(&unk_86A220);
  _qdf_frag_cache_drain((__int64)&unk_86A530);
  return 0;
}
