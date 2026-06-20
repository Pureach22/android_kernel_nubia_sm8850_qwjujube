void sub_102628()
{
  int v0; // w20
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &kgsl_drawobj_sync_add_syncpoints__alloc_tag;
  if ( is_mul_ok(v0, 0x78u) )
    _kmalloc_noprof(120LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x102520);
}
