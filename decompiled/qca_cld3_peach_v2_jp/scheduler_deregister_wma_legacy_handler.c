__int64 __fastcall scheduler_deregister_wma_legacy_handler(__int64 a1)
{
  __int64 context; // x0
  __int64 v2; // x8

  context = scheduler_get_context(a1);
  if ( !context )
    return 16;
  v2 = context;
  *(_QWORD *)(v2 + 696) = 0;
  return 0;
}
