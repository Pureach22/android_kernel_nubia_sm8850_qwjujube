__int64 __fastcall sde_hdcp_1x_force_encryption(__int64 a1, char a2)
{
  if ( !a1 )
    return printk(&unk_255B25, "sde_hdcp_1x_force_encryption");
  *(_BYTE *)(a1 + 35) = a2 & 1;
  return printk(&unk_25CE28, "sde_hdcp_1x_force_encryption");
}
