__int64 __fastcall msm_dma_unmap_all_for_dev(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w21
  _QWORD *v5; // x8
  _QWORD *v6; // x25
  int v13; // w8

  mutex_lock(&msm_iommu_map_mutex);
  v2 = rb_first(&iommu_root);
  if ( v2 )
  {
    v3 = v2;
    v4 = 0;
    do
    {
      mutex_lock(v3 + 48);
      v5 = *(_QWORD **)(v3 + 24);
      if ( v5 != (_QWORD *)(v3 + 24) )
      {
        do
        {
          v6 = (_QWORD *)*v5;
          if ( v5[5] == a1 )
          {
            _X0 = (unsigned int *)(v5 + 9);
            __asm { PRFM            #0x11, [X0] }
            do
              v13 = __ldxr(_X0);
            while ( __stlxr(v13 - 1, _X0) );
            if ( v13 == 1 )
            {
              __dmb(9u);
              msm_iommu_map_release((__int64)_X0);
            }
            else
            {
              if ( v13 <= 0 )
                refcount_warn_saturate(_X0, 3);
              v4 = -22;
            }
          }
          v5 = v6;
        }
        while ( v6 != (_QWORD *)(v3 + 24) );
      }
      mutex_unlock(v3 + 48);
      v3 = rb_next(v3);
    }
    while ( v3 );
  }
  else
  {
    v4 = 0;
  }
  mutex_unlock(&msm_iommu_map_mutex);
  return v4;
}
