char *__fastcall sta_info_string_from_dbgid(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 < 0x22 )
    return sta_info_string_from_dbgid_strings[a1];
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Debug string not found for debug id %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "sta_info_string_from_dbgid",
    a1,
    v9,
    v10);
  return (char *)&unk_98C763;
}
