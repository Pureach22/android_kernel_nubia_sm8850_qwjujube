__int64 __fastcall update_allowed_flash_current(_DWORD *a1, unsigned int *a2, char a3)
{
  __int64 v6; // x22
  unsigned int v7; // w8
  unsigned int v8; // w9
  bool v9; // cf
  unsigned int v10; // w8
  __int64 v11; // x23
  unsigned int updated; // w0
  int v13; // w8
  unsigned int v14; // w21
  bool v15; // zf
  unsigned int v16; // w8
  unsigned int v17; // w9
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w19
  int v22; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v24; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)a1;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  raw_spin_lock(v6 + 128);
  v7 = a1[139];
  if ( (a3 & 1) == 0 || v7 )
  {
    v8 = *(_DWORD *)(v6 + 136);
    v9 = v8 >= v7;
    v10 = v8 - v7;
    if ( !v9 )
      v10 = 0;
    *(_DWORD *)(v6 + 136) = v10;
    if ( v10 <= 0x3E7 )
    {
      v11 = *(_QWORD *)a1;
      if ( (*(_BYTE *)(*(_QWORD *)a1 + 146LL) & 1) == 0 )
      {
        if ( *(_BYTE *)(v11 + 145) )
        {
          updated = regmap_field_update_bits_base(*(_QWORD *)(v11 + 88), 0xFFFFFFFFLL, 0, 0, 0, 0);
          if ( (updated & 0x80000000) != 0 )
            goto LABEL_49;
          *(_BYTE *)(v11 + 145) = 0;
        }
      }
    }
    updated = 0;
    a1[139] = 0;
    if ( (a3 & 1) == 0 )
      goto LABEL_49;
  }
  updated = regmap_field_read(*(_QWORD *)(v6 + 96), &v23);
  if ( (updated & 0x80000000) == 0 )
  {
    updated = regmap_field_read(*(_QWORD *)(v6 + 104), (char *)&v23 + 4);
    if ( (updated & 0x80000000) == 0 )
    {
      v13 = *(_DWORD *)(v6 + 132);
      if ( !v13 )
      {
        updated = regmap_field_read(*(_QWORD *)(v6 + 112), &v24);
        if ( (updated & 0x80000000) != 0 )
          goto LABEL_49;
        v13 = *(_DWORD *)(v6 + 132);
      }
      v14 = 3;
      if ( v13 == 1 )
      {
        if ( *(_BYTE *)(v6 + 143) == 1 )
          v14 = 3;
        else
          v14 = 0;
      }
      updated = regmap_field_update_bits_base(*(_QWORD *)(v6 + 96), 0xFFFFFFFFLL, v14, 0, 0, 0);
      if ( (updated & 0x80000000) == 0 )
      {
        if ( *(_DWORD *)(v6 + 132) == 1 )
          v14 = 0;
        if ( (regmap_field_update_bits_base(*(_QWORD *)(v6 + 104), 0xFFFFFFFFLL, v14, 0, 0, 0) & 0x80000000) != 0
          || !*(_DWORD *)(v6 + 132)
          && (regmap_field_update_bits_base(*(_QWORD *)(v6 + 112), 0xFFFFFFFFLL, v14, 0, 0, 0) & 0x80000000) != 0
          || (unsigned int)regmap_field_read(*(_QWORD *)(v6 + 16), &v22) )
        {
LABEL_45:
          updated = regmap_field_update_bits_base(*(_QWORD *)(v6 + 96), 0xFFFFFFFFLL, (unsigned int)v23, 0, 0, 0);
          if ( (updated & 0x80000000) == 0 )
          {
            updated = regmap_field_update_bits_base(*(_QWORD *)(v6 + 104), 0xFFFFFFFFLL, HIDWORD(v23), 0, 0, 0);
            if ( (updated & 0x80000000) == 0 && !*(_DWORD *)(v6 + 132) )
              updated = regmap_field_update_bits_base(*(_QWORD *)(v6 + 112), 0xFFFFFFFFLL, v24, 0, 0, 0);
          }
          goto LABEL_49;
        }
        if ( *(_DWORD *)(v6 + 132) )
        {
          if ( (v22 & 0x10) == 0 )
          {
            v15 = (v22 & 0x20) == 0;
            goto LABEL_33;
          }
        }
        else
        {
          if ( (v22 & 4) != 0 )
          {
            v16 = 200;
            goto LABEL_38;
          }
          if ( (v22 & 2) == 0 )
          {
            v15 = (v22 & 1) == 0;
LABEL_33:
            if ( v15 )
              v16 = 2000;
            else
              v16 = 1000;
LABEL_38:
            v17 = *(_DWORD *)(v6 + 136);
            v9 = v16 >= v17;
            v18 = v16 - v17;
            if ( !v9 )
              v18 = 0;
            if ( *a2 < v18 )
              v18 = *a2;
            *a2 = v18;
            a1[139] = v18;
            v19 = *(_DWORD *)(v6 + 136) + v18;
            *(_DWORD *)(v6 + 136) = v19;
            if ( v19 >= 0x3E8 )
            {
              updated = set_lmh_mitigation(a1, 1);
              if ( (updated & 0x80000000) != 0 )
                goto LABEL_49;
              _const_udelay(2147500);
            }
            goto LABEL_45;
          }
        }
        v16 = 500;
        goto LABEL_38;
      }
    }
  }
LABEL_49:
  v20 = updated;
  raw_spin_unlock(v6 + 128);
  _ReadStatusReg(SP_EL0);
  return v20;
}
