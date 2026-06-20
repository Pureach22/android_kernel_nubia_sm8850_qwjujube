void sub_2679BC()
{
  unsigned __int16 v0; // w21
  int v1; // w28
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x28
  __int64 v5; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(v2 - 36) = v1;
  v4 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_cci_data_queue_burst__alloc_tag;
  v5 = _kvmalloc_node_noprof(4LL * v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v4;
  if ( !v5 )
    JUMPOUT(0x266F88);
  JUMPOUT(0x266E08);
}
