__int64 __fastcall sde_plane_static_img_control(__int64 result, int a2, int a3)
{
  __int64 v4; // x1

  if ( !result )
    return printk(&unk_226FC0, "sde_plane_static_img_control");
  v4 = *(_QWORD *)(result + 1768);
  if ( !v4 )
    return printk(&unk_226FC0, "sde_plane_static_img_control");
  *(_DWORD *)(v4 + 2744) = a2;
  *(_DWORD *)(v4 + 2748) = a3;
  if ( (a2 & 0xFFFFFFFE) == 4 )
    return ((__int64 (*)(void))sde_plane_sspp_setup_sys_cache)();
  return result;
}
