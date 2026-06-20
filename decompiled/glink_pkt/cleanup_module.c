__int64 cleanup_module()
{
  class_destroy(glink_pkt_class);
  unregister_chrdev_region((unsigned int)glink_pkt_major >> 20, (unsigned int)num_glink_pkt_devs);
  return platform_driver_unregister(&glink_pkt_driver);
}
