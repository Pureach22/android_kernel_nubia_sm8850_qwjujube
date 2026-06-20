__int64 sub_686914()
{
  __int64 v0; // x19

  if ( (v0 & 0x2000000000LL) != 0 )
    JUMPOUT(0x684814);
  return send_set_del_pmkid_cache_cmd_tlv();
}
