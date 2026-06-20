__int64 __fastcall dp_rx_fst_update_pm_suspend_status(__int64 result, char a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(result + 1480);
  if ( v2 )
    *(_DWORD *)(v2 + 612) = a2 & 1;
  return result;
}
