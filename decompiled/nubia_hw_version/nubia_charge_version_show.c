__int64 __fastcall nubia_charge_version_show(int a1, int a2, char *s)
{
  char *v4; // x19

  if ( !s )
    return 0;
  if ( (unsigned __int8)nubia_pcb_gpio3_v <= 2uLL )
    *(_DWORD *)s = dword_7A18[(unsigned __int8)nubia_pcb_gpio3_v];
  if ( debug_value == 1 )
  {
    v4 = s;
    printk(byte_732D, s);
    s = v4;
  }
  return snprintf(s, 0xCu, "%s", s);
}
