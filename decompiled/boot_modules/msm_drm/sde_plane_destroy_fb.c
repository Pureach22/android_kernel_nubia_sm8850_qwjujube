__int64 __fastcall sde_plane_destroy_fb(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19

  if ( !result )
    return printk(&unk_27DD6C, "sde_plane_destroy_fb");
  if ( *(_QWORD *)(result + 1520) == 1 )
  {
    v1 = *(_QWORD *)(result + 16);
    if ( v1 )
    {
      v2 = result;
      result = drm_mode_object_put(v1 + 24);
      *(_QWORD *)(v2 + 16) = 0;
    }
  }
  return result;
}
