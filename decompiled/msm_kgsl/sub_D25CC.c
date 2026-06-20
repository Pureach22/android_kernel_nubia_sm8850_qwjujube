void sub_D25CC()
{
  __int64 v0; // x21
  unsigned int v1; // w23
  unsigned __int64 StatusReg; // x24
  __int64 v3; // x25
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gen8_hwsched_build_gmu_scaling_table__alloc_tag;
  v4 = _kmalloc_noprof(4LL * v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v0 + 1816) = v4;
  if ( !v4 )
    JUMPOUT(0xD24C8);
  JUMPOUT(0xD249C);
}
