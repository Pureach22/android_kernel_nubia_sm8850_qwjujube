__int64 __fastcall scheduler_register_sys_legacy_handler(__int64 a1)
{
  __int64 context; // x0
  __int64 v3; // x8

  context = scheduler_get_context(a1);
  if ( !context )
    return 16;
  v3 = context;
  *(_QWORD *)(v3 + 704) = a1;
  return 0;
}
