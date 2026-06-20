void sub_17F64C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = wcnss_prealloc_put;
  *(_QWORD *)(StatusReg + 80) = &_qdf_nbuf_dmamap_create__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 32);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x17F628);
}
