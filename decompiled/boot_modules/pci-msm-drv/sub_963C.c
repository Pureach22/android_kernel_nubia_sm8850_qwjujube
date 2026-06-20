void __fastcall sub_963C(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x22
  unsigned __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &msm_msi_init__alloc_tag_21;
  v3 = *(int *)(a1 + 40);
  if ( is_mul_ok(v3, 0x420u) )
    _kmalloc_noprof(1056 * v3, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x9520);
}
