bool __fastcall sde_fence_signaled(__int64 a1)
{
  int v1; // w19

  v1 = *(_QWORD *)(a1 + 40) - *(_DWORD *)(*(_QWORD *)(a1 + 64) + 4LL);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "status:%d fence seq:%llu and timeline:%u\n", v1 < 1);
  return v1 < 1;
}
