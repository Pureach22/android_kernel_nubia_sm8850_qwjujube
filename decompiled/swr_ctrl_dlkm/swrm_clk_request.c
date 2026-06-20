__int64 __fastcall swrm_clk_request(__int64 a1, char a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int v7; // w20
  _DWORD *v8; // x8
  __int64 v9; // x0
  int v10; // w8
  _DWORD *v11; // x8
  __int64 v12; // x0
  int v13; // w8
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  __int64 v15; // x0
  _DWORD *v17; // x8
  __int64 v18; // x0

  if ( *(_QWORD *)(a1 + 9096) && *(_QWORD *)(a1 + 9064) )
  {
    mutex_lock(a1 + 8640);
    if ( (a2 & 1) != 0 )
    {
      if ( *(_BYTE *)(a1 + 15748) != 1 )
      {
        v7 = -19;
LABEL_34:
        mutex_unlock(a1 + 8640);
        return v7;
      }
      if ( *(int *)(a1 + 9128) <= 17104897 && (v4 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 9104)) != nullptr )
      {
        v5 = *(_QWORD *)(a1 + 9064);
        if ( *((_DWORD *)v4 - 1) != -1297827279 )
          __break(0x8228u);
        v6 = v4(v5, 1);
        if ( v6 )
        {
          v7 = v6;
          if ( (unsigned int)__ratelimit(&swrm_clk_request__rs, "swrm_clk_request") )
            dev_err(*(_QWORD *)(a1 + 8512), "%s: core vote request failed\n", "swrm_clk_request");
          v8 = *(_DWORD **)(a1 + 9104);
          v9 = *(_QWORD *)(a1 + 9064);
          if ( *(v8 - 1) != -1297827279 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v8)(v9, 0);
          goto LABEL_34;
        }
        v17 = *(_DWORD **)(a1 + 9104);
        v18 = *(_QWORD *)(a1 + 9064);
        if ( *(v17 - 1) != -1297827279 )
          __break(0x8228u);
        v7 = ((__int64 (__fastcall *)(__int64, _QWORD))v17)(v18, 0);
      }
      else
      {
        v7 = 0;
      }
      v13 = *(_DWORD *)(a1 + 8536);
      *(_DWORD *)(a1 + 8536) = v13 + 1;
      if ( !v13 )
      {
        v14 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 9096);
        v15 = *(_QWORD *)(a1 + 9064);
        if ( *((_DWORD *)v14 - 1) != -1297827279 )
          __break(0x8228u);
        v7 = v14(v15, 1);
        if ( v7 )
        {
          if ( (unsigned int)__ratelimit(&swrm_clk_request__rs_56, "swrm_clk_request") )
            dev_err(*(_QWORD *)(a1 + 8512), "%s: clock enable req failed", "swrm_clk_request");
          --*(_DWORD *)(a1 + 8536);
        }
      }
    }
    else
    {
      v10 = *(_DWORD *)(a1 + 8536) - 1;
      *(_DWORD *)(a1 + 8536) = v10;
      if ( !v10 )
      {
        v11 = *(_DWORD **)(a1 + 9096);
        v12 = *(_QWORD *)(a1 + 9064);
        if ( *(v11 - 1) != -1297827279 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v11)(v12, 0);
        complete(a1 + 8544);
      }
      v7 = 0;
    }
    if ( (*(_DWORD *)(a1 + 8536) & 0x80000000) != 0 )
    {
      if ( (unsigned int)__ratelimit(&swrm_clk_request__rs_58, "swrm_clk_request") )
        dev_err(*(_QWORD *)(a1 + 8512), "%s: swrm clk count mismatch\n", "swrm_clk_request");
      *(_DWORD *)(a1 + 8536) = 0;
    }
    goto LABEL_34;
  }
  return (unsigned int)-22;
}
