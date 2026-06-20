__int64 __fastcall sde_plane_restore(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x19

  if ( !result )
    return printk(&unk_226FC0, "sde_plane_restore");
  v1 = *(_QWORD *)(result + 1768);
  if ( !v1 )
    return printk(&unk_226FC0, "sde_plane_restore");
  if ( *(_BYTE *)(result + 2416) == 1 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      v2 = result;
      _drm_dev_dbg(0, 0, 0, "plane%d \n", *(_DWORD *)(result + 104));
      v1 = *(_QWORD *)(v2 + 1768);
      result = v2;
    }
    return sde_plane_atomic_update(result, v1);
  }
  return result;
}
