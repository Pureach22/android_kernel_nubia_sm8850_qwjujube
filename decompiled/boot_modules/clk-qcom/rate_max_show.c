__int64 __fastcall rate_max_show(__int64 a1)
{
  __int64 v1; // x28
  __int64 rate; // x21
  unsigned int v4; // w9
  __int64 v5; // x26
  unsigned __int64 v6; // x21
  __int64 v7; // x22
  unsigned __int64 v8; // x9
  __int64 v9; // x8
  unsigned __int64 v10; // x10
  __int64 v11; // x9
  const char *name; // x0
  __int64 v14; // x23
  unsigned __int64 v15; // x9
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x25
  bool v19; // cf
  char v20; // w27
  __int64 v21; // x23
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  int v24; // w20
  char v26; // w27
  __int64 v27; // x27
  __int64 v28; // x0
  __int64 vdd_level; // x23
  const char *v30; // x2
  __int64 v31; // x24
  int v32; // w8
  int i; // w20
  __int64 v34; // x9
  unsigned __int64 StatusReg; // x20
  __int64 v36; // x23
  __int64 v37; // [xsp+8h] [xbp-8h]

  v1 = *(_QWORD *)(a1 + 128);
  rate = clk_get_rate(*(_QWORD *)(v1 + 8));
  if ( (clk_find_vdd_level(v1, v1 + 48, rate) & 0x80000000) != 0 )
  {
    name = (const char *)clk_hw_get_name(v1);
    seq_printf(a1, "could not find_vdd_level for %s, %ld\n", name, rate);
    return 0;
  }
  else
  {
    v4 = *(_DWORD *)(v1 + 80);
    if ( *(_QWORD *)(v1 + 48) )
      v5 = v4 + 1;
    else
      v5 = v4;
    if ( (v5 & 0x80000000) == 0 )
    {
      v6 = 8LL * (unsigned int)v5;
      v7 = _kmalloc_noprof(v6, 3264);
      while ( 1 )
      {
        if ( !v7 )
          return 4294967284LL;
        if ( *(int *)(v1 + 80) < 1 )
        {
          v9 = 0;
          v11 = *(_QWORD *)(v1 + 48);
          if ( v11 )
          {
LABEL_20:
            if ( v6 < 8 * v9 || v6 - 8 * v9 < 8 )
              goto LABEL_76;
            *(_QWORD *)(v7 + 8 * v9) = v11;
          }
LABEL_23:
          seq_printf(a1, "%12s", (const char *)&unk_28527);
          if ( (int)v5 <= 0 )
          {
            seq_printf(a1, "\n%12s", "freq");
LABEL_55:
            seq_putc(a1, 10);
            if ( *(int *)(v1 + 72) < 1 )
            {
LABEL_74:
              kfree(v7);
              return 0;
            }
            v27 = 0;
            v37 = v1;
            while ( 1 )
            {
              v28 = clk_get_rate(*(_QWORD *)(v1 + 8));
              vdd_level = (unsigned int)clk_find_vdd_level(v1, v1 + 48, v28);
              v30 = v27 == vdd_level ? "[" : (const char *)&unk_28527;
              seq_printf(a1, "%2s%10lu", v30, *(_QWORD *)(*(_QWORD *)(v1 + 64) + 8 * v27));
              if ( (int)v5 >= 1 )
                break;
LABEL_72:
              if ( v27 == vdd_level )
                seq_putc(a1, 93);
              seq_putc(a1, 10);
              v1 = v37;
              if ( ++v27 >= *(int *)(v37 + 72) )
                goto LABEL_74;
            }
            v1 = 0;
            while ( ((8 * v1) & 0x8000000000000000LL) == 0 && v6 >= 8 * v1 && v6 - 8 * v1 >= 8 )
            {
              v31 = *(_QWORD *)(v7 + 8 * v1);
              v32 = *(_DWORD *)(v31 + 24);
              if ( v32 >= 1 )
              {
                for ( i = 0; i < v32; ++i )
                {
                  v34 = *(_QWORD *)(v31 + 32);
                  if ( v34 )
                  {
                    seq_printf(a1, "%10u", *(_DWORD *)(v34 + 4LL * (i + (int)v27 * v32)));
                    v32 = *(_DWORD *)(v31 + 24);
                  }
                }
              }
              if ( ++v1 == v5 )
                goto LABEL_72;
            }
          }
          else
          {
            v14 = 0;
            while ( 1 )
            {
              v15 = 8 * v14;
              if ( 8 * v14 < 0 || v6 < 8 * v14 || v6 - 8 * v14 < 8 )
                break;
              v16 = *(_QWORD *)(v7 + 8 * v14);
              if ( *(int *)(v16 + 24) >= 1 )
              {
                v19 = v6 >= v15;
                v17 = v6 - v15;
                v18 = 0;
                v19 = v19 && v17 >= 8;
                v20 = !v19;
                do
                {
                  seq_printf(a1, "%10s", *(const char **)(*(_QWORD *)(v16 + 16) + 8 * v18));
                  if ( (v20 & 1) != 0 )
                    goto LABEL_76;
                  v16 = *(_QWORD *)(v7 + 8 * v14);
                }
                while ( ++v18 < *(int *)(v16 + 24) );
              }
              if ( ++v14 == v5 )
              {
                seq_printf(a1, "\n%12s", "freq");
                v21 = 0;
                while ( 1 )
                {
                  v22 = 8 * v21;
                  if ( 8 * v21 < 0 || v6 < 8 * v21 || v6 - 8 * v21 < 8 )
                    goto LABEL_76;
                  if ( *(int *)(*(_QWORD *)(v7 + 8 * v21) + 24LL) >= 1 )
                  {
                    v19 = v6 >= v22;
                    v23 = v6 - v22;
                    v24 = 0;
                    v26 = !v19 || v23 < 8;
                    do
                    {
                      seq_printf(a1, "%10s", "uV");
                      if ( (v26 & 1) != 0 )
                        goto LABEL_76;
                    }
                    while ( ++v24 < *(_DWORD *)(*(_QWORD *)(v7 + 8 * v21) + 24LL) );
                  }
                  if ( ++v21 == v5 )
                    goto LABEL_55;
                }
              }
            }
          }
        }
        else
        {
          v8 = 0;
          v9 = 0;
          v10 = v6;
          while ( (v8 & 0x8000000000000000LL) == 0 )
          {
            if ( v6 < v8 )
              break;
            v19 = v10 >= 8;
            v10 -= 8LL;
            if ( !v19 )
              break;
            ++v9;
            *(_QWORD *)(v7 + v8) = *(_QWORD *)(*(_QWORD *)(v1 + 56) + v8);
            v8 += 8LL;
            if ( v9 >= *(int *)(v1 + 80) )
            {
              v11 = *(_QWORD *)(v1 + 48);
              if ( v11 )
                goto LABEL_20;
              goto LABEL_23;
            }
          }
        }
LABEL_76:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v36 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &rate_max_show__alloc_tag;
        if ( (v5 & 0x80000000) != 0 )
        {
          v6 = 0;
          v7 = 0;
        }
        else
        {
          v6 = 8LL * (unsigned int)v5;
          v7 = _kmalloc_noprof(v6, 3264);
        }
        *(_QWORD *)(StatusReg + 80) = v36;
      }
    }
    return 4294967284LL;
  }
}
