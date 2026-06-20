__int64 __fastcall mlo_get_link_vdev_ix(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20

  qdf_mutex_acquire(a1 + 1656);
  if ( *(_QWORD *)(a1 + 24) == a2 )
  {
    v4 = 0;
  }
  else if ( *(_QWORD *)(a1 + 32) == a2 )
  {
    v4 = 1;
  }
  else
  {
    v4 = -1;
  }
  qdf_mutex_release(a1 + 1656);
  return v4;
}
