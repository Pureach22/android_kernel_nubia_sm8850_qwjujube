__int64 cds_is_driver_recovering()
{
  return ((unsigned int)cds_get_driver_state() >> 3) & 1;
}
