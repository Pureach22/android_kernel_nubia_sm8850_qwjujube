__int64 __fastcall dp_rx_intrabss_ucast_fwd(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned __int8 a7)
{
  __int64 v7; // x26
  __int64 v8; // x28
  __int16 v10; // w27
  __int64 v12; // x25
  __int64 v13; // x20
  void (__fastcall *v17)(__int64, __int64); // x8
  __int64 v18; // x0
  __int64 v19; // x9
  __int64 v20; // x11
  __int64 result; // x0
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x10
  char v27; // [xsp+Ch] [xbp-4h]

  v7 = *(_QWORD *)(a5 + 40);
  v8 = *(_QWORD *)(a5 + 72);
  v10 = *(_WORD *)(a5 + 62);
  v12 = *(unsigned __int16 *)(a5 + 60);
  v13 = a5;
  v27 = *(_BYTE *)(a5 + 86);
  if ( (*(char *)(a5 + 84) & 0x80000000) == 0 )
    goto LABEL_2;
  if ( *(_DWORD *)(a5 + 116) )
  {
    result = _pskb_pull_tail(a5);
    if ( !result )
      return result;
  }
  v13 = qdf_nbuf_unshare(v13);
  if ( v13 )
  {
LABEL_2:
    qdf_mem_set((void *)(v13 + 40), 0x30u, 0);
    if ( (_qdf_is_pp_nbuf(v13) & 1) != 0 )
      *(_QWORD *)(v13 + 40) = v7;
    v17 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)a2 + 264LL);
    if ( v17 )
    {
      v18 = *(_QWORD *)(*(_QWORD *)a2 + 88LL);
      if ( *((_DWORD *)v17 - 1) != 1328777552 )
        __break(0x8228u);
      v17(v18, v13);
    }
    if ( (*(_BYTE *)(a1 + 20148) & 1) != 0 || dp_tx_send(a1, a3, v13) )
    {
      if ( a2 )
      {
        v19 = a2 + 4072LL * a7;
        v20 = *(_QWORD *)(v19 + 3192) + v12;
        ++*(_QWORD *)(v19 + 3184);
        *(_QWORD *)(v19 + 3192) = v20;
      }
      result = 0;
      ++*(_QWORD *)(a6 + 296);
      v22 = *(_QWORD *)(v13 + 72);
      *(_WORD *)(v13 + 60) = v12;
      *(_WORD *)(v13 + 62) = v10;
      *(_QWORD *)(v13 + 72) = v22 & 0xFFFFFFFFFFC3FFFFLL | v8 & 0x3C0000;
      *(_BYTE *)(v13 + 86) = v27;
    }
    else
    {
      if ( a2 )
      {
        v23 = a2 + 4072LL * a7;
        v24 = *(_QWORD *)(v23 + 3176) + v12;
        ++*(_QWORD *)(v23 + 3168);
        *(_QWORD *)(v23 + 3176) = v24;
      }
      return 1;
    }
  }
  else
  {
    if ( a2 )
    {
      v25 = a2 + 4072LL * a7;
      v26 = *(_QWORD *)(v25 + 3192) + v12;
      ++*(_QWORD *)(v25 + 3184);
      *(_QWORD *)(v25 + 3192) = v26;
    }
    ++*(_QWORD *)(a6 + 296);
    return 0;
  }
  return result;
}
