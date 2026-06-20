__int64 __fastcall ieee80211_recalc_smps_chanctx(__int64 result, _BYTE *a2)
{
  _QWORD *v2; // x23
  _BYTE *v3; // x8
  _QWORD *v4; // x24
  __int64 v5; // x13
  _BYTE *v6; // x1
  unsigned __int8 v7; // w22
  unsigned __int8 v8; // w21
  __int64 v9; // x20
  unsigned int v10; // w9
  unsigned int v11; // w10
  __int64 v12; // x26
  unsigned int v13; // w10
  int v14; // w9
  __int64 v15; // x9
  _DWORD *v16; // x9
  __int64 v17; // [xsp+8h] [xbp-18h]
  _BYTE *v18; // [xsp+10h] [xbp-10h]
  _BYTE *v19; // [xsp+18h] [xbp-8h]

  v2 = *(_QWORD **)(result + 4616);
  v3 = a2;
  v4 = (_QWORD *)(result + 4616);
  v5 = result;
  v6 = a2 + 152;
  if ( v2 != (_QWORD *)(result + 4616) )
  {
    v7 = 1;
    v8 = 1;
    while ( (v2[204] & 1) == 0 )
    {
LABEL_3:
      v2 = (_QWORD *)*v2;
      if ( v2 == v4 )
        goto LABEL_28;
    }
    v9 = 0;
    while ( 1 )
    {
      v12 = v2[v9 + 571];
      if ( v12 )
      {
        v13 = *(_DWORD *)(*(_QWORD *)v12 + 4720LL);
        if ( v13 <= 0xB
          && (((1 << v13) & 0x88A) != 0 || v13 == 2 && (*(_BYTE *)(*(_QWORD *)v12 + 2477LL) & 8) != 0)
          && *(_BYTE **)(*(_QWORD *)(v12 + 944) + 832LL) == v6 )
        {
          break;
        }
      }
LABEL_13:
      if ( ++v9 == 15 )
        goto LABEL_3;
    }
    v14 = *(_DWORD *)(v12 + 444);
    if ( v14 != 1 )
    {
      if ( v14 == 2 )
      {
        v10 = 1;
        goto LABEL_26;
      }
      if ( v14 == 3 )
      {
        v10 = *(unsigned __int8 *)(v12 + 442);
LABEL_26:
        v11 = 1;
        goto LABEL_9;
      }
      if ( (ieee80211_recalc_smps_chanctx___already_done & 1) == 0 )
      {
        v19 = v6;
        ieee80211_recalc_smps_chanctx___already_done = 1;
        v17 = v5;
        v18 = v3;
        result = _warn_printk("Invalid SMPS mode %d\n", v14);
        v5 = v17;
        v3 = v18;
        v6 = v19;
        __break(0x800u);
      }
    }
    v10 = *(unsigned __int8 *)(v12 + 442);
    v11 = v10;
LABEL_9:
    if ( v7 <= v11 )
      v7 = v11;
    if ( v8 <= v10 )
      v8 = v10;
    goto LABEL_13;
  }
  v8 = 1;
  v7 = 1;
LABEL_28:
  v15 = *(_QWORD *)(v5 + 5384);
  if ( v15 && *(_BYTE **)(v15 + 5640) == v6 )
  {
    v8 = *(_BYTE *)(v5 + 1504);
    v7 = v8;
  }
  if ( (unsigned __int8)v3[252] != v7 || (unsigned __int8)v3[253] != v8 )
  {
    v3[252] = v7;
    v3[253] = v8;
    v16 = *(_DWORD **)(*(_QWORD *)(v5 + 464) + 608LL);
    if ( v16 )
    {
      if ( (v3[84] & 1) == 0 )
      {
        __break(0x800u);
        v16 = *(_DWORD **)(*(_QWORD *)(v5 + 464) + 608LL);
      }
      if ( *(v16 - 1) != 1043050079 )
        __break(0x8229u);
      return ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))v16)(v5, v6, 2);
    }
  }
  return result;
}
