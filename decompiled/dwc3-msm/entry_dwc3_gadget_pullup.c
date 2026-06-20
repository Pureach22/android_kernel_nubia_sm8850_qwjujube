__int64 __fastcall entry_dwc3_gadget_pullup(__int64 a1, _DWORD *a2)
{
  __int64 *v3; // x8
  unsigned int v4; // w2

  v3 = *(__int64 **)(*(_QWORD *)a2 + 248LL);
  *(_QWORD *)(a1 + 48) = v3;
  v4 = a2[2];
  *(_DWORD *)(a1 + 56) = v4;
  dwc3_msm_notify_event(v3, 8, v4);
  if ( *(_DWORD *)(a1 + 56) )
    dwc3_msm_notify_event(*(__int64 **)(a1 + 48), 16, 0);
  return 0;
}
