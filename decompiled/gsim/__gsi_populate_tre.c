__int64 __fastcall _gsi_populate_tre(__int64 a1, __int64 *a2)
{
  unsigned int v2; // w5
  unsigned __int64 v3; // x13
  unsigned __int64 v4; // x14
  __int64 v5; // x10
  __int16 v6; // w11
  __int16 v7; // w12
  unsigned int v8; // w8
  unsigned int v9; // w13
  unsigned __int64 v10; // x14
  __int64 v11; // x10

  v2 = *((_DWORD *)a2 + 3);
  if ( v2 >= 3 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d chan_hdl=%u bad RE type=%u\n",
      "__gsi_populate_tre",
      4282,
      *(unsigned __int8 *)(a1 + 8),
      v2);
    return (unsigned int)-22;
  }
  else if ( *(_DWORD *)(a1 + 120) )
  {
    v3 = *(_QWORD *)(a1 + 168);
    v4 = *(_QWORD *)(a1 + 144);
    v5 = *a2;
    v6 = *((_WORD *)a2 + 4);
    v7 = *((_WORD *)a2 + 5) & 0x701;
    if ( v4 > v3 || *(_QWORD *)(a1 + 192) <= v3 )
    {
      __break(0x800u);
      v4 = *(_QWORD *)(a1 + 144);
    }
    v8 = 0;
    v9 = (unsigned __int16)(((int)v3 - (int)v4) / (unsigned int)*(unsigned __int8 *)(a1 + 188));
    v10 = *(_QWORD *)(a1 + 136) + *(unsigned __int8 *)(a1 + 188) * (unsigned __int64)v9;
    *(_QWORD *)v10 = v5;
    v11 = 16LL * v9;
    *(_WORD *)(v10 + 8) = v6;
    *(_WORD *)(v10 + 10) = 0;
    *(_WORD *)(v10 + 12) = v7;
    *(_BYTE *)(v10 + 14) = v2 + 2;
    *(_BYTE *)(v10 + 15) = 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 200) + v11) = 1;
    *(_QWORD *)(*(_QWORD *)(a1 + 200) + v11 + 8) = a2[2];
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad state %d\n", "__gsi_populate_tre", 4292, 0);
    return (unsigned int)-7;
  }
  return v8;
}
