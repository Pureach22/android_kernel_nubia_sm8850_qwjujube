__int64 __fastcall sde_kms_get_disp_op(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
    if ( v1 )
      return *(unsigned int *)(v1 + 5912);
  }
  printk(&unk_25E374, "sde_kms_get_disp_op");
  return 0;
}
