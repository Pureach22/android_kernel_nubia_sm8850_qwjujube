void __fastcall panel_event_notifier_callback(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v4; // w0
  int v6; // w0

  if ( a2 )
  {
    if ( *a2 == 2 )
    {
      if ( *(_BYTE *)(a3 + 228) == 1 )
      {
        v6 = amoled_ecm_enable((_QWORD *)a3);
        if ( v6 < 0 )
          dev_err(*(_QWORD *)(a3 + 8), "Failed to re-enable ECM for display UNBLANK, rc=%d\n", v6);
        else
          *(_BYTE *)(a3 + 228) = 0;
      }
    }
    else if ( *a2 == 1 && *(_BYTE *)(a3 + 226) == 1 )
    {
      v4 = amoled_ecm_disable((_QWORD *)a3);
      if ( v4 < 0 )
        dev_err(*(_QWORD *)(a3 + 8), "Failed to disable ECM for display BLANK, rc=%d\n", v4);
      else
        *(_BYTE *)(a3 + 228) = 1;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a3 + 8), "Invalid panel notification\n");
  }
}
