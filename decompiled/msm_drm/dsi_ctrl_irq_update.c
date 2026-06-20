__int64 __fastcall dsi_ctrl_irq_update(__int64 result, char a2)
{
  int *v2; // x19

  if ( result )
  {
    v2 = (int *)result;
    mutex_lock(result + 32);
    if ( (a2 & 1) != 0 )
      dsi_ctrl_enable_status_interrupt(v2, 0xAu, nullptr);
    else
      dsi_ctrl_disable_status_interrupt(v2, 0xAu);
    return mutex_unlock(v2 + 8);
  }
  return result;
}
