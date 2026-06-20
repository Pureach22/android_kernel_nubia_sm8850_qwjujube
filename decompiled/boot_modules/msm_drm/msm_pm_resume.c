__int64 __fastcall msm_pm_resume(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 *v3; // x9
  __int64 v4; // x9
  __int64 (*v5)(void); // x9

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(v1 + 56);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(__int64 **)(v2 + 8);
  if ( v3 && (v4 = *v3) != 0 && (v5 = *(__int64 (**)(void))(v4 + 216)) != nullptr )
  {
    if ( *((_DWORD *)v5 - 1) != 711998475 )
      __break(0x8229u);
    return v5();
  }
  else
  {
    drm_kms_helper_poll_enable(*(_QWORD *)(a1 + 152));
    return 0;
  }
}
