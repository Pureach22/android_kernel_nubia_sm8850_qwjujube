__int64 init_module()
{
  unsigned int v0; // w19

  v0 = bus_register(&soundwire_type);
  if ( v0 || (v0 = device_register(&soundwire_dev)) != 0 )
    bus_unregister(&soundwire_type);
  return v0;
}
