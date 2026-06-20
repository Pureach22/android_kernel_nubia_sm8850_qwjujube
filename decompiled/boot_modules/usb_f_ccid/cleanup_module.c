__int64 cleanup_module()
{
  return usb_function_unregister(&ccidusb_func);
}
