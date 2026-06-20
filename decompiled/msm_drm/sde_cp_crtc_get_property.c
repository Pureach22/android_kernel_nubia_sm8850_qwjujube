__int64 __fastcall sde_cp_crtc_get_property(char *a1, _DWORD *a2, _QWORD *a3)
{
  char *v6; // x9

  if ( a1 && a2 && a3 )
  {
    *a3 = 0;
    mutex_lock(a1 + 4664);
    v6 = a1 + 4520;
    while ( 1 )
    {
      v6 = *(char **)v6;
      if ( v6 == a1 + 4520 )
        break;
      if ( a2[4] == *((_DWORD *)v6 - 10) )
      {
        *a3 = *((_QWORD *)v6 - 2);
        break;
      }
    }
    mutex_unlock(a1 + 4664);
    return 0;
  }
  else
  {
    _drm_err("invalid crtc %pK property %pK val %pK\n", a1, a2, a3);
    return 4294967274LL;
  }
}
