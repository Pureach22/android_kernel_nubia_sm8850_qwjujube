__int64 __fastcall sub_B6E0(__int64 a1, int a2)
{
  if ( !a2 )
    JUMPOUT(0xFFFFFFFFFFF0F474LL);
  return qcom_scm_iommu_secure_ptbl_init();
}
