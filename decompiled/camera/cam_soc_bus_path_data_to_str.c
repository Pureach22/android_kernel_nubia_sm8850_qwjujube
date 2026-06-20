const char *__fastcall cam_soc_bus_path_data_to_str(unsigned int a1)
{
  if ( a1 > 2 )
    return "BUS_PATH_INVALID";
  else
    return off_44BA00[a1];
}
