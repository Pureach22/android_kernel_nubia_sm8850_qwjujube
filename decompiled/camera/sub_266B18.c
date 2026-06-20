void sub_266B18()
{
  __int64 v0; // x20
  __int64 v1; // x21
  unsigned __int64 StatusReg; // x23
  __int64 v3; // x26
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_cci_i2c_write_async__alloc_tag_146;
  v4 = _kvmalloc_node_noprof(16LL * *(unsigned int *)(v0 + 32), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v1 + 32) = v4;
  if ( !v4 )
    JUMPOUT(0x266A78);
  JUMPOUT(0x266930);
}
