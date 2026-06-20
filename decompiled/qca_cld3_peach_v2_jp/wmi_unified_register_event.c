__int64 __fastcall wmi_unified_register_event(__int64 a1, __int64 a2, __int64 a3)
{
  return wmi_register_event_handler_with_ctx(a1, a2, a3, 1, 0);
}
