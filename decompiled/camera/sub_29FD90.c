void sub_29FD90()
{
  __int64 v0; // x21
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x0
  __int64 v3; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_spi_tx_helper__alloc_tag_32;
  v2 = _kmalloc_noprof(v0, 3521);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v2 )
    JUMPOUT(0x29FABC);
  JUMPOUT(0x29FB18);
}
