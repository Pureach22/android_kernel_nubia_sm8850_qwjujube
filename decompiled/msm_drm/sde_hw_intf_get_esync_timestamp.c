unsigned __int64 __fastcall sde_hw_intf_get_esync_timestamp(__int64 a1)
{
  unsigned int v2; // w20

  v2 = sde_reg_read(a1, 1188);
  return v2 | (unsigned __int64)(sde_reg_read(a1, 1192) << 32);
}
