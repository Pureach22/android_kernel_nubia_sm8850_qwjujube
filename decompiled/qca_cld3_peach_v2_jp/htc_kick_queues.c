__int64 __fastcall htc_kick_queues(__int64 *a1)
{
  __int64 result; // x0
  __int64 i; // x20
  __int64 *v4; // x21
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0

  result = hif_rtpm_get(2u, 3u);
  if ( !(_DWORD)result )
  {
    for ( i = 0; i != 369; i += 41 )
    {
      v4 = &a1[i];
      if ( WORD2(a1[i + 1]) )
      {
        v5 = (void (__fastcall *)(_QWORD))v4[10];
        if ( v5 )
        {
          v6 = a1[i + 2];
          if ( *((_DWORD *)v5 - 1) != 251140989 )
            __break(0x8228u);
          v5(v6);
        }
        htc_try_send((__int64)a1, (_DWORD *)v4 + 2, 0);
      }
    }
    hif_fastpath_resume(*a1);
    return hif_rtpm_put(4, 3u);
  }
  return result;
}
