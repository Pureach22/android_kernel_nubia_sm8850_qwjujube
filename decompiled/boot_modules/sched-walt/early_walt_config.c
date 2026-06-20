__int64 early_walt_config()
{
  const char *id_string; // x20
  __int64 result; // x0

  id_string = (const char *)socinfo_get_id_string();
  soc_cluster_freq_table_size = 0;
  qword_69018 = 0;
  memset(&soc_cluster_freq_table, 0, 0x640u);
  result = strcmp(id_string, "SUN");
  if ( (_DWORD)result && (result = strcmp(id_string, "SUNP"), (_DWORD)result) )
  {
    result = strcmp(id_string, "CANOE");
    if ( !(_DWORD)result )
    {
      soc_cluster_freq_table_size = 0x2000000020LL;
      soc_cluster_freq_table = 0x2D000000224LL;
      qword_69028 = 0x35900000330LL;
      qword_69030 = 0x39700000379LL;
      qword_69038 = 0x3CB000003AFLL;
      qword_69040 = 0x3F3000003DFLL;
      qword_69048 = 0x42C00000405LL;
      qword_69050 = 0x46B0000044ELL;
      qword_69058 = 0x4B900000491LL;
      qword_69060 = 0x526000004DDLL;
      qword_69068 = 0x5B200000575LL;
      qword_69070 = 0x6BC000005F4LL;
      qword_69078 = 0x7FF0000075ALL;
      qword_69080 = 0x8D000000865LL;
      qword_69088 = 0x9DD00000941LL;
      qword_69090 = 0xB9E00000AD8LL;
      qword_69098 = 0xD3100000C7FLL;
      qword_691B0 = 0x77D00000761LL;
      qword_691B8 = 0x7A800000797LL;
      qword_691C0 = 0x7C3000007B8LL;
      qword_691C8 = 0x86400000814LL;
      qword_691D0 = 0x9020000089ELL;
      qword_691D8 = 0x9B40000095ALL;
      qword_691E0 = 0xA79000009F9LL;
      qword_691E8 = 0xB8B00000AFFLL;
      qword_691F0 = 0xD0F00000C56LL;
      qword_691F8 = 0xE4D00000D9ELL;
      qword_69200 = 0x114400000F04LL;
      qword_69208 = 0x151800001324LL;
      qword_69210 = 0x1988000016A8LL;
      qword_69218 = 0x1E1000001C31LL;
      qword_69220 = 0x21E800002034LL;
      qword_69228 = 0x251E0000238BLL;
    }
  }
  else
  {
    soc_cluster_freq_table_size = 0x1000000010LL;
    soc_cluster_freq_table = 0x2DB000002ABLL;
    qword_69028 = 0x3180000030ELL;
    qword_69030 = 0x3580000032DLL;
    qword_69038 = 0x3BE00000374LL;
    qword_69040 = 0x43F000003ECLL;
    qword_69048 = 0x51400000481LL;
    qword_69050 = 0x65D000005B6LL;
    qword_69058 = 0x88700000766LL;
    qword_691B0 = 0x6D500000677LL;
    qword_691B8 = 0x79F000006EFLL;
    qword_691C0 = 0x8DC00000838LL;
    qword_691C8 = 0x9E200000979LL;
    qword_691D0 = 0xB5700000A5CLL;
    qword_691D8 = 0xE0800000C99LL;
    qword_691E0 = 0x13DF00001120LL;
    qword_691E8 = 0x158C0000150ELL;
  }
  return result;
}
