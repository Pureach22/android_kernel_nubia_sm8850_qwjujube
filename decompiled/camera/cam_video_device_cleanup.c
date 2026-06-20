__int64 cam_video_device_cleanup()
{
  __int64 result; // x0

  video_unregister_device(g_dev);
  result = video_device_release(g_dev);
  g_dev = 0;
  return result;
}
