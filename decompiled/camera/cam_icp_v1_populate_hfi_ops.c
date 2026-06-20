_QWORD *__fastcall cam_icp_v1_populate_hfi_ops(_QWORD *result)
{
  if ( !result )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_v1_populate_hfi_ops",
                       564,
                       "Invalid hfi ops argument");
  *result = hfi_icp_v1_ops;
  return result;
}
