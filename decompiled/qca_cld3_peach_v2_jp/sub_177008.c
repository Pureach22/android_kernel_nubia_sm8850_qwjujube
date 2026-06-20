__int64 __fastcall sub_177008(__int64 a1, __int64 a2)
{
  __int64 v2; // x22

  *(_QWORD *)(a2 + 312) = 0;
  *(_QWORD *)(a2 + 320) = v2;
  return _qdf_delayed_work_stop_sync();
}
