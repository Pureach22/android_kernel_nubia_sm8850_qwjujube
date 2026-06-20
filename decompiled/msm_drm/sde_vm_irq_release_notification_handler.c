__int64 __fastcall sde_vm_irq_release_notification_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  if ( a1 )
  {
    sde_crtc_vm_reclaim_notify(*(_QWORD *)(a1 + 264));
    if ( (_drm_debug & 4) == 0 )
      return printk(&unk_26ED8B, "sde_vm_irq_release_notification_handler");
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "unable to send reclaim notification to userspace: null sde_vm pointer");
    if ( (_drm_debug & 4) == 0 )
      return printk(&unk_26ED8B, "sde_vm_irq_release_notification_handler");
  }
  return printk(&unk_26B28A, a3);
}
