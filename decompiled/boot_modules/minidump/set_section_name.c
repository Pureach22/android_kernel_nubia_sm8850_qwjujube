__int64 __fastcall set_section_name(__int64 a1)
{
  unsigned int v1; // w19
  __int64 v2; // x8

  if ( *(_WORD *)(minidump_elfheader + 62) )
  {
    v1 = 0;
    if ( a1 )
    {
      v2 = minidump_elfheader
         + *(_QWORD *)(*(_QWORD *)(minidump_elfheader + 40)
                     + minidump_elfheader
                     + ((unsigned __int64)*(unsigned __int16 *)(minidump_elfheader + 62) << 6)
                     + 24);
      if ( v2 )
      {
        v1 = qword_10040;
        qword_10040 = (int)(sized_strscpy(v2 + (int)qword_10040, a1) + v1 + 1);
      }
    }
  }
  else
  {
    return 0;
  }
  return v1;
}
