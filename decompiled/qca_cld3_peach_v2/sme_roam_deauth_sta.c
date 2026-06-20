__int64 __fastcall sme_roam_deauth_sta(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w22
  __int64 result; // x0
  __int64 v8; // x8
  unsigned int v9; // w20

  if ( !a1 )
    return 16;
  v3 = (unsigned __int8)a2;
  qdf_trace(52, 0x53u, (unsigned __int8)a2, *(unsigned __int16 *)(a3 + 12));
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( v3 <= 5 && (v8 = *(_QWORD *)(a1 + 17296)) != 0 && *(_BYTE *)(v8 + 96LL * (unsigned __int8)a2 + 1) == 1 )
      v9 = csr_roam_issue_deauth_sta_cmd(a1, a2, a3);
    else
      v9 = 4;
    qdf_mutex_release(a1 + 12848);
    return v9;
  }
  return result;
}
