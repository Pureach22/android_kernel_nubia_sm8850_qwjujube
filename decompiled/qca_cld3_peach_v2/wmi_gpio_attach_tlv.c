__int64 __fastcall wmi_gpio_attach_tlv(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 728);
  *(_QWORD *)(v1 + 2456) = send_gpio_config_cmd_tlv;
  *(_QWORD *)(v1 + 2464) = send_gpio_output_cmd_tlv;
  return result;
}
