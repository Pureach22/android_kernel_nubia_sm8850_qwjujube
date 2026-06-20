__int64 richtap_file_release()
{
  module_put(&_this_module);
  return 0;
}
