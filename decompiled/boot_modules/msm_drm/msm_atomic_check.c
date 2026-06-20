__int64 __fastcall msm_atomic_check(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x9

  v2 = *(_QWORD *)(a1 + 56);
  if ( !v2 )
    return drm_atomic_helper_check(a1, a2);
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
    return drm_atomic_helper_check(a1, a2);
  if ( !*(_QWORD *)v3 )
    return drm_atomic_helper_check(a1, a2);
  v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v3 + 120LL);
  if ( !v4 )
    return drm_atomic_helper_check(a1, a2);
  if ( *((_DWORD *)v4 - 1) != 265361133 )
    __break(0x8229u);
  return v4(v3);
}
