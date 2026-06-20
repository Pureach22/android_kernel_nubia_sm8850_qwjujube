__int64 __fastcall sde_crtc_early_unregister(__int64 result)
{
  if ( result )
    return debugfs_remove(*(_QWORD *)(result + 4392));
  return result;
}
