__int64 __fastcall wda_qmi_client_release(__int64 result)
{
  if ( result )
    return qmi_handle_release(result + 48);
  return result;
}
