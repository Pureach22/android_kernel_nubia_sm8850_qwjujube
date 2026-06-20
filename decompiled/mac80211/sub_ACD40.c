// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_ACD40@<X0>(unsigned __int64 a1@<X0>, int a2@<W1>, __int64 a3@<X8>)
{
  _BOOL4 v3; // w17
  __int64 v4; // x17
  __int64 v5; // x17
  __int64 v6; // x0
  _DWORD *v7; // x0
  unsigned int v8; // t1
  _QWORD *v9; // x8
  __int64 v10; // x16
  _QWORD *v11; // x2
  _QWORD *v12; // x1
  _QWORD *v13; // x20
  _QWORD *v14; // x16
  int v15; // w15
  _QWORD *v16; // x8
  __int64 v17; // x11
  _QWORD *v18; // x9
  __int64 v19; // x10
  __int64 v20; // x11
  _QWORD *v21; // x12
  _QWORD *v22; // x13
  unsigned int v23; // w14
  int v24; // w15
  __int64 v25; // x16
  int v26; // w17
  __int64 v27; // x19
  unsigned int v28; // w20
  __int64 v29; // x21
  __int64 v30; // x22
  int v31; // w23

  if ( (a2 & 0x80000) == 0 )
    return ieee80211_vif_to_wdev(a1);
  while ( 1 )
  {
    if ( v26 - *(_DWORD *)(a1 + 28) < 0 )
    {
      if ( v28 == 4 )
        goto LABEL_43;
      *(_DWORD *)(v25 + v28 * (unsigned __int64)v23 + 24) = v26 + *(unsigned __int16 *)(a3 - 2000);
      v28 = *((unsigned __int8 *)v18 + 65);
      if ( v28 > 4 )
        goto LABEL_43;
    }
    else if ( (v31 & 1) != 0 )
    {
      goto LABEL_35;
    }
    v9 = (_QWORD *)v18[1];
    if ( (_QWORD *)*v9 == v18 && (v10 = *v18, *(_QWORD **)(*v18 + 8LL) == v18) )
    {
      *(_QWORD *)(v10 + 8) = v9;
      *v9 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(v18);
    }
    v11 = (_QWORD *)(v20 + 16LL * v28);
    v12 = (_QWORD *)v11[1];
    if ( v18 == v11 || v12 == v18 || (_QWORD *)*v12 != v11 )
    {
      _list_add_valid_or_report(v18, v12);
    }
    else
    {
      v11[1] = v18;
      *v18 = v11;
      v18[1] = v12;
      *v12 = v18;
    }
    v18 = (_QWORD *)*v21;
    v13 = nullptr;
    if ( (_QWORD *)*v21 == v21 )
      break;
    v14 = v18 - 23;
    v15 = v31 | v24;
    if ( v18 == &qword_B8 )
      break;
    v3 = v14 != v22;
    if ( v14 == v22 && (v15 & 1) == 0 )
      goto LABEL_36;
    a3 = v18[7];
    if ( !v22 )
      v22 = v18 - 23;
    if ( !a3 )
    {
LABEL_35:
      if ( *((unsigned __int16 *)v18 - 2) == *(unsigned __int16 *)(v19 + 2 * v30) )
      {
LABEL_36:
        v13 = nullptr;
      }
      else
      {
        v16 = (_QWORD *)v18[1];
        v13 = v18 + 6;
        if ( (_QWORD *)*v16 == v18 && (v17 = *v18, *(_QWORD **)(*v18 + 8LL) == v18) )
        {
          *(_QWORD *)(v17 + 8) = v16;
          *v16 = v17;
        }
        else
        {
          _list_del_entry_valid_or_report(v18);
        }
        *v18 = v18;
        v18[1] = v18;
        *((_WORD *)v18 - 2) = *(_WORD *)(v19 + 2 * v30);
      }
      break;
    }
    v24 = v3 & v15;
    v31 = 1;
    if ( (*(_BYTE *)(*(_QWORD *)(v27 + 72) + 117LL) & 1) != 0 )
    {
      v4 = v18[7];
      if ( v4 )
      {
        if ( *((_BYTE *)v18 + 64) != 16 )
        {
          if ( *((unsigned __int8 *)v18 + 65) >= 4uLL )
            goto LABEL_43;
          v5 = v4 - 2160;
          v6 = v5 + *((unsigned __int8 *)v18 + 65) * (unsigned __int64)v23;
          v8 = *(_DWORD *)(v6 + 28);
          v7 = (_DWORD *)(v6 + 28);
          if ( v8 >= v7[1]
            && (*(_DWORD *)(v27 + 444) >= *(_DWORD *)(v27 + 440)
             || *v7 >= *(_DWORD *)(v5 + *((unsigned __int8 *)v18 + 65) * (unsigned __int64)v23 + 36)) )
          {
            v31 = 0;
          }
        }
      }
    }
    v28 = *((unsigned __int8 *)v18 + 65);
    if ( v28 >= 5 )
    {
LABEL_43:
      __break(0x5512u);
      JUMPOUT(0xA5B80);
    }
    v25 = a3 - 2160;
    a1 = a3 - 2160 + *((unsigned __int8 *)v18 + 65) * (unsigned __int64)v23;
    v26 = *(_DWORD *)(a1 + 24);
  }
  raw_spin_unlock_bh(v29 + 308);
  return (__int64)v13;
}
