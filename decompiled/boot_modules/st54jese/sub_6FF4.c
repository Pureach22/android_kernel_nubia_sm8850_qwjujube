void sub_6FF4()
{
  __int64 v0; // x22
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x23
  __int64 v3; // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = (unsigned int)bufsiz;
  *(_QWORD *)(StatusReg + 80) = &st54spi_open__alloc_tag;
  v4 = _kmalloc_noprof(v3, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 72) = v4;
  if ( !v4 )
    JUMPOUT(0x6F0C);
  JUMPOUT(0x6EAC);
}
