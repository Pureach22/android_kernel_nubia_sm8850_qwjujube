__int64 __fastcall wlan_ipa_uc_smmu_map(char a1, unsigned int a2, __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  const char *v15; // x2

  if ( (ipa_cb_is_ready() & 1) == 0 )
  {
    v15 = "%s: IPA is not READY";
LABEL_7:
    qdf_trace_msg(0x61u, 4u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_ipa_uc_smmu_map");
    return 0;
  }
  if ( !a2 )
  {
    v15 = "%s: No buffers to map/unmap";
    goto LABEL_7;
  }
  if ( (a1 & 1) != 0 )
    return ipa_wdi_create_smmu_mapping_per_inst(0, a2, a3);
  else
    return ipa_wdi_release_smmu_mapping_per_inst(0, a2, a3);
}
