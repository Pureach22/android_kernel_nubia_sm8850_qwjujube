__int64 __fastcall qcom_mhi_qrtr_dl_callback(__int64 result, __int64 a2)
{
  __int64 v2; // x19

  v2 = *(_QWORD *)(result + 192);
  if ( v2 && !*(_DWORD *)(a2 + 20) )
  {
    result = qrtr_endpoint_post(*(_QWORD *)(result + 192), *(_QWORD *)a2, *(_QWORD *)(a2 + 8));
    if ( (_DWORD)result == -22 )
      return dev_err(*(_QWORD *)(v2 + 32), "invalid ipcrouter packet\n");
  }
  return result;
}
