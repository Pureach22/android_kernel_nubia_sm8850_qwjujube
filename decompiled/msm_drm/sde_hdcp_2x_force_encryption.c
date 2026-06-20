__int64 __fastcall sde_hdcp_2x_force_encryption(__int64 a1, char a2)
{
  if ( !a1 )
    return printk(&unk_252102, "sde_hdcp_2x_force_encryption");
  *(_BYTE *)(a1 + 138) = a2 & 1;
  return printk(&unk_255BCB, "sde_hdcp_2x_force_encryption");
}
