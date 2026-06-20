__int64 __fastcall swr_master_read(__int64 a1, unsigned __int16 a2)
{
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v4; // x0
  unsigned int v7; // w20
  int v8; // w0

  v2 = *(__int64 (__fastcall **)(_QWORD))(a1 + 9072);
  if ( !v2 )
  {
    mutex_lock(a1 + 8736);
    if ( *(_BYTE *)(a1 + 15748) != 1 )
    {
LABEL_9:
      v7 = 0;
LABEL_16:
      mutex_unlock(a1 + 8736);
      return v7;
    }
    if ( *(int *)(a1 + 9128) >= 17104898 )
    {
      v8 = swrm_core_vote_request(a1, 1);
      v7 = 0;
      if ( v8 == -522 )
        goto LABEL_14;
      if ( v8 )
        goto LABEL_16;
    }
    else if ( (unsigned int)swrm_clk_request(a1, 1) )
    {
      if ( (unsigned int)__ratelimit(&swrm_ahb_read__rs, "swrm_ahb_read") )
      {
        dev_err(*(_QWORD *)(a1 + 8512), "%s: clock request failed\n", "swrm_ahb_read");
        v7 = 0;
        goto LABEL_16;
      }
      goto LABEL_9;
    }
    v7 = readl(*(_QWORD *)(a1 + 9032) + a2);
    if ( *(int *)(a1 + 9128) >= 17104898 )
      goto LABEL_15;
    swrm_clk_request(a1, 0);
LABEL_14:
    if ( *(int *)(a1 + 9128) < 17104898 )
      goto LABEL_16;
LABEL_15:
    swrm_core_vote_request(a1, 0);
    goto LABEL_16;
  }
  v4 = *(_QWORD *)(a1 + 9064);
  if ( *((_DWORD *)v2 - 1) != -1029257147 )
    __break(0x8228u);
  return v2(v4);
}
