__int64 __fastcall vx_show(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x21
  unsigned __int64 v7; // x25
  const char *v8; // x2
  unsigned __int64 v9; // x8
  int v10; // w22
  __int64 v11; // x26
  __int64 v12; // x21
  __int64 v13; // x27
  const char *v14; // x11
  __int64 v15; // x10
  unsigned __int64 v16; // x20
  bool v18; // w28
  const char *v19; // x2
  __int64 v20; // x24
  int *v21; // x9
  char v22; // w10
  int v23; // w8
  unsigned __int64 v24; // x10
  int v25; // w11
  int v26; // w10
  int *v27; // x11
  unsigned __int64 v28; // x12
  int v29; // w13
  int v30; // w14
  int v31; // w11
  int v32; // w12
  unsigned __int64 v33; // x8
  int v34; // w22
  const char *v35; // x2
  __int64 v36; // x20
  __int64 v37; // x19
  __int64 *v38; // x21
  __int64 v39; // t1
  const char *v40; // [xsp+8h] [xbp-38h]
  __int64 v41; // [xsp+10h] [xbp-30h]
  int v42; // [xsp+18h] [xbp-28h]
  char v43; // [xsp+1Ch] [xbp-24h]
  __int64 v44; // [xsp+20h] [xbp-20h] BYREF
  __int64 v45; // [xsp+28h] [xbp-18h]
  __int64 v46; // [xsp+30h] [xbp-10h]
  __int64 v47; // [xsp+38h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  result = read_vx_data(v2, &v44);
  if ( (_DWORD)result )
    goto LABEL_60;
  v4 = 32;
  v5 = 16;
  v42 = BYTE3(v44);
  if ( BYTE3(v44) == 221 || BYTE3(v44) == 204 )
    goto LABEL_6;
  if ( BYTE3(v44) == 170 )
  {
    v4 = 40;
    v5 = 24;
LABEL_6:
    v6 = *(_QWORD *)(v2 + v4);
    if ( v6 )
    {
      v7 = *(_QWORD *)(v2 + v5);
      if ( v7 )
      {
        if ( BYTE3(v44) == 170 )
        {
          v8 = "AOSS";
        }
        else if ( BYTE3(v44) == 204 )
        {
          v8 = "CXPC";
        }
        else
        {
          v8 = BYTE3(v44) == 221 ? "DDR" : (const char *)&unk_7520;
        }
        seq_printf(
          a1,
          "Mode           : %s\nDuration (ms)  : %u\nTime Shift     : %u\nFlush Threshold: %u\nMax Log Entries: %u\n",
          v8,
          HIWORD(v44),
          BYTE5(v44),
          BYTE4(v44),
          BYTE2(v44));
        seq_write(a1, "Timestamp|", 10);
        v9 = 0;
        v10 = 1;
        do
        {
          seq_printf(a1, "%*s|", 8, *(const char **)(v6 + 8 * v9));
          v9 = v10++;
        }
        while ( v7 > v9 );
        seq_putc(a1, 10);
        v11 = (unsigned int)v46;
        if ( (int)v46 >= 1 )
        {
          v12 = v45;
          v13 = 0;
          v43 = 0;
          if ( v42 == 221 )
            v14 = "DDR";
          else
            v14 = (const char *)&unk_7520;
          if ( v7 <= 1 )
            v15 = 1;
          else
            v15 = v7;
          v16 = v15 & 0xFFFFFFFFFFFFFFFELL;
          v40 = v14;
          v41 = v15;
          v18 = ((v15 - 1) & 0xFFFFFFFF80000000LL) != 0 || (unsigned int)(v15 - 1) > 0x7FFFFFFE;
          do
          {
            v20 = v12 + 16 * v13;
            seq_printf(a1, "%*x|", 9, *(_DWORD *)v20);
            v21 = *(int **)(v20 + 8);
            v22 = v7 < 2 || v18;
            v23 = *v21;
            if ( (v22 & 1) != 0 )
            {
              v24 = 0;
              v25 = 0;
            }
            else
            {
              v26 = 0;
              v27 = v21 + 1;
              v28 = v16;
              do
              {
                v29 = *(v27 - 1);
                v30 = *v27;
                v28 -= 2LL;
                v27 += 2;
                v23 |= v29;
                v26 |= v30;
              }
              while ( v28 );
              v23 |= v26;
              v24 = v16;
              v25 = v16;
              if ( v41 == v16 )
                goto LABEL_43;
            }
            v31 = v25 + 1;
            do
            {
              v32 = v21[v24];
              v24 = v31++;
              v23 |= v32;
            }
            while ( v7 > v24 );
LABEL_43:
            if ( v23 )
            {
              v33 = 0;
              v34 = 1;
              do
              {
                seq_printf(a1, "%*u|", 8, *(_DWORD *)(*(_QWORD *)(v20 + 8) + 4 * v33));
                v33 = v34++;
              }
              while ( v7 > v33 );
              seq_putc(a1, 10);
            }
            else if ( (v43 & 1) != 0 )
            {
              if ( v42 == 170 )
              {
                v19 = "AOSS";
              }
              else
              {
                v19 = "CXPC";
                if ( v42 != 204 )
                  v19 = v40;
              }
              seq_printf(a1, "%s Exit\n", v19);
              v43 = 0;
            }
            else
            {
              if ( v42 == 170 )
              {
                v35 = "AOSS";
              }
              else
              {
                v35 = "CXPC";
                if ( v42 != 204 )
                  v35 = v40;
              }
              seq_printf(a1, "%s Enter\n", v35);
              v43 = 1;
            }
          }
          while ( ++v13 != v11 );
        }
      }
    }
  }
  v36 = (unsigned int)v46;
  v37 = v45;
  if ( (int)v46 >= 1 )
  {
    v38 = (__int64 *)(v45 + 8);
    do
    {
      v39 = *v38;
      v38 += 2;
      kfree(v39);
      --v36;
    }
    while ( v36 );
  }
  kfree(v37);
  result = 0;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
