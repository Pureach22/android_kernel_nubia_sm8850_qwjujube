__int64 __fastcall entry_dwc3_send_gadget_ep_cmd(__int64 a1, _DWORD *a2)
{
  if ( a2[2] == 8 )
    dwc3_msm_notify_event(*(__int64 **)(*(_QWORD *)a2 + 152LL), 7, *(unsigned __int8 *)(*(_QWORD *)a2 + 170LL));
  return 0;
}
