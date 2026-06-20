__int64 __fastcall task_info_get(__int64 a1)
{
  const char *v1; // x3

  if ( task_info )
    v1 = "1 - Full";
  else
    v1 = "0 - Part";
  return scnprintf(a1, 4096, "%s\n", v1);
}
