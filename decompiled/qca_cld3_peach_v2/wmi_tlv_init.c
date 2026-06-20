__int64 wmi_tlv_init()
{
  return wmi_unified_register_module(0, (__int64)wmi_tlv_attach);
}
