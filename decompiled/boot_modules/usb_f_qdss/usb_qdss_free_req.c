__int64 __fastcall usb_qdss_free_req(__int64 a1)
{
  if ( !a1 )
    return printk(&unk_81A4, "usb_qdss_free_req");
  mutex_lock(a1 + 176);
  if ( (*(_BYTE *)(a1 + 224) & 1) != 0 )
    qdss_free_reqs(a1 - 296);
  else
    printk(&unk_8283, "usb_qdss_free_req");
  return mutex_unlock(a1 + 176);
}
