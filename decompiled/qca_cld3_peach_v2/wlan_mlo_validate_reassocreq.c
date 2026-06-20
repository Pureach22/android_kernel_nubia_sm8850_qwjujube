__int64 __fastcall wlan_mlo_validate_reassocreq(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  unsigned int v11; // w20

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 120);
    v10 = *(_QWORD *)(a1 + 56);
    if ( !v10 || *(_QWORD *)(a1 + 80) || *(_DWORD *)(v10 + 68) == 13 )
      v11 = 0;
    else
      v11 = 16;
    qdf_mutex_release(a1 + 120);
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s:  ml peer is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_validate_reassocreq");
    return 16;
  }
  return v11;
}
