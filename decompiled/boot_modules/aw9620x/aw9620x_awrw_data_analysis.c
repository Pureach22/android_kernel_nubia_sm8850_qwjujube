__int64 __fastcall aw9620x_awrw_data_analysis(__int64 a1, char *s, unsigned __int8 a3)
{
  unsigned int v4; // w25
  int v7; // w23
  unsigned int v8; // w27
  unsigned __int8 v9; // w26
  __int64 result; // x0
  int v11; // [xsp+0h] [xbp-10h] BYREF
  char sa[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v4 = 5 * a3;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v7 = strlen(s);
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_awrw_data_analysis", 2793);
  if ( v4 + 20 == v7 )
  {
    if ( a3 )
    {
      v8 = 0;
      v9 = 0;
      do
      {
        *(_WORD *)sa = *(_WORD *)&s[v8 + 22];
        if ( sscanf(sa, "%02x", &v11) == 1 )
        {
          *(_BYTE *)(*(_QWORD *)(a1 + 632) + v9) = v11;
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(a1 + 48),
            "[%s:%d] tranfar_data = 0x%2x\n",
            "aw9620x_awrw_data_analysis",
            2811,
            *(unsigned __int8 *)(*(_QWORD *)(a1 + 632) + v9));
        }
        ++v9;
        v8 = (unsigned __int8)(v8 + 5);
      }
      while ( v8 < v4 );
    }
    result = 0;
  }
  else
  {
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] error theory_len = %d actual_len = %d\n",
      "aw9620x_awrw_data_analysis",
      2798,
      v4 + 20,
      v7);
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
