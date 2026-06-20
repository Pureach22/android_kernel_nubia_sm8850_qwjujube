__int64 __fastcall sde_encoder_early_unregister(__int64 result)
{
  if ( result )
    return debugfs_remove(*(_QWORD *)(result + 520));
  return result;
}
