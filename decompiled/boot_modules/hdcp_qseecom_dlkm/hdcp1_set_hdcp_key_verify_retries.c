__int64 __fastcall hdcp1_set_hdcp_key_verify_retries(__int64 result, int a2)
{
  *(_DWORD *)(result + 40) = a2;
  return result;
}
