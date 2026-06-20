void sub_16B5D4()
{
  __int64 v0; // x0
  unsigned __int64 StatusReg; // [xsp+10h] [xbp+10h]
  __int64 v2; // [xsp+18h] [xbp+18h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_hw_cdm_submit_gen_irq__alloc_tag;
  v0 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v0 )
    JUMPOUT(0x16B300);
  JUMPOUT(0x16B1E4);
}
