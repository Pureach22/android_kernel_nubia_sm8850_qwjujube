__int64 __fastcall hal_reo_ix_remap_value_get_be(__int64 a1, char a2)
{
  unsigned int v2; // w8
  _DWORD *v3; // x10
  __int64 result; // x0
  unsigned int v5; // w9
  _BOOL8 v6; // x14
  unsigned int v7; // w10
  unsigned int v8; // w11
  unsigned int v9; // w12
  unsigned int v10; // w13
  unsigned int v11; // w9
  unsigned int v12; // w8
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v13, 0, 32);
  if ( (a2 & 1) != 0 )
  {
    LODWORD(v13[0]) = reo_dest_ring_remap;
    v2 = 1;
    if ( (a2 & 2) == 0 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v2 = 0;
  if ( (a2 & 2) != 0 )
  {
LABEL_5:
    v3 = (_DWORD *)((unsigned __int64)v13 | (4LL * v2++));
    *v3 = dword_163C4;
  }
LABEL_6:
  if ( (a2 & 4) != 0 )
  {
    *((_DWORD *)v13 + v2++) = dword_163C8;
    if ( (a2 & 8) == 0 )
    {
LABEL_8:
      if ( (a2 & 0x10) == 0 )
        goto LABEL_9;
      goto LABEL_16;
    }
  }
  else if ( (a2 & 8) == 0 )
  {
    goto LABEL_8;
  }
  *((_DWORD *)v13 + v2++) = dword_163CC;
  if ( (a2 & 0x10) == 0 )
  {
LABEL_9:
    if ( (a2 & 0x20) == 0 )
      goto LABEL_10;
    goto LABEL_17;
  }
LABEL_16:
  *((_DWORD *)v13 + v2++) = dword_163D0;
  if ( (a2 & 0x20) == 0 )
  {
LABEL_10:
    if ( (a2 & 0x40) == 0 )
      goto LABEL_11;
    goto LABEL_18;
  }
LABEL_17:
  *((_DWORD *)v13 + v2++) = dword_163D4;
  if ( (a2 & 0x40) == 0 )
  {
LABEL_11:
    if ( (a2 & 0x80) == 0 )
      goto LABEL_12;
LABEL_19:
    *((_DWORD *)v13 + v2++) = dword_163DC;
    goto LABEL_20;
  }
LABEL_18:
  *((_DWORD *)v13 + v2++) = dword_163D8;
  if ( a2 < 0 )
    goto LABEL_19;
LABEL_12:
  if ( !a2 )
  {
    result = 1431655765;
    goto LABEL_28;
  }
LABEL_20:
  if ( v2 == 1 )
    v5 = 1;
  else
    v5 = 2;
  v6 = v2 != 1;
  v7 = v5 % v2;
  v8 = (v5 % v2 + 1) % v2;
  v9 = (unsigned __int8)(v8 + 1) % v2;
  if ( v9 > 7
    || (v10 = (unsigned __int8)(v9 + 1) % v2, v10 > 7)
    || (v11 = (unsigned __int8)(v10 + 1) % v2, v11 > 7)
    || (v12 = (unsigned __int8)(v11 + 1) % v2, v12 > 7) )
  {
    __break(1u);
  }
  result = (16 * (unsigned __int8)*(_DWORD *)((unsigned __int64)v13 | (4 * v6)))
         | LOBYTE(v13[0])
         | ((unsigned __int8)*((_DWORD *)v13 + v7) << 8)
         | ((unsigned __int8)*((_DWORD *)v13 + v8) << 12)
         | ((unsigned __int8)*((_DWORD *)v13 + (unsigned __int8)v9) << 16)
         | ((unsigned __int8)*((_DWORD *)v13 + (unsigned __int8)v10) << 20)
         | (*((_DWORD *)v13 + (unsigned __int8)v11) << 24)
         | (*((_DWORD *)v13 + (unsigned __int8)v12) << 28);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
