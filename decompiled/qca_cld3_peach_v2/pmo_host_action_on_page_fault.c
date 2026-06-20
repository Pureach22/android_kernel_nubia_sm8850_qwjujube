__int64 __fastcall pmo_host_action_on_page_fault(__int64 a1)
{
  __int64 result; // x0

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( result )
    return *(unsigned int *)(result + 100);
  return result;
}
