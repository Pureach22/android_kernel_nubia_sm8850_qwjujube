__int64 __fastcall sde_demura_read_plane_status(__int64 a1, int *a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // w8

  if ( !a1 )
    return _drm_err("invalid parameter ctx %pK", nullptr);
  result = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL) + 4));
  if ( (result & 4) == 0 )
  {
    v5 = 4;
LABEL_4:
    *a2 = v5;
    return result;
  }
  v6 = *(_DWORD *)(a1 + 64);
  if ( v6 > 2 )
  {
    if ( v6 == 4 )
      goto LABEL_15;
    if ( v6 != 3 )
      return result;
  }
  else if ( v6 != 1 )
  {
    if ( v6 != 2 )
      return result;
LABEL_15:
    if ( (result & 0x80000000) != 0 )
      v5 = 1;
    else
      v5 = 3;
    goto LABEL_4;
  }
  if ( (result & 0x80000000) == 0 )
  {
    v5 = 2;
    goto LABEL_4;
  }
  *a2 = 0;
  return result;
}
