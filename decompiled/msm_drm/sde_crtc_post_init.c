__int64 __fastcall sde_crtc_post_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x1
  unsigned __int64 v5; // x0
  __int64 ns; // x0
  __int64 v7; // x0
  __int64 result; // x0

  if ( a1 && (v2 = *(_QWORD *)(a1 + 64)) != 0 && a2 && (v4 = *(_QWORD *)(v2 + 8)) != 0 )
  {
    v5 = device_create_with_groups(
           *(_QWORD *)(v4 + 792),
           v4,
           0,
           a2,
           &sde_crtc_attr_groups,
           "card%d-sde-crtc-%d",
           *(_DWORD *)v2,
           *(_DWORD *)(a2 + 160));
    *(_QWORD *)(a2 + 4488) = v5;
    if ( v5 && v5 < 0xFFFFFFFFFFFFF001LL )
    {
      ns = kernfs_find_and_get_ns(*(_QWORD *)(v5 + 48), "vsync_event", 0);
      *(_QWORD *)(a2 + 4496) = ns;
      if ( !ns )
        printk(&unk_2195E1, "sde_crtc_post_init");
      v7 = kernfs_find_and_get_ns(*(_QWORD *)(*(_QWORD *)(a2 + 4488) + 48LL), "retire_frame_event", 0);
      *(_QWORD *)(a2 + 4504) = v7;
      if ( !v7 )
        printk(&unk_256C14, "sde_crtc_post_init");
      return 0;
    }
    else
    {
      printk(&unk_24FB35, "sde_crtc_post_init");
      result = *(_QWORD *)(a2 + 4488);
      if ( !result )
        return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_2120FD, "sde_crtc_post_init");
    return 4294967274LL;
  }
  return result;
}
