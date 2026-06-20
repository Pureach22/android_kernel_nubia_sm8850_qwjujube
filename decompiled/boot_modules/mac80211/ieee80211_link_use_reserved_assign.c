__int64 __fastcall ieee80211_link_use_reserved_assign(__int64 *a1)
{
  __int64 v1; // x8
  char v2; // w9
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v6; // x8
  _QWORD *v7; // x23
  __int64 *v8; // x22
  _QWORD *v9; // x25
  __int64 v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x26
  __int64 v13; // x10
  __int64 *v14; // x0
  __int64 v15; // x9
  _QWORD *v16; // x12
  bool v17; // zf
  __int64 v18; // x8
  __int64 v19; // x11
  _QWORD *v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x8
  __int64 v24; // x9
  _QWORD *v25; // t2
  __int64 **v26; // x8
  __int64 *v27; // x0
  __int64 *v28; // x9
  __int64 result; // x0
  int v30; // w9
  _QWORD *v31; // x8
  _QWORD *v32; // x8
  _QWORD *v33; // x10
  int v34; // w9
  _QWORD *v35; // x10
  _QWORD *v36; // x10
  _QWORD *v37; // x8
  unsigned int v38; // w23
  __int64 v39; // x9
  __int64 v40; // x8
  unsigned int v41; // w9
  int v42; // w9
  unsigned int v43; // w20
  __int64 v44; // [xsp+8h] [xbp-48h] BYREF
  __int64 v45; // [xsp+10h] [xbp-40h]
  __int64 v46; // [xsp+18h] [xbp-38h]
  __int64 v47; // [xsp+20h] [xbp-30h]
  __int64 v48; // [xsp+28h] [xbp-28h]
  __int64 v49; // [xsp+30h] [xbp-20h]
  __int64 v50; // [xsp+38h] [xbp-18h]
  __int64 v51; // [xsp+40h] [xbp-10h]
  __int64 v52; // [xsp+48h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v2 = *((_BYTE *)a1 + 441);
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v3 = *(_QWORD *)(v1 + 1616);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  if ( (v2 & 1) != 0
    && ((v4 = a1[46], (v6 = *(_QWORD *)(a1[118] + 832)) == 0) || v6 == 152)
    && v4
    && *(_DWORD *)(v4 + 64) != 2 )
  {
    v7 = (_QWORD *)(v4 + 32);
    v8 = a1 + 47;
    v9 = (_QWORD *)(v4 + 32);
    while ( 1 )
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == v7 )
        break;
      if ( !v9[44] )
      {
        v10 = v9[116];
        v12 = (_QWORD *)(v10 + 168);
        v11 = *(_QWORD *)(v10 + 168);
        if ( v11 )
        {
          v13 = v8[4];
          if ( v13 )
          {
            if ( v11 != v13
              || *(_DWORD *)(v10 + 176) != *((_DWORD *)v8 + 10)
              || *(_DWORD *)(v10 + 180) != *((_DWORD *)v8 + 11)
              || *(unsigned __int16 *)(v10 + 196) != *((unsigned __int16 *)v8 + 30)
              || *(_DWORD *)(v10 + 184) != *((_DWORD *)v8 + 12)
              || *(unsigned __int16 *)(v10 + 198) != *((unsigned __int16 *)v8 + 31) )
            {
              goto LABEL_47;
            }
          }
        }
        v14 = (__int64 *)cfg80211_chandef_compatible(v10 + 136, v8);
        if ( !v14 )
          goto LABEL_47;
        v15 = v14[3];
        v16 = v8 + 4;
        v8 = &v44;
        v17 = *v12 == 0;
        v18 = *v14;
        v19 = v14[1];
        v46 = v14[2];
        v47 = v15;
        if ( v17 )
          v20 = v16;
        else
          v20 = v12;
        v44 = v18;
        v45 = v19;
        v22 = v20[2];
        v21 = v20[3];
        v25 = v20;
        v24 = *v20;
        v23 = v25[1];
        v50 = v22;
        v51 = v21;
        v48 = v24;
        v49 = v23;
      }
    }
    if ( !v8 )
    {
LABEL_47:
      __break(0x800u);
      result = 4294967274LL;
      goto LABEL_50;
    }
    ieee80211_change_chanctx(v3, v4, v4, v8, 0);
    v26 = (__int64 **)a1[5];
    v27 = a1 + 4;
    if ( *v26 == a1 + 4 && (v28 = (__int64 *)*v27, *(__int64 **)(*v27 + 8) == v27) )
    {
      v28[1] = (__int64)v26;
      *v26 = v28;
    }
    else
    {
      _list_del_entry_valid_or_report(v27);
    }
    a1[46] = 0;
    a1[4] = 0xDEAD000000000100LL;
    a1[5] = 0xDEAD000000000122LL;
    result = ieee80211_assign_link_chanctx(a1, v4, 0);
    if ( (_DWORD)result )
    {
      v30 = 2;
      v31 = (_QWORD *)(v4 + 32);
      do
      {
        v31 = (_QWORD *)*v31;
        --v30;
      }
      while ( v31 != v7 );
      v32 = (_QWORD *)(v4 + 48);
      v33 = (_QWORD *)(v4 + 48);
      do
      {
        v33 = (_QWORD *)*v33;
        --v30;
      }
      while ( v33 != v32 );
      if ( !v30 )
      {
        v34 = 2;
        v35 = (_QWORD *)(v4 + 32);
        do
        {
          v35 = (_QWORD *)*v35;
          --v34;
        }
        while ( v35 != v7 );
        v36 = (_QWORD *)(v4 + 48);
        do
        {
          v36 = (_QWORD *)*v36;
          --v34;
        }
        while ( v36 != v32 );
        if ( v34 )
          __break(0x800u);
        v37 = *(_QWORD **)(v4 + 8);
        v38 = result;
        if ( *v37 == v4 && (v39 = *(_QWORD *)v4, *(_QWORD *)(*(_QWORD *)v4 + 8LL) == v4) )
        {
          *(_QWORD *)(v39 + 8) = v37;
          *v37 = v39;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        *(_QWORD *)(v4 + 8) = 0xDEAD000000000122LL;
        ieee80211_del_chanctx(v3, v4, 0);
        kvfree_call_rcu(v4 + 16, v4);
        result = v38;
      }
    }
    v40 = *a1;
    v41 = *(_DWORD *)(*a1 + 4720);
    if ( v41 <= 0xD )
    {
      v42 = 1 << v41;
      if ( (v42 & 0x3771) != 0 )
      {
        __break(0x800u);
      }
      else
      {
        v43 = result;
        if ( (v42 & 0x88A) != 0 )
          wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v40 + 1616) + 72LL), a1 + 18);
        else
          wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v40 + 1616) + 72LL), a1 + 71, 0);
        result = v43;
      }
    }
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
