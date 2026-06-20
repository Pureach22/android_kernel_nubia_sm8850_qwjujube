__int64 __fastcall sde_kms_get_address_space_device(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  void *v4; // x0

  if ( !a1 )
  {
    v4 = &unk_234896;
    goto LABEL_10;
  }
  v2 = *(_QWORD *)(a1 + 136);
  if ( !v2 || !*(_QWORD *)(v2 + 8) )
  {
    v4 = &unk_223EAA;
LABEL_10:
    printk(v4, "_sde_kms_get_address_space_device");
    return 0;
  }
  if ( a2 <= 3 )
  {
    result = *(_QWORD *)(a1 + 8LL * a2 + 1704);
    if ( !result )
      return result;
    if ( *(_BYTE *)(result + 268) == 1 )
      return msm_gem_get_aspace_device();
  }
  return 0;
}
