void sub_69E64()
{
  unsigned __int64 v0; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  if ( v0 >= 0xFFFFFFFFFFFFFCE0LL )
    v3 = -1;
  else
    v3 = v0 + 800;
  *(_QWORD *)(StatusReg + 80) = &ieee802_11_parse_elems_full__alloc_tag;
  v4 = _kmalloc_noprof(v3, 2336);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v4 )
    JUMPOUT(0x69A6C);
  JUMPOUT(0x6973C);
}
