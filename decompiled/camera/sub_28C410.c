void sub_28C410()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_ois_fw_info_pkt_parser_v2__alloc_tag;
  _kvmalloc_node_noprof((unsigned __int64)*(unsigned __int8 *)(v0 + 6) << 6, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x28BFE4);
}
