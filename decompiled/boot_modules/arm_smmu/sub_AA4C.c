__int64 sub_AA4C()
{
  __int16 v0; // w28

  if ( (v0 & 0x1000) == 0 )
    JUMPOUT(0xFFD8);
  return arm_smmu_print_context_fault_info();
}
