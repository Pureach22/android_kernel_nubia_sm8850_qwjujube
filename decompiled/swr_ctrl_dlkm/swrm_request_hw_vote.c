__int64 __fastcall swrm_request_hw_vote(__int64 a1, int a2, char a3)
{
  __int64 v6; // x0
  int v7; // w8
  unsigned int v8; // w20
  int v9; // w8
  int v10; // w8

  mutex_lock(a1 + 8736);
  if ( a2 != 1 )
  {
    if ( a2 )
      goto LABEL_25;
    v6 = *(_QWORD *)(a1 + 15848);
    if ( !v6 )
      goto LABEL_25;
    if ( (a3 & 1) != 0 )
    {
      if ( *(_BYTE *)(a1 + 15748) == 1 )
      {
        v7 = *(_DWORD *)(a1 + 15872);
        *(_DWORD *)(a1 + 15872) = v7 + 1;
        if ( !v7 )
        {
          v8 = digital_cdc_rsc_mgr_hw_vote_enable();
          if ( (v8 & 0x80000000) != 0 )
          {
            if ( (unsigned int)__ratelimit(&swrm_request_hw_vote__rs, "swrm_request_hw_vote") )
              dev_err(*(_QWORD *)(a1 + 8512), "%s:lpass core hw enable failed\n", "swrm_request_hw_vote");
            --*(_DWORD *)(a1 + 15872);
          }
          goto LABEL_26;
        }
LABEL_25:
        v8 = 0;
        goto LABEL_26;
      }
LABEL_21:
      v8 = -19;
      goto LABEL_26;
    }
    v10 = *(_DWORD *)(a1 + 15872) - 1;
    *(_DWORD *)(a1 + 15872) = v10;
    if ( v10 < 0 )
    {
      v8 = 0;
      *(_DWORD *)(a1 + 15872) = 0;
      goto LABEL_26;
    }
LABEL_23:
    if ( !v10 )
      digital_cdc_rsc_mgr_hw_vote_disable(v6, *(_QWORD *)(a1 + 8512));
    goto LABEL_25;
  }
  v6 = *(_QWORD *)(a1 + 15856);
  if ( !v6 )
    goto LABEL_25;
  if ( (a3 & 1) == 0 )
  {
    v10 = *(_DWORD *)(a1 + 15876) - 1;
    *(_DWORD *)(a1 + 15876) = v10;
    if ( v10 < 0 )
    {
      v8 = 0;
      *(_DWORD *)(a1 + 15876) = 0;
      goto LABEL_26;
    }
    goto LABEL_23;
  }
  if ( *(_BYTE *)(a1 + 15748) != 1 )
    goto LABEL_21;
  v9 = *(_DWORD *)(a1 + 15876);
  *(_DWORD *)(a1 + 15876) = v9 + 1;
  if ( v9 )
    goto LABEL_25;
  v8 = digital_cdc_rsc_mgr_hw_vote_enable();
  if ( (v8 & 0x80000000) != 0 )
  {
    if ( (unsigned int)__ratelimit(&swrm_request_hw_vote__rs_46, "swrm_request_hw_vote") )
      dev_err(*(_QWORD *)(a1 + 8512), "%s:lpass audio hw enable failed\n", "swrm_request_hw_vote");
    --*(_DWORD *)(a1 + 15876);
  }
LABEL_26:
  mutex_unlock(a1 + 8736);
  return v8;
}
