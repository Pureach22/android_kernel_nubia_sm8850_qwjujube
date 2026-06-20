__int64 __fastcall lpg_apply(__int64 *a1)
{
  int v2; // w8
  __int64 v3; // x20
  int v4; // w9
  unsigned int v5; // w8
  __int64 v6; // x2
  int v7; // w8
  char v8; // w8
  int v9; // w9
  __int64 v10; // x0
  int v11; // w8
  __int64 v12; // x24
  __int64 v13; // x20
  int v14; // w8
  int v15; // w9
  int v16; // w10
  unsigned __int64 v17; // x11
  __int64 v18; // x10
  __int64 v19; // x12
  char v20; // w13
  char v21; // w11
  int v22; // w9
  unsigned __int64 v23; // x8
  unsigned int v24; // w22
  unsigned int v25; // w23
  __int64 v26; // x9
  __int64 v27; // x11
  unsigned __int64 v28; // x21
  unsigned __int64 v29; // x20
  int v30; // w8
  __int64 v31; // x14
  bool v32; // zf
  char v33; // w13
  _QWORD *v34; // x21
  __int64 result; // x0
  int v36; // [xsp+0h] [xbp-20h] BYREF
  int v37; // [xsp+4h] [xbp-1Ch] BYREF
  char v38[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v39[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v40; // [xsp+10h] [xbp-10h] BYREF
  int v41; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  regmap_update_bits_base(*(_QWORD *)(*a1 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 67), 32, 32, 0, 0, 0);
  v2 = *((unsigned __int8 *)a1 + 46);
  v3 = *a1;
  if ( v2 == 1 )
  {
    v4 = *((_DWORD *)a1 + 5);
    v5 = *((_DWORD *)a1 + 14);
    switch ( v4 )
    {
      case 12:
        v6 = (16 * (*((_DWORD *)a1 + 17) & 7)) | v5;
        break;
      case 11:
        v6 = (4 * (*((_DWORD *)a1 + 17) & 1)) | v5;
        break;
      case 2:
        v6 = v5 | 0x30;
        break;
      default:
        v6 = v5 | 0x10;
        break;
    }
    regmap_write(*(_QWORD *)(v3 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 65), v6);
    regmap_write(
      *(_QWORD *)(v3 + 8),
      (unsigned int)(*((_DWORD *)a1 + 2) + 66),
      a1[8] & 7 | (32 * (*((_DWORD *)a1 + 15) & 3u)));
    v8 = *((_BYTE *)a1 + 46);
    v3 = *a1;
    LOWORD(v41) = *((_WORD *)a1 + 22);
    if ( (v8 & 1) != 0 )
      goto LABEL_12;
  }
  else
  {
    LOWORD(v41) = *((_WORD *)a1 + 22);
    if ( v2 )
    {
LABEL_12:
      regmap_bulk_write(*(_QWORD *)(v3 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 68), &v41, 2);
      v3 = *a1;
      if ( (*((_BYTE *)a1 + 46) & 1) != 0 )
        v7 = 160;
      else
        v7 = 32;
      goto LABEL_15;
    }
  }
  v7 = 32;
LABEL_15:
  if ( *((_DWORD *)a1 + 24) == *((_DWORD *)a1 + 25) )
    v9 = 4;
  else
    v9 = 2;
  regmap_write(*(_QWORD *)(v3 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 70), v9 | (unsigned int)v7);
  if ( *((_BYTE *)a1 + 46) == 1 )
  {
    v10 = *(_QWORD *)(*a1 + 8);
    v11 = *((_DWORD *)a1 + 2);
    LOWORD(v41) = *((_WORD *)a1 + 22);
    regmap_bulk_write(v10, (unsigned int)(v11 + 68), &v41, 2);
  }
  regmap_write(*(_QWORD *)(*a1 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 71), 1);
  v12 = *a1;
  v13 = *(_QWORD *)(*a1 + 104);
  if ( v13 )
  {
    v14 = *((_DWORD *)a1 + 24);
    v15 = *((_DWORD *)a1 + 25);
    v16 = *((unsigned __int8 *)a1 + 72);
    v39[0] = 0;
    v38[0] = 0;
    v41 = v14;
    v40 = v15;
    if ( v16 != 1 || v14 == v15 )
      goto LABEL_54;
    v17 = *((unsigned __int16 *)a1 + 38);
    v18 = a1[10];
    v19 = a1[11];
    v20 = *((_BYTE *)a1 + 74);
    v36 = (v18 + v17 - 1) / v17;
    v37 = (v17 - 1 + v19) / v17;
    if ( (v20 & 1) != 0 )
    {
      v21 = 0;
    }
    else
    {
      v21 = 8;
      v38[0] = 8;
    }
    v31 = *(_QWORD *)(v12 + 112);
    if ( v19 )
      v32 = 1;
    else
      v32 = v31 == 0;
    v33 = v32;
    if ( v19 && v31 )
    {
      v21 |= 2u;
      v34 = (_QWORD *)(v12 + 112);
      v38[0] = v21;
      if ( !v18 )
        goto LABEL_51;
    }
    else
    {
      v34 = (_QWORD *)(v12 + 112);
      if ( !v18 )
      {
        if ( (v33 & 1) != 0 )
        {
LABEL_52:
          nvmem_device_write(v13, (unsigned int)(*((_DWORD *)a1 + 6) + 6), 1, v39);
          nvmem_device_write(v13, (unsigned int)(*((_DWORD *)a1 + 6) + 1), 1, v38);
          nvmem_device_write(v13, (unsigned int)(*((_DWORD *)a1 + 6) + 3), 1, &v40);
          nvmem_device_write(v13, (unsigned int)(*((_DWORD *)a1 + 6) + 4), 1, &v41);
          v39[0] = (70481515 * (unsigned __int64)(1000 * (unsigned int)*((unsigned __int16 *)a1 + 38))) >> 39;
          nvmem_device_write(v13, 71, 1, v39);
          if ( *v34 )
          {
            nvmem_device_write(v13, (unsigned int)(*((_DWORD *)a1 + 6) + 8), 1, &v37);
            nvmem_device_write(v13, (unsigned int)(*((_DWORD *)a1 + 6) + 9), 1, &v36);
          }
          goto LABEL_54;
        }
LABEL_51:
        v40 = v15 + 5;
        v41 = v14 + 5;
        goto LABEL_52;
      }
      if ( (v33 & 1) != 0 )
        goto LABEL_52;
    }
    v38[0] = v21 | 1;
    goto LABEL_51;
  }
  v22 = *((unsigned __int8 *)a1 + 72);
  v23 = *((unsigned __int16 *)a1 + 38);
  v24 = *((_DWORD *)a1 + 24);
  v25 = *((_DWORD *)a1 + 25);
  LOWORD(v41) = *((_WORD *)a1 + 38);
  if ( v22 == 1 && v24 != v25 )
  {
    v27 = a1[10];
    v26 = a1[11];
    v28 = (v26 + v23 - 1) / v23;
    v29 = (v27 + v23 - 1) / v23;
    if ( *((_BYTE *)a1 + 75) )
      v30 = 0;
    else
      v30 = 16;
    if ( !*((_BYTE *)a1 + 74) )
      v30 |= 8u;
    if ( *((_BYTE *)a1 + 73) )
      v30 |= 4u;
    if ( v26 )
      v30 |= 2u;
    regmap_write(*(_QWORD *)(v12 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 64), v30 | (unsigned int)(v27 != 0));
    regmap_write(*(_QWORD *)(v12 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 86), v25);
    regmap_write(*(_QWORD *)(v12 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 87), v24);
    regmap_bulk_write(*(_QWORD *)(v12 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 80), &v41, 2);
    regmap_write(*(_QWORD *)(v12 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 82), (unsigned int)v28);
    regmap_write(*(_QWORD *)(v12 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 84), (unsigned int)v29);
  }
LABEL_54:
  result = regmap_update_bits_base(*(_QWORD *)(*a1 + 8), (unsigned int)(*((_DWORD *)a1 + 2) + 67), 32, 0, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
