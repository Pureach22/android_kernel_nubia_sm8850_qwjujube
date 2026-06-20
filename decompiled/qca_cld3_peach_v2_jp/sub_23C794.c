__int64 sub_23C794()
{
  __int64 v0; // x24

  if ( (v0 & 0x400000000LL) != 0 )
    JUMPOUT(0x23FA40);
  return send_update_edca_pifs_param_cmd_tlv();
}
