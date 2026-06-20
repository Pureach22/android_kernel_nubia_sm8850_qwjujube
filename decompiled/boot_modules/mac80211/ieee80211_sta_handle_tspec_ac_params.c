__int64 __fastcall ieee80211_sta_handle_tspec_ac_params(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  char v3; // w26
  __int64 v4; // x27
  unsigned int v5; // w22
  char v6; // w8
  _DWORD *v7; // x21
  __int64 v8; // x25
  __int64 v9; // x24
  __int64 v10; // x28
  int v11; // w9
  int v12; // w10
  __int64 v13; // x3
  unsigned int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x3
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // [xsp+8h] [xbp-8h]

  v1 = *(_QWORD *)(result + 1616);
  if ( *(unsigned __int16 *)(v1 + 128) >= 4u )
  {
    v2 = result;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = (_DWORD *)(result + 3616);
    v8 = result + 4504;
    v19 = result + 4504;
    while ( 1 )
    {
      v9 = v2 + v4;
      v10 = jiffies;
      v11 = *(_DWORD *)(v2 + v4 + 2764);
      if ( v11 == 2 )
        goto LABEL_13;
      if ( v11 != 1 )
        break;
      if ( *(_QWORD *)(v9 + 2744) - jiffies + 250LL >= 0 )
      {
        if ( v4 == 96 )
          goto LABEL_21;
        if ( (((unsigned __int64)*(unsigned __int8 *)(v2 + 1890) >> (v3 + 5)) & 1) != 0 )
        {
          if ( v4 == 64 )
            goto LABEL_21;
          if ( (((unsigned __int64)*(unsigned __int8 *)(v2 + 1890) >> (v3 + 3)) & 1) != 0 )
          {
            if ( v4 == 32 )
              goto LABEL_21;
            if ( (((unsigned __int64)*(unsigned __int8 *)(v2 + 1890) >> (v3 + 1)) & 1) != 0 )
            {
              if ( v4 )
                v14 = v5 + 4;
              else
LABEL_21:
                v14 = 4;
            }
            else
            {
              v14 = v5 + 3;
            }
          }
          else
          {
            v14 = v5 + 2;
          }
        }
        else
        {
          v14 = v5 + 1;
        }
        if ( v14 >= 3 )
          v14 = 3;
        if ( (unsigned int)drv_conf_tx(v1, v7, v5, v19 + 14LL * v14) )
        {
          v18 = *(_QWORD *)v7;
          if ( *(_WORD *)(*(_QWORD *)v7 + 5800LL) )
            printk(&unk_BC5A9, v18 + 1640, *(unsigned int *)(v2 + 3624), v5);
          else
            printk(&unk_B7D5C, v18 + 1640, v5, v16);
        }
        v17 = *(_QWORD *)(v9 + 2744);
        *(_DWORD *)(v9 + 2764) = 0;
        result = wiphy_delayed_work_queue(*(_QWORD *)(v1 + 72), v2 + 2872, v17 - v10 + 251);
        goto LABEL_4;
      }
      *(_DWORD *)(v9 + 2764) = 0;
LABEL_4:
      v6 = 1;
LABEL_5:
      v4 += 32;
      ++v5;
      v3 -= 2;
      v8 += 14;
      if ( v4 == 128 )
      {
        if ( (v6 & 1) != 0 )
          return ieee80211_link_info_change_notify(v2, (__int64)v7, 0x2000);
        return result;
      }
    }
    if ( v11 )
      goto LABEL_5;
    if ( !*(_DWORD *)(v2 + v4 + 2752) )
      goto LABEL_5;
    if ( *(_QWORD *)(v9 + 2744) - jiffies + 250LL >= 0 )
      goto LABEL_5;
    *(_QWORD *)(v9 + 2744) = jiffies;
    v12 = *(unsigned __int8 *)(v2 + v4 + 2768);
    *(_DWORD *)(v2 + v4 + 2760) = 0;
    if ( v12 != 1 )
      goto LABEL_5;
    *(_DWORD *)(v9 + 2764) = 2;
LABEL_13:
    result = drv_conf_tx(v1, v7, v5, v8);
    if ( (_DWORD)result )
    {
      v15 = *(_QWORD *)v7;
      if ( *(_WORD *)(*(_QWORD *)v7 + 5800LL) )
        result = printk(&unk_BC5A9, v15 + 1640, *(unsigned int *)(v2 + 3624), v5);
      else
        result = printk(&unk_B7D5C, v15 + 1640, v5, v13);
    }
    *(_DWORD *)(v9 + 2764) = 0;
    *(_BYTE *)(v2 + v4 + 2768) = 0;
    goto LABEL_4;
  }
  return result;
}
