__int64 socinfo_get_serial_number()
{
  if ( socinfo )
    return *(unsigned int *)(socinfo + 96);
  else
    return 0;
}
