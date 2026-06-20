__int64 __fastcall ccid_function_disable(__int64 a1)
{
  usb_ep_disable(*(_QWORD *)(a1 + 240));
  usb_ep_disable(*(_QWORD *)(a1 + 248));
  usb_ep_disable(*(_QWORD *)(a1 + 256));
  *(_DWORD *)(a1 + 696) = 0;
  *(_DWORD *)(a1 + 232) = 0;
  _wake_up(a1 + 504, 3, 1, 0);
  _wake_up(a1 + 480, 3, 1, 0);
  return _wake_up(a1 + 296, 3, 1, 0);
}
