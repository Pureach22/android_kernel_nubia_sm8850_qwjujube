__int64 fastrpc_transport_deinit()
{
  return unregister_rpmsg_driver(&fastrpc_driver);
}
