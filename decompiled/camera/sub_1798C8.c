void sub_1798C8()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // [xsp+8h] [xbp+8h]
  __int64 v2; // [xsp+10h] [xbp+10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_irq_controller_subscribe_irq__alloc_tag_36;
  _kvmalloc_node_noprof(4LL * *(unsigned int *)(v0 + 24), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x179600);
}
