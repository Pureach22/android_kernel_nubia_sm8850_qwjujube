__int64 __fastcall sde_kms_vm_trusted_post_commit(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  int v7; // w4
  __int64 v8; // x20
  __int64 v9; // x11
  __int64 result; // x0
  __int64 v11; // x19
  __int64 v13; // x8
  __int64 v14; // x20
  __int64 v15; // x8
  _QWORD *v16; // x20
  _QWORD *i; // x22
  __int64 v18; // x0
  __int64 v19; // x8
  void (*v20)(void); // x9
  __int64 v21; // x0
  __int64 (__fastcall *v22)(_QWORD); // x9
  __int64 v23; // x8
  unsigned int v24; // w19

  if ( !a1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 6384);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 860LL);
  if ( (int)v3 < 1 )
    return 0;
  v4 = *(_QWORD *)(a2 + 32);
  v5 = 56 * v3;
  v6 = 0;
  while ( 1 )
  {
    v8 = *(_QWORD *)(v4 + v6);
    if ( !v8 )
      goto LABEL_7;
    v9 = *(_QWORD *)(v4 + v6 + 24);
    if ( (*(_BYTE *)(v9 + 9) & 1) == 0 )
      break;
    if ( v9 )
      goto LABEL_6;
LABEL_7:
    v6 += 56;
    if ( v5 == v6 )
      return 0;
  }
  if ( !v9 || (*(_BYTE *)(*(_QWORD *)(v4 + v6 + 16) + 9LL) & 1) == 0 )
    goto LABEL_7;
LABEL_6:
  v7 = *(_DWORD *)(v9 + 1568);
  if ( !v7 )
    goto LABEL_7;
  v11 = a1;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "valid vm request:%d found on crtc-%d\n", v7, *(_DWORD *)(v8 + 112));
    v4 = *(_QWORD *)(a2 + 32);
    a1 = v11;
  }
  v13 = *(_QWORD *)(v4 + 56LL * *(unsigned int *)(v8 + 160) + 24);
  if ( !v13 || *(_DWORD *)(v13 + 1568) != 1 )
    return 0;
  v14 = a1;
  ((void (*)(void))sde_kms_vm_pre_release)();
  v15 = *(_QWORD *)(v14 + 136);
  v16 = *(_QWORD **)(v15 + 840);
  for ( i = (_QWORD *)(v15 + 840); v16 != i; v16 = (_QWORD *)*v16 )
    sde_plane_set_sid(v16 - 1, 0);
  v18 = *(_QWORD *)(v11 + 3552);
  v19 = v11;
  if ( v18 )
  {
    v20 = *(void (**)(void))(v18 + 32);
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != 34661390 )
        __break(0x8229u);
      v20();
      v19 = v11;
    }
  }
  v21 = *(_QWORD *)(v19 + 6384);
  if ( v21 )
  {
    mutex_lock(v21);
    v19 = v11;
  }
  v22 = *(__int64 (__fastcall **)(_QWORD))(v2 + 80);
  if ( v22 )
  {
    if ( *((_DWORD *)v22 - 1) != 925264262 )
      __break(0x8229u);
    result = v22(v11);
    v19 = v11;
  }
  else
  {
    result = 0;
  }
  v23 = *(_QWORD *)(v19 + 6384);
  if ( v23 )
  {
    v24 = result;
    mutex_unlock(v23);
    return v24;
  }
  return result;
}
