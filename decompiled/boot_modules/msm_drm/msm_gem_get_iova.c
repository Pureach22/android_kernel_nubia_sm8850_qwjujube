__int64 __fastcall msm_gem_get_iova(__int64 a1, __int64 a2, _QWORD *a3)
{
  _QWORD *v6; // x23
  _QWORD *v7; // x8
  _QWORD *v8; // x24
  const char **aspace_device; // x20
  unsigned int v10; // w25
  __int64 v11; // x8
  const char **v12; // x8
  const char *v13; // x1
  const char *v14; // x2
  _QWORD *v15; // x0
  _QWORD *v16; // x26
  _QWORD *v17; // x1
  unsigned __int64 pages; // x0
  __int64 *v19; // x8
  __int64 v20; // x24
  __int64 v21; // x25
  __int64 v22; // x1
  unsigned __int64 v23; // x0
  __int64 v24; // x0
  unsigned __int64 v25; // x0
  _QWORD *v26; // x8
  __int64 v27; // x9
  _QWORD *v28; // x8

  mutex_lock(a1 + 544);
  if ( (mutex_is_locked(a1 + 544) & 1) == 0 )
    __break(0x800u);
  if ( (mutex_is_locked(a1 + 544) & 1) == 0 )
    __break(0x800u);
  v6 = (_QWORD *)(a1 + 440);
  v7 = (_QWORD *)(a1 + 440);
  do
  {
    v7 = (_QWORD *)*v7;
    if ( v7 == v6 )
    {
      aspace_device = (const char **)msm_gem_get_aspace_device(a2);
      goto LABEL_17;
    }
  }
  while ( *(v7 - 1) != a2 );
  v8 = v7 - 23;
  aspace_device = (const char **)msm_gem_get_aspace_device(a2);
  if ( v8 )
  {
LABEL_9:
    *a3 = v8[21];
    if ( a2 && (*(_BYTE *)(a1 + 616) & 1) == 0 )
    {
      mutex_lock(a2 + 320);
      msm_gem_add_obj_to_aspace_active_list(a2, a1);
      mutex_unlock(a2 + 320);
    }
    if ( aspace_device && (*((_BYTE *)aspace_device + 844) & 0x20) == 0 && (*(_BYTE *)(a1 + 370) & 1) != 0 )
    {
      v10 = 0;
      if ( (*((_BYTE *)aspace_device + 844) & 0x40) == 0 )
      {
        v28 = *(_QWORD **)(a1 + 424);
        if ( v28 )
        {
          _dma_sync_sg_for_device(aspace_device, *v28);
          v10 = 0;
        }
      }
    }
    else
    {
      v10 = 0;
    }
    goto LABEL_67;
  }
LABEL_17:
  if ( aspace_device
    && (v11 = *(_QWORD *)(a1 + 240)) != 0
    && (aspace_device != *(const char ***)(v11 + 8) || *(_BYTE *)(a1 + 649) == 1) )
  {
    if ( (unsigned int)of_device_is_compatible(aspace_device[93], "qcom,smmu_sde_unsec")
      && (unsigned int)of_device_is_compatible(
                         *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 240) + 8LL) + 744LL),
                         "qcom,smmu_sde_sec") )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "msm_gem_get_iova_locked",
        470,
        -1,
        *(_QWORD *)(*(_QWORD *)(a1 + 240) + 8LL),
        (int)aspace_device,
        *(_QWORD *)(a1 + 424),
        *(unsigned __int8 *)(a1 + 649),
        239);
      v12 = *(const char ***)(*(_QWORD *)(a1 + 240) + 8LL);
      v13 = v12[14];
      if ( !v13 )
        v13 = *v12;
      v14 = aspace_device[14];
      if ( !v14 )
        v14 = *aspace_device;
      _drm_err("gem obj found mapped to %s, now requesting map on %s", v13, v14);
      v10 = -22;
      goto LABEL_67;
    }
    v19 = *(__int64 **)(a1 + 240);
    v20 = *v19;
    v21 = v19[9];
    _drm_dev_dbg(0, 0, 0, "detach nsec-dev:%pK attach sec-dev:%pK\n", (const void *)v19[1], aspace_device);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "msm_gem_get_iova_locked",
      482,
      -1,
      *(_QWORD *)(*(_QWORD *)(a1 + 240) + 8LL),
      (int)aspace_device,
      *(_QWORD *)(a1 + 424),
      *(unsigned __int8 *)(a1 + 649),
      239);
    v22 = *(_QWORD *)(a1 + 424);
    if ( v22 )
      dma_buf_unmap_attachment_unlocked(*(_QWORD *)(a1 + 240), v22, 0);
    dma_buf_detach(v20, *(_QWORD *)(a1 + 240));
    v23 = dma_buf_attach(v20, aspace_device);
    *(_QWORD *)(a1 + 240) = v23;
    if ( v23 >= 0xFFFFFFFFFFFFF001LL )
    {
      _drm_err("dma_buf_attach failure, err=%ld\n", v23);
      v10 = *(_DWORD *)(a1 + 240);
      goto LABEL_67;
    }
    *(_QWORD *)(v23 + 72) |= v21;
    *(_BYTE *)(a1 + 649) = 0;
  }
  else if ( (*(_BYTE *)(a1 + 371) & 0x40) == 0 || *(_QWORD *)(a1 + 424) )
  {
    goto LABEL_30;
  }
  if ( !a1 )
  {
    _drm_err("NULL drm gem object\n");
LABEL_59:
    v10 = -22;
    goto LABEL_60;
  }
  v24 = *(_QWORD *)(a1 + 240);
  if ( !v24 )
  {
    _drm_err("NULL dma_buf_attachment in drm gem object\n");
    goto LABEL_59;
  }
  *(_QWORD *)(v24 + 72) |= 0x20000uLL;
  v25 = dma_buf_map_attachment_unlocked(v24);
  v10 = v25;
  if ( v25 <= 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)(a1 + 416) = 0;
    *(_QWORD *)(a1 + 424) = v25;
    goto LABEL_30;
  }
  _drm_err("dma_buf_map_attachment failure, err=%d\n", v25);
  if ( v10 )
  {
LABEL_60:
    _drm_err("delayed dma-buf import failed %d\n", v10);
    *(_BYTE *)(a1 + 649) = 1;
    goto LABEL_67;
  }
