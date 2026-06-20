__int64 __fastcall sde_setup_dspp_hist_v1_7(_QWORD *a1, char *a2)
{
  char v3; // w21
  unsigned int v4; // w20
  int v5; // w0
  int v6; // w8
  int v7; // w8
  unsigned int v8; // w21

  if ( !a1 || !a2 )
    return _drm_err("invalid parameters ctx %pK cfg %pK", a1, a2);
  v3 = *a2;
  v4 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 308LL);
  v5 = sde_reg_read((__int64)a1, v4);
  if ( (v5 & 0xFE0000E0) != 0 )
    v6 = -65537;
  else
    v6 = 32440095;
  v7 = v6 & v5;
  if ( (v3 & 1) != 0 )
    v8 = v5 | 0x110000;
  else
    v8 = v7;
  sde_reg_write((__int64)a1, v4 + 4, 0, "offset");
  return sde_reg_write((__int64)a1, v4, v8, "base");
}
