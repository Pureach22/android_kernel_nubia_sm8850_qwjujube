__int64 __fastcall ddr_stats_show(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned __int64 v4; // x25
  unsigned __int64 v5; // x6
  int v6; // w21
  unsigned __int64 v7; // x24
  __int64 v8; // x28
  unsigned int v9; // w8
  unsigned int v11; // [xsp+Ch] [xbp-294h] BYREF
  _QWORD s[82]; // [xsp+10h] [xbp-290h] BYREF

  s[80] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x280u);
  v2 = *(_QWORD *)(a1 + 128);
  v11 = 0;
  v3 = qcom_stats_fill_ddr_stats(v2, (__int64)s, &v11);
  v4 = s[15] + s[11] + s[7] + s[3];
  if ( v4 )
    v5 = 100LL * s[3] / v4;
  else
    LODWORD(v5) = 0;
  if ( BYTE1(s[0]) == 1 )
  {
    if ( LODWORD(s[0]) >= 0x10000 && HIDWORD(s[0]) )
      seq_printf(
        a1,
        "Freq %uMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%llu (~%u%%)\n",
        HIWORD(LODWORD(s[0])),
        s[0] & 0x1F,
        HIDWORD(s[0]),
        s[3],
        v5);
  }
  else if ( !BYTE1(s[0]) )
  {
    v6 = 1;
    seq_printf(
      a1,
      "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%llu (~%u%%)\n",
      1,
      LOBYTE(s[0]),
      HIDWORD(s[0]),
      s[3],
      v5);
    goto LABEL_11;
  }
  v6 = 0;
LABEL_11:
  if ( BYTE1(s[4]) )
  {
    if ( BYTE1(s[4]) == 1 && LODWORD(s[4]) >= 0x10000 && HIDWORD(s[4]) )
      seq_printf(
        a1,
        "Freq %uMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%llu (~%u%%)\n",
        HIWORD(LODWORD(s[4])),
        s[4] & 0x1F);
  }
  else
  {
    seq_printf(a1, "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%llu (~%u%%)\n", (unsigned int)++v6, LOBYTE(s[4]));
  }
  if ( BYTE1(s[8]) )
  {
    if ( BYTE1(s[8]) == 1 && LODWORD(s[8]) >= 0x10000 && HIDWORD(s[8]) )
      seq_printf(
        a1,
        "Freq %uMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%llu (~%u%%)\n",
        HIWORD(LODWORD(s[8])),
        s[8] & 0x1F);
  }
  else
  {
    seq_printf(a1, "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%llu (~%u%%)\n", (unsigned int)++v6, LOBYTE(s[8]));
  }
  if ( BYTE1(s[12]) )
  {
    if ( BYTE1(s[12]) == 1 && LODWORD(s[12]) >= 0x10000 && HIDWORD(s[12]) )
      seq_printf(
        a1,
        "Freq %uMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%llu (~%u%%)\n",
        HIWORD(LODWORD(s[12])),
        s[12] & 0x1F);
  }
  else
  {
    seq_printf(a1, "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%llu (~%u%%)\n", (unsigned int)++v6, LOBYTE(s[12]));
  }
  if ( !v3 )
  {
LABEL_48:
    seq_write(a1, "ddr_stats: Freq update failed.\n", 31);
    goto LABEL_49;
  }
  if ( v11 >= 5 )
  {
    v7 = 0;
    v8 = 32LL * v11 - 128;
    while ( 1 )
    {
      if ( v7 == 544 )
        __break(0x5512u);
      if ( v3 != v4 && v7 + 152 > 0x280 || v7 + 128 > 0x27F )
        break;
      v9 = s[v7 / 8 + 16];
      if ( BYTE1(v9) == 1 )
      {
        if ( v9 >= 0x10000 )
        {
          if ( v7 + 132 > 0x280 )
            break;
          if ( HIDWORD(s[v7 / 8 + 16]) )
          {
            if ( v7 + 152 > 0x280 )
              break;
            seq_printf(a1, "Freq %uMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%llu (~%u%%)\n", HIWORD(v9), v9 & 0x1F);
          }
        }
      }
      else if ( !BYTE1(v9) )
      {
        if ( v7 + 132 > 0x280 || v7 + 152 > 0x280 )
          break;
        seq_printf(
          a1,
          "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%llu (~%u%%)\n",
          (unsigned int)++v6,
          (unsigned __int8)LODWORD(s[v7 / 8 + 16]));
      }
      v7 += 32LL;
      if ( v8 == v7 )
        goto LABEL_49;
    }
    __break(1u);
    goto LABEL_48;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return 0;
}
