__int64 socinfo_get_package_type()
{
  if ( socinfo )
    return *(unsigned int *)(socinfo + 216);
  else
    return 0;
}
