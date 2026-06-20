__int64 __fastcall geni_spi_irq(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 v4; // x20
  unsigned int v5; // w21
  __int64 v6; // x0
  __int64 v7; // x1
  int v8; // w8
  int v9; // w23
  __int64 v10; // x8
  int v11; // w23
  int v12; // w9
  unsigned int v13; // w10
  unsigned int v14; // w23
  unsigned int v15; // w22
  int v16; // w11
  int v17; // w11
  int v18; // w12
  int v19; // w10
  int v20; // w9
  int v21; // w24
  int v22; // w26
  __int64 v23; // x25
  __int64 v24; // x8
  int v25; // w9
  int v26; // w8
  int v27; // w27
  __int64 v28; // x8
  int v29; // w10
  int v30; // w9
  int v31; // w23
  int v32; // w11
  int v33; // w9
  int v34; // w24
  int v35; // w26
  __int64 v36; // x25
  __int64 v37; // x0
  int v38; // w9
  int v39; // w8
  int v40; // w12
  unsigned int v41; // w8
  __int64 v42; // x9
  int v43; // w10
  int v44; // w11
  int v45; // w12
  int v46; // w8
  int v47; // w3
  __int64 v48; // x0
  __int64 v49; // x21
  __int64 v50; // x0

  v2 = *(_QWORD *)(a2 + 488);
  if ( v2 )
  {
    if ( *(_DWORD *)(a2 + 496) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_spi_irq", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  if ( *(_DWORD *)(*(_QWORD *)(a2 + 200) + 500LL) == 2 )
  {
    ipc_log_string(*(_QWORD *)(a2 + 472), "%s: device is suspended\n", "geni_spi_irq");
    if ( *(_QWORD *)(a2 + 200) )
      spi_trace_log();
    v5 = 0;
    goto LABEL_93;
  }
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 184) + 1552LL));
  v8 = *(_DWORD *)(a2 + 452);
  v5 = v6;
  if ( v8 == 2 )
  {
    v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 184) + 3136LL));
    v15 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 184) + 3392LL));
    if ( v14 )
      writel_relaxed(v14, *(_QWORD *)(a2 + 184) + 3140LL);
    if ( v15 )
      writel_relaxed(v15, *(_QWORD *)(a2 + 184) + 3396LL);
    if ( (v14 & 1) != 0 )
    {
      *(_DWORD *)(a2 + 236) = 0;
      if ( (v15 & 1) == 0 )
      {
LABEL_23:
        if ( !*(_DWORD *)(a2 + 236) )
        {
LABEL_27:
          if ( !*(_DWORD *)(a2 + 240) )
            *(_BYTE *)(a2 + 506) = 1;
        }
LABEL_29:
        if ( (v5 & 0x30) != 0 )
          *(_BYTE *)(a2 + 506) = 1;
        goto LABEL_93;
      }
    }
    else if ( (v15 & 1) == 0 )
    {
      goto LABEL_23;
    }
    *(_DWORD *)(a2 + 240) = 0;
    if ( !*(_DWORD *)(a2 + 236) )
      goto LABEL_27;
    goto LABEL_29;
  }
  if ( v8 == 1 )
  {
    if ( (v6 & 0xC000000) != 0 )
    {
      v9 = *(_DWORD *)(a2 + 216);
      v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 184) + 2052LL));
      v10 = *(_QWORD *)(a2 + 248);
      if ( v10 )
      {
        v11 = v9 >> 3;
        v12 = v6 & 0x1FFFFFF;
        if ( (v6 & 0x80000000) != 0 )
        {
          v13 = ((unsigned int)v6 >> 28) & 7;
          v16 = v13 - 1 < 3;
          if ( v13 - 1 >= 3 )
            v13 = 0;
          v12 -= v16;
        }
        else
        {
          v13 = 0;
        }
        v17 = *(_DWORD *)(a2 + 232);
        v18 = v11;
        if ( *(_DWORD *)(a2 + 216) % v17 )
          v18 = *(_DWORD *)(a2 + 232) / 8 + 1;
        v19 = v13 + v18 * v12;
        v20 = *(_DWORD *)(a2 + 240);
        if ( v20 >= v19 )
          v21 = v19;
        else
          v21 = *(_DWORD *)(a2 + 240);
        if ( v21 >= 1 )
        {
          v22 = 0;
          v23 = *(_QWORD *)(v10 + 8) + (unsigned int)(*(_DWORD *)(v10 + 16) - v20);
          do
          {
            v25 = *(_DWORD *)(a2 + 232);
            v26 = v11;
            if ( *(_DWORD *)(a2 + 216) % v25 )
              v26 = v25 / 8 + 1;
            if ( v21 - v22 >= v26 )
              v27 = v26;
            else
              v27 = v21 - v22;
            v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 184) + 1920LL));
            if ( v27 < 1 )
            {
              LODWORD(v24) = v22;
            }
            else
            {
              v24 = v22 + 1LL;
              *(_BYTE *)(v23 + v22) = v6;
              if ( v27 != 1 )
              {
                *(_BYTE *)(v23 + v24) = BYTE1(v6);
                LODWORD(v24) = v22 + 2;
                if ( v27 != 2 )
                {
                  *(_BYTE *)(v23 + (int)v24) = BYTE2(v6);
                  if ( v27 == 3 )
                  {
                    LODWORD(v24) = v22 + 3;
                  }
                  else
                  {
                    *(_BYTE *)(v23 + v22 + 3) = BYTE3(v6);
                    if ( v27 != 4 )
                    {
LABEL_100:
                      __break(1u);
                      return writel_relaxed(v6, v7);
                    }
                    LODWORD(v24) = v22 + 4;
                  }
                }
              }
            }
            v22 = v24;
          }
          while ( (int)v24 < v21 );
          v20 = *(_DWORD *)(a2 + 240);
        }
        *(_DWORD *)(a2 + 240) = v20 - v21;
      }
    }
    if ( (v5 & 0x40000000) != 0 )
    {
      v28 = *(_QWORD *)(a2 + 248);
      if ( v28 )
      {
        v29 = *(_DWORD *)(a2 + 216);
        v30 = *(_DWORD *)(a2 + 232);
        v31 = v29 >> 3;
        v32 = v29 >> 3;
        if ( v29 % v30 )
          v32 = *(_DWORD *)(a2 + 232) / 8 + 1;
        v33 = *(_DWORD *)(a2 + 236);
        if ( v33 >= v32 * (*(_DWORD *)(a2 + 212) - *(_DWORD *)(a2 + 220)) )
          v34 = v32 * (*(_DWORD *)(a2 + 212) - *(_DWORD *)(a2 + 220));
        else
          v34 = *(_DWORD *)(a2 + 236);
        if ( v34 >= 1 )
        {
          v35 = 0;
          v36 = *(_QWORD *)v28 + (unsigned int)(*(_DWORD *)(v28 + 16) - v33);
          while ( 1 )
          {
            v38 = *(_DWORD *)(a2 + 232);
            v39 = v31;
            if ( *(_DWORD *)(a2 + 216) % v38 )
              v39 = v38 / 8 + 1;
            v40 = v34 - v35 >= v39 ? v39 : v34 - v35;
            if ( v40 >= 1 )
              break;
            v37 = 0;
LABEL_67:
            v6 = writel_relaxed(v37, *(_QWORD *)(a2 + 184) + 1792LL);
            __dsb(0xFu);
            if ( v35 >= v34 )
            {
              v33 = *(_DWORD *)(a2 + 236);
              goto LABEL_84;
            }
          }
          v41 = *(unsigned __int8 *)(v36 + v35);
          v42 = v35 + 1LL;
          if ( v40 == 1 )
          {
            v43 = 0;
          }
          else
          {
            v43 = *(unsigned __int8 *)(v36 + v42);
            LODWORD(v42) = v35 + 2;
            if ( v40 != 2 )
            {
              v44 = *(unsigned __int8 *)(v36 + (int)v42);
              LODWORD(v42) = v35 + 3;
              if ( v40 != 3 )
              {
                if ( v40 != 4 )
                  goto LABEL_100;
                v45 = *(unsigned __int8 *)(v36 + (int)v42);
                LODWORD(v42) = v35 + 4;
                goto LABEL_79;
              }
LABEL_78:
              v45 = 0;
LABEL_79:
              v35 = v42;
              v37 = (v44 << 16) | (v45 << 24) | (v43 << 8) | v41;
              goto LABEL_67;
            }
          }
          v44 = 0;
          goto LABEL_78;
        }
LABEL_84:
        *(_DWORD *)(a2 + 236) = v33 - v34;
        if ( v33 == v34 )
        {
          writel_relaxed(0, *(_QWORD *)(a2 + 184) + 2060LL);
          __dsb(0xFu);
        }
      }
    }
    if ( (v5 & 0x31) != 0 )
    {
      v46 = *(_DWORD *)(a2 + 236);
      *(_BYTE *)(a2 + 506) = 1;
      if ( v46 )
      {
        writel_relaxed(0, *(_QWORD *)(a2 + 184) + 2060LL);
        ipc_log_string(
          *(_QWORD *)(a2 + 472),
          "%s:Premature Done.tx_rem%d bpw%d\n",
          "geni_spi_irq",
          *(_DWORD *)(a2 + 236),
          *(_DWORD *)(a2 + 232));
        if ( *(_QWORD *)(a2 + 200) )
          spi_trace_log();
      }
      v47 = *(_DWORD *)(a2 + 240);
      if ( v47 )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 472),
          "%s:Premature Done.rx_rem%d bpw%d\n",
          "geni_spi_irq",
          v47,
          *(_DWORD *)(a2 + 232));
        if ( *(_QWORD *)(a2 + 200) )
          spi_trace_log();
      }
    }
  }
LABEL_93:
  v48 = writel_relaxed(v5, *(_QWORD *)(a2 + 184) + 1560LL);
  if ( *(_BYTE *)(a2 + 506) == 1 )
  {
    *(_BYTE *)(a2 + 506) = 0;
    v48 = complete(a2 + 256);
  }
  v49 = *(_QWORD *)(a2 + 488);
  if ( v49 && v4 )
  {
    if ( *(_DWORD *)(a2 + 496) )
    {
      v50 = sched_clock(v48);
      ipc_log_string(v49, "%s:took %llu nsec(%llu usec)\n", "geni_spi_irq", v50 - v4, (v50 - v4) / 0x3E8);
    }
  }
  return 1;
}
