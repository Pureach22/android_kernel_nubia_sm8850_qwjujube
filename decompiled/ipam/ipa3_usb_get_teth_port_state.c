bool ipa3_usb_get_teth_port_state()
{
  return ipa3_usb_ctx && *(_DWORD *)(ipa3_usb_ctx + 656) == 2;
}
