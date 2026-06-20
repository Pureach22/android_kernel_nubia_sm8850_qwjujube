__int64 __fastcall mlo_reset_link_peer(__int64 a1, __int64 a2)
{
  int v4; // w8

  qdf_mutex_acquire(a1 + 120);
  v4 = *(_DWORD *)(a2 + 64);
  *(_QWORD *)(a2 + 784) = 0;
  *(_DWORD *)(a2 + 64) = v4 & 0xFFFFFFFE;
  return qdf_mutex_release(a1 + 120);
}
