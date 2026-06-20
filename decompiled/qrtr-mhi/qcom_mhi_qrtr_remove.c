__int64 __fastcall qcom_mhi_qrtr_remove(__int64 a1)
{
  __int64 result; // x0

  qrtr_endpoint_unregister(*(_QWORD *)(a1 + 192));
  result = mhi_unprepare_from_transfer(a1);
  *(_QWORD *)(a1 + 192) = 0;
  return result;
}
