__int64 __fastcall qcom_smd_trysend(__int64 a1, __int64 a2, __int64 a3)
{
  return _qcom_smd_send(*(_QWORD *)(a1 + 104), a2, a3, 0);
}
