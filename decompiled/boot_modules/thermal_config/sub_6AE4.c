void sub_6AE4()
{
  __int64 v0; // x29
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x20

  v1 = *(_QWORD *)(v0 - 48);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &fetch_and_populate_cdevs__alloc_tag;
  _kmalloc_noprof((int)v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x6508);
}
