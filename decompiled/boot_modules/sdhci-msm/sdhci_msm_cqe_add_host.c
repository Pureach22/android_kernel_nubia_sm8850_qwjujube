__int64 __fastcall sdhci_msm_cqe_add_host(__int64 a1, __int64 a2)
{
  unsigned int v4; // w22
  unsigned __int64 v5; // x0
  _QWORD *v6; // x21
  char v7; // w8
  __int64 *v8; // x25
  unsigned int v9; // w24
  __int64 (*v10)(void); // x8
  __int64 v11; // x23
  unsigned __int64 v12; // x0
  int v13; // w0
  _DWORD *v14; // x8
  int v15; // w0
  _DWORD *v16; // x8
  __int64 v18; // x8
  const char *v19; // x2
  __int64 v20; // x8
  const char *v21; // x2

  if ( (*(_BYTE *)(a1 + 1163) & 0x10) != 0 )
    *(_DWORD *)(a1 + 1036) = 16;
  v4 = sdhci_setup_host(a1);
  if ( v4 )
    return v4;
  v5 = cqhci_pltfm_init(a2);
  v6 = (_QWORD *)v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a2 + 16, "cqhci-pltfm init: failed: %d\n", v5);
    v4 = (unsigned int)v6;
    goto LABEL_18;
  }
  *(_DWORD *)(*(_QWORD *)(a1 + 1536) + 1000LL) |= 0x1800000u;
  *(_QWORD *)v5 = &sdhci_msm_cqhci_ops;
  v7 = *(_BYTE *)(a1 + 2008);
  *(_QWORD *)(a1 + 1552) = v5;
  *(_BYTE *)(v5 + 62) = v7;
  v8 = *(__int64 **)(a1 + 1536);
  v9 = *(_DWORD *)(a1 + 796);
  v10 = *(__int64 (**)(void))(*(_QWORD *)v5 + 16LL);
  v11 = *v8;
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 1427797680 )
      __break(0x8228u);
    if ( (v10() & 0x10000000) == 0 )
      goto LABEL_11;
  }
  else if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 8) + 4LL)) & 0x10000000) == 0 )
  {
    goto LABEL_11;
  }
  v12 = of_qcom_ice_get(v11);
  if ( v12 == -95 )
  {
    dev_warn(v11, "Disabling inline encryption support\n");
  }
  else
  {
    v4 = v12;
    if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(a1 + 1512) = v12;
      *((_DWORD *)v8 + 250) |= 0x8000000u;
    }
    else if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      goto LABEL_18;
    }
  }
LABEL_11:
  v13 = cqhci_init(v6, *(_QWORD *)(a1 + 72), (v9 >> 12) & 1);
  if ( v13 )
  {
    v18 = *(_QWORD *)(a1 + 72);
    v4 = v13;
    v19 = *(const char **)(v18 + 120);
    if ( !v19 )
      v19 = *(const char **)(v18 + 8);
    dev_err(a2 + 16, "%s: CQE init: failed (%d)\n", v19, v13);
    goto LABEL_18;
  }
  v14 = *(_DWORD **)(*v6 + 16LL);
  if ( v14 )
  {
    if ( *(v14 - 1) != 1427797680 )
      __break(0x8228u);
    v15 = ((__int64 (__fastcall *)(_QWORD *, __int64))v14)(v6, 2560);
  }
  else
  {
    v15 = readl_relaxed((unsigned int *)(v6[1] + 2560LL));
  }
  v16 = *(_DWORD **)(*v6 + 8LL);
  if ( v16 )
  {
    if ( *(v16 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v16)(v6, v15 | 0x6000u, 2560);
    if ( (*(_BYTE *)(a1 + 797) & 0x10) == 0 )
      goto LABEL_17;
    goto LABEL_16;
  }
  writel_relaxed(v15 | 0x6000, (unsigned int *)(v6[1] + 2560LL));
  if ( (*(_BYTE *)(a1 + 797) & 0x10) != 0 )
LABEL_16:
    *(_DWORD *)(a1 + 1032) = 12;
LABEL_17:
  v4 = _sdhci_add_host(a1);
  if ( v4 )
  {
LABEL_18:
    sdhci_cleanup_host(a1);
    return v4;
  }
  v20 = *(_QWORD *)(a1 + 72);
  v21 = *(const char **)(v20 + 120);
  if ( !v21 )
    v21 = *(const char **)(v20 + 8);
  dev_info(a2 + 16, "%s: CQE init: success\n", v21);
  return 0;
}
