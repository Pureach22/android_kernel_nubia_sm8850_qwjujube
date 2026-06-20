__int64 __fastcall lpi_gpio_dbg_show(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x27
  unsigned __int64 v5; // x28
  __int64 v6; // x8
  const char *v7; // x24
  unsigned int *v8; // x25
  char v9; // w26
  unsigned int v10; // w0
  unsigned int v11; // w25
  const char *v12; // x3

  if ( *(_WORD *)(a2 + 172) )
  {
    v3 = result;
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(gpiochip_get_data(a2) + 8) + 16LL) + 8LL) + v4;
      v7 = *(const char **)(v6 + 8);
      v8 = *(unsigned int **)(v6 + 16);
      v9 = lpi_gpio_read(v8, 4u);
      v10 = lpi_gpio_read(v8, 0);
      v11 = v10;
      if ( (v9 & 2) != 0 )
        v12 = (const char *)&unk_82BF;
      else
        v12 = "in";
      seq_printf(v3, " %-8s: %-3s %d", v7, v12, (v10 >> 2) & 0xF);
      seq_printf(v3, " %dmA", ((v11 >> 5) & 0xE) + 2);
      seq_printf(v3, " %s", lpi_gpio_dbg_show_one_pulls[v11 & 3]);
      result = seq_putc(v3, 10);
      ++v5;
      v4 += 24;
    }
    while ( v5 < *(unsigned __int16 *)(a2 + 172) );
  }
  return result;
}
