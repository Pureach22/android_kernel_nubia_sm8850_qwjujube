__int64 __fastcall sde_crtc_debugfs_state_open(__int64 a1, __int64 a2)
{
  return single_open(a2, sde_crtc_debugfs_state_show, *(_QWORD *)(a1 + 696));
}
