const char *__fastcall cm_roam_get_requestor_string(int a1)
{
  bool v2; // cc
  const char *result; // x0

  v2 = a1 <= 7;
  result = "No requestor";
  if ( v2 )
  {
    switch ( a1 )
    {
      case 1:
        return "SAP start";
      case 2:
        return "CSA";
      case 4:
        return "STA connection";
    }
  }
  else if ( a1 > 31 )
  {
    if ( a1 == 32 )
    {
      return "Set PCL";
    }
    else if ( a1 == 64 )
    {
      return "Set Link";
    }
  }
  else if ( a1 == 8 )
  {
    return "SAP Ch switch";
  }
  else if ( a1 == 16 )
  {
    return "NDP connection";
  }
  return result;
}
