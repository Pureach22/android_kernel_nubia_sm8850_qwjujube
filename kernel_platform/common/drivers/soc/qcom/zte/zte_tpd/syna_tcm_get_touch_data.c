__int64 __fastcall syna_tcm_get_touch_data(__int64 a1, int a2, __int64 a3, unsigned int a4, unsigned int *a5)
{
  unsigned __int64 v6; // x12
  unsigned int v7; // w9
  bool v8; // zf
  unsigned int v9; // w11
  unsigned int v10; // w9
  unsigned int v11; // w12
  int v12; // w15
  int v13; // w13
  unsigned int v14; // w14
  char v15; // w15

  if ( a4 - 33 <= 0xFFFFFFDF )
  {
    printk(unk_3399D, "syna_tcm_get_touch_data", a4);
    return 4294967055LL;
  }
  else if ( a1 )
  {
    if ( a4 + (unsigned int)a3 <= 8 * a2 )
    {
      v6 = (unsigned __int64)(unsigned int)a3 >> 3;
      v7 = 8 - (a3 & 7);
      if ( v7 >= a4 )
        v7 = a4;
      v9 = a4 - v7;
      v8 = a4 == v7;
      v10 = (*(unsigned __int8 *)(a1 + v6) >> (a3 & 7)) & (0xFFu >> (8 - v7));
      if ( !v8 )
      {
        v11 = v6 + 1;
        do
        {
          v12 = *(unsigned __int8 *)(a1 + v11++);
          if ( v9 >= 8 )
            v13 = 8;
          else
            v13 = v9;
          v14 = (0xFFu >> (8 - v13)) & v12;
          v15 = a4 - v9;
          v9 -= v13;
          v10 |= v14 << v15;
        }
        while ( v9 );
      }
      *a5 = v10;
      return 0;
    }
    else
    {
      *a5 = 0;
      return 0;
    }
  }
  else
  {
    printk(unk_37361, "syna_tcm_get_touch_data", a3);
    return 4294967055LL;
  }
}
