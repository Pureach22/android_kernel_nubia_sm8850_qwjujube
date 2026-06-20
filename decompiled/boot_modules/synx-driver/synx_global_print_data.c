_WORD *__fastcall synx_global_print_data(_WORD *result, __int64 a2)
{
  _WORD *v3; // x21
  _WORD *v4; // x21
  _WORD *v5; // x21
  _WORD *v6; // x21

  if ( (synx_debug & 0x10) != 0 )
  {
    v3 = result;
    printk(&unk_2B6CD, "verb", "synx_global_print_data", 83, a2, *(unsigned int *)result);
    result = v3;
    if ( (synx_debug & 0x10) != 0 )
    {
      printk(&unk_2A341, "verb", "synx_global_print_data", 87, a2, (unsigned __int16)v3[6]);
      result = v3;
    }
  }
  if ( result[8] && (synx_debug & 0x10) != 0 )
  {
    v4 = result;
    printk(&unk_26498, "verb", "synx_global_print_data", 92, a2, 0);
    result = v4;
    if ( !v4[9] )
      goto LABEL_7;
  }
  else if ( !result[9] )
  {
    goto LABEL_7;
  }
  if ( (synx_debug & 0x10) != 0 )
  {
    v5 = result;
    printk(&unk_26498, "verb", "synx_global_print_data", 92, a2, 1);
    result = v5;
  }
LABEL_7:
  if ( result[10] && (synx_debug & 0x10) != 0 )
  {
    v6 = result;
    printk(&unk_26498, "verb", "synx_global_print_data", 92, a2, 2);
    result = v6;
    if ( !v6[11] )
      return result;
  }
  else if ( !result[11] )
  {
    return result;
  }
  if ( (synx_debug & 0x10) != 0 )
    return (_WORD *)printk(&unk_26498, "verb", "synx_global_print_data", 92, a2, 3);
  return result;
}
