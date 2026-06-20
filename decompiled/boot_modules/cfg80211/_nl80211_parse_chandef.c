__int64 __fastcall nl80211_parse_chandef(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  _QWORD *v4; // x24
  const char **v5; // x23
  __int64 v6; // x8
  unsigned int v10; // w22
  __int64 v11; // x8
  const char *v13; // x19
  _DWORD *channel_khz; // x0
  __int64 v15; // x8
  unsigned int v16; // w2
  __int64 v17; // x8
  __int64 v18; // x8
  const char *v19; // x8
  __int64 v21; // x8
  int v22; // w22
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  int v29; // w8
  const char *v30; // x19
  __int64 v31; // x3

  v4 = *(_QWORD **)(a2 + 32);
  v5 = *(const char ***)(a2 + 64);
  v6 = v4[38];
  if ( !v6 )
  {
    v13 = "Frequency is missing";
    goto LABEL_15;
  }
  v10 = 1000 * *(_DWORD *)(v6 + 4);
  v11 = v4[290];
  if ( v11 )
    v10 += *(_DWORD *)(v11 + 4);
  *(_QWORD *)(a4 + 16) = 0;
  *(_QWORD *)(a4 + 24) = 0;
  *(_QWORD *)a4 = 0;
  *(_QWORD *)(a4 + 8) = 0;
  channel_khz = (_DWORD *)ieee80211_get_channel_khz(a1 + 992, v10);
  *(_QWORD *)a4 = channel_khz;
  *(_DWORD *)(a4 + 16) = 0;
  *(_DWORD *)(a4 + 8) = 0;
  *(_DWORD *)(a4 + 12) = v10 / 0x3E8;
  *(_WORD *)(a4 + 28) = v10 % 0x3E8;
  if ( !channel_khz )
  {
    v13 = "Unknown channel";
LABEL_15:
    do_trace_netlink_extack(v13);
    if ( v5 )
    {
      *v5 = v13;
      v19 = (const char *)v4[38];
      goto LABEL_17;
    }
    return 4294967274LL;
  }
  v15 = v4[39];
  if ( v15 )
  {
    v16 = *(_DWORD *)(v15 + 4);
    if ( v16 > 3 )
    {
      do_trace_netlink_extack("invalid channel type");
      if ( !v5 )
        return 4294967274LL;
      *v5 = "invalid channel type";
      v19 = (const char *)v4[39];
      goto LABEL_17;
    }
    cfg80211_chandef_create(a4, (__int64)channel_khz, v16);
    v17 = v4[160];
    if ( v17 && *(_DWORD *)(a4 + 12) != *(_DWORD *)(v17 + 4) )
    {
      do_trace_netlink_extack("bad center frequency 1");
      if ( !v5 )
        return 4294967274LL;
      *v5 = "bad center frequency 1";
      v19 = (const char *)v4[160];
      goto LABEL_17;
    }
    v18 = v4[161];
    if ( v18 && *(_DWORD *)(v18 + 4) )
    {
      do_trace_netlink_extack("center frequency 2 can't be used");
      if ( v5 )
      {
        *v5 = "center frequency 2 can't be used";
        v19 = (const char *)v4[161];
LABEL_17:
        v5[1] = v19;
        v5[2] = nullptr;
        return 4294967274LL;
      }
      return 4294967274LL;
    }
  }
  else
  {
    v21 = v4[159];
    if ( v21 )
    {
      v22 = *(_DWORD *)(v21 + 4);
      *(_DWORD *)(a4 + 8) = v22;
      if ( *channel_khz == 4 && v22 != (unsigned int)ieee80211_s1g_channel_width(channel_khz) )
      {
        do_trace_netlink_extack("bad channel width");
        if ( !v5 )
          return 4294967274LL;
        *v5 = "bad channel width";
        v19 = (const char *)v4[159];
        goto LABEL_17;
      }
      v23 = v4[160];
      if ( v23 )
      {
        *(_DWORD *)(a4 + 12) = *(_DWORD *)(v23 + 4);
        v24 = v4[291];
        if ( v24 )
          LODWORD(v24) = *(_DWORD *)(v24 + 4);
        *(_WORD *)(a4 + 28) = v24;
      }
      v25 = v4[161];
      if ( v25 )
        *(_DWORD *)(a4 + 16) = *(_DWORD *)(v25 + 4);
    }
  }
  v26 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 2240LL);
  if ( v26 )
  {
    *(_BYTE *)(a4 + 20) = *(_BYTE *)(v26 + 4);
    v27 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 2248LL);
    if ( v27 )
      *(_DWORD *)(a4 + 24) = *(unsigned __int8 *)(v27 + 4);
  }
  else
  {
    *(_DWORD *)(a4 + 24) = 0;
    *(_BYTE *)(a4 + 20) = 0;
  }
  v28 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 2576LL);
  if ( v28 )
  {
    v29 = *(_DWORD *)(v28 + 4);
    *(_WORD *)(a4 + 30) = v29;
    if ( (_WORD)v29 )
    {
      if ( (*(_BYTE *)(a1 + 1111) & 0x40) == 0 )
      {
        v30 = "driver doesn't support puncturing";
        goto LABEL_50;
      }
    }
  }
  if ( (cfg80211_chandef_valid((__int64 *)a4) & 1) == 0 )
  {
    v30 = "invalid channel definition";
    goto LABEL_50;
  }
  if ( (a3 & 1) != 0 )
    v31 = 0x1000000;
  else
    v31 = 0;
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cfg80211_chandef_usable)(a1 + 992, a4, 1, v31) & 1) == 0 )
  {
    v30 = "(extension) channel is disabled";
LABEL_50:
    do_trace_netlink_extack(v30);
    if ( v5 )
      *v5 = v30;
    return 4294967274LL;
  }
  if ( (*(_DWORD *)(a4 + 8) & 0xFFFFFFFE) == 6 && (*(_BYTE *)(a1 + 1094) & 0x40) == 0 )
  {
    v30 = "5/10 MHz not supported";
    goto LABEL_50;
  }
  return 0;
}
