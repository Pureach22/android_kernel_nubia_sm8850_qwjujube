__int64 __fastcall pmic_arb_chained_irq(__int64 a1)
{
  unsigned __int16 *v1; // x24
  _QWORD *v2; // x22
  __int64 v4; // x23
  __int64 v5; // x21
  __int64 v6; // x26
  unsigned int v7; // w20
  _QWORD *v8; // x28
  void (__fastcall *v9)(_QWORD); // x8
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  unsigned int v12; // w23
  char v13; // w19
  int v14; // w23
  __int64 v15; // x19
  _DWORD *v16; // x8
  unsigned int *v17; // x0
  _DWORD *v18; // x8
  unsigned int *v19; // x0
  _DWORD *v21; // x8
  unsigned int *v22; // x0
  unsigned int v23; // w0
  _BOOL4 v24; // w9
  unsigned int v25; // w24
  unsigned int v26; // w8
  unsigned int v27; // w25
  int v28; // w8
  bool v29; // cc
  _DWORD *v30; // x8
  unsigned int *v31; // x0
  int v32; // w0
  int v33; // w8
  unsigned int v34; // w1
  _BOOL4 v35; // w25
  __int64 v36; // x19
  __int64 (__fastcall *v37)(_QWORD); // x8
  __int64 v39; // [xsp+0h] [xbp-40h]
  __int64 v40; // [xsp+10h] [xbp-30h]
  _QWORD *v41; // [xsp+18h] [xbp-28h]
  int v42; // [xsp+24h] [xbp-1Ch]
  unsigned int v43; // [xsp+30h] [xbp-10h]
  _BOOL4 v44; // [xsp+34h] [xbp-Ch]
  unsigned __int16 *v45; // [xsp+38h] [xbp-8h]

  v1 = *(unsigned __int16 **)(a1 + 8);
  v2 = *(_QWORD **)(a1 + 72);
  v4 = *(_QWORD *)v1;
  v5 = v1[80];
  v6 = v1[81];
  v7 = v1[26];
  v8 = *(_QWORD **)(*(_QWORD *)v1 + 56LL);
  v43 = *(unsigned __int8 *)(*(_QWORD *)v1 + 49LL);
  if ( !v2[9] )
  {
    v9 = (void (__fastcall *)(_QWORD))v2[7];
    if ( v9 )
      goto LABEL_6;
    v10 = (void (__fastcall *)(_QWORD))v2[6];
    v11 = a1 + 48;
    if ( *((_DWORD *)v10 - 1) != 270158662 )
      __break(0x8228u);
    v10(v11);
    v9 = (void (__fastcall *)(_QWORD))v2[5];
    if ( v9 )
    {
LABEL_6:
      if ( *((_DWORD *)v9 - 1) != 270158662 )
        __break(0x8228u);
      v9(a1 + 48);
    }
  }
  v39 = v4;
  v12 = (unsigned int)v5 >> 5;
  v40 = a1;
  if ( (unsigned int)v5 >> 5 <= (unsigned int)v6 >> 5 )
  {
    v13 = 0;
    v45 = v1;
    v42 = 0;
    v41 = v8;
    do
    {
      v21 = (_DWORD *)v8[8];
      if ( *(v21 - 1) != -1500441957 )
        __break(0x8228u);
      v22 = (unsigned int *)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, _QWORD))v21)(v1, v43, v12 - (v7 >> 5));
      v23 = readl_relaxed(v22);
      v24 = v23 != 0;
      if ( v23 )
      {
        v25 = v23;
        do
        {
          while ( 1 )
          {
            v26 = __clz(__rbit32(v25));
            v27 = v26 | (32 * v12);
            v28 = 1 << v26;
            v29 = v27 < (unsigned int)v5 || v27 > (unsigned int)v6;
            v25 &= ~v28;
            if ( !v29 )
              break;
            if ( (pmic_arb_chained_irq___already_done & 1) != 0 )
            {
              if ( !v25 )
                goto LABEL_26;
            }
            else
            {
              v34 = v27;
              pmic_arb_chained_irq___already_done = 1;
              v35 = v24;
              _warn_printk("spurious spmi irq received for apid=%d\n", v34);
              v24 = v35;
              __break(0x800u);
              if ( !v25 )
                goto LABEL_26;
            }
          }
          v30 = (_DWORD *)v8[9];
          v44 = v24;
          if ( *(v30 - 1) != -395291818 )
            __break(0x8228u);
          v31 = (unsigned int *)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD))v30)(v45, v27);
          if ( (readl_relaxed(v31) & 1) != 0 )
          {
            v32 = periph_interrupt(v45, v27);
            v33 = v42;
            if ( v32 )
              v33 = v42 + 1;
            v42 = v33;
          }
          v24 = v44;
          v8 = v41;
        }
        while ( v25 );
      }
LABEL_26:
      v1 = v45;
      v13 |= v24;
    }
    while ( v12++ != (unsigned int)v6 >> 5 );
  }
  else
  {
    v42 = 0;
    v13 = 0;
  }
  if ( (v13 & 1) != 0 )
  {
    v36 = v40;
    if ( !v42 )
LABEL_51:
      handle_bad_irq(v36);
  }
  else
  {
    if ( (unsigned int)v5 > (unsigned int)v6 )
    {
      v14 = v42;
    }
    else
    {
      v14 = v42;
      v15 = (4 * v5) | 3;
      do
      {
        if ( *(unsigned __int8 *)(*((_QWORD *)v1 + 19) + v15) == *(unsigned __int8 *)(v39 + 49) )
        {
          v16 = (_DWORD *)v8[10];
          if ( *(v16 - 1) != -395291818 )
            __break(0x8228u);
          v17 = (unsigned int *)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD))v16)(v1, (unsigned int)v5);
          if ( (unsigned int)readl_relaxed(v17) )
          {
            v18 = (_DWORD *)v8[9];
            if ( *(v18 - 1) != -395291818 )
              __break(0x8228u);
            v19 = (unsigned int *)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD))v18)(v1, (unsigned int)v5);
            if ( (readl_relaxed(v19) & 1) != 0 && (unsigned int)periph_interrupt(v1, (unsigned int)v5) )
              ++v14;
          }
        }
        ++v5;
        v15 += 4;
      }
      while ( v6 + 1 != v5 );
    }
    v36 = v40;
    if ( !v14 )
      goto LABEL_51;
  }
  v37 = (__int64 (__fastcall *)(_QWORD))v2[9];
  if ( !v37 )
    v37 = (__int64 (__fastcall *)(_QWORD))v2[8];
  if ( *((_DWORD *)v37 - 1) != 270158662 )
    __break(0x8228u);
  return v37(v36 + 48);
}
