__int64 __fastcall cam_icp_dev_mini_dump_cb(const void *a1, const void *a2)
{
  if ( a1 && a2 )
    return cam_context_mini_dump_from_hw((__int64)a1);
  else
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_dev_mini_dump_cb",
             151,
             "Invalid params: priv: %pK args %pK",
             a1,
             a2);
}
