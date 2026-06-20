__int64 __fastcall swr_master_write(__int64 a1, unsigned __int16 a2, unsigned int a3)
{
  _DWORD *v3; // x8
  __int64 v6; // x0
  int v9; // w0

  v3 = *(_DWORD **)(a1 + 9080);
  if ( !v3 )
  {
    mutex_lock(a1 + 8736);
    if ( *(_BYTE *)(a1 + 15748) != 1 )
      return mutex_unlock(a1 + 8736);
    if ( *(int *)(a1 + 9128) >= 17104898 )
    {
      v9 = swrm_core_vote_request(a1, 1);
      if ( v9 == -522 )
      {
LABEL_14:
        if ( *(int *)(a1 + 9128) >= 17104898 )
          goto LABEL_15;
        return mutex_unlock(a1 + 8736);
      }
      if ( v9 )
        return mutex_unlock(a1 + 8736);
    }
    else if ( (unsigned int)swrm_clk_request(a1, 1) )
    {
      if ( (unsigned int)__ratelimit(&swrm_ahb_write__rs, "swrm_ahb_write") )
        dev_err(*(_QWORD *)(a1 + 8512), "%s: clock request failed\n", "swrm_ahb_write");
      return mutex_unlock(a1 + 8736);
    }
    writel(a3, *(_QWORD *)(a1 + 9032) + a2);
    if ( *(int *)(a1 + 9128) >= 17104898 )
    {
LABEL_15:
      swrm_core_vote_request(a1, 0);
      return mutex_unlock(a1 + 8736);
    }
    swrm_clk_request(a1, 0);
    goto LABEL_14;
  }
  v6 = *(_QWORD *)(a1 + 9064);
  if ( *(v3 - 1) != 731400050 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v3)(v6, a2);
}
