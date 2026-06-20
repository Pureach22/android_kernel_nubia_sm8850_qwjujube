__int64 __fastcall sme_get_pmk_info(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x8

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    if ( a1 )
    {
      if ( (unsigned __int8)a2 <= 5u )
      {
        v7 = *(_QWORD *)(a1 + 17224);
        if ( v7 )
        {
          if ( *(_BYTE *)(v7 + 96LL * (unsigned __int8)a2 + 1) == 1 )
            csr_get_pmk_info(a1, a2, a3);
        }
      }
    }
    return qdf_mutex_release(a1 + 12776);
  }
  return result;
}
