__int64 __fastcall ieee80211_s1g_rx_twt_action(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x23
  char v8; // w9
  __int16 v9; // w8
  __int64 v10; // x20
  int v11; // w2
  void (__fastcall *v12)(__int64, __int64, __int64); // x8
  __int64 v13; // x21
  __int64 v14; // x8
  size_t v15; // x20
  __int64 v16; // x8
  __int64 v17; // x21
  __int64 v18; // x9
  _WORD *v19; // x22
  __int16 v20; // w9
  int v21; // w10
  __int16 v22; // w9
  __int64 v23; // x9
  __int64 v24; // x21
  const char *v25; // x1

  v2 = *(_QWORD *)(a2 + 224);
  result = sta_info_get_bss(a1, v2 + 10);
  if ( result )
  {
    v6 = *(unsigned __int8 *)(v2 + 25);
    if ( v6 == 7 )
      return drv_twt_teardown_request(
               *(_QWORD *)(a1 + 1616),
               a1,
               result + 2688,
               *(unsigned __int8 *)(*(_QWORD *)(a2 + 224) + 26LL));
    if ( v6 == 6 )
    {
      v7 = *(_QWORD *)(a2 + 224);
      v8 = *(_BYTE *)(v7 + 29);
      v9 = *(_WORD *)(v7 + 30);
      *(_WORD *)(v7 + 30) = v9 & 0xFFFE;
      if ( (v8 & 8) != 0 )
      {
        *(_WORD *)(v7 + 30) = v9 & 0xFFF0 | 0xE;
      }
      else
      {
        *(_BYTE *)(v7 + 29) = v8 | 0x10;
        v10 = *(_QWORD *)(a1 + 1616);
        if ( (*(_BYTE *)(v10 + 1471) & 1) != 0
          || (v11 = *(_DWORD *)(a1 + 1624), (v11 & 0x20) != 0)
          || (drv_add_twt_setup___already_done & 1) != 0 )
        {
          if ( (*(_BYTE *)(a1 + 1624) & 0x20) != 0 )
            goto LABEL_9;
        }
        else
        {
          v23 = *(_QWORD *)(a1 + 1608);
          drv_add_twt_setup___already_done = 1;
          v24 = result;
          if ( v23 )
            v25 = (const char *)(v23 + 296);
          else
            v25 = (const char *)(a1 + 1640);
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v25, v11);
          result = v24;
          __break(0x800u);
          if ( (*(_BYTE *)(a1 + 1624) & 0x20) != 0 )
          {
LABEL_9:
            v12 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v10 + 464) + 888LL);
            if ( *((_DWORD *)v12 - 1) != 1550162876 )
              __break(0x8228u);
            v12(v10, result + 2688, v7 + 26);
          }
        }
      }
      v13 = *(_QWORD *)(a1 + 1616);
      v14 = *(unsigned __int8 *)(v7 + 28);
      v15 = v14 + 29;
      result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v13 + 104) + v14 + 29), 2080);
      if ( result )
      {
        v16 = *(int *)(v13 + 104);
        v17 = result;
        v18 = *(_QWORD *)(result + 224) + v16;
        LODWORD(v16) = *(_DWORD *)(result + 208) + v16;
        *(_QWORD *)(result + 224) = v18;
        *(_DWORD *)(result + 208) = v16;
        v19 = (_WORD *)skb_put(result, (unsigned int)v15);
        memset(v19, 0, v15);
        *v19 = 208;
        v20 = *(_WORD *)(v7 + 14);
        *((_DWORD *)v19 + 1) = *(_DWORD *)(v7 + 10);
        v19[4] = v20;
        v21 = *(_DWORD *)(a1 + 5842);
        v19[7] = *(_WORD *)(a1 + 5846);
        *(_DWORD *)(v19 + 5) = v21;
        v22 = *(_WORD *)(a1 + 5846);
        *((_DWORD *)v19 + 4) = *(_DWORD *)(a1 + 5842);
        v19[10] = v22;
        v19[12] = 1558;
        memcpy(v19 + 13, (const void *)(v7 + 26), *(unsigned __int8 *)(v7 + 28) + 3LL);
        *(_DWORD *)(v17 + 40) |= 0x110001u;
        return ieee80211_tx_skb_tid(a1, v17, 7, 0xFFFFFFFFLL);
      }
    }
  }
  return result;
}
