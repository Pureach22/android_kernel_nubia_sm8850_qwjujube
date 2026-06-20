__int64 cleanup_module()
{
  return usb_function_unregister(&cserusb_func);
}
