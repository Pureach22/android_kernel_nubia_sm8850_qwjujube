__int64 __fastcall ieee80211_txq_may_transmit(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x9
  _DWORD *v3; // x21
  __int64 v4; // x22
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 v8; // x10
  int v9; // w11
  _QWORD *v10; // x13
  _QWORD *v11; // x11
  _QWORD *v12; // x10
  __int64 v13; // x12
  unsigned int v14; // w13
  __int64 v15; // x8
  __int64 v16; // x14
  unsigned __int64 v17; // x17
  int v18; // w16
  _QWORD *v19; // x8
  __int64 v20; // x15
  _QWORD *v21; // x8
  _DWORD *v22; // x11
  __int64 v23; // x8
  __int64 v24; // x9
  _QWORD *v25; // x10
  unsigned int v26; // w20
  _QWORD *v28; // x8
  __int64 v29; // x11

  v4 = *(unsigned __int8 *)(a2 + 17);
  if ( (unsigned int)v4 >= 5 )
    goto LABEL_49;
  v3 = (_DWORD *)(a1 + 4 * v4);
  v6 = a2;
  raw_spin_lock_bh(v3 + 77);
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
    goto LABEL_33;
  v2 = (_QWORD *)(v6 - 48);
  if ( *(_QWORD *)(v6 - 48) == v6 - 48 )
    goto LABEL_33;
  v8 = a1 + 16 * v4;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 117LL) & 1) == 0 )
    goto LABEL_9;
  v9 = -2;
  v10 = (_QWORD *)(v8 + 328);
  do
  {
    v10 = (_QWORD *)*v10;
    ++v9;
  }
  while ( v10 != (_QWORD *)(v8 + 328) );
  if ( (_DWORD)v4 == 4 )
    goto LABEL_49;
  if ( v3[112] < v3[106] + ((unsigned int)(v3[102] * v9) >> 1) )
  {
LABEL_9:
    v11 = *(_QWORD **)(v8 + 328);
    v12 = (_QWORD *)(v8 + 328);
    if ( v11 != v12 )
    {
      v13 = v6 - 232;
      if ( v11 - 23 != (_QWORD *)(v6 - 232) )
      {
        v14 = 40;
        while ( 1 )
        {
          v15 = v11[7];
          v16 = *v11;
          if ( v15 )
          {
            v17 = v15 - 2160 + (unsigned int)v4 * (unsigned __int64)v14;
            v18 = *(_DWORD *)(v17 + 24);
            if ( v18 - *(_DWORD *)(v17 + 28) < 0 )
            {
              if ( (_DWORD)v4 == 4 )
                goto LABEL_49;
              *(_DWORD *)(v15 - 2160 + (unsigned int)v4 * (unsigned __int64)v14 + 24) = v18
                                                                                      + *(unsigned __int16 *)(v15 - 2000);
            }
            v19 = (_QWORD *)v11[1];
            if ( (_QWORD *)*v19 != v11 || (v20 = *v11, *(_QWORD **)(*v11 + 8LL) != v11) )
            {
LABEL_28:
              _list_del_entry_valid_or_report(v11);
              goto LABEL_22;
            }
            *(_QWORD *)(v20 + 8) = v19;
            *v19 = v20;
          }
          else
          {
            v21 = (_QWORD *)v11[1];
            if ( (_QWORD *)*v21 != v11 || *(_QWORD **)(v16 + 8) != v11 )
              goto LABEL_28;
            *(_QWORD *)(v16 + 8) = v21;
            *v21 = v16;
          }
LABEL_22:
          a2 = v12[1];
          if ( v11 == v12 || (_QWORD *)a2 == v11 || *(_QWORD **)a2 != v12 )
          {
            _list_add_valid_or_report(v11, a2);
            if ( (_QWORD *)v16 == v12 )
            {
LABEL_30:
              v7 = *(_QWORD *)(v6 + 8);
              break;
            }
          }
          else
          {
            v12[1] = v11;
            *v11 = v12;
            v11[1] = a2;
            *(_QWORD *)a2 = v11;
            if ( (_QWORD *)v16 == v12 )
              goto LABEL_30;
          }
          v11 = (_QWORD *)v16;
          if ( v16 - 184 == v13 )
            goto LABEL_30;
        }
      }
    }
    if ( (_DWORD)v4 != 4 )
    {
      v22 = (_DWORD *)(v7 + 40LL * (unsigned int)v4 - 2136);
      if ( (*v22 & 0x80000000) == 0 )
        goto LABEL_33;
      *v22 += *(unsigned __int16 *)(v7 - 2000);
      v28 = *(_QWORD **)(v6 - 40);
      if ( (_QWORD *)*v28 == v2 && (v29 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v29 + 8) = v28;
        *v28 = v29;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      a2 = v12[1];
      if ( v2 != v12 && (_QWORD *)a2 != v2 && *(_QWORD **)a2 == v12 )
      {
        v26 = 0;
        v12[1] = v2;
        *(_QWORD *)(v6 - 48) = v12;
        *(_QWORD *)(v6 - 40) = a2;
        *(_QWORD *)a2 = v2;
        goto LABEL_39;
      }
LABEL_50:
      _list_add_valid_or_report(v2, a2);
      v26 = 0;
      goto LABEL_39;
    }
LABEL_49:
    __break(0x5512u);
    goto LABEL_50;
  }
LABEL_33:
  v24 = v6 - 48;
  v23 = *(_QWORD *)(v6 - 48);
  if ( v23 != v6 - 48 )
  {
    v25 = *(_QWORD **)(v6 - 40);
    if ( *v25 == v24 && *(_QWORD *)(v23 + 8) == v24 )
    {
      *(_QWORD *)(v23 + 8) = v25;
      *v25 = v23;
    }
    else
    {
      _list_del_entry_valid_or_report(v6 - 48);
    }
    *(_QWORD *)(v6 - 48) = v6 - 48;
    *(_QWORD *)(v6 - 40) = v24;
  }
  v26 = 1;
LABEL_39:
  raw_spin_unlock_bh(v3 + 77);
  return v26;
}
