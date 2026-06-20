__int64 __fastcall sde_vm_mem_lend_notification_handler(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  if ( !(_DWORD)result && a2 == 1360003089 && a3 && a4 && *(_BYTE *)(a4 + 5) == 1 && *(_DWORD *)(a4 + 12) == 17 )
  {
    mutex_lock(a3);
    *(_DWORD *)(a3 + 60) = *(_DWORD *)a4;
    mutex_unlock(a3);
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_244B90, 0);
    else
      return printk(&unk_23DFEA, "sde_vm_mem_lend_notification_handler");
  }
  return result;
}
