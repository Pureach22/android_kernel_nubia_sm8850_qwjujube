__int64 __fastcall ieee80211_set_wmm_default(__int64 result, __int64 a2, char a3)
{
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 lock; // x0
  _DWORD **v8; // x8
  char v9; // w23
  int v10; // w24
  int v11; // w28
  __int16 v12; // w9
  char v13; // w8
  __int64 v14; // x27
  __int64 v15; // x25
  char v16; // w8
  unsigned int v17; // w23
  _QWORD *v18; // x9
  __int64 v19; // x10
  char v20; // w8
  __int16 v21; // w8
  unsigned int v22; // w9
  char v23; // [xsp+Ch] [xbp-34h]
  char v24; // [xsp+10h] [xbp-30h]
  __int16 v25; // [xsp+14h] [xbp-2Ch]
  char v26; // [xsp+18h] [xbp-28h]
  char v27; // [xsp+1Ch] [xbp-24h]
  char v28; // [xsp+20h] [xbp-20h]
  _BYTE v29[14]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)result;
  v4 = *(_QWORD *)(*(_QWORD *)result + 1616LL);
  if ( !*(_QWORD *)(*(_QWORD *)(v4 + 464) + 336LL) || *(unsigned __int16 *)(v4 + 128) < 4u )
    goto LABEL_42;
  v6 = result;
  v23 = a3 & 1;
  v24 = a2;
  *(_QWORD *)&v29[6] = 0;
  lock = _rcu_read_lock(result, a2);
  v8 = *(_DWORD ***)(*(_QWORD *)(v6 + 944) + 832LL);
  if ( v8 && !**v8 )
    v9 = *(_BYTE *)(v6 + 136) ^ 1;
  else
    v9 = 0;
  _rcu_read_unlock(lock);
  if ( (v9 & 1) != 0 )
    v10 = 31;
  else
    v10 = 15;
  v11 = *(_DWORD *)(v3 + 4720);
  *(_WORD *)&v29[4] = 1023;
  v29[6] = 2;
  if ( (v9 & 1) != 0 )
    v12 = 188;
  else
    v12 = 94;
  v25 = v12;
  v26 = v9;
  if ( v11 == 11 )
    v13 = 9;
  else
    v13 = 7;
  v14 = 0;
  v15 = 888;
  v28 = v13;
  if ( v11 == 11 )
    v16 = 6;
  else
    v16 = 3;
  *(_WORD *)v29 = 0;
  *(_WORD *)&v29[2] = v10;
  v27 = v16;
  do
  {
    if ( (a3 & 1) == 0 )
    {
      v17 = v14;
      goto LABEL_21;
    }
    if ( !(_DWORD)v14 )
    {
      *(_WORD *)&v29[4] = ((unsigned int)(v10 + 1) >> 1) - 1;
      *(_WORD *)&v29[2] = ((unsigned int)(v10 + 1) >> 2) - 1;
      if ( v11 == 11 )
      {
        v17 = 0;
        *(_WORD *)v29 = 0;
LABEL_38:
        v20 = 2;
        goto LABEL_39;
      }
      v17 = 0;
      if ( (v26 & 1) != 0 )
        v21 = 102;
      else
        v21 = 47;
LABEL_37:
      *(_WORD *)v29 = v21;
      goto LABEL_38;
    }
    if ( (_DWORD)v14 != 1 )
    {
      *(_WORD *)&v29[4] = 1023;
      if ( (_DWORD)v14 == 3 )
      {
        v20 = v28;
        v17 = 3;
      }
      else
      {
        v20 = v27;
        v17 = v14;
      }
      *(_WORD *)&v29[2] = v10;
      *(_WORD *)v29 = 0;
      goto LABEL_39;
    }
    *(_WORD *)&v29[4] = v10;
    *(_WORD *)&v29[2] = ((unsigned int)(v10 + 1) >> 1) - 1;
    if ( v11 != 11 )
    {
      v21 = v25;
      v17 = 1;
      goto LABEL_37;
    }
    *(_WORD *)v29 = 0;
    v17 = 1;
    v20 = 3;
LABEL_39:
    v29[6] = v20;
LABEL_21:
    ieee80211_regulatory_limit_wmm_params(v3, (unsigned __int16 *)v29, v17);
    v29[8] = 0;
    v18 = (_QWORD *)(v6 + v15);
    v19 = *(_QWORD *)&v29[6];
    *v18 = *(_QWORD *)v29;
    *(_QWORD *)((char *)v18 + 6) = v19;
    result = drv_conf_tx(v4, (_DWORD *)v6, v17, (__int64)v29);
    ++v14;
    v15 += 14;
  }
  while ( v14 != 4 );
  v22 = *(_DWORD *)(v3 + 4720);
  if ( v22 > 0xC || ((1 << v22) & 0x1440) == 0 )
  {
    *(_BYTE *)(*(_QWORD *)(v6 + 944) + 224LL) = v23;
    if ( (v24 & 1) != 0 )
      result = ieee80211_link_info_change_notify(v3, v6, 0x2000);
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
