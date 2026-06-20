__int64 init_module()
{
  return usb_function_register(&ccidusb_func);
}
