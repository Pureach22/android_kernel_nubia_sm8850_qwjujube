__int64 __fastcall usb_cser_disable(__int64 a1)
{
  __int64 result; // x0

  usb_cser_disconnect(a1 - 1200);
  result = usb_ep_disable(*(_QWORD *)(a1 + 240));
  **(_QWORD **)(a1 + 240) = 0;
  return result;
}
