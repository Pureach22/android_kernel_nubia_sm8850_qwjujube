__int64 __fastcall cam_jpeg_dev_mini_dump_cb(const void *a1, const void *a2)
{
  if ( a1 && a2 )
    return cam_context_mini_dump_from_hw((__int64)a1);
  else
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_dev_mini_dump_cb",
             85,
             "Invalid param priv %pK %pK args",
             a1,
             a2);
}
