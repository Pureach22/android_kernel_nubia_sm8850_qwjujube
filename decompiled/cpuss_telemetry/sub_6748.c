void sub_6748()
{
  __int64 v0; // x27
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x21

  v1 = *(_QWORD *)(v0 + 3144);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cpuss_telemetry_create_fs_entries__alloc_tag_14;
  _kmalloc_noprof(8LL * *(unsigned __int16 *)(v1 + 26), 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x6278);
}
