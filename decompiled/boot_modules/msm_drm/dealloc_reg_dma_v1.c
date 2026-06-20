__int64 __fastcall dealloc_reg_dma_v1(_QWORD *a1, unsigned int a2)
{
  _QWORD *v3; // x19

  if ( a1 )
  {
    if ( a2 < 2 )
    {
      if ( *a1 )
      {
        v3 = a1;
        msm_gem_put_iova(*a1, 0);
        msm_gem_address_space_unregister_cb(v3[1], sde_reg_dma_aspace_cb_locked, v3);
        mutex_lock(*(_QWORD *)reg_dma_0[a2] + 128LL);
        msm_gem_free_object(*v3);
        mutex_unlock(*(_QWORD *)reg_dma_0[a2] + 128LL);
        a1 = v3;
      }
      kfree(a1);
      return 0;
    }
    else
    {
      _drm_err("invalid dpu idx %d\n", a2);
      return 4294967274LL;
    }
  }
  else
  {
    _drm_err("invalid param reg_buf %pK\n", nullptr);
    return 4294967274LL;
  }
}
