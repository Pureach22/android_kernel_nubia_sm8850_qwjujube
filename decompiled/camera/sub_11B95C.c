void sub_11B95C()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_packet_util_get_unique_tbl__alloc_tag_27;
  v2 = _kvmalloc_node_noprof(1600, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x11B8B4);
  JUMPOUT(0x11B854);
}
