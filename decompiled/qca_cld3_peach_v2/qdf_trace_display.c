__int64 __fastcall qdf_trace_display(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x3
  unsigned int v5; // w19
  char *v6; // x20
  __int64 i; // x21
  const char *v8; // x28
  __int64 result; // x0

  printk(&unk_A6C76D, a2, a3, a4);
  v5 = 0;
  v6 = g_qdf_category_name;
  for ( i = 32; i != 366; i += 2 )
  {
    if ( (unsigned int)qdf_pidx >= 0x20 )
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
LABEL_10:
      v8 = " ";
      goto LABEL_11;
    }
    if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) == 0 )
    {
      printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      goto LABEL_10;
    }
    if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
      goto LABEL_55;
    if ( (*(_WORD *)((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + i) & 2) != 0 )
      v8 = "X";
    else
      v8 = " ";
LABEL_11:
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
          goto LABEL_55;
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
          goto LABEL_55;
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
          goto LABEL_55;
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
          goto LABEL_55;
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
          goto LABEL_55;
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
          goto LABEL_55;
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    if ( (unsigned int)qdf_pidx < 0x20 )
    {
      if ( (*((_BYTE *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx + 384) & 1) != 0 )
      {
        if ( (i + 392 * (unsigned __int64)(unsigned int)qdf_pidx) >> 8 > 0x30 )
        {
LABEL_55:
          __break(1u);
          JUMPOUT(0x19B208);
        }
      }
      else
      {
        printk(&unk_9EF77B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
      }
    }
    else
    {
      printk(&unk_A8530B, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, v4);
    }
    result = printk(&unk_9FB939, v5++, v6, v8);
    v6 += 32;
  }
  return result;
}
