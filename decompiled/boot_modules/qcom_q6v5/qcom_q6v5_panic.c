__int64 __fastcall qcom_q6v5_panic(__int64 a1)
{
  qcom_smem_state_update_bits(
    *(_QWORD *)(a1 + 16),
    1LL << *(_DWORD *)(a1 + 56),
    (unsigned int)(1LL << *(_DWORD *)(a1 + 56)));
  return 200;
}
