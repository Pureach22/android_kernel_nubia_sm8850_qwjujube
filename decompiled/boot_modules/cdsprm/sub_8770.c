void sub_8770()
{
  __int64 v0; // x26
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qos_cores_init__alloc_tag_164;
  _kmalloc_noprof(80LL * *(unsigned int *)(v0 + 1272), 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x8158);
}
