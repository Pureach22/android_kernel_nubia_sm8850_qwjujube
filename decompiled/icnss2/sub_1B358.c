void sub_1B358()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &icnss_power_misc_params_init__alloc_tag;
  v3 = *(unsigned int *)(v0 + 5776);
  if ( (v3 & 0x80000000) == 0 )
    _kmalloc_noprof(8 * v3, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1B2C8);
}
