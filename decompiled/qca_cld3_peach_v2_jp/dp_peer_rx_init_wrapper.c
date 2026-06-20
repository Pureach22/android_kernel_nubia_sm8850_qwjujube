__int64 __fastcall dp_peer_rx_init_wrapper(__int64 a1, __int64 *a2)
{
  __int64 result; // x0
  __int64 v4; // x8

  result = dp_peer_rx_tid_setup(a2);
  v4 = *a2;
  *((_DWORD *)a2 + 56) = 0;
  *((_BYTE *)a2 + 228) = 0;
  if ( v4 )
  {
    *(_DWORD *)(v4 + 64) = 0;
    *(_DWORD *)(*a2 + 76) = 0;
  }
  return result;
}
