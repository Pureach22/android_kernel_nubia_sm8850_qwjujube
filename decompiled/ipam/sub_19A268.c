void __fastcall sub_19A268(__int64 a1, char a2)
{
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x21
  __int64 v5; // x1
  __int64 v6; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(StatusReg + 80);
  if ( (a2 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  *(_QWORD *)(StatusReg + 80) = &ipahal_generate_init_pyld_flt_rt_v4_5__alloc_tag;
  v6 = _kmalloc_noprof((16 * v2) | 4, v5);
  *(_QWORD *)(StatusReg + 80) = v4;
  if ( !v6 )
    JUMPOUT(0x19A1E0);
  JUMPOUT(0x19A1D8);
}
