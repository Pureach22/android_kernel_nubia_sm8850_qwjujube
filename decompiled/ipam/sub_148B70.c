__int64 __fastcall sub_148B70(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x30

  return rmnet_ipa3_set_lan_client_info(a1, a2, a3, a4, a3 ^ ~(v4 >> 12));
}
