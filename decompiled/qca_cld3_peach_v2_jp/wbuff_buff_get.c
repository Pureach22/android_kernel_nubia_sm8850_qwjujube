__int64 __fastcall wbuff_buff_get(unsigned __int8 *a1, unsigned __int8 a2, int a3)
{
  __int64 result; // x0
  unsigned __int64 v5; // x8
  char *v6; // x19
  char *v7; // x19
  int v8; // t1
  unsigned int v9; // w10
  unsigned int v10; // w11
  unsigned int v11; // w11
  unsigned int v12; // w11
  unsigned int v13; // w11
  unsigned int v14; // w11
  unsigned int v15; // w11
  unsigned int v16; // w11
  unsigned int v17; // w11
  unsigned int v18; // w11
  unsigned int v19; // w11
  unsigned int v20; // w11
  unsigned int v21; // w11
  unsigned int v22; // w11
  unsigned int v23; // w11
  __int64 v24; // x9
  __int64 v25; // x8
  unsigned __int64 v26; // x21
  __int64 v27; // x20
  _QWORD *v28; // x8
  __int16 v29; // w10
  _QWORD *v30; // x22
  _QWORD *v31; // x8

  result = 0;
  if ( !a1 || (wbuff[0] & 1) == 0 )
    return result;
  v5 = *a1;
  if ( v5 > 1 )
    return 0;
  v6 = &wbuff[808 * (unsigned int)v5];
  v8 = (unsigned __int8)v6[8];
  v7 = v6 + 8;
  if ( v8 != 1 || a2 >= 0x10u && !a3 )
    return 0;
  if ( a2 != 16 || !a3 )
  {
    if ( a2 <= 0xFu )
      goto LABEL_75;
    return 0;
  }
  if ( v7[40] == 1 )
  {
    LOWORD(v9) = *((_WORD *)v7 + 28);
    if ( (unsigned __int16)(a3 - 1) < (unsigned int)(unsigned __int16)v9 )
    {
      a2 = 0;
LABEL_75:
      v24 = 808LL * (unsigned int)v5;
      v25 = 48LL * a2;
      v26 = v24 + v25 + 48;
      if ( v26 > 0x67F )
      {
LABEL_86:
        __break(1u);
        return wbuff_buff_put(result);
      }
      v27 = (__int64)&v7[v25 + 40];
      if ( *(_BYTE *)v27 == 1 )
      {
        result = qdf_spin_lock_bh_19((__int64)(v7 + 8));
        if ( v26 <= 0x677 )
        {
          v28 = *(_QWORD **)(v27 + 8);
          if ( v28 )
          {
            v29 = *((_WORD *)v7 + 1);
            v30 = *(_QWORD **)(v27 + 8);
            *(_QWORD *)(v27 + 8) = *v28;
            *((_WORD *)v7 + 1) = v29 + 1;
            result = qdf_spin_unlock_bh_24((__int64)(v7 + 8));
            *v30 = 0;
            if ( v26 <= 0x667 )
            {
              result = (__int64)v30;
              v31 = (_QWORD *)(v27 + 24);
LABEL_85:
              ++*v31;
              return result;
            }
          }
          else
          {
            result = qdf_spin_unlock_bh_24((__int64)(v7 + 8));
            if ( v26 <= 0x65F )
            {
              result = 0;
              v31 = (_QWORD *)(v27 + 32);
              goto LABEL_85;
            }
          }
        }
        goto LABEL_86;
      }
      return 0;
    }
  }
  else
  {
    LOWORD(v9) = 0;
  }
  if ( v7[88] == 1 )
  {
    v10 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 52);
    if ( v10 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 1;
      goto LABEL_75;
    }
  }
  if ( v7[136] == 1 )
  {
    v11 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 76);
    if ( v11 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 2;
      goto LABEL_75;
    }
  }
  if ( v7[184] == 1 )
  {
    v12 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 100);
    if ( v12 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 3;
      goto LABEL_75;
    }
  }
  if ( v7[232] == 1 )
  {
    v13 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 124);
    if ( v13 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 4;
      goto LABEL_75;
    }
  }
  if ( v7[280] == 1 )
  {
    v14 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 148);
    if ( v14 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 5;
      goto LABEL_75;
    }
  }
  if ( v7[328] == 1 )
  {
    v15 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 172);
    if ( v15 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 6;
      goto LABEL_75;
    }
  }
  if ( v7[376] == 1 )
  {
    v16 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 196);
    if ( v16 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 7;
      goto LABEL_75;
    }
  }
  if ( v7[424] == 1 )
  {
    v17 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 220);
    if ( v17 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 8;
      goto LABEL_75;
    }
  }
  if ( v7[472] == 1 )
  {
    v18 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 244);
    if ( v18 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 9;
      goto LABEL_75;
    }
  }
  if ( v7[520] == 1 )
  {
    v19 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 268);
    if ( v19 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 10;
      goto LABEL_75;
    }
  }
  if ( v7[568] == 1 )
  {
    v20 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 292);
    if ( v20 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 11;
      goto LABEL_75;
    }
  }
  if ( v7[616] == 1 )
  {
    v21 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 316);
    if ( v21 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 12;
      goto LABEL_75;
    }
  }
  if ( v7[664] == 1 )
  {
    v22 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 340);
    if ( v22 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 13;
      goto LABEL_75;
    }
  }
  if ( v7[712] == 1 )
  {
    v23 = (unsigned __int16)v9;
    v9 = *((unsigned __int16 *)v7 + 364);
    if ( v23 < (unsigned __int16)a3 && v9 >= (unsigned __int16)a3 )
    {
      a2 = 14;
      goto LABEL_75;
    }
  }
  if ( v7[760] != 1 )
    return 0;
  result = 0;
  if ( (unsigned __int16)v9 < (unsigned int)(unsigned __int16)a3
    && *((unsigned __int16 *)v7 + 388) >= (unsigned int)(unsigned __int16)a3 )
  {
    a2 = 15;
    goto LABEL_75;
  }
  return result;
}
