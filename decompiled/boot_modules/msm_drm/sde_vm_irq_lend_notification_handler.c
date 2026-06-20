__int64 __fastcall sde_vm_irq_lend_notification_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  if ( (_drm_debug & 4) != 0 )
    return printk(&unk_23723E, a3);
  else
    return printk(&unk_26EDEE, "sde_vm_irq_lend_notification_handler");
}
