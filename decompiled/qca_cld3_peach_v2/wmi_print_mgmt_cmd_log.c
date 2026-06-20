__int64 __fastcall wmi_print_mgmt_cmd_log(
        __int64 a1,
        unsigned int a2,
        __int64 (__fastcall *a3)(__int64, const char *),
        __int64 a4)
{
  return wmi_print_cmd_log_buffer(a1 + 536, a2, a3, a4);
}
