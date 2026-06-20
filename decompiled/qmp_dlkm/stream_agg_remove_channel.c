__int64 __fastcall stream_agg_remove_channel(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  char v4; // w25
  unsigned int v7; // w21
  unsigned int v8; // w20
  __int64 v9; // x2
  __int64 v10; // x3
  unsigned int v11; // w22
  unsigned __int8 *v12; // x26
  __int64 v13; // x24
  _UNKNOWN **v14; // x9
  int v15; // w8
  __int64 v16; // x1
  unsigned __int8 *v17; // x28
  int v18; // w8
  _BYTE *v19; // x9
  __int64 *v20; // x26
  _DWORD *v21; // x27
  unsigned __int8 *v22; // x21
  _BYTE *v23; // x0
  _BYTE *v24; // x9
  __int64 v25; // x8
  _QWORD *v26; // x21
  int v27; // w8
  void **v28; // x8
  unsigned int matching_stream_index_or_first_available; // w0
  __int64 v30; // x3
  char v32[4]; // [xsp+0h] [xbp-10h] BYREF
  char v33[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 1;
  v32[0] = a2;
  if ( a1 )
  {
    v4 = a2 - 46;
    if ( (unsigned __int8)(a2 - 46) >= 4u )
    {
      v4 = a2 - 50;
      if ( (unsigned __int8)(a2 - 50) >= 4u )
      {
        v4 = a2 - 54;
        if ( (unsigned __int8)(a2 - 54) >= 4u )
        {
          printk(&unk_AB70, a2, a4, a3);
          v8 = -22;
          goto LABEL_69;
        }
        v7 = 4;
      }
      else
      {
        v7 = 3;
      }
    }
    else
    {
      v7 = 2;
    }
    mutex_lock(&agg_lock);
    if ( aggregator_[0] == a1 )
    {
      v11 = 0;
    }
    else if ( qword_B288 == a1 )
    {
      v11 = 1;
    }
    else if ( qword_B4A0 == a1 )
    {
      v11 = 2;
    }
    else if ( qword_B6B8 == a1 )
    {
      v11 = 3;
    }
    else if ( qword_B8D0 == a1 )
    {
      v11 = 4;
    }
    else if ( qword_BAE8 == a1 )
    {
      v11 = 5;
    }
    else if ( qword_BD00 == a1 )
    {
      v11 = 6;
    }
    else
    {
      if ( qword_BF18 != a1 )
      {
        printk(&unk_A570, a1, v9, v10);
LABEL_54:
        mutex_unlock(&agg_lock);
        v8 = -22;
        goto LABEL_69;
      }
      v11 = 7;
    }
    v12 = (unsigned __int8 *)channel_links_list;
    if ( channel_links_list != (_UNKNOWN *)&channel_links_list )
    {
      v13 = 1LL << v11;
      while ( 1 )
      {
        v14 = *(_UNKNOWN ***)v12;
        if ( ((unsigned __int8)v13 & v12[24]) != 0 && v12[17] == v7 && 1LL << v4 == v12[18] )
          break;
        v12 = *(unsigned __int8 **)v12;
        if ( v14 == &channel_links_list )
          goto LABEL_53;
      }
      if ( v12 )
      {
        v15 = v12[19];
        v12[19] = v15 & ~(_BYTE)v13;
        if ( (unsigned int)_sw_hweight8(v15 & ((unsigned int)v13 ^ 0xFF)) )
          v8 = 0;
        else
          v8 = swr_disconnect_port(*((_QWORD *)v12 + 7), v12 + 22, 1, v33, v32);
        v17 = (unsigned __int8 *)channel_links_list;
        if ( channel_links_list == (_UNKNOWN *)&channel_links_list )
        {
          v20 = &aggregator_[67 * v11];
          v21 = v20 + 1;
          if ( *((_DWORD *)v20 + 2) )
          {
LABEL_68:
            mutex_unlock(&agg_lock);
            goto LABEL_69;
          }
        }
        else
        {
          v18 = 0;
          v19 = channel_links_list;
          do
          {
            if ( ((unsigned __int8)v13 & v19[24]) != 0 && ((unsigned __int8)v13 & v19[19]) == 0 )
              ++v18;
            v19 = *(_BYTE **)v19;
          }
          while ( v19 != (_BYTE *)&channel_links_list );
          v20 = &aggregator_[67 * v11];
          v21 = v20 + 1;
          if ( v18 != *((_DWORD *)v20 + 2) )
            goto LABEL_68;
          if ( channel_links_list != (_UNKNOWN *)&channel_links_list )
          {
            while ( 1 )
            {
              v22 = *(unsigned __int8 **)v17;
              if ( ((unsigned __int8)v13 & v17[24]) != 0 && (unsigned int)_sw_hweight8(v17[20]) == 1 )
                break;
              v17 = v22;
              if ( v22 == (unsigned __int8 *)&channel_links_list )
                goto LABEL_51;
            }
            if ( v17 )
              v8 = swr_slvdev_datapath_control(
                     *((_QWORD *)v17 + 7),
                     *(unsigned __int8 *)(*((_QWORD *)v17 + 7) + 64LL),
                     0);
          }
        }
LABEL_51:
        v23 = channel_links_list;
        if ( channel_links_list != (_UNKNOWN *)&channel_links_list )
        {
          do
          {
            v25 = (unsigned __int8)v23[24];
            if ( (v13 & v25) != 0 )
              v23[20] &= ~(_BYTE)v13;
            v26 = *(_QWORD **)v23;
            v27 = v25 & (v13 ^ 0xFF);
            v23[24] = v27;
            if ( !v27 )
            {
              v28 = *((void ***)v23 + 1);
              if ( *v28 == v23 && (_BYTE *)v26[1] == v23 )
              {
                v26[1] = v28;
                *v28 = v26;
              }
              else
              {
                _list_del_entry_valid_or_report(v23, v16);
                v23 = v24;
              }
              *(_QWORD *)v23 = 0xDEAD000000000100LL;
              *((_QWORD *)v23 + 1) = 0xDEAD000000000122LL;
              kfree(v23);
            }
            v23 = v26;
          }
          while ( v26 != &channel_links_list );
        }
        *v21 = 0;
        matching_stream_index_or_first_available = get_matching_stream_index_or_first_available(a1);
        if ( (matching_stream_index_or_first_available & 0x80000000) != 0 )
        {
          printk(&unk_A95C, "update_ch_per_substream", matching_stream_index_or_first_available, v30);
        }
        else
        {
          if ( matching_stream_index_or_first_available > 8 )
          {
            __break(1u);
            JUMPOUT(0x8994);
          }
          num_chs[matching_stream_index_or_first_available] = 0;
        }
        *v20 = 0;
        *(__int64 *)((char *)&aggregator_[67 * v11 + 1] + 4) = 0;
        goto LABEL_68;
      }
    }
LABEL_53:
    printk(&unk_ABC0, a1, a2, v7);
    goto LABEL_54;
  }
  v8 = -22;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return v8;
}
