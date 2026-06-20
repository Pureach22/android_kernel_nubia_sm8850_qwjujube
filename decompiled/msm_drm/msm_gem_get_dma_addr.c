__int64 __fastcall msm_gem_get_dma_addr(__int64 a1)
{
  unsigned __int64 v1; // x1
  unsigned __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 424);
  if ( !v1 )
  {
    v3 = dma_buf_map_attachment_unlocked(*(_QWORD *)(a1 + 240));
    v1 = v3;
    if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      _drm_err("dma_buf_map_attachment failure, err=%ld\n", v3);
      return 0;
    }
    *(_QWORD *)(a1 + 424) = v3;
  }
  return *(_QWORD *)(*(_QWORD *)v1 + 16LL);
}
