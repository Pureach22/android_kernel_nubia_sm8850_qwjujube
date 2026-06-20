__int64 __fastcall sde_hdcp_1x_abort(__int64 a1, char a2)
{
  __int64 result; // x0

  *(_DWORD *)(a1 + 36) = a2 & 1;
  cancel_delayed_work_sync(a1 + 704);
  result = _flush_workqueue(*(_QWORD *)(a1 + 1432));
  if ( *(_DWORD *)(a1 + 40) == 1 )
    *(_DWORD *)(a1 + 40) = 3;
  return result;
}
