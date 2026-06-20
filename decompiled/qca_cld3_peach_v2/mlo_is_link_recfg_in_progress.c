bool __fastcall mlo_is_link_recfg_in_progress(_BOOL8 result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1360);
    if ( v1 && (v2 = *(_QWORD *)(v1 + 3888)) != 0 )
    {
      v3 = result;
      qdf_mutex_acquire(v2 + 760);
      v4 = *(_QWORD *)(*(_QWORD *)(v3 + 1360) + 3888LL);
      LODWORD(v3) = *(_DWORD *)(v4 + 832);
      qdf_mutex_release(v4 + 760);
      return (_DWORD)v3 != 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
