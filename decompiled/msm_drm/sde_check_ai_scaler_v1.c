__int64 __fastcall sde_check_ai_scaler_v1(_DWORD *a1, _QWORD *a2)
{
  unsigned int v2; // w1

  if ( !a1 || !a2 )
  {
    _drm_err("invalid parameters ctx %pK cfg %pK\n", a1, a2);
    return 4294967274LL;
  }
  if ( !*a2 && a1[16] == *(_DWORD *)(a2[6] + 64LL) )
  {
    v2 = *((_DWORD *)a2 + 7);
    if ( v2 >= 3 )
    {
      _drm_err("invalid mixer count %d\n", v2);
      return 4294967274LL;
    }
  }
  return 0;
}
