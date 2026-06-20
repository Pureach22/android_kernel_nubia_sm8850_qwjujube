void sub_6718()
{
  __int64 v0; // x27
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x20

  v1 = *(_QWORD *)(v0 + 3144);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_noprof(8LL * *(unsigned int *)(v1 + 28), 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x6238);
}
