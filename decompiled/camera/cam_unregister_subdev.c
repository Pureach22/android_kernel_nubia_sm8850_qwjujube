__int64 __fastcall cam_unregister_subdev(__int64 a1)
{
  if ( (byte_2FDA98 & 1) != 0 )
  {
    mutex_lock(&unk_2FDA68);
    v4l2_device_unregister_subdev(a1 + 8);
    --dword_2FDA60;
    mutex_unlock(&unk_2FDA68);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_unregister_subdev",
      1017,
      "camera root device not ready yet");
    return 4294967277LL;
  }
}
