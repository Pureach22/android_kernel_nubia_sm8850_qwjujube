__int64 __fastcall dsi_display_pre_release(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x9

  if ( !a1 )
    return 4294967274LL;
  mutex_lock(a1 + 72);
  *(_BYTE *)(a1 + 1642) = 0;
  mutex_unlock(a1 + 72);
  v2 = *(_DWORD *)(a1 + 160);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 + 168);
    if ( v3 && *(_BYTE *)(v3 + 2848) == 1 )
    {
      _flush_workqueue(*(_QWORD *)(a1 + 1624));
      cancel_work_sync(*(_QWORD *)(a1 + 168) + 2808LL);
      *(_BYTE *)(*(_QWORD *)(a1 + 168) + 2848LL) = 0;
      v2 = *(_DWORD *)(a1 + 160);
    }
    if ( v2 >= 2 )
    {
      v4 = *(_QWORD *)(a1 + 216);
      if ( v4 )
      {
        if ( *(_BYTE *)(v4 + 2848) == 1 )
        {
          _flush_workqueue(*(_QWORD *)(a1 + 1624));
          cancel_work_sync(*(_QWORD *)(a1 + 216) + 2808LL);
          *(_BYTE *)(*(_QWORD *)(a1 + 216) + 2848LL) = 0;
          v2 = *(_DWORD *)(a1 + 160);
        }
      }
    }
    if ( v2 )
    {
      if ( a1 != -168 )
      {
        dsi_ctrl_irq_update(*(_QWORD *)(a1 + 168), 0);
        v2 = *(_DWORD *)(a1 + 160);
      }
      if ( v2 >= 2 && a1 != -216 )
        dsi_ctrl_irq_update(*(_QWORD *)(a1 + 216), 0);
    }
  }
  return 0;
}
