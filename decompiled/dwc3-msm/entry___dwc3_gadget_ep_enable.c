__int64 __fastcall entry___dwc3_gadget_ep_enable(__int64 a1, _DWORD *a2)
{
  if ( a2[2] == 0x80000000 && *(_BYTE *)(*(_QWORD *)a2 + 170LL) == 1 )
    dwc3_msm_notify_event(*(__int64 **)(*(_QWORD *)a2 + 152LL), 5, 0);
  return 0;
}
