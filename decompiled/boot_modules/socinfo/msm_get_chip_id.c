__int64 __fastcall msm_get_chip_id(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v3; // x9
  const char *v4; // x3

  if ( (unsigned int)socinfo_format <= 0xC )
    v3 = "N/A";
  else
    v3 = (const char *)(socinfo + 124);
  if ( socinfo )
    v4 = v3;
  else
    v4 = "N/A";
  return (int)scnprintf(a3, 4096, "%-.32s\n", v4);
}
