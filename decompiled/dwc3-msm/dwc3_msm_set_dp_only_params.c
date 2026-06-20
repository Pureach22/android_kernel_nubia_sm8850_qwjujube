__int64 __fastcall dwc3_msm_set_dp_only_params(__int64 a1)
{
  __int64 v2; // x9
  unsigned int v3; // w8
  unsigned int *v4; // x9
  __int64 v5; // x8

  usb_redriver_release_lanes(*(_QWORD *)(a1 + 464), ((*(_DWORD *)(a1 + 1240) >> 2) & 1) == 0, 4);
  v2 = *(_QWORD *)(a1 + 40);
  v3 = *(_DWORD *)(a1 + 1132);
  *(_BYTE *)(a1 + 1232) = 1;
  if ( v2 )
    v4 = (unsigned int *)(*(_QWORD *)(v2 + 168) + 1232LL);
  else
    v4 = (unsigned int *)(a1 + 1128);
  if ( v3 >= 3 )
    v3 = 3;
  *v4 = v3;
  v5 = *(_QWORD *)(a1 + 456);
  if ( v5 )
    *(_DWORD *)(v5 + 16) |= 0x200u;
  return phy_set_mode_ext(*(_QWORD *)(a1 + 480), 0, 4);
}
