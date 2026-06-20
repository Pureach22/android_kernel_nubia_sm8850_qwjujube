__int64 __fastcall sde_encoder_get_disp_op(__int64 result)
{
  __int64 v1; // x8
  void *v2; // x0

  if ( result )
  {
    if ( *(_QWORD *)result )
    {
      v1 = *(_QWORD *)(*(_QWORD *)result + 56LL);
      if ( v1 && *(_QWORD *)(v1 + 8) )
        return sde_kms_get_disp_op();
      v2 = &unk_234896;
    }
    else
    {
      v2 = &unk_26FCAB;
    }
    printk(v2, "sde_encoder_get_kms");
    return 0;
  }
  return result;
}
