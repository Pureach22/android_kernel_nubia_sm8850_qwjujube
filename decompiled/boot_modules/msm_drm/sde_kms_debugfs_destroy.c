__int64 __fastcall sde_kms_debugfs_destroy(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    sde_debugfs_vbif_destroy();
    return sde_debugfs_core_irq_destroy(v1);
  }
  return result;
}
