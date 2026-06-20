__int64 __fastcall msm_gem_sync(__int64 result)
{
  __int64 v1; // x19

  if ( result && !*(_QWORD *)(result + 536) )
  {
    v1 = result;
    result = msm_gem_get_aspace_device(*(_QWORD *)(result + 608));
    if ( result )
    {
      if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
        return _dma_sync_sg_for_device(result, **(_QWORD **)(v1 + 424));
    }
    else
    {
      return _drm_err("failed to get aspace_device\n");
    }
  }
  return result;
}
