__int64 __fastcall qcom_llcc_cfg_program(__int64 *a1)
{
  __int64 v1; // x8
  int v2; // w28
  __int64 v3; // x22
  __int64 *v4; // x19
  int v5; // w9
  __int64 v6; // x12
  __int64 v7; // x11
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x24
  int v11; // w9
  __int64 v12; // x2
  unsigned int v13; // w20
  unsigned int v14; // w21
  __int64 v15; // x8
  unsigned __int64 v16; // x0
  __int64 v17; // x13
  unsigned int v18; // w10
  unsigned int v19; // w8
  _BOOL4 v20; // w11
  __int64 v21; // x13
  unsigned __int64 v22; // x9
  int v23; // w8
  __int64 v24; // x20
  _DWORD *v25; // x10
  int v26; // w12
  int v27; // w23
  unsigned int v28; // w26
  __int64 v29; // x2
  unsigned int v30; // w27
  unsigned int v31; // w24
  int v32; // w2
  int v33; // w21
  __int64 v34; // x10
  unsigned int v35; // w8
  unsigned int v36; // w11
  _BOOL4 v37; // w12
  unsigned int v38; // w19
  int v39; // w26
  int v40; // w24
  unsigned int v41; // w21
  unsigned int v42; // w8
  char v43; // w25
  int v44; // w24
  unsigned int v45; // w23
  unsigned __int64 v46; // x0
  int v48; // [xsp+14h] [xbp-Ch]
  int v49; // [xsp+18h] [xbp-8h]
  int v50; // [xsp+1Ch] [xbp-4h]

  v1 = drv_data;
  v2 = *(_DWORD *)(drv_data + 92);
  if ( !v2 )
    return 0;
  v3 = *(_QWORD *)(drv_data + 24);
  v4 = a1;
  v5 = 0;
  do
  {
    v6 = v3 + 56LL * v5;
    v7 = 3LL * v5++;
    v7 *= 8;
    *(_DWORD *)(*(_QWORD *)(v1 + 128) + v7) = *(_DWORD *)(v6 + 4);
    *(_QWORD *)(*(_QWORD *)(v1 + 128) + v7 + 8) = *(unsigned int *)(v6 + 8);
    *(_DWORD *)(*(_QWORD *)(v1 + 128) + v7 + 16) = 0;
  }
  while ( v2 != v5 );
  if ( *(_DWORD *)(v1 + 116) >> 25 >= 3u )
  {
    v23 = 0;
    do
    {
      v24 = v3 + 56LL * v23;
      v48 = v23;
      v25 = (_DWORD *)v4[1];
      v26 = v25[2];
      v27 = v25[3];
      v28 = *(_DWORD *)(v24 + 4);
      v29 = *(unsigned int *)(v24 + 24);
      v49 = v25[5];
      v50 = v25[4];
      v30 = *(_DWORD *)(v24 + 28)
          | (16 * *(_DWORD *)(v24 + 32))
          | (*(unsigned __int8 *)(v24 + 16) << 8)
          | (*(_DWORD *)(v24 + 12) << 12);
      if ( *(_BYTE *)(v24 + 49) == 1 )
      {
        v31 = *(_DWORD *)(v24 + 24);
        v32 = *(_DWORD *)(v24 + 52);
        v33 = v25[2];
        if ( v32 && *(_BYTE *)(v24 + 16) )
        {
          v34 = *v4;
          v35 = *((_DWORD *)v4 + 6);
          v36 = 0;
          v37 = *v4 != 0;
          if ( *v4 && v35 )
          {
            v36 = 0;
            while ( *(_DWORD *)(v34 + 4) != v32 )
            {
              v34 += 56;
              ++v36;
              v37 = v34 != 0;
              if ( !v34 || v36 >= v35 )
                goto LABEL_69;
            }
            v37 = 1;
          }
LABEL_69:
          if ( !v37 || v36 == v35 )
          {
            v38 = *(_DWORD *)(v24 + 20);
            printk(&unk_7FA7, v28);
          }
          else
          {
            v38 = *(_DWORD *)(v24 + 20);
            if ( *(_DWORD *)(v24 + 8) > *(_DWORD *)(v34 + 8) )
              printk(&unk_7F46, v28);
            else
              v30 |= (v32 << 16) | 0x1000000;
          }
        }
        else
        {
          v38 = *(_DWORD *)(v24 + 20);
          printk(&unk_7EBC, v28);
        }
        v26 = v33;
        v29 = v31;
      }
      else
      {
        v38 = *(_DWORD *)(v24 + 20);
      }
      v39 = v28 << 6;
      v40 = *(_DWORD *)(v24 + 8);
      v41 = *(_DWORD *)(drv_data + 100);
      result = regmap_write(*(_QWORD *)(drv_data + 8), (unsigned int)(v39 + v26), v29);
      if ( (_DWORD)result )
        break;
      result = regmap_write(*(_QWORD *)(drv_data + 8), (unsigned int)(v27 + v39), v38);
      if ( (_DWORD)result )
        break;
      result = regmap_write(*(_QWORD *)(drv_data + 8), (unsigned int)(v50 + v39), v30);
      if ( (_DWORD)result )
        break;
      result = regmap_write(*(_QWORD *)(drv_data + 8), (unsigned int)(v49 + v39), ((v40 << 10) / v41) >> 6);
      if ( (_DWORD)result )
        break;
      v42 = *(_DWORD *)(v24 + 4);
      v4 = a1;
      v43 = v42 & 0x1F;
      v44 = (v42 >> 3) & 0x1FFFFFFC;
      if ( *((_BYTE *)a1 + 28) == 1 )
      {
        result = regmap_write(
                   *(_QWORD *)(drv_data + 8),
                   (unsigned int)(*(_DWORD *)(a1[1] + 24) + v44),
                   *(unsigned __int8 *)(v24 + 36) << v43);
        if ( (_DWORD)result )
          break;
      }
      v45 = 1 << v43;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 60) + v44),
                 (unsigned int)(1 << v43),
                 *(unsigned __int8 *)(v24 + 39) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 64) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 40) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 28) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 41) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 32) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 42) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 36) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 43) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 40) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 44) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 44) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 45) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 48) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 46) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 52) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 47) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      result = regmap_update_bits_base(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(*(_DWORD *)(a1[1] + 56) + v44),
                 v45,
                 *(unsigned __int8 *)(v24 + 48) << v43,
                 0,
                 0,
                 0);
      if ( (_DWORD)result )
        break;
      if ( *(_BYTE *)(v24 + 38) == 1 )
      {
        v46 = llcc_slice_getd(*(_DWORD *)v24);
        if ( v46 >= 0xFFFFFFFFFFFFF001LL )
          return 4294967274LL;
        result = llcc_slice_activate(v46);
        if ( (_DWORD)result )
          return result;
      }
      result = 0;
      v23 = v48 + 1;
    }
    while ( v48 + 1 != v2 );
  }
  else
  {
    v8 = 0;
    while ( 1 )
    {
      v10 = v3 + 56LL * v8;
      result = regmap_write(
                 *(_QWORD *)(drv_data + 8),
                 (unsigned int)(8 * *(_DWORD *)(v10 + 4) + 135172),
                 *(_DWORD *)(v10 + 28)
               | (4 * *(_DWORD *)(v10 + 32))
               | (8 * *(unsigned __int8 *)(v10 + 16))
               | (16 * *(_DWORD *)(v10 + 12))
               | ((unsigned int)((*(_DWORD *)(v10 + 8) << 10) / *(_DWORD *)(drv_data + 100)) >> 6 << 16));
      if ( (_DWORD)result )
        break;
      if ( *(_DWORD *)(drv_data + 116) <= 0x400FFFFu )
      {
        v13 = 0;
        v14 = 0;
        v12 = (unsigned int)*(unsigned __int16 *)(v10 + 24) | (*(_DWORD *)(v10 + 20) << 16);
        v11 = *(_DWORD *)(v10 + 4);
      }
      else
      {
        v11 = *(_DWORD *)(v10 + 4);
        v13 = *(_DWORD *)(v10 + 20);
        v12 = *(unsigned int *)(v10 + 24);
        v14 = 4 * v11 + 135424;
      }
      result = regmap_write(*(_QWORD *)(drv_data + 8), (unsigned int)(8 * v11 + 135168), v12);
      if ( (_DWORD)result )
        break;
      v15 = drv_data;
      if ( *(_DWORD *)(drv_data + 116) > 0x400FFFFu )
      {
        result = regmap_write(*(_QWORD *)(drv_data + 8), v14, v13);
        if ( (_DWORD)result )
          return result;
        v15 = drv_data;
      }
      if ( *((_BYTE *)v4 + 28) == 1 )
      {
        result = regmap_update_bits_base(
                   *(_QWORD *)(v15 + 8),
                   139008,
                   1LL << *(_DWORD *)(v10 + 4),
                   *(unsigned __int8 *)(v10 + 36) << *(_DWORD *)(v10 + 4),
                   0,
                   0,
                   0);
        if ( (_DWORD)result )
          return result;
        v15 = drv_data;
        if ( *(unsigned __int16 *)(drv_data + 118) <= 0x400u )
        {
          result = regmap_update_bits_base(
                     *(_QWORD *)(drv_data + 8),
                     139012,
                     1LL << *(_DWORD *)(v10 + 4),
                     *(unsigned __int8 *)(v10 + 37) << *(_DWORD *)(v10 + 4),
                     0,
                     0,
                     0);
          if ( (_DWORD)result )
            return result;
          v15 = drv_data;
        }
      }
      if ( *(_DWORD *)(v15 + 116) >> 25 )
      {
        result = regmap_update_bits_base(
                   *(_QWORD *)(v15 + 8),
                   139040,
                   1LL << *(_DWORD *)(v10 + 4),
                   *(unsigned __int8 *)(v10 + 39) << *(_DWORD *)(v10 + 4),
                   0,
                   0,
                   0);
        if ( (_DWORD)result )
          break;
        if ( *(unsigned __int16 *)(drv_data + 118) >= 0x201u )
        {
          result = regmap_update_bits_base(
                     *(_QWORD *)(drv_data + 8),
                     139052,
                     1LL << *(_DWORD *)(v10 + 4),
                     *(unsigned __int8 *)(v10 + 40) << *(_DWORD *)(v10 + 4),
                     0,
                     0,
                     0);
          if ( (_DWORD)result )
            break;
          if ( *(_DWORD *)(drv_data + 116) > 0x400FFFFu )
          {
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139020,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 41) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139024,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 42) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139028,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 43) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139032,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 44) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139036,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 45) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139044,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 46) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139048,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 47) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
            result = regmap_update_bits_base(
                       *(_QWORD *)(drv_data + 8),
                       139056,
                       1LL << *(_DWORD *)(v10 + 4),
                       *(unsigned __int8 *)(v10 + 48) << *(_DWORD *)(v10 + 4),
                       0,
                       0,
                       0);
            if ( (_DWORD)result )
              break;
          }
        }
      }
      if ( *(_BYTE *)(v10 + 38) == 1 )
      {
        if ( (unsigned __int64)drv_data <= 0xFFFFFFFFFFFFF000LL )
        {
          v17 = *(_QWORD *)(drv_data + 24);
          v18 = *(_DWORD *)(drv_data + 92);
          v19 = 0;
          v20 = v17 != 0;
          if ( v17 && v18 )
          {
            v19 = 0;
            v21 = v17 + 56;
            while ( *(_DWORD *)(v21 - 56) != *(_DWORD *)v10 )
            {
              ++v19;
              v20 = v21 != 0;
              if ( v21 )
              {
                v21 += 56;
                if ( v19 < v18 )
                  continue;
              }
              goto LABEL_47;
            }
            v20 = 1;
          }
LABEL_47:
          v16 = -19;
          if ( v20 && v19 != v18 )
          {
            v22 = *(_QWORD *)(drv_data + 128);
            if ( v22 )
            {
              if ( v22 <= 0xFFFFFFFFFFFFF000LL )
                v16 = v22 + 24LL * v19;
            }
          }
        }
        else
        {
          v16 = drv_data;
        }
        if ( v16 >= 0xFFFFFFFFFFFFF001LL )
          return 4294967274LL;
        result = llcc_slice_activate(v16);
        if ( (_DWORD)result )
          return result;
      }
      if ( ++v8 == v2 )
        return 0;
    }
  }
  return result;
}
