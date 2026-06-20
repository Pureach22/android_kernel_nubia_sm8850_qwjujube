void sub_2A8F54()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x27
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_res_mgr_gpio_request__alloc_tag;
  v2 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x2A8DC0);
  JUMPOUT(0x2A8D1C);
}
