__int64 __fastcall hdcp2_set_hdcp_key_verify_retries(__int64 result, int a2)
{
  *(_DWORD *)(result + 128) = a2;
  return result;
}
