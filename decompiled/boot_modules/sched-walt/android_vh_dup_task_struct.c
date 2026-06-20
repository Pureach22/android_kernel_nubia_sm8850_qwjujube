void *__fastcall android_vh_dup_task_struct(__int64 a1, char *a2)
{
  void *v2; // x0

  if ( a2 == (char *)&init_task )
    v2 = &vendor_data_pad;
  else
    v2 = a2 + 5184;
  return memset(v2, 0, 0x1F0u);
}
