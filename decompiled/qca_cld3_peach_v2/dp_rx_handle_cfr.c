__int64 __fastcall dp_rx_handle_cfr(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v5; // x19
  __int64 v6; // x24
  __int64 v7; // x23
  unsigned __int64 v8; // x8
  unsigned int v9; // w8
  __int64 v10; // x2
  _DWORD *v11; // x22
  __int64 v12; // x2
  int v13; // w8
  int v14; // w9

  v5 = result;
  v6 = a2 + 94208;
  v7 = a3 + 12288;
  if ( a2 )
  {
    v8 = *(unsigned __int8 *)(a3 + 14220);
    if ( v8 >= 4 )
      goto LABEL_9;
    ++*(_QWORD *)(a2 + 8 * v8 + 94232);
    if ( *(_BYTE *)(a3 + 14219) == 1 )
    {
      ++*(_QWORD *)(a2 + 94224);
      if ( *(_BYTE *)(a3 + 14216) == 1 )
      {
        ++*(_QWORD *)v6;
        v9 = *(unsigned __int8 *)(a3 + 14218);
        if ( v9 < 6 )
        {
LABEL_6:
          ++*(_QWORD *)(a2 + 8LL * v9 + 94264);
          goto LABEL_10;
        }
      }
      else
      {
        if ( *(_BYTE *)(a3 + 14217) != 1 )
          goto LABEL_10;
        ++*(_QWORD *)(a2 + 94216);
        v9 = *(unsigned __int8 *)(a3 + 14218);
        if ( v9 <= 5 )
          goto LABEL_6;
      }
LABEL_9:
      __break(0x5512u);
    }
  }
LABEL_10:
  if ( *(_BYTE *)(a3 + 14216) == 1 )
  {
    result = _qdf_nbuf_alloc(*(_QWORD *)(result + 24), 368, 0, 0, 0, "dp_rx_handle_cfr", 247);
    if ( result )
    {
      v10 = *(_QWORD *)(result + 224);
      v11 = (_DWORD *)result;
      if ( *(_BYTE *)(v6 + 1728) == 1 )
      {
        *(_BYTE *)(v10 + 316) = *(_BYTE *)(v7 + 1928);
        *(_BYTE *)(v10 + 317) = *(_BYTE *)(v7 + 1929);
        *(_BYTE *)(v10 + 318) = *(_BYTE *)(v7 + 1930);
        *(_BYTE *)(v10 + 319) = *(_BYTE *)(v7 + 1931);
        *(_BYTE *)(v10 + 320) = *(_BYTE *)(v7 + 1932);
        *(_BYTE *)(v10 + 321) = *(_BYTE *)(v7 + 1933);
        *(_DWORD *)(v10 + 324) = *(_DWORD *)(a3 + 14224);
        *(_WORD *)(v10 + 328) = *(_WORD *)(v7 + 1940);
        *(_DWORD *)(v10 + 332) = *(_DWORD *)(a3 + 14232);
        *(_DWORD *)(v10 + 336) = *(_DWORD *)(a3 + 14236);
        *(_DWORD *)(v10 + 340) = *(_DWORD *)(a3 + 14240);
        *(_DWORD *)(v10 + 344) = *(_DWORD *)(a3 + 14244);
        *(_DWORD *)(v10 + 348) = *(_DWORD *)(a3 + 14248);
        *(_DWORD *)(v10 + 352) = *(_DWORD *)(a3 + 14252);
        *(_DWORD *)(v10 + 356) = *(_DWORD *)(a3 + 14256);
      }
      dp_rx_mon_populate_cfr_ppdu_info(a2, a3, v10);
      if ( v11[29] )
      {
        v12 = 368;
      }
      else
      {
        v14 = v11[52];
        v13 = v11[53];
        if ( (unsigned int)(v13 - v14) > 0x16F )
          goto LABEL_19;
        v12 = (unsigned int)(v14 - v13 + 368);
      }
      if ( (unsigned int)pskb_expand_head(v11, 0, v12, 2080) )
      {
        dev_kfree_skb_any_reason(v11, 1);
        return dp_wdi_event_handler(0x10Cu, v5, (__int64)v11, 0xFFFFu, 0xFFFFFFFF, *(_BYTE *)a2);
      }
LABEL_19:
      skb_put(v11, 368);
      return dp_wdi_event_handler(0x10Cu, v5, (__int64)v11, 0xFFFFu, 0xFFFFFFFF, *(_BYTE *)a2);
    }
  }
  return result;
}
