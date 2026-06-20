void sub_19B16C()
{
  int v0; // w19
  char v1; // w20
  bool v2; // zf
  unsigned __int64 StatusReg; // x21
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x0

  v2 = (v1 & 1) == 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(StatusReg + 80);
  if ( v2 )
    v5 = 3520;
  else
    v5 = 2336;
  *(_QWORD *)(StatusReg + 80) = &ipahal_generate_init_pyld_drop_v5_0__alloc_tag;
  v6 = _kmalloc_noprof((8 * v0) | 4u, v5);
  *(_QWORD *)(StatusReg + 80) = v4;
  if ( !v6 )
    JUMPOUT(0x19B158);
  JUMPOUT(0x19B150);
}
