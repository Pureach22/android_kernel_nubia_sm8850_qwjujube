__int64 __fastcall ieee80211_process_adv_ttlm(__int64 result, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int16 v4; // w19
  int v5; // w10
  char *v6; // x8
  char v7; // w9
  int v8; // w20
  unsigned __int16 *v9; // x8
  __int64 v10; // x19
  int v11; // w11
  int v12; // w12
  int v13; // w21
  int v14; // w8
  __int64 v15; // x22
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x19
  __int64 v19; // x2
  __int64 v20; // x3
  void *v21; // x8
  __int64 v22; // x19
  __int64 v23; // x2

  if ( !*(_WORD *)(result + 5800) )
    return result;
  v5 = *(unsigned __int8 *)(a2 + 736);
  if ( !*(_BYTE *)(a2 + 736) )
  {
    if ( *(_WORD *)(result + 3112) )
    {
      v10 = result;
      wiphy_delayed_work_cancel(*(_QWORD *)(*(_QWORD *)(result + 1616) + 72LL), result + 3040);
    }
    else
    {
      if ( *(_BYTE *)(result + 3122) != 1 )
      {
LABEL_45:
        *(_DWORD *)(result + 3120) = 0;
        *(_QWORD *)(result + 3112) = 0;
        return result;
      }
      v10 = result;
      if ( (unsigned int)ieee80211_vif_set_links((unsigned __int16 *)result, *(unsigned __int16 *)(result + 5800), 0) )
        return printk(&unk_B8C3B, v10 + 1640, v19, v20);
      ieee80211_vif_cfg_change_notify(v10, 0x200000000LL);
    }
    result = v10;
    goto LABEL_45;
  }
  v6 = *(char **)(a2 + 472);
  v7 = *v6;
  if ( (*v6 & 0xC) == 8 )
    goto LABEL_4;
  if ( v5 == 1 )
    return result;
  v6 = *(char **)(a2 + 480);
  v7 = *v6;
  if ( (*v6 & 0xC) == 8 )
  {
LABEL_4:
    if ( (v7 & 3) != 2 )
    {
      v21 = &unk_B7A59;
LABEL_49:
      v22 = result;
      printk(v21, result + 1640, a3, a4);
      return _ieee80211_disconnect(v22);
    }
    v5 = (unsigned __int8)v6[1];
    if ( *((unsigned __int16 *)v6 + 1) <= 1u )
      v4 = 1;
    else
      v4 = *((_WORD *)v6 + 1);
    if ( (v7 & 0x10) == 0 )
    {
      v8 = 0;
      v9 = (unsigned __int16 *)(v6 + 4);
      goto LABEL_17;
    }
  }
  else
  {
    if ( v5 == 2 )
      return result;
    __break(0x5512u);
  }
  v11 = *((unsigned __int16 *)v6 + 2);
  v12 = (unsigned __int8)v6[6];
  v9 = (unsigned __int16 *)(v6 + 7);
  v8 = v11 | (v12 << 16);
LABEL_17:
  if ( v5 != 255 )
  {
    v21 = &unk_B8C65;
    goto LABEL_49;
  }
  if ( (v7 & 0x20) == 0 )
  {
    v13 = *v9;
    if ( *v9 )
    {
      if ( v9[1] == v13 )
      {
        if ( v9[2] == v13 )
        {
          if ( v9[3] == v13 )
          {
            if ( v9[4] == v13 )
            {
              if ( v9[5] == v13 )
              {
                if ( v9[6] == v13 )
                {
                  v14 = v9[7];
                  goto LABEL_35;
                }
                goto LABEL_55;
              }
              goto LABEL_54;
            }
            goto LABEL_53;
          }
          goto LABEL_52;
        }
        goto LABEL_51;
      }
LABEL_50:
      v23 = 1;
LABEL_57:
      v22 = result;
      printk(&unk_B7D92, result + 1640, v23, a4);
      return _ieee80211_disconnect(v22);
    }
    goto LABEL_48;
  }
  v13 = *(unsigned __int8 *)v9;
  if ( !*(_BYTE *)v9 )
  {
LABEL_48:
    v21 = &unk_B866A;
    goto LABEL_49;
  }
  if ( *((unsigned __int8 *)v9 + 1) != v13 )
    goto LABEL_50;
  if ( *((unsigned __int8 *)v9 + 2) != v13 )
  {
LABEL_51:
    v23 = 2;
    goto LABEL_57;
  }
  if ( v13 != *((unsigned __int8 *)v9 + 3) )
  {
LABEL_52:
    v23 = 3;
    goto LABEL_57;
  }
  if ( v13 != *((unsigned __int8 *)v9 + 4) )
  {
LABEL_53:
    v23 = 4;
    goto LABEL_57;
  }
  if ( v13 != *((unsigned __int8 *)v9 + 5) )
  {
LABEL_54:
    v23 = 5;
    goto LABEL_57;
  }
  if ( v13 != *((unsigned __int8 *)v9 + 6) )
  {
LABEL_55:
    v23 = 6;
    goto LABEL_57;
  }
  v14 = *((unsigned __int8 *)v9 + 7);
LABEL_35:
  if ( v14 != v13 )
  {
    v23 = 7;
    goto LABEL_57;
  }
  if ( (unsigned __int16)(v4 - (a3 >> 10)) <= 0xFF00u )
  {
    v15 = result;
    v16 = _usecs_to_jiffies((unsigned __int16)(v4 - (a3 >> 10)) << 10);
    v17 = *(_QWORD *)(v15 + 1616);
    *(_WORD *)(v15 + 3112) = v4;
    *(_WORD *)(v15 + 3114) = 0;
    *(_DWORD *)(v15 + 3116) = v8;
    if ( (v16 & 0xFFFFFFFE) <= 0x19uLL )
      v18 = 0;
    else
      v18 = (unsigned int)(v16 - 25);
    *(_WORD *)(v15 + 3120) = v13;
    *(_WORD *)(v15 + 3122) = 0;
    wiphy_delayed_work_cancel(*(_QWORD *)(v17 + 72), v15 + 3040);
    return wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v15 + 1616) + 72LL), v15 + 3040, v18);
  }
  return result;
}
