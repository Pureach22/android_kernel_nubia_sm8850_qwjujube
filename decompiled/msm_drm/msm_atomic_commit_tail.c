__int64 __fastcall msm_atomic_commit_tail(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  void (__fastcall *v4)(__int64, __int64); // x8
  long double v5; // q0
  void (__fastcall *v6)(__int64, __int64, long double); // x8
  __int64 v7; // x8
  __int64 v8; // x23
  __int64 v9; // x24
  __int64 v10; // x22
  __int64 v11; // x9
  void (__fastcall *v12)(_QWORD); // x8
  void (__fastcall *v13)(__int64, __int64); // x8

  v1 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(*(_QWORD *)(v1 + 56) + 8LL);
  v4 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v3 + 56LL);
  if ( *((_DWORD *)v4 - 1) != 1690549992 )
    __break(0x8228u);
  v4(v3, a1);
  drm_atomic_helper_commit_modeset_disables(v1, a1);
  drm_atomic_helper_commit_planes(v1, a1, 0);
  drm_atomic_helper_commit_modeset_enables(v1, a1);
  if ( *(_QWORD *)(*(_QWORD *)v3 + 64LL) )
  {
    *(double *)&v5 = _drm_dev_dbg(0, 0, 4, "triggering commit\n");
    v6 = *(void (__fastcall **)(__int64, __int64, long double))(*(_QWORD *)v3 + 64LL);
    if ( *((_DWORD *)v6 - 1) != 1690549992 )
      __break(0x8228u);
    v6(v3, a1, v5);
  }
  if ( (*(_BYTE *)(a1 + 16) & 2) == 0 )
  {
    v7 = *(_QWORD *)(a1 + 8);
    if ( *(int *)(v7 + 860) >= 1 )
    {
      v8 = 0;
      v9 = 0;
      v10 = *(_QWORD *)(*(_QWORD *)(v7 + 56) + 8LL);
      do
      {
        v11 = *(_QWORD *)(a1 + 32);
        if ( *(_QWORD *)(v11 + v8) && *(_BYTE *)(*(_QWORD *)(v11 + v8 + 24) + 9LL) == 1 )
        {
          v12 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v10 + 88LL);
          if ( *((_DWORD *)v12 - 1) != 1715898470 )
            __break(0x8228u);
          v12(v10);
          v7 = *(_QWORD *)(a1 + 8);
        }
        ++v9;
        v8 += 56;
      }
      while ( v9 < *(int *)(v7 + 860) );
    }
  }
  v13 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v3 + 72LL);
  if ( *((_DWORD *)v13 - 1) != 1690549992 )
    __break(0x8228u);
  v13(v3, a1);
  drm_atomic_helper_wait_for_vblanks(v1, a1);
  drm_atomic_helper_commit_hw_done(a1);
  return drm_atomic_helper_cleanup_planes(v1, a1);
}
