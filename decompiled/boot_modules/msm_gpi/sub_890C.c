void sub_890C()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gpi_dump_debug_reg__alloc_tag_99;
  v3 = _kmalloc_cache_noprof(dma_release_channel, 2336, 560);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 1376) = v3;
  if ( !v3 )
    JUMPOUT(0x81EC);
  JUMPOUT(0x7DB4);
}
