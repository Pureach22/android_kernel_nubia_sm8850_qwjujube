void sub_138C70()
{
  unsigned __int64 StatusReg; // [xsp+30h] [xbp+30h]
  __int64 v1; // [xsp+38h] [xbp+38h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_smmu_map_buffer_validate__alloc_tag;
  _kvmalloc_node_noprof(136, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1388E8);
}
