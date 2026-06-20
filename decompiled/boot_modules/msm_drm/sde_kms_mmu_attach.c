__int64 __fastcall sde_kms_mmu_attach(_QWORD *a1, char a2)
{
  __int64 v2; // x21
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  void (__fastcall *v8)(__int64, char **, __int64); // x8
  __int64 v9; // x21
  __int64 v10; // x22
  void (__fastcall ****v11)(__int64, char **, __int64); // x23
  __int64 (__fastcall *v13)(_QWORD); // x8
  void (__fastcall *v14)(__int64, char **, __int64); // x8
  __int64 v15; // x21
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 (__fastcall *v18)(_QWORD); // x8
  void (__fastcall *v19)(__int64, char **, __int64); // x8
  __int64 v20; // x20
  __int64 v21; // x21
  void (__fastcall ****v22)(__int64, char **, __int64); // x22
  __int64 (__fastcall *v23)(_QWORD); // x8
  void (__fastcall *v24)(__int64, char **, __int64); // x8

  if ( !a1 )
    return 4294967274LL;
  v2 = a1[213];
  if ( v2 )
  {
    v5 = *(_QWORD *)(v2 + 256);
    if ( (a2 & 1) != 0 )
    {
      v6 = *(_QWORD *)(v2 + 256);
      v7 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v5 + 72LL);
      if ( *((_DWORD *)v7 - 1) != -1045879528 )
        __break(0x8228u);
      if ( (v7(v6) & 1) == 0 )
      {
        v9 = a1[214];
        if ( !v9 )
          goto LABEL_26;
        v10 = *(_QWORD *)(v9 + 256);
        v11 = (void (__fastcall ****)(__int64, char **, __int64))(v9 + 256);
        goto LABEL_18;
      }
    }
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "Attaching domain:%d\n", 0);
    v8 = ***(void (__fastcall ****)(__int64, char **, __int64))(v2 + 256);
    if ( *((_DWORD *)v8 - 1) != -1242077318 )
      __break(0x8228u);
    v8(v5, &iommu_ports, 1);
    *(_BYTE *)(v2 + 268) = 1;
    msm_gem_aspace_domain_attach_detach_update(v2, 0);
  }
  v9 = a1[214];
  if ( !v9 )
    goto LABEL_26;
  v10 = *(_QWORD *)(v9 + 256);
  v11 = (void (__fastcall ****)(__int64, char **, __int64))(v9 + 256);
  if ( (a2 & 1) == 0 )
    goto LABEL_21;
LABEL_18:
  v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v10 + 72LL);
  if ( *((_DWORD *)v13 - 1) != -1045879528 )
    __break(0x8228u);
  if ( (v13(v10) & 1) != 0 )
  {
LABEL_21:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "Attaching domain:%d\n", 1);
    v14 = ***v11;
    if ( *((_DWORD *)v14 - 1) != -1242077318 )
      __break(0x8228u);
    v14(v10, &iommu_ports, 1);
    *(_BYTE *)(v9 + 268) = 1;
    msm_gem_aspace_domain_attach_detach_update(v9, 0);
  }
LABEL_26:
  v15 = a1[215];
  if ( !v15 )
    goto LABEL_36;
  v16 = *(_QWORD *)(v15 + 256);
  if ( (a2 & 1) == 0 )
    goto LABEL_31;
  v17 = *(_QWORD *)(v15 + 256);
  v18 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v16 + 72LL);
  if ( *((_DWORD *)v18 - 1) != -1045879528 )
    __break(0x8228u);
  if ( (v18(v17) & 1) != 0 )
  {
LABEL_31:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "Attaching domain:%d\n", 2);
    v19 = ***(void (__fastcall ****)(__int64, char **, __int64))(v15 + 256);
    if ( *((_DWORD *)v19 - 1) != -1242077318 )
      __break(0x8228u);
    v19(v16, &iommu_ports, 1);
    *(_BYTE *)(v15 + 268) = 1;
    msm_gem_aspace_domain_attach_detach_update(v15, 0);
LABEL_36:
    v20 = a1[216];
    if ( v20 )
    {
      v21 = *(_QWORD *)(v20 + 256);
      v22 = (void (__fastcall ****)(__int64, char **, __int64))(v20 + 256);
      if ( (a2 & 1) == 0 )
      {
LABEL_44:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "Attaching domain:%d\n", 3);
        v24 = ***v22;
        if ( *((_DWORD *)v24 - 1) != -1242077318 )
          __break(0x8228u);
        v24(v21, &iommu_ports, 1);
        *(_BYTE *)(v20 + 268) = 1;
        msm_gem_aspace_domain_attach_detach_update(v20, 0);
        return 0;
      }
LABEL_41:
      v23 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v21 + 72LL);
      if ( *((_DWORD *)v23 - 1) != -1045879528 )
        __break(0x8228u);
      if ( (v23(v21) & 1) == 0 )
        return 0;
      goto LABEL_44;
    }
    return 0;
  }
  v20 = a1[216];
  if ( v20 )
  {
    v21 = *(_QWORD *)(v20 + 256);
    v22 = (void (__fastcall ****)(__int64, char **, __int64))(v20 + 256);
    goto LABEL_41;
  }
  return 0;
}
