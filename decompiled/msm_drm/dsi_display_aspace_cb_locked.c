__int64 __fastcall dsi_display_aspace_cb_locked(_QWORD *a1, char a2)
{
  __int64 v4; // x0
  unsigned int iova; // w0
  unsigned __int64 vaddr; // x0

  if ( !a1 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: aspace cb called with invalid cb_data\n");
  mutex_lock(a1[33] + 1040LL);
  if ( (a2 & 1) != 0 )
  {
    v4 = a1[153];
    a1[155] = 0;
    msm_gem_put_vaddr(v4);
    msm_gem_vunmap(a1[153], 0);
  }
  else
  {
    iova = msm_gem_get_iova(a1[153], a1[157], a1 + 155);
    if ( iova )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get the iova rc %d\n", iova);
    }
    else
    {
      vaddr = msm_gem_get_vaddr(a1[153]);
      a1[156] = vaddr;
      if ( !vaddr || vaddr >= 0xFFFFFFFFFFFFF001LL )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get va rc %d\n", 0);
    }
  }
  return mutex_unlock(a1[33] + 1040LL);
}
