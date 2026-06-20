__int64 sub_25CC44()
{
  __int64 v0; // x24

  if ( (v0 & 0x400000000LL) != 0 )
    JUMPOUT(0x25FEF0);
  return send_update_edca_pifs_param_cmd_tlv();
}
