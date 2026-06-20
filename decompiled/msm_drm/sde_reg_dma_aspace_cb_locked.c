unsigned __int64 __fastcall sde_reg_dma_aspace_cb_locked(_QWORD *a1, char a2)
{
  __int64 v3; // x0
  unsigned __int64 result; // x0
  unsigned int iova; // w0
  __int64 v6; // x8
  __int64 v7; // x9

  if ( !a1 )
    return _drm_err("aspace cb called with invalid dma_buf\n");
  if ( (a2 & 1) != 0 )
  {
    v3 = *a1;
    a1[3] = 0;
    msm_gem_put_vaddr(v3);
    return msm_gem_vunmap(*a1, 0);
  }
  else
  {
    iova = msm_gem_get_iova(*a1, a1[1], a1 + 3);
    if ( iova )
    {
      return _drm_err("failed to get the iova rc %d\n", iova);
    }
    else
    {
      result = msm_gem_get_vaddr(*a1);
      a1[4] = result;
      if ( result && result < 0xFFFFFFFFFFFFF001LL )
      {
        v6 = a1[3];
        v7 = (((_DWORD)v6 + 255) & 0xFFFFFF00) - (unsigned int)v6;
        a1[3] = v7 + v6;
        a1[4] = result + v7;
        *((_DWORD *)a1 + 10) = 1;
      }
      else
      {
        return _drm_err("failed to get va rc %d\n", 0);
      }
    }
  }
  return result;
}
