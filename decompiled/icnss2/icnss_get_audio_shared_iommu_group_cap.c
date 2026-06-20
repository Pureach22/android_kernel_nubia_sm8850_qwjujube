__int64 __fastcall icnss_get_audio_shared_iommu_group_cap(__int64 a1)
{
  __int64 v1; // x20
  char v2; // w8
  __int64 compatible_node; // x0
  const char *v6; // x19
  __int64 v7; // x21
  __int64 v8; // x0
  const char *v9; // x19
  __int64 v10; // [xsp+8h] [xbp-58h] BYREF
  __int64 v11; // [xsp+10h] [xbp-50h]
  __int64 v12; // [xsp+18h] [xbp-48h]
  __int64 v13; // [xsp+20h] [xbp-40h]
  __int64 v14; // [xsp+28h] [xbp-38h]
  __int64 v15; // [xsp+30h] [xbp-30h]
  __int64 v16; // [xsp+38h] [xbp-28h]
  __int64 v17; // [xsp+40h] [xbp-20h]
  __int64 v18; // [xsp+48h] [xbp-18h]
  __int64 v19; // [xsp+50h] [xbp-10h]
  __int64 v20; // [xsp+58h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    goto LABEL_2;
  compatible_node = of_find_compatible_node(0, 0, "qcom,icnss-direct-link");
  if ( !compatible_node )
  {
    v6 = "%sicnss2: Unable to get direct link node";
    printk("%sicnss2: Unable to get direct link node", byte_130B32);
LABEL_14:
    ipc_log_string(icnss_ipc_log_context, v6, &unk_12DBF3);
LABEL_2:
    v2 = 0;
    goto LABEL_3;
  }
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(compatible_node, "qcom,iommu-group", 0, 0, 0, &v10) || (v7 = v10) == 0 )
  {
    v6 = "%sicnss2: Unable to get direct link iommu group phandle";
    printk("%sicnss2: Unable to get direct link iommu group phandle", byte_130B32);
    goto LABEL_14;
  }
  v8 = *(_QWORD *)(a1 + 744);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v8, "qcom,iommu-group", 0, 0, 0, &v10) || !v10 )
  {
    v6 = "%sicnss2: Unable to get cnss iommu group phandle";
    printk("%sicnss2: Unable to get cnss iommu group phandle", byte_130B32);
    goto LABEL_14;
  }
  if ( v10 == v7 )
  {
    v9 = "%sicnss2: CNSS and direct link share IOMMU group";
    *(_BYTE *)(v1 + 6153) = 1;
    printk("%sicnss2: CNSS and direct link share IOMMU group", byte_13289B);
  }
  else
  {
    v9 = "%sicnss2: CNSS and direct link do not share IOMMU group";
    printk("%sicnss2: CNSS and direct link do not share IOMMU group", byte_13289B);
  }
  ipc_log_string(icnss_ipc_log_context, v9, &unk_12DBF3);
  v2 = *(_BYTE *)(v1 + 6153);
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v2 & 1;
}
