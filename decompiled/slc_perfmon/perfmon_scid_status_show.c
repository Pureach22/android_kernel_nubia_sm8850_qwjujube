__int64 __fastcall perfmon_scid_status_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x26
  __int16 v5; // w20
  int v6; // w27
  unsigned int v7; // w21
  __int64 v8; // x20
  __int64 v9; // x24
  const char *v10; // x4
  __int64 v11; // x20
  unsigned int v12; // w25
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x8
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v16[0] = 0;
  v5 = **(_WORD **)(v4 + 120);
  if ( *(_BYTE *)(v4 + 216) == 1 )
  {
    regmap_read(*(_QWORD *)(v4 + 208), 295168, v16);
    regmap_write(*(_QWORD *)(v4 + 208), 295168, 0);
    regmap_write(*(_QWORD *)(v4 + 208), 295168, 1);
    regmap_write(*(_QWORD *)(v4 + 208), 295168, 0);
  }
  v6 = (unsigned __int8)v5;
  if ( (_BYTE)v5 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      v12 = (v7 << 12) | 4;
      if ( (*(_BYTE *)(*(_QWORD *)(v4 + 112) + 6LL) & 0x3F) != 0 )
      {
        v13 = 0;
        v9 = 0;
        do
        {
          regmap_read(*(_QWORD *)(*(_QWORD *)(v4 + 200) + 8 * v13++), v12, (char *)v16 + 4);
          v14 = *(_BYTE *)(*(_QWORD *)(v4 + 112) + 6LL) & 0x3F;
          v9 += (unsigned __int64)HIDWORD(v16[0]) >> 16;
          HIDWORD(v16[0]) >>= 16;
        }
        while ( v13 < v14 );
      }
      else
      {
        v9 = 0;
      }
      regmap_read(*(_QWORD *)(v4 + 208), v12, (char *)v16 + 4);
      if ( (v16[0] & 0x100000000LL) != 0 )
        v10 = "ACTIVE";
      else
        v10 = "DE-ACTIVE";
      v11 = v8 + (int)scnprintf(a3 + v8, 4096 - v8, "SCID %02d %10s", v7++, v10);
      v8 = v11 + (int)scnprintf(a3 + v11, 4096 - v11, ",0x%08lx\n", v9);
    }
    while ( v7 != v6 );
  }
  else
  {
    v8 = 0;
  }
  if ( *(_BYTE *)(v4 + 216) == 1 )
    regmap_write(*(_QWORD *)(v4 + 208), 295168, LODWORD(v16[0]));
  _ReadStatusReg(SP_EL0);
  return v8;
}
