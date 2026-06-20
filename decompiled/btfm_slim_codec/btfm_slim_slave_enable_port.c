__int64 __fastcall btfm_slim_slave_enable_port(__int64 a1, unsigned __int8 a2, char a3, char a4)
{
  int v6; // w8
  unsigned __int8 v7; // w9
  __int16 v8; // w8
  __int64 v9; // x22
  unsigned int v10; // w8
  unsigned __int16 v11; // w21
  __int16 v12; // w23
  __int64 v13; // x21
  unsigned int v14; // w8
  unsigned int v15; // w19
  __int64 v16; // x2
  __int16 v17; // w24
  int v18; // w9
  unsigned int v19; // w22
  __int64 v20; // x21
  unsigned int v21; // w8
  __int64 v22; // x21
  unsigned int v23; // w8
  __int64 v24; // x2
  __int64 result; // x0
  unsigned int v26; // w8
  __int64 v27; // x20
  int v28; // w19
  unsigned int v29; // w9

  if ( !a3 )
  {
    v12 = a2;
    if ( !a4 )
      goto LABEL_24;
    if ( a2 <= 5u )
    {
      if ( a2 )
      {
        if ( ((1 << a2) & 0x36) != 0 )
        {
          v17 = 4 * a2;
          v18 = a2 == 4 ? 16 : 6;
          v19 = a2 == 5 ? 32 : v18;
          v20 = a1;
          printk(&unk_8D6A, "btfm_slim_slave_enable_port", v19);
          v21 = btfm_slim_write(v20, v17 + 256, v19, 0);
          a1 = v20;
          if ( (v21 & 0x80000000) != 0 )
          {
            v29 = v21;
            goto LABEL_44;
          }
        }
      }
      else
      {
        v13 = a1;
        v14 = btfm_slim_write(a1, 0x100u, 1u, 0);
        a1 = v13;
        if ( (v14 & 0x80000000) != 0 )
        {
          v15 = v14;
          v16 = v14;
LABEL_45:
          printk(&unk_87C7, "btfm_slim_slave_enable_port", v16);
          return v15;
        }
      }
    }
    v22 = a1;
    v23 = btfm_slim_write(a1, v12 + 496, 3u, 0);
    a1 = v22;
    if ( (v23 & 0x80000000) == 0 )
    {
LABEL_24:
      v11 = v12 + 80;
      goto LABEL_25;
    }
    v29 = v23;
LABEL_44:
    v15 = v29;
    v16 = v29;
    goto LABEL_45;
  }
  if ( a4 )
  {
    v6 = *(_DWORD *)(a1 + 1084);
    if ( v6 != 44100 && v6 != 88200 )
    {
      v7 = a2 - 24;
      if ( a2 >= 0x18u )
      {
        v8 = 385;
      }
      else
      {
        v7 = a2 - 16;
        v8 = 384;
      }
      v9 = a1;
      v10 = btfm_slim_write(a1, v8 + 4 * v7, 1 << v7, 0);
      a1 = v9;
      if ( (v10 & 0x80000000) != 0 )
      {
        v29 = v10;
        goto LABEL_44;
      }
    }
  }
  v11 = a2 + 48;
LABEL_25:
  if ( a2 > 5u )
    goto LABEL_34;
  if ( ((1 << a2) & 0x36) != 0 )
  {
    if ( a4 )
      LODWORD(v24) = 17;
    else
      LODWORD(v24) = 16;
    goto LABEL_30;
  }
  if ( a2 )
LABEL_34:
    v26 = 23;
  else
    v26 = 3;
  if ( a4 )
    v24 = v26;
  else
    v24 = 0;
  if ( !a2 && a4 )
  {
    v27 = a1;
    v28 = v24;
    printk(&unk_84CB, "btfm_slim_slave_enable_port", v24);
    LODWORD(v24) = v28;
    a1 = v27;
  }
LABEL_30:
  result = btfm_slim_write(a1, v11, v24, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v15 = result;
    v16 = (unsigned int)result;
    goto LABEL_45;
  }
  return result;
}
