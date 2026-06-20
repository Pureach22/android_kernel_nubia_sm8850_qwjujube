void __fastcall hal_reo_remap_ix2_ix3_value_get_be(__int64 a1, int a2, int *a3, int *a4)
{
  unsigned int v4; // w8
  _DWORD *v5; // x9
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9
  unsigned int v10; // w10
  unsigned int v11; // w12
  _BOOL8 v12; // x11
  unsigned int v13; // w13
  unsigned int v14; // w15
  unsigned int v15; // w14
  unsigned int v16; // w16
  unsigned int v17; // w17
  unsigned int v18; // w0
  unsigned int v19; // w4
  unsigned int v20; // w5
  unsigned int v21; // w6
  unsigned int v22; // w1
  unsigned int v23; // w8
  int v24; // w9
  int v25; // w13
  _QWORD v26[5]; // [xsp+8h] [xbp-28h] BYREF

  v26[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v26, 0, 32);
  if ( (a2 & 1) != 0 )
  {
    LODWORD(v26[0]) = reo_dest_ring_remap;
    v4 = 1;
    if ( (a2 & 2) == 0 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v4 = 0;
  if ( (a2 & 2) != 0 )
  {
LABEL_5:
    v5 = (_DWORD *)((unsigned __int64)v26 | (4LL * v4++));
    *v5 = dword_15AA4;
  }
LABEL_6:
  if ( (a2 & 4) != 0 )
  {
    *((_DWORD *)v26 + v4++) = dword_15AA8;
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
  *((_DWORD *)v26 + v4++) = dword_15AAC;
  if ( (a2 & 0x10) == 0 )
  {
LABEL_9:
    if ( (a2 & 0x20) == 0 )
      goto LABEL_10;
    goto LABEL_17;
  }
LABEL_16:
  *((_DWORD *)v26 + v4++) = dword_15AB0;
  if ( (a2 & 0x20) == 0 )
  {
LABEL_10:
    if ( (a2 & 0x40) == 0 )
      goto LABEL_11;
    goto LABEL_18;
  }
LABEL_17:
  *((_DWORD *)v26 + v4++) = dword_15AB4;
  if ( (a2 & 0x40) == 0 )
  {
LABEL_11:
    if ( (a2 & 0x80) == 0 )
      goto LABEL_12;
LABEL_19:
    *((_DWORD *)v26 + v4++) = dword_15ABC;
    goto LABEL_20;
  }
LABEL_18:
  *((_DWORD *)v26 + v4++) = dword_15AB8;
  if ( (a2 & 0x80) != 0 )
    goto LABEL_19;
LABEL_12:
  if ( !a2 )
  {
    v6 = 1431655765;
    v7 = 1431655765;
    goto LABEL_36;
  }
LABEL_20:
  if ( v4 == 1 )
    v8 = 1;
  else
    v8 = 2;
  v9 = v8 % v4;
  v10 = (v9 + 1) % v4;
  v11 = (unsigned __int8)(v10 + 1) % v4;
  v12 = v4 != 1;
  if ( v11 > 7 )
    goto LABEL_37;
  v13 = (unsigned __int8)(v11 + 1) % v4;
  if ( v13 > 7 )
    goto LABEL_37;
  v14 = (unsigned __int8)(v13 + 1) % v4;
  if ( v14 > 7 )
    goto LABEL_37;
  v15 = (unsigned __int8)(v14 + 1) % v4;
  if ( v15 > 7 )
    goto LABEL_37;
  v16 = (unsigned __int8)(v15 + 1) % v4;
  if ( v16 > 7
    || (v17 = (unsigned __int8)(v16 + 1) % v4, v17 > 7)
    || (v18 = (unsigned __int8)(v17 + 1) % v4, v18 > 7)
    || (v19 = (unsigned __int8)(v18 + 1) % v4, v19 > 7)
    || (v20 = (unsigned __int8)(v19 + 1) % v4, v20 > 7)
    || (v21 = (unsigned __int8)(v20 + 1) % v4, v21 > 7)
    || (v22 = (unsigned __int8)(v21 + 1) % v4, v22 > 7)
    || (v23 = (unsigned __int8)(v22 + 1) % v4, v23 > 7) )
  {
LABEL_37:
    __break(1u);
  }
  v24 = (16 * (unsigned __int8)*(_DWORD *)((unsigned __int64)v26 | (4 * v12)))
      | LOBYTE(v26[0])
      | ((unsigned __int8)*((_DWORD *)v26 + v9) << 8)
      | ((unsigned __int8)*((_DWORD *)v26 + v10) << 12)
      | ((unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v11) << 16)
      | ((unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v13) << 20);
  v25 = *((_DWORD *)v26 + (unsigned __int8)v23);
  v6 = v24 | (*((_DWORD *)v26 + (unsigned __int8)v14) << 24) | (*((_DWORD *)v26 + (unsigned __int8)v15) << 28);
  v7 = (16 * (unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v17))
     | *((unsigned __int8 *)v26 + 4 * (unsigned __int8)v16)
     | ((unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v18) << 8)
     | ((unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v19) << 12)
     | ((unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v20) << 16)
     | ((unsigned __int8)*((_DWORD *)v26 + (unsigned __int8)v21) << 20)
     | (*((_DWORD *)v26 + (unsigned __int8)v22) << 24)
     | (v25 << 28);
LABEL_36:
  *a3 = v6;
  _ReadStatusReg(SP_EL0);
  *a4 = v7;
}
