__int64 __fastcall qdf_nbuf_smmu_map_debug(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, __int64 a4)
{
  return ipa_wdi_create_smmu_mapping_per_inst(a2, a3, a4);
}
