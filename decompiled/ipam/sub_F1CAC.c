__int64 sub_F1CAC()
{
  __int64 v0; // x28

  if ( (v0 & 0x20000000000000LL) != 0 )
    JUMPOUT(0xEAE6C);
  return ipa3_qmi_send_mhi_cleanup_request();
}
