void sub_11A78()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &aw_dev_parse_get_vaild_prof__alloc_tag;
  v3 = _kmalloc_noprof((unsigned __int64)*(unsigned int *)(v0 + 624) << 6, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 640) = v3;
  if ( v3 )
    JUMPOUT(0x11240);
  JUMPOUT(0x112D8);
}
