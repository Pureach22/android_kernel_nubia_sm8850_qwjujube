__int64 init_module()
{
  unsigned int v0; // w0
  unsigned int v1; // w19

  v0 = bus_register(&gprbus);
  if ( v0 )
  {
    v1 = v0;
    bus_unregister(&gprbus);
  }
  else
  {
    return (unsigned int)_register_rpmsg_driver(&gpr_driver, &_this_module);
  }
  return v1;
}