LABEL_30:
  if ( (mutex_is_locked(a1 + 544) & 1) == 0 )
    __break(0x800u);
  v15 = (_QWORD *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 208);
  v8 = v15;
  if ( !v15 )
  {
    LODWORD(v8) = -12;
    goto LABEL_66;
  }
  v16 = v15 + 23;
  v17 = *(_QWORD **)(a1 + 448);
  v15[22] = a2;
  *(_QWORD *)(a1 + 608) = a2;
  if ( v15 + 23 == v6 || v17 == v16 || (_QWORD *)*v17 != v6 )
  {
    _list_add_valid_or_report(v15 + 23, v17);
    if ( (unsigned __int64)v8 < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_37;
LABEL_66:
    v10 = (unsigned int)v8;
    goto LABEL_67;
  }
  *(_QWORD *)(a1 + 448) = v16;
  v15[23] = v6;
  v15[24] = v17;
  *v17 = v16;
  if ( (unsigned __int64)v15 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_66;
LABEL_37:
  pages = get_pages(a1);
  if ( pages < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = msm_gem_map_vma(a2, v8, *(_QWORD *)(a1 + 424), *(_QWORD *)(a1 + 216) >> 12, *(unsigned int *)(a1 + 368));
    if ( !v10 )
      goto LABEL_9;
  }
  else
  {
    v10 = pages;
  }
  v26 = (_QWORD *)v8[24];
  if ( (_QWORD *)*v26 == v16 && (v27 = *v16, *(_QWORD **)(*v16 + 8LL) == v16) )
  {
    *(_QWORD *)(v27 + 8) = v26;
    *v26 = v27;
  }
  else
  {
    _list_del_entry_valid_or_report(v8 + 23);
  }
  v8[23] = 0xDEAD000000000100LL;
  v8[24] = 0xDEAD000000000122LL;
  kfree(v8);
LABEL_67:
  mutex_unlock(a1 + 544);
  return v10;
}
