__int64 __fastcall nubia_hw_pcb_version_show(__int64 a1, __int64 a2, char *a3)
{
  if ( !a3 )
    return 0;
  ((void (__fastcall *)(char *))nubia_get_hw_pcb_version)(a3);
  if ( debug_value == 1 )
    printk(byte_71B5, a3);
  return snprintf(a3, 0xCu, "%s", a3);
}
