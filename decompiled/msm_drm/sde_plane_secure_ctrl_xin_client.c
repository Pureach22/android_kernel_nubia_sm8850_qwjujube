__int64 __fastcall sde_plane_secure_ctrl_xin_client(__int64 result, __int64 a2)
{
  __int64 v2; // x19

  if ( !result || !a2 )
    return printk(&unk_224704, "sde_plane_secure_ctrl_xin_client");
  if ( (*(_BYTE *)(result + 1938) & 0x20) == 0 )
  {
    v2 = result;
    sde_plane_set_qos_remap();
    return sde_plane_set_ot_limit(v2, a2);
  }
  return result;
}
