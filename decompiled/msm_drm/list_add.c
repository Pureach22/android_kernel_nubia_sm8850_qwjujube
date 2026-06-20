_UNKNOWN **__fastcall list_add(_UNKNOWN **result)
{
  void *v1; // x2

  v1 = dsi_phy_list;
  if ( dsi_phy_list == (_UNKNOWN *)result
    || result == &dsi_phy_list
    || *((_QWORD *)dsi_phy_list + 1) != (_QWORD)&dsi_phy_list )
  {
    return (_UNKNOWN **)_list_add_valid_or_report(result, &dsi_phy_list);
  }
  *((_QWORD *)dsi_phy_list + 1) = result;
  *result = v1;
  result[1] = &dsi_phy_list;
  dsi_phy_list = result;
  return result;
}
