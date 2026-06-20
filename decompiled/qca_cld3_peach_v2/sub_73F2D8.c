__int64 sub_73F2D8()
{
  __int64 v0; // x19

  if ( (v0 & 0x2000000000LL) != 0 )
    JUMPOUT(0x73D1D8);
  return send_set_del_pmkid_cache_cmd_tlv();
}
