__int64 __fastcall arm_smmu_set_fault_handler_irq(__int64 result, __int64 a2, __int64 a3)
{
  *(_QWORD *)(result - 40) = a2;
  *(_QWORD *)(result - 32) = a3;
  return result;
}
