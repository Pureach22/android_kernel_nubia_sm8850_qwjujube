__int64 __fastcall exit_dwc3_gadget_pullup(__int64 a1)
{
  dwc3_msm_notify_event(*(__int64 **)(a1 + 48), 9, *(_DWORD *)(a1 + 56));
  return 0;
}
