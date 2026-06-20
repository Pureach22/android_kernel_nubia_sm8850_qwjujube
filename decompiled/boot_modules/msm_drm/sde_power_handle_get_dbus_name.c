char *__fastcall sde_power_handle_get_dbus_name(unsigned int a1)
{
  if ( a1 > 3 )
    return nullptr;
  else
    return data_bus_name[a1];
}
