__int64 __fastcall sde_parse_reg_dma_dt(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x20
  __int64 result; // x0
  __int64 v6; // x9
  unsigned __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x3
  __int64 v10; // x15
  int v11; // w16
  int v12; // w9
  int v13; // w10
  int v14; // w11
  int v15; // w9
  int v16; // w10
  int v17; // w9
  unsigned __int64 v24; // x11
  void *v25; // x0
  unsigned int v26; // [xsp+8h] [xbp-38h] BYREF
  _WORD v27[2]; // [xsp+Ch] [xbp-34h]
  _DWORD v28[2]; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v29[3]; // [xsp+18h] [xbp-28h] BYREF
  int v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  memset(v29, 0, sizeof(v29));
  v26 = 0;
  *(_DWORD *)((char *)v28 + 3) = 0;
  v28[0] = 0;
  v27[0] = 0;
  v4 = (_DWORD *)_kvmalloc_node_noprof(5376, 0, 3520, 0xFFFFFFFFLL);
  if ( v4
    && !(unsigned int)validate_dt_entry(a1, &reg_dma_prop, 7, v29, &v26)
    && v26
    && !(unsigned int)read_dt_entry(a1, &reg_dma_prop, 7, v29, v28, v4) )
  {
    v6 = v26;
    v7 = a2 + 0x4000;
    v27[0] = 0;
    *(_DWORD *)(a2 + 19904) = 0;
    if ( (_DWORD)v6 )
    {
      v8 = 0;
      while ( 1 )
      {
        if ( v8 == 64 )
          goto LABEL_26;
        v9 = (unsigned int)v4[v8 + 192];
        if ( (unsigned int)v9 >= 2 )
          break;
        if ( *((_BYTE *)v27 + v9) == 1 )
        {
          v25 = &unk_22F15A;
          goto LABEL_38;
        }
        v10 = a2 + 19908 + 12LL * (unsigned int)v9;
        v11 = v4[v8++];
        *((_BYTE *)v27 + v9) = 1;
        *(_DWORD *)(a2 + 19904) = v8;
        *(_DWORD *)(v10 + 4) = v11;
        *(_BYTE *)v10 = 1;
        if ( v6 == v8 )
          goto LABEL_12;
      }
      v25 = &unk_250B25;
LABEL_38:
      printk(v25, "sde_parse_reg_dma_dt");
      goto LABEL_5;
    }
LABEL_12:
    v12 = v4[384];
    v13 = v4[576];
    v14 = v4[768];
    *(_DWORD *)(a2 + 19952) = 0;
    *(_DWORD *)(a2 + 19932) = v12;
    v15 = v4[960];
    *(_DWORD *)(a2 + 19936) = v13;
    *(_DWORD *)(a2 + 19940) = v14;
    *(_DWORD *)(a2 + 19948) = v15;
    *(_DWORD *)(a2 + 19960) = 18;
    if ( (*(_QWORD *)(a2 + 22008) & 0x8000000000LL) != 0 )
      goto LABEL_27;
    v7 = *(unsigned int *)(a2 + 644);
    if ( !(_DWORD)v7 )
      goto LABEL_28;
    v16 = v4[1216];
    v17 = v4[1217];
    *(_DWORD *)(a2 + 868) = v16;
    *(_DWORD *)(a2 + 872) = v17;
    if ( (_DWORD)v7 == 1 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 1268) = v16;
    *(_DWORD *)(a2 + 1272) = v17;
    if ( (_DWORD)v7 == 2 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 1668) = v16;
    *(_DWORD *)(a2 + 1672) = v17;
    if ( (_DWORD)v7 == 3 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 2068) = v16;
    *(_DWORD *)(a2 + 2072) = v17;
    if ( (_DWORD)v7 == 4 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 2468) = v16;
    *(_DWORD *)(a2 + 2472) = v17;
    if ( (_DWORD)v7 == 5 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 2868) = v16;
    *(_DWORD *)(a2 + 2872) = v17;
    if ( (_DWORD)v7 == 6 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 3268) = v16;
    *(_DWORD *)(a2 + 3272) = v17;
    if ( (_DWORD)v7 == 7 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 3668) = v16;
    *(_DWORD *)(a2 + 3672) = v17;
    if ( (_DWORD)v7 == 8 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 4068) = v16;
    *(_DWORD *)(a2 + 4072) = v17;
    if ( (_DWORD)v7 == 9 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 4468) = v16;
    *(_DWORD *)(a2 + 4472) = v17;
    if ( (_DWORD)v7 == 10 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 4868) = v16;
    *(_DWORD *)(a2 + 4872) = v17;
    if ( (_DWORD)v7 == 11 )
      goto LABEL_28;
    *(_DWORD *)(a2 + 5268) = v16;
    *(_DWORD *)(a2 + 5272) = v17;
    if ( (_DWORD)v7 == 12 )
      goto LABEL_28;
LABEL_26:
    while ( 1 )
    {
      __break(0x5512u);
LABEL_27:
      *(_DWORD *)(v7 + 3560) = 1;
LABEL_28:
      if ( !*(_DWORD *)(a2 + 5448) )
        break;
      v7 = 0;
      _X9 = (unsigned __int64 *)(a2 + 5488);
      while ( v7 != 13 )
      {
        __asm { PRFM            #0x11, [X9] }
        do
          v24 = __ldxr(_X9);
        while ( __stxr(v24 | 0x2000, _X9) );
        ++v7;
        _X9 += 6;
        if ( v7 >= *(unsigned int *)(a2 + 5448) )
          goto LABEL_5;
      }
    }
  }
LABEL_5:
  result = kvfree(v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
