_QWORD *__fastcall ieee80211_sta_other_link_csa_disappeared(_QWORD *result, __int64 *a2)
{
  unsigned __int16 *v2; // x9
  __int64 v3; // x20
  unsigned __int64 v4; // x8
  __int64 v5; // x19
  char v6; // w8
  __int64 v7; // x10
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x8
  _QWORD *v13; // [xsp+0h] [xbp-20h] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (unsigned __int16 *)a2[56];
  v3 = *result;
  v13 = result;
  v14 = 0;
  v15 = 0;
  if ( v2 )
  {
    v4 = *v2;
    v5 = (__int64)result;
    if ( (v4 & 0x200) != 0 )
    {
      v7 = 9;
      if ( (v4 & 0x10) != 0 )
        v7 = 10;
      v6 = *((_BYTE *)v2 + v7 + ((v4 >> 5) & 1) + ((v4 >> 5) & 2) + ((v4 >> 6) & 2) + ((v4 >> 7) & 2));
    }
    else
    {
      v6 = 0;
    }
    v8 = *a2;
    v9 = a2[1];
    LOBYTE(v15) = v6;
    result = (_QWORD *)cfg80211_iter_rnr(v8, v9, ieee80211_sta_csa_rnr_iter, &v13);
    if ( v14 )
    {
      if ( v14 != *(_QWORD *)(v5 + 168) )
        result = (_QWORD *)ieee80211_sta_abort_chanswitch(v5);
    }
    else
    {
      v12 = *(_QWORD *)v5;
      if ( *(_WORD *)(*(_QWORD *)v5 + 5800LL) )
        printk(&unk_B9E50, v12 + 1640, *(unsigned int *)(v5 + 8), v11);
      else
        printk(&unk_BD059, v12 + 1640, v10, v11);
      result = (_QWORD *)wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v3 + 1616) + 72LL), v3 + 2432);
    }
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
