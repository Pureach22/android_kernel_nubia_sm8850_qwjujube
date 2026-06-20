__int64 init_module()
{
  return usb_function_register(&cserusb_func);
}
