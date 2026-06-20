__int64 __fastcall uetm_remove(__int64 a1)
{
  return coresight_unregister(*(_QWORD *)(*(_QWORD *)(a1 + 168) + 8LL));
}
