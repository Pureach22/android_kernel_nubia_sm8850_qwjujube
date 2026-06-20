__int64 cleanup_module()
{
  return class_unregister(&hwmon_class);
}
