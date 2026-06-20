__int64 __fastcall qcom_reboot_reason_reboot(__int64 a1, int a2, char *s1)
{
  const char *v3; // x1
  char *v6; // x21

  if ( s1 )
  {
    v3 = reasons;
    if ( reasons )
    {
      v6 = (char *)&unk_F8;
      while ( strcmp(s1, v3) )
      {
        v3 = *((const char **)v6 + 1);
        v6 += 16;
        if ( !v3 )
          return 1;
      }
      nvmem_cell_write(*(_QWORD *)(a1 + 24), v6, 1);
    }
  }
  return 1;
}
