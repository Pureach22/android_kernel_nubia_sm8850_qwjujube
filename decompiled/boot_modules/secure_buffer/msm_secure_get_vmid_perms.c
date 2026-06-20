__int64 __fastcall msm_secure_get_vmid_perms(int a1)
{
  if ( a1 == 17 )
    return 4;
  if ( a1 == 42 )
    return 7;
  if ( a1 == 29 && (vmid_cp_camera_preview_ro & 1) != 0 )
    return 4;
  return 6;
}
