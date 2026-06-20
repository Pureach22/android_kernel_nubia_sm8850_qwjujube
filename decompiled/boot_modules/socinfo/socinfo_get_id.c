__int64 socinfo_get_id()
{
  if ( socinfo )
    return *(unsigned int *)(socinfo + 4);
  else
    return 0;
}
