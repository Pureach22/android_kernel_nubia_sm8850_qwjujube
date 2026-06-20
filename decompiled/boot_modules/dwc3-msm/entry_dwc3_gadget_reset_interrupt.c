__int64 __fastcall entry_dwc3_gadget_reset_interrupt(__int64 a1, __int64 *a2)
{
  __int64 *v2; // x19

  v2 = (__int64 *)*a2;
  dwc3_core_stop_hw_active_transfers(*a2);
  dwc3_msm_notify_event(v2, 15, 0);
  return 0;
}
