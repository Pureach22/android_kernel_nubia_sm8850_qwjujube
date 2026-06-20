__int64 __fastcall swrm_core_vote_request(__int64 a1, char a2)
{
  _DWORD *v4; // x8
  __int64 v5; // x0
  unsigned int v6; // w20

  if ( *(_QWORD *)(a1 + 9064) )
  {
    mutex_lock(a1 + 8640);
    if ( *(_BYTE *)(a1 + 15748) == 1 )
    {
      v4 = *(_DWORD **)(a1 + 9104);
      if ( v4 )
      {
        v5 = *(_QWORD *)(a1 + 9064);
        if ( *(v4 - 1) != -1297827279 )
          __break(0x8228u);
        v6 = ((__int64 (__fastcall *)(__int64, _QWORD))v4)(v5, a2 & 1);
        if ( v6
          && (unsigned int)__ratelimit(&swrm_core_vote_request_rtl, "swrm_core_vote_request")
          && (unsigned int)__ratelimit(&swrm_core_vote_request__rs, "swrm_core_vote_request") )
        {
          dev_err(*(_QWORD *)(a1 + 8512), "%s: core vote request failed\n", "swrm_core_vote_request");
        }
      }
      else
      {
        v6 = 0;
      }
    }
    else
    {
      v6 = -19;
    }
    mutex_unlock(a1 + 8640);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v6;
}
