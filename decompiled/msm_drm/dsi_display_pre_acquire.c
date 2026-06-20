__int64 __fastcall dsi_display_pre_acquire(__int64 a1)
{
  unsigned int v2; // w8

  if ( !a1 )
    return 4294967274LL;
  mutex_lock(a1 + 72);
  *(_BYTE *)(a1 + 1642) = 1;
  mutex_unlock(a1 + 72);
  v2 = *(_DWORD *)(a1 + 160);
  if ( v2 )
  {
    if ( a1 != -168 )
    {
      dsi_ctrl_irq_update(*(_QWORD *)(a1 + 168), 1);
      v2 = *(_DWORD *)(a1 + 160);
    }
    if ( v2 >= 2 && a1 != -216 )
      dsi_ctrl_irq_update(*(_QWORD *)(a1 + 216), 1);
  }
  return 0;
}
