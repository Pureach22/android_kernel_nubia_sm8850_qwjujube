__int64 __fastcall hif_recovery_notifier_cb(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 result; // x0
  _DWORD *v5; // x19
  int *v7; // x20

  result = 4294967274LL;
  if ( a1 && a3 )
  {
    v5 = *(_DWORD **)(a1 + 24);
    if ( v5 )
    {
      v7 = (int *)(a3 + 1);
      if ( (hif_log_bus_info(*(_QWORD *)(a1 + 24)) & 1) != 0 )
      {
        return 0x8000;
      }
      else
      {
        hif_log_ce_info(v5, *a3, v7);
        return 0;
      }
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
