__int64 __fastcall mhi_status_cb(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x0

  if ( a2 == 9 )
  {
    v2 = *(_QWORD *)(result + 192);
    v3 = result;
    v4 = raw_spin_lock_irqsave(v2 + 232);
    *(_DWORD *)(v2 + 344) = *(_DWORD *)(v3 + 976);
    raw_spin_unlock_irqrestore(v2 + 232, v4);
    return _wake_up(v2 + 208, 3, 1, 0);
  }
  return result;
}
