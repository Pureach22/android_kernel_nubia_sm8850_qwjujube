__int64 mlo_ap_link_sync_wait_notify()
{
  return mlo_handle_link_ready() & 1;
}
