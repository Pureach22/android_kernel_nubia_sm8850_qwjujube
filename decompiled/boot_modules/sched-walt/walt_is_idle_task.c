__int64 __fastcall walt_is_idle_task(char *a1)
{
  unsigned __int8 *v1; // x8

  v1 = (unsigned __int8 *)&vendor_data_pad;
  if ( a1 != (char *)&init_task )
    v1 = (unsigned __int8 *)(a1 + 5184);
  return (*v1 >> 2) & 1;
}
