__int64 __fastcall cds_deregister_all_modules(__int64 a1)
{
  __int64 v1; // x0

  v1 = scheduler_deregister_wma_legacy_handler(a1);
  scheduler_deregister_sys_legacy_handler(v1);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(21);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(55);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(73);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(53);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(52);
  return ((__int64 (__fastcall *)(__int64))scheduler_deregister_module)(72);
}
