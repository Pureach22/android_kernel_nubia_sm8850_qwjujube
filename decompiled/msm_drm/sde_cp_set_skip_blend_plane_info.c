__int64 __fastcall sde_cp_set_skip_blend_plane_info(char *a1, unsigned __int8 *a2)
{
  int v4; // w9
  __int64 v5; // x8
  char *v6; // x8
  int v7; // w9

  if ( !a1 || !a2 )
    return _drm_err("invalid crtc handle drm_crtc %pK skip_blend %pK\n", a1, a2);
  mutex_lock(a1 + 4664);
  v4 = *a2;
  v5 = 7976;
  if ( a2[20] )
    v5 = 7996;
  v6 = &a1[v5];
  *v6 = v4;
  if ( v4 == 1 )
  {
    *((_DWORD *)v6 + 1) = *((_DWORD *)a2 + 1);
    *((_DWORD *)v6 + 2) = *((_DWORD *)a2 + 2);
    *((_DWORD *)v6 + 3) = *((_DWORD *)a2 + 3);
    v7 = *((_DWORD *)a2 + 4);
  }
  else
  {
    v7 = 0;
    *(_QWORD *)(v6 + 4) = 0;
    *((_DWORD *)v6 + 3) = 0;
  }
  *((_DWORD *)v6 + 4) = v7;
  return mutex_unlock(a1 + 4664);
}
