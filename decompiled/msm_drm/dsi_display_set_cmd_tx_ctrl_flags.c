__int64 __fastcall dsi_display_set_cmd_tx_ctrl_flags(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x8
  unsigned int v4; // w9
  int v5; // w8
  bool v6; // cc
  unsigned __int64 v7; // x9
  __int64 v8; // x10
  int v9; // w11
  bool v10; // w12
  unsigned __int64 v11; // x10
  unsigned int v12; // w10
  int v14; // w12
  __int64 v15; // x11
  int v16; // w10
  bool v17; // w11
  unsigned __int64 v18; // x10
  unsigned int v19; // w9
  bool v20; // zf
  int v21; // w8
  int v22; // w10

  v2 = *(_DWORD *)(result + 836);
  if ( v2 >= 3 )
  {
    __break(0x5512u);
    JUMPOUT(0x1DD86C);
  }
  v3 = *(_QWORD *)(result + 168 + 48LL * v2);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 88);
    v5 = *(_DWORD *)(result + 160);
    v6 = v4 > 8;
    v7 = 256;
    if ( v6 )
      v7 = 1024;
    if ( v5 )
    {
      v8 = *(_QWORD *)(result + 168);
      if ( v8 )
      {
        if ( (*(_BYTE *)(v8 + 2800) & 1) != 0 )
        {
          v9 = 16;
          v10 = 1;
        }
        else
        {
          v11 = *(_QWORD *)(a2 + 8) + 4LL;
          v10 = v11 <= v7;
          if ( v11 > v7 )
            v9 = 160;
          else
            v9 = 32;
        }
        v12 = *(unsigned __int16 *)(a2 + 2);
        if ( (v10 & *(_BYTE *)(result + 1032)) != 0 )
          v9 |= 0x1000u;
        if ( (v12 & 0x80) == 0 && v5 != 1 )
          v9 |= 0xAu;
        if ( *(_DWORD *)(*(_QWORD *)(result + 264) + 1352LL) == 1 )
        {
          v9 |= 0x100u;
        }
        else
        {
          v14 = v9 | 0x100;
          if ( (v12 & 0x20) != 0 )
            v9 |= 0x100u;
          if ( (v9 & 2) != 0 )
            v9 = v14;
          if ( !*(_BYTE *)(result + 1920) )
            v9 &= ~0x100u;
        }
        if ( (((v9 & 0x90) == 0) & (v12 >> 6)) == 0 )
          v9 |= 0x40u;
        if ( *(_BYTE *)(result + 1616) == 1 && (v9 & 0x90) == 0 && !*(_DWORD *)(a2 + 44) )
          v9 |= ~(*(_DWORD *)(a2 + 52) << 9) & 0x200;
        LODWORD(v8) = v9 | (32 * v12) & 0x200;
      }
      if ( v5 != 1 )
      {
        v15 = *(_QWORD *)(result + 216);
        if ( v15 )
        {
          if ( (*(_BYTE *)(v15 + 2800) & 1) != 0 )
          {
            v16 = 16;
            v17 = 1;
          }
          else
          {
            v18 = *(_QWORD *)(a2 + 8) + 4LL;
            v17 = v18 <= v7;
            if ( v18 > v7 )
              v16 = 160;
            else
              v16 = 32;
          }
          v19 = *(unsigned __int16 *)(a2 + 2);
          if ( (v17 & *(_BYTE *)(result + 1032)) != 0 )
            v16 |= 0x1000u;
          v20 = (v19 & 0x80) != 0 || v5 == 1;
          v21 = v16 | 0xA;
          if ( v20 )
            v21 = v16;
          if ( *(_DWORD *)(*(_QWORD *)(result + 264) + 1352LL) == 1 )
          {
            v21 |= 0x100u;
          }
          else
          {
            v22 = v21 | 0x100;
            if ( (v19 & 0x20) != 0 )
              v21 |= 0x100u;
            if ( (v21 & 2) != 0 )
              v21 = v22;
            if ( !*(_BYTE *)(result + 1920) )
              v21 &= ~0x100u;
          }
          if ( (((v21 & 0x90) == 0) & (v19 >> 6)) == 0 )
            v21 |= 0x40u;
          if ( *(_BYTE *)(result + 1616) == 1 && (v21 & 0x90) == 0 && !*(_DWORD *)(a2 + 44) )
            v21 |= ~(*(_DWORD *)(a2 + 52) << 9) & 0x200;
          LODWORD(v8) = v21 | (32 * v19) & 0x200;
        }
      }
    }
    else
    {
      LODWORD(v8) = 0;
    }
    *(_DWORD *)(a2 + 52) |= v8;
  }
  return result;
}
