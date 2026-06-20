void sub_71C8()
{
  __int64 v0; // x20
  unsigned int *v1; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x22
  __int64 v4; // x8

  v1 = *(unsigned int **)(v0 + 992);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qptf_init__alloc_tag_20;
  v4 = *v1;
  if ( (v4 & 0x80000000) == 0 )
    _kmalloc_noprof(v4 << 6, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x6EE0);
}
