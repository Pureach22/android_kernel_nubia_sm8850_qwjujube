void sub_13C920()
{
  int v0; // w20
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_smmu_fw_dev_component_bind__alloc_tag_359;
  _kvmalloc_node_noprof((unsigned int)(32 * v0), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x13C79C);
}
