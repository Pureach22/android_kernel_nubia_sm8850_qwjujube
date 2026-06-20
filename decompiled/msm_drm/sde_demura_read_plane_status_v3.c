__int64 __fastcall sde_demura_read_plane_status_v3(__int64 a1, int *a2)
{
  __int64 result; // x0
  int v5; // w8
  int v6; // w8

  if ( !a1 )
    return _drm_err("invalid parameter ctx %pK", nullptr);
  *a2 = 4;
  result = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL) + 24));
  v5 = *(_DWORD *)(a1 + 64);
  if ( v5 > 2 )
  {
    if ( v5 == 4 )
    {
LABEL_12:
      if ( (_DWORD)result == 3 )
      {
        v6 = 3;
      }
      else
      {
        if ( (_DWORD)result != 1 )
          return result;
        v6 = 1;
      }
      goto LABEL_17;
    }
    if ( v5 != 3 )
      return result;
  }
  else if ( v5 != 1 )
  {
    if ( v5 != 2 )
      return result;
    goto LABEL_12;
  }
  if ( (_DWORD)result == 3 )
  {
    v6 = 2;
LABEL_17:
    *a2 = v6;
    return result;
  }
  if ( (_DWORD)result == 1 )
    *a2 = 0;
  return result;
}
