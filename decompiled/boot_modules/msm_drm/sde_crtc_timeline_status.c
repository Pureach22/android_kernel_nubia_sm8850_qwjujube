__int64 __fastcall sde_crtc_timeline_status(__int64 a1)
{
  if ( a1 )
    return sde_fence_timeline_status(*(_QWORD *)(a1 + 3232), a1 + 112);
  else
    return printk(&unk_25E167, "sde_crtc_timeline_status");
}
