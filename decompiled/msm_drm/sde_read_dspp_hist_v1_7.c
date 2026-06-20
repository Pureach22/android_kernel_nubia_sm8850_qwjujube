__int64 __fastcall sde_read_dspp_hist_v1_7(_QWORD *a1, char *a2)
{
  __int64 v3; // x21
  char *v4; // x23
  int v5; // w20

  if ( !a1 || !a2 )
    return _drm_err("invalid parameters ctx %pK cfg %pK", a1, a2);
  v3 = 0;
  v4 = a2 + 8;
  v5 = *(_DWORD *)(*(_QWORD *)(a1[9] + 48LL) + 308LL);
  do
  {
    *(_DWORD *)&v4[v3] += sde_reg_read((__int64)a1, v5 + 1024 + (int)v3) & 0xFFFFFF;
    v3 += 4;
  }
  while ( v3 != 1024 );
  return sde_reg_write((__int64)a1, v5 + 4, 0, "offset_ctl");
}
