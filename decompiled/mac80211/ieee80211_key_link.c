__int64 __fastcall ieee80211_key_link(__int64 unlock, __int64 *a2, __int64 a3)
{
  __int64 v5; // x19
  __int64 v6; // x22
  __int64 v7; // x8
  unsigned int v8; // w25
  int v9; // w24
  __int64 v10; // x9
  __int64 v11; // x23
  __int64 v12; // x9
  __int64 v13; // x9
  unsigned int v14; // w20
  int v15; // w2
  __int64 *v16; // x0
  __int64 *v17; // x1
  __int64 v18; // x9
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x8
  char v22; // w26
  __int64 v23; // x8
  __int64 lock; // x0
  _QWORD *i; // x8
  int v26; // w8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x9
  unsigned int v37; // w8
  unsigned int v38; // w8
  __int64 v39; // [xsp+8h] [xbp-48h] BYREF
  __int64 v40; // [xsp+10h] [xbp-40h]
  __int64 v41; // [xsp+18h] [xbp-38h]
  __int64 v42; // [xsp+20h] [xbp-30h]
  __int64 v43; // [xsp+28h] [xbp-28h] BYREF
  __int64 v44; // [xsp+30h] [xbp-20h]
  __int64 v45; // [xsp+38h] [xbp-18h]
  __int64 v46; // [xsp+40h] [xbp-10h]
  __int64 v47; // [xsp+48h] [xbp-8h]

  v5 = unlock;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a2;
  v7 = *(unsigned __int8 *)(unlock + 551);
  v8 = *(unsigned __int16 *)(unlock + 552);
  v9 = *(_DWORD *)(*a2 + 4720);
  if ( a3 && (v8 & 8) != 0 )
  {
    if ( (unsigned int)v7 < 4 )
    {
      v10 = *(_QWORD *)(a3 + 88 + 8 * (v7 ^ 1));
      v11 = *(_QWORD *)(a3 + 88 + 8 * v7);
      if ( v10 && *(_DWORD *)(v10 + 544) != *(_DWORD *)(unlock + 544) )
      {
LABEL_27:
        v14 = -95;
        if ( !unlock )
          goto LABEL_62;
        goto LABEL_28;
      }
      if ( !v11 )
        goto LABEL_39;
      goto LABEL_26;
    }
    goto LABEL_63;
  }
  if ( !a3 )
  {
    if ( (char)v7 > 3 )
    {
      if ( (unsigned int)v7 > 7 )
        goto LABEL_63;
    }
    else
    {
      if ( (unsigned int)v7 > 3 )
        goto LABEL_63;
      v11 = *(_QWORD *)(v6 + 8 * v7 + 1896);
      if ( v11 )
      {
        if ( (v8 & 8) != 0 )
          goto LABEL_30;
        goto LABEL_25;
      }
    }
    v11 = a2[v7 + 6];
    if ( (v8 & 8) != 0 )
      goto LABEL_30;
LABEL_25:
    if ( v11 )
    {
LABEL_26:
      if ( *(_DWORD *)(v11 + 544) != *(_DWORD *)(unlock + 544) )
        goto LABEL_27;
      goto LABEL_31;
    }
    goto LABEL_30;
  }
  v12 = *(char *)(unlock + 554);
  if ( v12 < 0 )
  {
    v13 = a3 + 1640;
  }
  else
  {
    if ( (unsigned int)v12 > 0xE )
      goto LABEL_63;
    v13 = *(_QWORD *)(a3 + 8 * v12 + 2568);
    if ( !v13 )
    {
      v14 = -67;
      if ( !unlock )
        goto LABEL_62;
      goto LABEL_28;
    }
  }
  if ( (unsigned int)v7 > 7 )
LABEL_63:
    __break(0x5512u);
  v11 = *(_QWORD *)(v13 + 8 * v7 + 40);
  if ( (v8 & 8) == 0 )
    goto LABEL_25;
LABEL_30:
  if ( !v11 )
  {
LABEL_39:
    v22 = 1;
LABEL_40:
    v23 = *(_QWORD *)(v6 + 1616);
    *(_QWORD *)(v5 + 16) = a3;
    *(_QWORD *)v5 = v23;
    *(_QWORD *)(v5 + 8) = v6;
    _X9 = &ieee80211_key_link_key_color;
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v37 = __ldxr((unsigned int *)&ieee80211_key_link_key_color);
      v38 = v37 + 1;
    }
    while ( __stlxr(v38, (unsigned int *)&ieee80211_key_link_key_color) );
    __dmb(0xBu);
    *(_DWORD *)(v5 + 528) = v38;
    if ( a3 && *(_BYTE *)(a3 + 2716) == 1 )
      *(_WORD *)(v5 + 552) |= 0x800u;
    if ( *(_DWORD *)(v6 + 4720) == 3 )
    {
      lock = _rcu_read_lock(unlock, a2);
      for ( i = *(_QWORD **)(v6 + 2264); i != (_QWORD *)(v6 + 2264); i = (_QWORD *)*i )
        ++*((_DWORD *)i - 184);
      unlock = _rcu_read_unlock(lock);
    }
    v26 = *(_DWORD *)(v6 + 1528);
    *(_DWORD *)(v6 + 1528) = v26 + 1;
    if ( !v26 )
      synchronize_net(unlock);
    v27 = ieee80211_key_replace(v6, a2, a3, (v8 >> 3) & 1, v11, v5);
    if ( (_DWORD)v27 )
    {
      v14 = v27;
      ieee80211_key_free(v5, v9 == 2);
    }
    else
    {
      if ( (v22 & 1) == 0 )
      {
        synchronize_net(v27);
        if ( *(_QWORD *)v11 )
        {
          v28 = *(_QWORD *)(v11 + 8);
          if ( v9 == 2 )
          {
            v29 = *(_QWORD *)(v28 + 1616);
            ++*(_DWORD *)(v28 + 1532);
            wiphy_delayed_work_queue(*(_QWORD *)(v29 + 72), v28 + 1536, 125);
          }
          else
          {
            decrease_tailroom_need_count(v28, 1);
          }
        }
        ieee80211_key_free_common(v11);
      }
      v14 = 0;
    }
    goto LABEL_62;
  }
LABEL_31:
  v15 = *(unsigned __int8 *)(unlock + 555);
  if ( v15 != *(unsigned __int8 *)(v11 + 555) )
    goto LABEL_38;
  v16 = (__int64 *)(v11 + 556);
  v17 = (__int64 *)(v5 + 556);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  if ( v9 == 2 && v15 == 32 && *(_DWORD *)(v5 + 544) == 1027074 && (v8 & 8) == 0 )
  {
    v18 = *(_QWORD *)(v11 + 564);
    v43 = *v16;
    v44 = v18;
    v19 = *(_QWORD *)(v5 + 564);
    v20 = *(_QWORD *)(v11 + 580);
    v16 = &v43;
    v39 = *v17;
    v40 = v19;
    v21 = *(_QWORD *)(v5 + 580);
    v17 = &v39;
    v45 = 0;
    v46 = v20;
    v41 = 0;
    v42 = v21;
  }
  unlock = _crypto_memneq(v16, v17);
  if ( unlock )
  {
LABEL_38:
    v22 = 0;
    goto LABEL_40;
  }
  v14 = -114;
  if ( !v5 )
    goto LABEL_62;
LABEL_28:
  if ( *(_QWORD *)(v5 + 8) || *(_QWORD *)v5 )
    __break(0x800u);
  ieee80211_key_free_common(v5);
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return v14;
}
