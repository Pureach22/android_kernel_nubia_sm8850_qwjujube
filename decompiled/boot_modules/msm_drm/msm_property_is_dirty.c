bool __fastcall msm_property_is_dirty(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8

  if ( a1 )
  {
    if ( a2 )
    {
      v3 = *(_QWORD *)(a2 + 8);
      if ( v3 )
      {
        if ( *(_DWORD *)(a1 + 32) > a3 )
          return *(_QWORD *)(v3 + 32LL * a3 + 16) != v3 + 32LL * a3 + 16;
      }
    }
  }
  _drm_err("invalid argument(s), idx %u\n", a3);
  return 0;
}
