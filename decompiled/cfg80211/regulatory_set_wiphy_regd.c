__int64 regulatory_set_wiphy_regd()
{
  __int64 result; // x0

  result = _regulatory_set_wiphy_regd();
  if ( !(_DWORD)result )
  {
    queue_work_on(32, system_wq, &reg_work);
    return 0;
  }
  return result;
}
