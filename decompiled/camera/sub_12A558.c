void sub_12A558()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_context_allocate_mem_hw_entries__alloc_tag_116;
  v3 = _kvmalloc_node_noprof(8LL * *(unsigned int *)(v0 + 200), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 496) = v3;
  if ( !v3 )
    JUMPOUT(0x12A1B8);
  JUMPOUT(0x12A0DC);
}
