__int64 __fastcall sde_kms_destroy(__int64 a1)
{
  __int64 v1; // x8

  if ( !a1 )
    return printk(&unk_234896, "sde_kms_destroy");
  v1 = *(_QWORD *)(a1 + 136);
  if ( !v1 || !*(_QWORD *)(v1 + 8) )
    return printk(&unk_231B33, "sde_kms_destroy");
  ((void (*)(void))sde_kms_hw_destroy)();
  return kfree(a1);
}
