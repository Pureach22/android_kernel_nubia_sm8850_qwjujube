__int64 __fastcall regmap_printable(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w8
  unsigned int v5; // w8
  unsigned int v6; // w8
  void (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x0
  _DWORD *v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x0
  _DWORD *v15; // x8
  __int64 v16; // x0
  unsigned int v17; // w8
  _DWORD *v18; // x8
  __int64 v19; // x0
  _DWORD *v20; // x8
  int v21; // w0
  __int64 v22; // x8
  void (__fastcall *v23)(_QWORD); // x9
  int v24; // w19
  __int64 result; // x0
  __int64 v26; // x0
  void (__fastcall *v27)(_QWORD); // x8
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 480) )
    goto LABEL_9;
  v4 = *(_DWORD *)(a1 + 376);
  if ( (!v4 || v4 >= a2) && !*(_QWORD *)(a1 + 144) )
  {
    v11 = *(_DWORD **)(a1 + 392);
    if ( v11 )
    {
      v12 = *(_QWORD *)(a1 + 88);
      if ( *(v11 - 1) != 398833565 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, _QWORD))v11)(v12, a2) & 1) == 0 )
        goto LABEL_5;
    }
    else if ( *(_QWORD *)(a1 + 440) && (regmap_check_range_table(a1, a2) & 1) == 0 )
    {
      goto LABEL_5;
    }
    v15 = *(_DWORD **)(a1 + 408);
    if ( v15 )
    {
      v16 = *(_QWORD *)(a1 + 88);
      if ( *(v15 - 1) != 398833565 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, _QWORD))v15)(v16, a2) & 1) != 0 )
        goto LABEL_71;
    }
    else if ( *(_QWORD *)(a1 + 456) && (regmap_check_range_table(a1, a2) & 1) != 0 )
    {
      goto LABEL_71;
    }
  }
LABEL_5:
  if ( *(_QWORD *)(a1 + 480) )
  {
    v5 = *(_DWORD *)(a1 + 376);
    if ( (!v5 || v5 >= a2) && !*(_QWORD *)(a1 + 144) )
    {
      v13 = *(_DWORD **)(a1 + 392);
      if ( v13 )
      {
        v14 = *(_QWORD *)(a1 + 88);
        if ( *(v13 - 1) != 398833565 )
          __break(0x8228u);
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))v13)(v14, a2) & 1) != 0 )
          goto LABEL_63;
      }
      else if ( !*(_QWORD *)(a1 + 440) || (regmap_check_range_table(a1, a2) & 1) != 0 )
      {
        goto LABEL_63;
      }
    }
  }
LABEL_9:
  if ( !*(_DWORD *)(a1 + 568) || !*(_QWORD *)(a1 + 560) || (v6 = *(_DWORD *)(a1 + 376)) != 0 && v6 < a2 )
  {
LABEL_71:
    result = 0;
    goto LABEL_72;
  }
  v7 = *(void (__fastcall **)(_QWORD))(a1 + 56);
  v8 = *(_QWORD *)(a1 + 72);
  v28 = 0;
  if ( *((_DWORD *)v7 - 1) != 251140989 )
    __break(0x8228u);
  v7(v8);
  if ( !*(_DWORD *)(a1 + 568) )
    goto LABEL_68;
  if ( !*(_QWORD *)(a1 + 560) )
  {
    __break(0x800u);
    goto LABEL_68;
  }
  if ( !*(_QWORD *)(a1 + 144) )
  {
    if ( !*(_QWORD *)(a1 + 480) )
      goto LABEL_58;
    v17 = *(_DWORD *)(a1 + 376);
    if ( v17 )
    {
      if ( v17 < a2 )
        goto LABEL_58;
    }
    v18 = *(_DWORD **)(a1 + 392);
    if ( v18 )
    {
      v19 = *(_QWORD *)(a1 + 88);
      if ( *(v18 - 1) != 398833565 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, _QWORD))v18)(v19, a2) & 1) == 0 )
        goto LABEL_58;
    }
    else if ( *(_QWORD *)(a1 + 440) && (regmap_check_range_table(a1, a2) & 1) == 0 )
    {
      goto LABEL_58;
    }
  }
  v9 = *(_DWORD **)(a1 + 400);
  if ( v9 )
  {
    v10 = *(_QWORD *)(a1 + 88);
    if ( *(v9 - 1) != 398833565 )
      __break(0x8228u);
    if ( (((__int64 (__fastcall *)(__int64, _QWORD))v9)(v10, a2) & 1) != 0 )
      goto LABEL_68;
    goto LABEL_58;
  }
  if ( !*(_QWORD *)(a1 + 448) )
  {
    if ( *(_QWORD *)(a1 + 560) )
      goto LABEL_58;
LABEL_68:
    v27 = *(void (__fastcall **)(_QWORD))(a1 + 64);
    v26 = *(_QWORD *)(a1 + 72);
    if ( *((_DWORD *)v27 - 1) != 251140989 )
      __break(0x8228u);
    v27(v26);
    goto LABEL_71;
  }
  if ( (regmap_check_range_table(a1, a2) & 1) != 0 )
    goto LABEL_68;
LABEL_58:
  v20 = *(_DWORD **)(*(_QWORD *)(a1 + 560) + 40LL);
  if ( *(v20 - 1) != 429693940 )
    __break(0x8228u);
  v21 = ((__int64 (__fastcall *)(__int64, _QWORD, int *))v20)(a1, a2, &v28);
  v23 = *(void (__fastcall **)(_QWORD))(a1 + 64);
  v22 = *(_QWORD *)(a1 + 72);
  v24 = v21;
  if ( *((_DWORD *)v23 - 1) != 251140989 )
    __break(0x8229u);
  v23(v22);
  if ( v24 )
    goto LABEL_71;
LABEL_63:
  result = 1;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
