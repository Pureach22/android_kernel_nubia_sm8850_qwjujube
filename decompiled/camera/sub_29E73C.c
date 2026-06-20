void __fastcall sub_29E73C(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x20
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_qup_i3c_write_table__alloc_tag_11;
  v4 = _kvmalloc_node_noprof(24LL * *(unsigned int *)(a2 + 8), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v4 )
    JUMPOUT(0x29D680);
  JUMPOUT(0x29D5EC);
}
