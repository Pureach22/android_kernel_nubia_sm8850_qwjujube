void sub_46654()
{
  unsigned int *v0; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x24
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &aes_siv_encrypt__alloc_tag_8;
  v3 = _kmalloc_noprof(*v0 + 80LL, 3264);
  if ( v3 )
  {
    *(_QWORD *)(v3 + 64) = v0 + 2;
    *(_QWORD *)(StatusReg + 80) = v2;
    JUMPOUT(0x465AC);
  }
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x465F8);
}
