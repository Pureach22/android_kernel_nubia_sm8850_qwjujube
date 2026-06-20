__int64 __fastcall cds_smmu_mem_map_setup(__int64 a1, char a2)
{
  __int64 domain; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  int attr; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  const char *v24; // x4
  __int64 result; // x0
  _WORD v26[2]; // [xsp+0h] [xbp-10h] BYREF
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  domain = pld_smmu_get_domain(*(_QWORD *)(a1 + 40));
  v13 = domain;
  if ( !domain )
  {
    qdf_trace_msg(0x38u, 4u, "%s: No SMMU mapping present", v5, v6, v7, v8, v9, v10, v11, v12, "cds_smmu_mem_map_setup");
    goto LABEL_8;
  }
  v27 = 0;
  attr = qdf_iommu_domain_get_attr(domain, 10, &v27);
  if ( attr | v27 )
  {
LABEL_8:
    *(_BYTE *)(a1 + 608) = 0;
    v24 = "disabled";
    *(_QWORD *)(a1 + 616) = v13;
    goto LABEL_11;
  }
  if ( (a2 & 1) == 0 )
  {
    *(_QWORD *)(a1 + 616) = v13;
    *(_BYTE *)(a1 + 608) = 1;
LABEL_10:
    v24 = "enabled";
    goto LABEL_11;
  }
  v26[0] = 0;
  v27 = 0;
  ipa_get_smmu_params(&v27, v26);
  v23 = LOBYTE(v26[0]);
  *(_BYTE *)(a1 + 608) = v26[0];
  if ( (v23 & 1) == 0 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: SMMU mismatch; IPA:%s, WLAN:%s",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cds_smmu_mem_map_setup",
      "disabled",
      "enabled");
    result = 16;
    goto LABEL_12;
  }
  *(_QWORD *)(a1 + 616) = v13;
  if ( v23 )
    goto LABEL_10;
  v24 = "disabled";
LABEL_11:
  qdf_trace_msg(0x38u, 4u, "%s: SMMU S1 %s", v15, v16, v17, v18, v19, v20, v21, v22, "cds_smmu_mem_map_setup", v24);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
