__int64 __fastcall mlo_mgr_is_link_switch_on_assoc_vdev(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w21
  char v4; // w8

  if ( !a1 )
    return 0;
  v1 = *(_QWORD *)(a1 + 1360);
  if ( v1
    && (qdf_mutex_acquire(v1 + 1656),
        v3 = *(_DWORD *)(*(_QWORD *)(v1 + 3880) + 164LL),
        qdf_mutex_release(v1 + 1656),
        v3 >= 2) )
  {
    v4 = *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 3880LL) + 172LL);
  }
  else
  {
    v4 = 0;
  }
  return v4 & 1;
}
