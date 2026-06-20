__int64 __fastcall qcom_smd_qrtr_remove(__int64 a1)
{
  __int64 result; // x0

  result = qrtr_endpoint_unregister(*(_QWORD *)(a1 + 152));
  *(_QWORD *)(a1 + 152) = 0;
  return result;
}
