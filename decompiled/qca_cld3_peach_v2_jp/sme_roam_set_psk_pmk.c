__int64 __fastcall sme_roam_set_psk_pmk(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 result; // x0
  int v9; // w0
  __int64 v10; // x8
  unsigned int v11; // w20

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v9 = 4;
    if ( a1 )
    {
      if ( (unsigned __int8)a3 <= 5u )
      {
        v10 = *(_QWORD *)(a1 + 17224);
        if ( v10 )
        {
          if ( *(_BYTE *)(v10 + 96LL * (unsigned __int8)a3 + 1) == 1 )
            v9 = csr_roam_set_psk_pmk(a1, a2, a3, a4 & 1);
        }
      }
    }
    v11 = v9;
    qdf_mutex_release(a1 + 12776);
    return v11;
  }
  return result;
}
