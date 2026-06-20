void sub_138C4()
{
  __int64 v0; // x29
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x23
  __int64 v4; // x0

  v1 = *(unsigned int *)(v0 - 16);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &synx_handle_import_arr__alloc_tag;
  v4 = _kmalloc_noprof(32 * v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v4 )
    JUMPOUT(0x135F4);
  JUMPOUT(0x13650);
}
