__int64 __fastcall cam_get_subpart_info(__int64 a1, unsigned int a2)
{
  int part_count; // w0
  unsigned int subpart_info; // w19

  part_count = socinfo_get_part_count(3);
  if ( part_count == a2 )
  {
    subpart_info = socinfo_get_subpart_info(3, a1, a2);
    if ( subpart_info )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_get_subpart_info",
        989,
        "Failed while getting subpart_info, rc = %d.",
        subpart_info);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_get_subpart_info",
      979,
      "Unsupported number of parts: %d",
      part_count);
    return (unsigned int)-22;
  }
  return subpart_info;
}
