__int64 __fastcall mlo_link_recfg_get_state(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w19

  if ( a1 )
  {
    qdf_mutex_acquire(*(_QWORD *)(a1 + 3888) + 760LL);
    v2 = *(_QWORD *)(a1 + 3888);
    v3 = *(_DWORD *)(v2 + 832);
    qdf_mutex_release(v2 + 760);
  }
  else
  {
    return 8;
  }
  return v3;
}
