__int64 __fastcall dsi_host_alloc_cmd_tx_buffer(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned int v5; // w20
  unsigned int v6; // w0
  unsigned int iova; // w0
  unsigned __int64 vaddr; // x0

  v2 = msm_gem_new(*(_QWORD *)(a1 + 8), 4096, 0x40000);
  *(_QWORD *)(a1 + 1224) = v2;
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 1232) = 4096;
    v4 = msm_gem_smmu_address_space_get(v3, 0);
    *(_QWORD *)(a1 + 1256) = v4;
    if ( v4 == -19 )
    {
      *(_QWORD *)(a1 + 1256) = 0;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: IOMMU not present, relying on VRAM\n");
    }
    else
    {
      v5 = v4;
      if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
      {
        *(_QWORD *)(a1 + 1256) = 0;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get aspace %d\n", (unsigned int)v4);
        goto LABEL_20;
      }
      v6 = msm_gem_address_space_register_cb(v4, dsi_display_aspace_cb_locked_0, a1);
      if ( v6 )
      {
        v5 = v6;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to register callback %d\n", v6);
LABEL_20:
        mutex_lock(*(_QWORD *)(a1 + 8) + 128LL);
        msm_gem_free_object(*(_QWORD *)(a1 + 1224));
        mutex_unlock(*(_QWORD *)(a1 + 8) + 128LL);
        return v5;
      }
    }
    iova = msm_gem_get_iova(*(_QWORD *)(a1 + 1224), *(_QWORD *)(a1 + 1256), a1 + 1240);
    if ( iova )
    {
      v5 = iova;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get the iova rc %d\n", iova);
LABEL_19:
      msm_gem_address_space_unregister_cb(*(_QWORD *)(a1 + 1256), dsi_display_aspace_cb_locked_0, a1);
      goto LABEL_20;
    }
    vaddr = msm_gem_get_vaddr(*(_QWORD *)(a1 + 1224));
    *(_QWORD *)(a1 + 1248) = vaddr;
    if ( !vaddr || vaddr > 0xFFFFFFFFFFFFF000LL )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get va rc %d\n", 0);
      msm_gem_put_iova(*(_QWORD *)(a1 + 1224), *(_QWORD *)(a1 + 1256));
      v5 = -22;
      goto LABEL_19;
    }
    if ( *(_DWORD *)(a1 + 160)
      && (*(_DWORD *)(*(_QWORD *)(a1 + 168) + 2776LL) = 4096,
          *(_DWORD *)(*(_QWORD *)(a1 + 168) + 2780LL) = *(_QWORD *)(a1 + 1240),
          *(_QWORD *)(*(_QWORD *)(a1 + 168) + 2792LL) = *(_QWORD *)(a1 + 1248),
          *(_QWORD *)(*(_QWORD *)(a1 + 168) + 2768LL) = *(_QWORD *)(a1 + 1224),
          *(_DWORD *)(a1 + 160) >= 2u) )
    {
      v5 = 0;
      *(_DWORD *)(*(_QWORD *)(a1 + 216) + 2776LL) = 4096;
      *(_DWORD *)(*(_QWORD *)(a1 + 216) + 2780LL) = *(_QWORD *)(a1 + 1240);
      *(_QWORD *)(*(_QWORD *)(a1 + 216) + 2792LL) = *(_QWORD *)(a1 + 1248);
      *(_QWORD *)(*(_QWORD *)(a1 + 216) + 2768LL) = *(_QWORD *)(a1 + 1224);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to allocate cmd tx buf memory\n");
    return (unsigned int)-12;
  }
  return v5;
}
