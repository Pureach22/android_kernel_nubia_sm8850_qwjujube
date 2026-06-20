__int64 __fastcall msm_gem_delayed_import(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned __int64 v4; // x0
  unsigned int v5; // w19

  if ( !a1 )
  {
    _drm_err("NULL drm gem object\n");
    return (unsigned int)-22;
  }
  v2 = *(_QWORD *)(a1 + 240);
  if ( !v2 )
  {
    _drm_err("NULL dma_buf_attachment in drm gem object\n");
    return (unsigned int)-22;
  }
  v3 = a1;
  *(_QWORD *)(v2 + 72) |= 0x20000uLL;
  v4 = dma_buf_map_attachment_unlocked(v2);
  v5 = v4;
  if ( v4 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v3 + 416) = 0;
    *(_QWORD *)(v3 + 424) = v4;
    return 0;
  }
  else
  {
    _drm_err("dma_buf_map_attachment failure, err=%d\n", v4);
  }
  return v5;
}
