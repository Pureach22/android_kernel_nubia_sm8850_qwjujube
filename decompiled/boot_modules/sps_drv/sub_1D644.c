void __usercall sub_1D644(int a1@<W8>)
{
  __int64 v1; // x22
  unsigned __int64 StatusReg; // x25
  __int64 v3; // x26

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sps_bam_pipe_set_params__alloc_tag_169;
  _kmalloc_noprof((unsigned int)(*(_DWORD *)(v1 + 224) + a1), 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x1D440);
}
