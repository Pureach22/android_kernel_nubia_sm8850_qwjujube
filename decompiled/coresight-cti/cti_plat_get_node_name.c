const char *__fastcall cti_plat_get_node_name(unsigned __int64 a1)
{
  const char *result; // x0

  result = "unknown";
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && *(_UNKNOWN **)(a1 + 8) == &of_fwnode_ops )
  {
    if ( a1 == 24 )
      return "<no-node>";
    else
      return *(const char **)(a1 - 8);
  }
  return result;
}
