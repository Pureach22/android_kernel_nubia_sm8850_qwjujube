__int64 __fastcall dp_audio_put(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( result )
  {
    v1 = result;
    v2 = *(_QWORD *)(result - 160);
    if ( v2 )
      destroy_workqueue(v2);
    return devm_kfree(*(_QWORD *)(v1 - 344) + 16LL);
  }
  return result;
}
