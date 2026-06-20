bool __fastcall wlan_pmo_enable_ssr_on_page_fault(__int64 a1)
{
  return (unsigned int)pmo_host_action_on_page_fault(a1) == 1;
}
