__int64 fastrpc_transport_init()
{
  unsigned int v0; // w0
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  unsigned int v7; // w19

  v0 = _register_rpmsg_driver(&fastrpc_driver, &_this_module);
  if ( (v0 & 0x80000000) == 0 )
    return 0;
  v7 = v0;
  printk(&unk_23DE2, v1, v2, v3, v4, v5);
  return v7;
}
