__int64 __fastcall fastrpc_rpmsg_callback(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v3; // x20
  char is_wakeup; // w0

  v3 = *(_QWORD *)(a1 + 152);
  is_wakeup = qcom_glink_is_wakeup(1);
  return fastrpc_handle_rpc_response(v3, a2, a3, is_wakeup & 1);
}
