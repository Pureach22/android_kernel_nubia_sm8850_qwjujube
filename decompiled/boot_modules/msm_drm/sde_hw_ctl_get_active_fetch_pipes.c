__int64 __fastcall sde_hw_ctl_get_active_fetch_pipes(__int64 a1)
{
  unsigned int v1; // w0

  if ( a1 )
  {
    v1 = sde_reg_read(a1, 252);
    return (v1 >> 15) & 0x1FE
         | ((v1 & 1) << 9) & 0x83FF
         | (((v1 >> 1) & 1) << 10) & 0xFFFF87FF
         | (((v1 >> 2) & 1) << 11) & 0xFFFF8FFF
         | (((v1 >> 3) & 1) << 12) & 0xFFFF9FFF
         | (((v1 >> 4) & 1) << 13) & 0xFFFFBFFF
         | (((v1 >> 5) & 1) << 14);
  }
  else
  {
    _drm_err("invalid args - ctx invalid\n");
    return 0;
  }
}
