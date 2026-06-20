bool __fastcall mlo_mgr_is_link_switch_in_progress(_BOOL8 result)
{
  __int64 v1; // x19
  unsigned int v2; // w20

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1360);
    if ( v1 )
    {
      qdf_mutex_acquire(v1 + 1656);
      v2 = *(_DWORD *)(*(_QWORD *)(v1 + 3880) + 164LL);
      qdf_mutex_release(v1 + 1656);
      return v2 > 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
