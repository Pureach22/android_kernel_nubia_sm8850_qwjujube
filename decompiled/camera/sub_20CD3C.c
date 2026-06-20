void sub_20CD3C()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_isp_irq_inject_parse_common_params__alloc_tag;
  v2 = _kvmalloc_node_noprof(1500, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x20C5FC);
  JUMPOUT(0x20C57C);
}
