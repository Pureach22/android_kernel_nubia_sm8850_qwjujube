__int64 __fastcall sde_hw_sspp_destroy(__int64 a1)
{
  if ( a1 )
  {
    ((void (__fastcall *)(__int64))reg_dmav1_deinit_sspp_ops)(a1);
    kfree(*(_QWORD *)(a1 + 56));
  }
  return kfree(a1);
}
