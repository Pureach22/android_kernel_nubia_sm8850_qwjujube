void sub_C070()
{
  unsigned int v0; // w21
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &setup_partitions__alloc_tag;
  _kmalloc_noprof(8LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xB80C);
}
