__int64 __fastcall sme_roam_disconnect_sta(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w20

  if ( !a1 )
    return 16;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( (unsigned __int8)a2 <= 5u
      && (v7 = *(_QWORD *)(a1 + 17296)) != 0
      && *(_BYTE *)(v7 + 96LL * (unsigned __int8)a2 + 1) == 1 )
    {
      v8 = csr_roam_issue_disassociate_sta_cmd(a1, a2, a3);
    }
    else
    {
      v8 = 4;
    }
    qdf_mutex_release(a1 + 12848);
    return v8;
  }
  return result;
}
