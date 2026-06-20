__int64 __fastcall measured_fps_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  int v4; // w8
  int v5; // w21
  __int64 v6; // x20
  unsigned __int64 v7; // x27
  __int64 i; // x19
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned __int64 v11; // x9
  char v12; // w8
  int v13; // w8
  int v14; // w8
  __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x4

  if ( !a1 || !a3 )
  {
    printk(&unk_2120FD, "measured_fps_show");
    return -11;
  }
  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
  {
    scnprintf(a3, 4096, "fps information not available");
    return -22;
  }
  if ( !*(_QWORD *)(v3 + 4472) )
  {
    scnprintf(a3, 4096, "timebuf null - fps information not available");
    return -22;
  }
  v4 = *(_DWORD *)(v3 + 4480);
  if ( v4 )
    v5 = v4 - 1;
  else
    v5 = 999;
  v6 = ktime_get(a1);
  v7 = 0;
  for ( i = 0; i != 1000; ++i )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(v3 + 4472) + 8LL * v5);
    if ( v6 / 1000 <= (unsigned __int64)(v9 / 1000) )
    {
      v12 = _drm_debug;
    }
    else
    {
      v10 = (unsigned __int128)((v6 - v9) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
      v11 = (v10 >> 7) + ((unsigned __int64)v10 >> 63);
      v12 = _drm_debug;
      if ( v11 >= *(unsigned int *)(v3 + 4468) )
      {
        v18 = v7 / (unsigned int)v11;
        *(_DWORD *)(v3 + 4464) = v18;
        if ( (v12 & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "measured fps: %d\n", v18);
        return (int)scnprintf(
                      a3,
                      4096,
                      "fps: %lld.%lld duration:%d frame_count:%lld\n",
                      *(unsigned int *)(v3 + 4464) / 0xAuLL,
                      *(_DWORD *)(v3 + 4464) % 0xAu,
                      *(_DWORD *)(v3 + 4468),
                      i);
      }
    }
    if ( v5 )
      --v5;
    else
      v5 = 999;
    if ( (v12 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "current time index: %d\n", v5);
    v7 += 10000000LL;
  }
  v13 = *(_DWORD *)(v3 + 4480);
  if ( v13 )
    v14 = v13 - 1;
  else
    v14 = 999;
  v15 = (unsigned __int128)((v6 - *(_QWORD *)(*(_QWORD *)(v3 + 4472) + 8LL * v14)) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
  v16 = (v15 >> 7) + ((unsigned __int64)v15 >> 63);
  if ( v16 >= *(unsigned int *)(v3 + 4468) )
    *(_DWORD *)(v3 + 4464) = 0x2540BE400uLL / (unsigned int)v16;
  i = 1000;
  return (int)scnprintf(
                a3,
                4096,
                "fps: %lld.%lld duration:%d frame_count:%lld\n",
                *(unsigned int *)(v3 + 4464) / 0xAuLL,
                *(_DWORD *)(v3 + 4464) % 0xAu,
                *(_DWORD *)(v3 + 4468),
                i);
}
