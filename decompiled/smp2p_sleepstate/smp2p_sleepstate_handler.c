__int64 smp2p_sleepstate_handler()
{
  pm_wakeup_ws_event(notify_ws, 200, 0);
  return 1;
}
