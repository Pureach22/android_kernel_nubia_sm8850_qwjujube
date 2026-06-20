__int64 __fastcall sde_cp_ad_interrupt_cb(__int64 a1)
{
  return ((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(), _QWORD, __int64))sde_crtc_event_queue)(
           a1,
           sde_cp_notify_ad_event,
           0,
           1);
}
