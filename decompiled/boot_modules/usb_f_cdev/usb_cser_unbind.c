__int64 __fastcall usb_cser_unbind(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v4; // x20
  __int64 v5; // x19

  if ( *(_BYTE *)(a2 + 360) == 1 )
  {
    usb_cser_disconnect(a2 - 1200);
    usb_ep_disable(*(_QWORD *)(a2 + 240));
    **(_QWORD **)(a2 + 240) = 0;
  }
  cser_string_defs = 0;
  result = usb_free_all_descriptors(a2);
  v4 = *(_QWORD **)(a2 + 248);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a2 + 240);
    kfree(*v4);
    return usb_ep_free_request(v5, v4);
  }
  return result;
}
