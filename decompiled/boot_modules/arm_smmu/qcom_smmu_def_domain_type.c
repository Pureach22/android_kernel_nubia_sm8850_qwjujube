__int64 __fastcall qcom_smmu_def_domain_type(__int64 a1)
{
  return 4 * (unsigned int)(of_match_device(&qcom_smmu_client_of_match, a1) != 0);
}
