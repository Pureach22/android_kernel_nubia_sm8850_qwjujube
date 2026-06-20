__int64 __fastcall set_flash_module_en(__int64 *a1, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x21
  __int64 v6; // x9
  __int64 v7; // x10
  int v8; // w22
  int v9; // w11
  int v10; // w12
  char *v11; // x13
  __int64 v12; // x15
  char v13; // w16
  char v14; // t1
  char *v15; // x9
  __int64 v16; // x8
  char v17; // t1
  int v18; // w8
  __int64 v19; // x0
  unsigned int updated; // w20

  v2 = *((unsigned __int8 *)a1 + 568);
  v3 = *a1;
  if ( *((_BYTE *)a1 + 568) )
  {
    v6 = a1[70];
    if ( (_DWORD)v2 == 1 )
    {
      v7 = 0;
      v8 = 0;
    }
    else
    {
      v7 = (unsigned __int8)v2 & 0xFE;
      v9 = 0;
      v10 = 0;
      v11 = (char *)(v6 + 1);
      v12 = v7;
      do
      {
        v13 = *(v11 - 1);
        v14 = *v11;
        v11 += 2;
        v12 -= 2;
        v9 |= (unsigned __int8)(1LL << v13);
        v10 |= (unsigned __int8)(1LL << v14);
      }
      while ( v12 );
      v8 = v10 | v9;
      if ( v7 == v2 )
        goto LABEL_10;
    }
    v15 = (char *)(v6 + v7);
    v16 = v2 - v7;
    do
    {
      v17 = *v15++;
      --v16;
      v8 |= (unsigned __int8)(1LL << v17);
    }
    while ( v16 );
  }
  else
  {
    v8 = 0;
  }
LABEL_10:
  raw_spin_lock(v3 + 128);
  if ( (a2 & 1) != 0 )
    v18 = *(unsigned __int8 *)(v3 + 142) | v8;
  else
    v18 = *(unsigned __int8 *)(v3 + 142) & (v8 ^ 0xFF);
  v19 = *(_QWORD *)(v3 + 48);
  *(_BYTE *)(v3 + 142) = v18;
  updated = regmap_field_update_bits_base(v19, 0xFFFFFFFFLL, v18 != 0, 0, 0, 0);
  if ( updated )
    dev_err(a1[11], "write module_en failed, rc=%d\n", updated);
  raw_spin_unlock(v3 + 128);
  return updated;
}
