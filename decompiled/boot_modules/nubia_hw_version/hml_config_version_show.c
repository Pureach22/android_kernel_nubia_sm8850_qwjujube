__int64 __fastcall hml_config_version_show(int a1, int a2, char *s)
{
  unsigned int v3; // w3
  char *v5; // x19
  unsigned int v6; // w20

  if ( !s )
    return 0;
  if ( (unsigned __int8)nubia_pcb_gpio3_v > 2uLL )
    v3 = -1;
  else
    v3 = dword_7A24[(unsigned __int8)nubia_pcb_gpio3_v];
  if ( debug_value == 1 )
  {
    v5 = s;
    v6 = v3;
    printk(byte_722F, v3);
    v3 = v6;
    s = v5;
  }
  return snprintf(s, 5u, "%d", v3);
}
