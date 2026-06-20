__int64 __fastcall os_if_qmi_send_request(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x0

  v5 = qmi_send_request(a1, a2, a3, a4, a5);
  if ( (v5 & 0x80000000) != 0 )
    return qdf_status_from_os_return(v5);
  else
    return 0;
}
