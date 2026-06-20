__int64 __fastcall sme_register_set_connection_info_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 14328) = a3;
    *(_QWORD *)(a1 + 14320) = a2;
    qdf_mutex_release(a1 + 12776);
    return 0;
  }
  return result;
}
