__int64 sub_CFB4()
{
  int v0; // w26

  if ( v0 )
    JUMPOUT(0xFFFFFFFFFFFC1ED0LL);
  return fast_smmu_unmap_page();
}
