__int64 __fastcall stream_agg_add_channel(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        void *a7,
        _QWORD *a8,
        void *a9)
{
  __int64 *v9; // x27
  unsigned __int8 v10; // w28
  unsigned __int8 v11; // w26
  int v17; // w25
  unsigned int v18; // w21
  unsigned int matching_stream_index_or_first_available; // w0
  __int64 v21; // x2
  __int64 v22; // x3
  _UNKNOWN **v23; // x9
  int v24; // w8
  char v25; // w10
  char v26; // w8
  _UNKNOWN **v27; // x11
  unsigned __int8 v28; // w25
  char v29; // w0
  _UNKNOWN **v30; // x0
  _UNKNOWN **v31; // x9
  _UNKNOWN **v32; // x2
  void *v33; // x0
  _UNKNOWN **v34; // x9
  unsigned __int64 StatusReg; // x22
  __int64 v36; // x23
  __int64 v37; // x0
  void *v38; // [xsp+8h] [xbp-18h]
  _QWORD *v39; // [xsp+10h] [xbp-10h]
  char v40; // [xsp+18h] [xbp-8h]

  if ( !a1 )
    return 4294967274LL;
  if ( (unsigned int)a2 >= 9 )
  {
    v33 = &unk_AF8A;
LABEL_38:
    printk(v33, a2, a3, a4);
    return 4294967274LL;
  }
  v11 = a4 - 46;
  v17 = a3;
  if ( (unsigned __int8)(a4 - 46) < 4u )
  {
    v18 = 2;
    goto LABEL_10;
  }
  v11 = a4 - 50;
  if ( (unsigned __int8)(a4 - 50) < 4u )
  {
    v18 = 3;
    goto LABEL_10;
  }
  v11 = a4 - 54;
  if ( (unsigned __int8)(a4 - 54) >= 4u )
  {
    v33 = &unk_A7C2;
    a2 = (unsigned __int8)a4;
    goto LABEL_38;
  }
  v18 = 4;
LABEL_10:
  mutex_lock(&agg_lock);
  matching_stream_index_or_first_available = get_matching_stream_index_or_first_available(a1);
  if ( (matching_stream_index_or_first_available & 0x80000000) != 0 )
  {
    printk(&unk_AC8A, a1, v21, v22);
LABEL_41:
    mutex_unlock(&agg_lock);
    return 4294967274LL;
  }
  else
  {
    v38 = a7;
    v39 = a8;
    if ( matching_stream_index_or_first_available > 8 )
    {
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v36 = *(_QWORD *)(StatusReg + 80);
      v37 = swr_disconnect_port;
      *(_QWORD *)(StatusReg + 80) = &stream_agg_add_channel__alloc_tag;
      v30 = (_UNKNOWN **)_kmalloc_cache_noprof(v37, 3520, 64);
      *(_QWORD *)(StatusReg + 80) = v36;
      if ( v30 )
        goto LABEL_33;
    }
    else
    {
      a8 = &channel_links_list;
      v9 = &aggregator_[67 * matching_stream_index_or_first_available];
      v23 = (_UNKNOWN **)channel_links_list;
      v40 = matching_stream_index_or_first_available;
      v24 = num_chs[matching_stream_index_or_first_available];
      v10 = a6;
      LOBYTE(a7) = a5;
      *v9 = a1;
      *((_DWORD *)v9 + 2) = v24;
      *((_DWORD *)v9 + 3) = v17;
      if ( v23 != &channel_links_list )
      {
        v25 = 0;
        v26 = 0;
LABEL_14:
        v27 = v23;
        do
        {
          v23 = (_UNKNOWN **)*v27;
          if ( *((unsigned __int8 *)v27 + 17) == v18 )
          {
            v26 |= *((_BYTE *)v27 + 18);
            v25 = 1;
            if ( v23 != &channel_links_list )
              goto LABEL_14;
            goto LABEL_21;
          }
          v27 = (_UNKNOWN **)*v27;
        }
        while ( v23 != &channel_links_list );
        if ( (v25 & 1) == 0 )
          goto LABEL_24;
LABEL_21:
        v28 = v26 | (1 << v11);
        v29 = _sw_hweight8(v28);
        if ( v29 != 1 && (!v29 || (v28 & ~(~(-1 << v29) << __clz(__rbit32(v28)))) != 0) )
        {
          printk(&unk_A979, a1, v18, v11);
          goto LABEL_41;
        }
LABEL_24:
        v30 = (_UNKNOWN **)channel_links_list;
        if ( channel_links_list != (_UNKNOWN *)&channel_links_list )
        {
          while ( 1 )
          {
            v31 = (_UNKNOWN **)*v30;
            if ( *((unsigned __int8 *)v30 + 17) == v18
              && 1LL << v11 == *((unsigned __int8 *)v30 + 18)
              && *((unsigned __int8 *)v30 + 22) == a5
              && *((unsigned __int8 *)v30 + 21) == a6 )
            {
              break;
            }
            v30 = (_UNKNOWN **)*v30;
            if ( v31 == &channel_links_list )
              goto LABEL_32;
          }
          if ( v30 )
            goto LABEL_36;
        }
      }
LABEL_32:
      v30 = (_UNKNOWN **)_kmalloc_cache_noprof(swr_disconnect_port, 3520, 64);
      if ( v30 )
      {
LABEL_33:
        v32 = (_UNKNOWN **)channel_links_list;
        *((_BYTE *)v30 + 17) = v18;
        *((_BYTE *)v30 + 21) = v10;
        *((_BYTE *)v30 + 18) = 1 << v11;
        *((_BYTE *)v30 + 22) = (_BYTE)a7;
        *(_WORD *)((char *)v30 + 23) = 0;
        *((_BYTE *)v30 + 19) = 0;
        v30[4] = v38;
        v30[5] = a9;
        *((_DWORD *)v30 + 12) = 0;
        v30[7] = v39;
        if ( v32 == v30 || *(_QWORD **)((char *)&unk_8 + (_QWORD)v32) != a8 )
        {
          _list_add_valid_or_report();
          v30 = v34;
        }
        else
        {
          *(_QWORD *)((char *)&unk_8 + (_QWORD)v32) = v30;
          *v30 = v32;
          v30[1] = a8;
          *a8 = v30;
        }
LABEL_36:
        *((_BYTE *)v30 + 24) |= 1LL << v40;
        ++*((_DWORD *)v9 + 4);
        mutex_unlock(&agg_lock);
        return 0;
      }
    }
    mutex_unlock(&agg_lock);
    return 4294967284LL;
  }
}
