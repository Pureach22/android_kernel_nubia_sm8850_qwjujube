__int64 __fastcall pm8xxx_rtc_set_time(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w0
  unsigned int *v4; // x20
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 result; // x0
  __int64 v9; // x21
  int v10; // w20
  __int64 v11; // x0
  int v12; // w20
  __int64 v13; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  v3 = rtc_tm_to_time64(a2);
  if ( *(_BYTE *)(v2 + 16) == 1 )
  {
    v4 = *(unsigned int **)(v2 + 24);
    v5 = *(_QWORD *)(v2 + 8);
    HIDWORD(v14[0]) = v3;
    v6 = v4[3];
    v7 = v4[6];
    LOBYTE(v14[0]) = 0;
    result = regmap_update_bits_base(v5, v6, v7, 0, v14, 0, 0);
    if ( !(_DWORD)result )
    {
      result = regmap_update_bits_base(*(_QWORD *)(v2 + 8), *v4, 128, 0, 0, 0, 0);
      if ( !(_DWORD)result )
      {
        result = regmap_write(*(_QWORD *)(v2 + 8), v4[1], 0);
        if ( !(_DWORD)result )
        {
          result = regmap_bulk_write(*(_QWORD *)(v2 + 8), v4[1] + 1, (char *)v14 + 5, 3);
          if ( !(_DWORD)result )
          {
            result = regmap_write(*(_QWORD *)(v2 + 8), v4[1], BYTE4(v14[0]));
            if ( !(_DWORD)result )
            {
              result = regmap_update_bits_base(*(_QWORD *)(v2 + 8), *v4, 128, 128, 0, 0, 0);
              if ( !(_DWORD)result )
              {
                if ( LOBYTE(v14[0]) != 1 )
                  goto LABEL_17;
                result = regmap_update_bits_base(*(_QWORD *)(v2 + 8), v4[3], v4[6], v4[6], 0, 0, 0);
                if ( !(_DWORD)result )
                  goto LABEL_17;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    if ( !*(_QWORD *)(v2 + 40) )
    {
      result = 4294967277LL;
      goto LABEL_19;
    }
    v9 = *(_QWORD *)(v2 + 24);
    v10 = v3;
    v11 = *(_QWORD *)(v2 + 8);
    v14[0] = 0;
    result = regmap_bulk_read(v11, *(unsigned int *)(v9 + 8), (char *)v14 + 4, 4);
    if ( !(_DWORD)result )
    {
      result = regmap_read(*(_QWORD *)(v2 + 8), *(unsigned int *)(v9 + 8), v14);
      if ( (result & 0x80000000) == 0 )
      {
        if ( LODWORD(v14[0]) >= BYTE4(v14[0])
          || (result = regmap_bulk_read(*(_QWORD *)(v2 + 8), *(unsigned int *)(v9 + 8), (char *)v14 + 4, 4),
              !(_DWORD)result) )
        {
          v12 = v10 - HIDWORD(v14[0]);
          if ( v12 == *(_DWORD *)(v2 + 48) )
          {
LABEL_17:
            result = 0;
            goto LABEL_19;
          }
          v13 = *(_QWORD *)(v2 + 40);
          HIDWORD(v14[0]) = v12;
          result = nvmem_cell_write(v13, (char *)v14 + 4, 4);
          if ( (result & 0x80000000) == 0 )
          {
            result = 0;
            *(_DWORD *)(v2 + 48) = v12;
          }
        }
      }
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
