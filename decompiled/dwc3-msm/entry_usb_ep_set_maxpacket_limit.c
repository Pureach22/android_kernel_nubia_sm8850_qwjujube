__int64 __fastcall entry_usb_ep_set_maxpacket_limit(__int64 a1, __int64 *a2)
{
  __int64 v2; // x9

  v2 = *a2;
  *(_QWORD *)(a1 + 48) = *(_QWORD *)(*a2 + 152);
  *(_DWORD *)(a1 + 56) = *(unsigned __int8 *)(v2 + 170);
  return 0;
}
