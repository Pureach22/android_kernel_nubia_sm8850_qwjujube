__int64 __fastcall msm_gem_get_buffer(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 v5; // x20
  int iova; // w0
  unsigned __int64 v7; // x8
  __int64 v8; // x8
  unsigned int v9; // w9
  char v10; // w8

  if ( !a1 )
  {
    _drm_err("invalid drm gem");
    LODWORD(v5) = -22;
    return (unsigned int)v5;
  }
  if ( ((*(_DWORD *)(a1 + 216) + 4095) & 0xFFFFF000) >= (unsigned __int64)a4 + 255 )
  {
    msm_gem_smmu_address_space_get(a2, 0);
    v5 = *(_QWORD *)(a1 + 608);
    if ( v5 == -19 )
    {
      _drm_dev_dbg(0, 0, 0, "IOMMU not present, relying on VRAM.");
      v5 = *(_QWORD *)(a1 + 608);
    }
    else if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      _drm_err("failed to get aspace");
      goto LABEL_16;
    }
    iova = msm_gem_get_iova(a1, v5, (_QWORD *)(a1 + 656));
    if ( iova )
    {
      LODWORD(v5) = iova;
      _drm_err("failed to get the iova ret %d", iova);
    }
    else
    {
      msm_gem_get_vaddr(a1);
      v7 = *(_QWORD *)(a1 + 432);
      if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
      {
        v8 = *(_QWORD *)(a1 + 656);
        LODWORD(v5) = 0;
        v9 = ((v8 + 255) & 0xFFFFFF00) - v8;
        *(_DWORD *)(a1 + 664) = v9;
        *(_QWORD *)(a1 + 656) = v8 + v9;
        return (unsigned int)v5;
      }
      _drm_err("failed to get vaddr");
      LODWORD(v5) = 0;
    }
    goto LABEL_16;
  }
  _drm_err("invalid gem size");
  LODWORD(v5) = -22;
LABEL_16:
  mutex_lock(a1 + 544);
  v10 = *(_BYTE *)(a1 + 373);
  if ( !v10 )
  {
    __break(0x800u);
    v10 = *(_BYTE *)(a1 + 373);
  }
  *(_BYTE *)(a1 + 373) = v10 - 1;
  mutex_unlock(a1 + 544);
  return (unsigned int)v5;
}
