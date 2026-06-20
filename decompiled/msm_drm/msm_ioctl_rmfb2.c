__int64 __fastcall msm_ioctl_rmfb2(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v4; // x0
  _QWORD *v5; // x20
  _QWORD *v6; // x9
  int v7; // w10
  _QWORD *v8; // x11
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  __int64 v11; // x10

  if ( (*(_DWORD *)(*(_QWORD *)(a1 + 48) + 176LL) & *(_DWORD *)(a1 + 104) & 2) == 0 )
    return 4294967274LL;
  v4 = drm_framebuffer_lookup(a1, a3, *a2);
  if ( !v4 )
    return 4294967294LL;
  v5 = (_QWORD *)v4;
  drm_mode_object_put(v4 + 24);
  mutex_lock(a3 + 176);
  v6 = *(_QWORD **)(a3 + 160);
  if ( v6 == (_QWORD *)(a3 + 160) )
    goto LABEL_14;
  v7 = 0;
  do
  {
    v8 = (_QWORD *)*v6;
    if ( v5 == v6 - 18 )
      v7 = 1;
    v6 = (_QWORD *)*v6;
  }
  while ( v8 != (_QWORD *)(a3 + 160) );
  if ( !v7 )
  {
LABEL_14:
    mutex_unlock(a3 + 176);
    return 4294967294LL;
  }
  v9 = (_QWORD *)v5[19];
  v10 = v5 + 18;
  if ( (_QWORD *)*v9 == v5 + 18 && (v11 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
  {
    *(_QWORD *)(v11 + 8) = v9;
    *v9 = v11;
  }
  else
  {
    _list_del_entry_valid_or_report(v5 + 18);
  }
  v5[18] = v5 + 18;
  v5[19] = v10;
  mutex_unlock(a3 + 176);
  drm_mode_object_put(v5 + 3);
  return 0;
}
