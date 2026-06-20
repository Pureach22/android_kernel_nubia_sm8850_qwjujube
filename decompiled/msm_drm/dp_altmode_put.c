__int64 __fastcall dp_altmode_put(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  if ( result )
  {
    v1 = result - 24;
    v2 = result;
    altmode_deregister_client(*(_QWORD *)(result + 72));
    altmode_deregister_notifier(*(_QWORD *)(v2 - 16), v1);
    return kfree(v1);
  }
  return result;
}
