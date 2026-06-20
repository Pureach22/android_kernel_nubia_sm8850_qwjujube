__int64 __fastcall sme_set_host_offload(__int64 a1, unsigned int a2, _BYTE *a3)
{
  __int64 result; // x0
  unsigned int v7; // w0
  unsigned int v8; // w20

  qdf_trace(52, 0x32u, (unsigned __int8)a2, 0);
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( *a3 == 2 )
      v7 = sme_set_ps_ns_offload(a1, a3, a2);
    else
      v7 = sme_set_ps_host_offload(a1, a3, a2);
    v8 = v7;
    qdf_mutex_release(a1 + 12848);
    return v8;
  }
  return result;
}
