__int64 __fastcall sde_vm_mem_release_notification_handler(unsigned int a1)
{
  if ( (_drm_debug & 4) != 0 )
    return printk(&unk_275C33, a1);
  else
    return printk(&unk_2306B7, "sde_vm_mem_release_notification_handler");
}
