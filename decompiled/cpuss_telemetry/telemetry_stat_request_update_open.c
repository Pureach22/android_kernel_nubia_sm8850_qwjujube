__int64 __fastcall telemetry_stat_request_update_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, 0, set_req_update, "%llu\n", a6);
}
