__int64 __fastcall nl80211_parse_mon_options(__int64 a1, __int64 a2, __int64 a3, int *a4)
{
  _WORD *v5; // x9
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x20
  _BOOL4 v9; // w22
  int *v10; // x23
  int v11; // w9
  int v12; // w11
  _BOOL4 v14; // w10
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x9
  __int64 v18; // [xsp+0h] [xbp-40h] BYREF
  __int64 v19; // [xsp+8h] [xbp-38h]
  __int64 v20; // [xsp+10h] [xbp-30h]
  __int64 v21; // [xsp+18h] [xbp-28h]
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_WORD **)(*(_QWORD *)(a3 + 32) + 184LL);
  result = v5 != nullptr;
  if ( !v5 )
  {
    if ( (*a4 & 0x40) == 0 )
      goto LABEL_30;
    goto LABEL_29;
  }
  if ( (_DWORD)a2 != 6 )
    goto LABEL_42;
  v23 = 0;
  v24 = 0;
  v7 = a1;
  v8 = a3;
  v21 = 0;
  v22 = 0;
  v9 = v5 != nullptr;
  v10 = a4;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  *a4 = 0;
  if ( (unsigned int)_nla_parse(&v18, a2, v5 + 2, (unsigned __int16)(*v5 - 4), &mntr_flags_policy, 0, 0) )
    goto LABEL_42;
  v11 = *v10;
  a4 = v10;
  if ( v19 )
  {
    v11 |= 2u;
    *v10 = v11;
  }
  result = v9;
  a1 = v7;
  a3 = v8;
  LODWORD(a2) = 6;
  if ( v20 )
  {
    v11 |= 4u;
    *v10 = v11;
  }
  if ( v21 )
  {
    v11 |= 8u;
    *v10 = v11;
  }
  if ( v22 )
  {
    v11 |= 0x10u;
    *v10 = v11;
  }
  if ( v23 )
  {
    v11 |= 0x20u;
    *v10 = v11;
  }
  if ( v24 )
    v12 = v11 | 0x40;
  else
    v12 = v11;
  v14 = (v12 & 0x20) == 0 || v12 == 32;
  if ( !v24 && !v14 )
    goto LABEL_44;
  *v10 = v12 | v14;
  if ( !v14 )
    goto LABEL_44;
  if ( (((unsigned __int8)v12 | v14) & 0x40) != 0 )
  {
LABEL_29:
    if ( (*(_BYTE *)(a1 + 1102) & 2) == 0 )
      goto LABEL_44;
  }
LABEL_30:
  v15 = *(_QWORD *)(a3 + 32);
  v16 = *(_QWORD *)(v15 + 1848);
  if ( v16 )
  {
    if ( (_DWORD)a2 == 6 )
    {
      if ( (*(_BYTE *)(a1 + 1104) & 4) == 0 )
        goto LABEL_44;
      if ( (*(_BYTE *)(v16 + 4) & 1) == 0 && (*(char *)(v16 + 27) & 0x80000000) == 0 )
      {
        *((_QWORD *)a4 + 2) = v16 + 4;
        v17 = *(_QWORD *)(*(_QWORD *)(a3 + 32) + 1856LL);
        if ( !v17 )
          goto LABEL_41;
LABEL_39:
        if ( (*(_BYTE *)(a1 + 1104) & 4) != 0 )
        {
          *((_QWORD *)a4 + 3) = v17 + 4;
LABEL_41:
          result = 1;
          goto LABEL_45;
        }
LABEL_44:
        result = 4294967201LL;
        goto LABEL_45;
      }
    }
LABEL_42:
    result = 4294967274LL;
    goto LABEL_45;
  }
  v17 = *(_QWORD *)(v15 + 1856);
  if ( v17 )
  {
    if ( (_DWORD)a2 == 6 )
      goto LABEL_39;
    goto LABEL_42;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
