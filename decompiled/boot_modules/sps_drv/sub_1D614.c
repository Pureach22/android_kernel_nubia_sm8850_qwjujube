void __usercall sub_1D614(int a1@<W8>)
{
  __int64 v1; // x22
  unsigned __int64 StatusReg; // x25
  __int64 v3; // x26
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sps_bam_pipe_set_params__alloc_tag_174;
  v4 = vzalloc_noprof((unsigned int)(*(_DWORD *)(v1 + 224) + a1));
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v1 + 248) = v4;
  if ( !v4 )
    JUMPOUT(0x1D460);
  JUMPOUT(0x1D4E4);
}
