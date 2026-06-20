__int64 __fastcall is_voter_disabled(__int64 a1, const char *a2)
{
  __int64 result; // x0
  __int64 v4; // x8
  size_t v6; // x0
  size_t v7; // x0

  result = 1;
  if ( a2 )
  {
    v4 = *(_QWORD *)(a1 + 744);
    if ( v4 )
    {
      result = true;
      if ( (of_property_match_string(v4, "qcom,disabled-voters", a2) & 0x80000000) != 0 )
      {
        v6 = strlen(a2);
        if ( !strnstr(a2, "disp", v6) || (socinfo_get_part_info(4) & 1) == 0 )
        {
          v7 = strlen(a2);
          if ( !strnstr(a2, "cam", v7) || (socinfo_get_part_info(3) & 1) == 0 )
            return false;
        }
      }
    }
  }
  return result;
}
