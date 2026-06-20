__int64 __fastcall sde_debugfs_fps_status_show(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  unsigned __int64 v4; // x8
  unsigned int v5; // w9
  unsigned __int64 v6; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 128)) != 0 )
  {
    v3 = ktime_get(a1);
    v4 = (v3 - *(_QWORD *)(v1 + 4456)) / 1000;
    if ( v4 >= 0xF4240 )
    {
      v5 = *(_DWORD *)(v1 + 4448);
      *(_QWORD *)(v1 + 4456) = v3;
      *(_DWORD *)(v1 + 4448) = 0;
      v6 = 10000000 * (unsigned __int64)v5 / (unsigned int)v4;
      LOBYTE(v5) = _drm_debug;
      *(_DWORD *)(v1 + 4464) = v6;
      if ( (v5 & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "Measured FPS for crtc%d is %d.%d\n",
          *(_DWORD *)(v1 + 112),
          (unsigned int)v6 / 0xA,
          (unsigned int)v6 % 0xA);
    }
    seq_printf(a1, "fps: %llu.%llu\n", *(unsigned int *)(v1 + 4464) / 0xAuLL, *(_DWORD *)(v1 + 4464) % 0xAu);
    return 0;
  }
  else
  {
    printk(&unk_2120FD, "_sde_debugfs_fps_status_show");
    return 4294967285LL;
  }
}
