__int64 __fastcall sme_update_hidden_ssid_status_cb(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 14584) = a2;
    qdf_mutex_release(a1 + 12848);
    return 0;
  }
  return result;
}
