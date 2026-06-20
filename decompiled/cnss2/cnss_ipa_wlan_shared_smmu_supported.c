__int64 __fastcall cnss_ipa_wlan_shared_smmu_supported(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x19
  __int64 compatible_node; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  unsigned __int64 v10; // x8
  __int64 v11; // x0
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x0
  const char *v15; // x1
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  __int16 v18; // w9
  const char *v19; // x8
  const char *v20; // x5
  unsigned __int64 v21; // x8
  __int16 v22; // w9
  const char *v23; // x8
  __int16 v24; // w9
  const char *v25; // x8
  __int16 v26; // w9
  const char *v27; // x8
  char v28; // w8
  unsigned __int64 v30; // x8
  __int16 v31; // w9
  const char *v32; // x8
  const char *v33; // x5
  __int16 v34; // w9
  const char *v35; // x8
  char v36; // [xsp+0h] [xbp-60h]
  __int64 v37; // [xsp+8h] [xbp-58h] BYREF
  __int64 v38; // [xsp+10h] [xbp-50h]
  __int64 v39; // [xsp+18h] [xbp-48h]
  __int64 v40; // [xsp+20h] [xbp-40h]
  __int64 v41; // [xsp+28h] [xbp-38h]
  __int64 v42; // [xsp+30h] [xbp-30h]
  __int64 v43; // [xsp+38h] [xbp-28h]
  __int64 v44; // [xsp+40h] [xbp-20h]
  __int64 v45; // [xsp+48h] [xbp-18h]
  __int64 v46; // [xsp+50h] [xbp-10h]
  __int64 v47; // [xsp+58h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v3 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(StatusReg + 16);
      v19 = (const char *)(StatusReg + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v19;
    }
    v20 = "plat_priv not available for IPA Shared CB cap\n";
    goto LABEL_34;
  }
  v6 = v3;
  compatible_node = of_find_compatible_node(0, 0, "qcom,ipa-smmu-wlan-cb");
  if ( !compatible_node )
  {
    v16 = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(v16 + 16);
      v23 = (const char *)(v16 + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v23;
    }
    v20 = "ipa-smmu-wlan-cb not enabled";
    goto LABEL_34;
  }
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(compatible_node, "qcom,iommu-group", 0, 0, 0, &v37) || (v8 = v37) == 0 )
  {
    v17 = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v24 = *(_DWORD *)(v17 + 16);
      v25 = (const char *)(v17 + 2320);
      if ( (v24 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v25;
    }
    v20 = "Unable to get ipa iommu group phandle";
    goto LABEL_34;
  }
  v9 = *(_QWORD *)(a1 + 744);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v9, "qcom,iommu-group", 0, 0, 0, &v37) || !v37 )
  {
    v21 = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v26 = *(_DWORD *)(v21 + 16);
      v27 = (const char *)(v21 + 2320);
      if ( (v26 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v27;
    }
    v20 = "Unable to get cnss iommu group phandle";
LABEL_34:
    cnss_debug_ipc_log_print(v14, v15, "cnss_ipa_wlan_shared_smmu_supported", 3u, 3u, v20, v4, v5, v36);
    v28 = 0;
    goto LABEL_35;
  }
  if ( v37 == v8 )
  {
    *(_BYTE *)(v6 + 7860) = 1;
    v30 = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v30 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v34 = *(_DWORD *)(v30 + 16);
      v35 = (const char *)(v30 + 2320);
      if ( (v34 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v35;
    }
    v33 = "CNSS and IPA share IOMMU group";
  }
  else
  {
    v10 = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v31 = *(_DWORD *)(v10 + 16);
      v32 = (const char *)(v10 + 2320);
      if ( (v31 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v32;
    }
    v33 = "CNSS and IPA do not share IOMMU group";
  }
  cnss_debug_ipc_log_print(v11, v12, "cnss_ipa_wlan_shared_smmu_supported", 6u, 6u, v33, v4, v5, v36);
  v28 = *(_BYTE *)(v6 + 7860);
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v28 & 1;
}
