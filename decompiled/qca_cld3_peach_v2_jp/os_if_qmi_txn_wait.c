__int64 os_if_qmi_txn_wait()
{
  __int64 v0; // x0

  v0 = qmi_txn_wait();
  if ( (v0 & 0x80000000) != 0 )
    return qdf_status_from_os_return(v0);
  else
    return 0;
}
