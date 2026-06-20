__int64 __fastcall etm_event_destroy(__int64 a1)
{
  __int64 result; // x0

  result = kfree(*(_QWORD *)(a1 + 464));
  *(_QWORD *)(a1 + 464) = 0;
  return result;
}
