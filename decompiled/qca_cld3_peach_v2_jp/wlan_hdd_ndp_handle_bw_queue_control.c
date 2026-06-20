__int64 __fastcall wlan_hdd_ndp_handle_bw_queue_control(_QWORD *a1, int a2, unsigned int a3)
{
  _QWORD *v3; // x9
  unsigned int *v4; // x8
  __int64 v5; // x10
  unsigned int v6; // w11
  unsigned __int64 v7; // x12
  __int64 v8; // x13
  __int64 v9; // x15
  char *v10; // x10
  int v11; // w22
  unsigned int v12; // w11
  __int64 v13; // x12
  unsigned __int64 v14; // x13
  __int64 v15; // x15
  __int64 v16; // x9

  v3 = a1 + 6469;
  v4 = (unsigned int *)(a1 + 5262);
  if ( a2 > 24 )
  {
    if ( a2 <= 26 )
    {
      if ( a2 != 25 )
        goto LABEL_25;
      v5 = 2;
    }
    else
    {
      switch ( a2 )
      {
        case 27:
          v5 = 3;
          break;
        case 28:
          goto LABEL_25;
        case 29:
          v5 = 4;
          break;
        default:
          goto LABEL_35;
      }
    }
    goto LABEL_17;
  }
  if ( a2 <= 21 )
  {
    v5 = 0;
    if ( a2 == 20 )
      goto LABEL_25;
    if ( a2 != 21 )
LABEL_35:
      JUMPOUT(0x36D234);
LABEL_17:
    v6 = *v4;
    v7 = 0;
    v8 = jiffies - a1[5264];
    v9 = a1[5265] + v8;
    a1[5264] = jiffies;
    a1[5265] = v9;
    while ( 1 )
    {
      if ( ((v6 >> v7) & 1) != 0 )
      {
        *v3 += v8;
        if ( v7 > 0x10 )
        {
LABEL_22:
          if ( a3 <= 0x11 )
          {
            v10 = (char *)a1 + v5;
            ++HIDWORD(a1[2 * a3 + 6468]);
            v11 = (unsigned __int8)v10[52037];
            *v4 = v6 & ~(unsigned int)(1LL << a3);
            v10[52037] = 0;
            if ( !v11 )
              JUMPOUT(0x36D250);
            JUMPOUT(0x36D0CC);
          }
          goto LABEL_36;
        }
      }
      else if ( v7 > 0x10 )
      {
        goto LABEL_22;
      }
      ++v7;
      v3 += 2;
    }
  }
  if ( a2 == 23 )
  {
    v5 = 1;
    goto LABEL_17;
  }
LABEL_25:
  v12 = *v4;
  v13 = jiffies - a1[5264];
  if ( *v4 )
  {
    v14 = 0;
    v15 = a1[5265] + v13;
    a1[5264] = jiffies;
    a1[5265] = v15;
    while ( 1 )
    {
      if ( ((v12 >> v14) & 1) != 0 )
      {
        *v3 += v13;
        if ( v14 > 0x10 )
          goto LABEL_33;
      }
      else if ( v14 > 0x10 )
      {
        goto LABEL_33;
      }
      ++v14;
      v3 += 2;
    }
  }
  v16 = a1[5266];
  a1[5264] = jiffies;
  a1[5266] = v13 + v16;
LABEL_33:
  if ( a3 >= 0x12 )
LABEL_36:
    JUMPOUT(0x36D268);
  ++LODWORD(a1[2 * a3 + 6468]);
  *v4 = v12 | (1LL << a3);
  return sub_36D0BC();
}
