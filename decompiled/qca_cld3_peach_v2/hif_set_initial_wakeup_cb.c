__int64 __fastcall hif_set_initial_wakeup_cb(__int64 result, __int64 a2, __int64 a3)
{
  *(_QWORD *)(result + 2584) = a2;
  *(_QWORD *)(result + 2592) = a3;
  return result;
}
