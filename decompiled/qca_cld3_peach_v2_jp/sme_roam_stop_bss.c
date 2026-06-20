__int64 __fastcall sme_roam_stop_bss(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v5; // w20

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    v5 = csr_roam_issue_stop_bss_cmd(a1, a2, 1);
    qdf_mutex_release(a1 + 12776);
    return v5;
  }
  return result;
}
