__int64 __fastcall ipa_smmu_free_sgt(_QWORD **a1)
{
  if ( *a1 )
  {
    kfree(**a1);
    **a1 = 0;
    kfree(*a1);
    *a1 = nullptr;
  }
  return 0;
}
