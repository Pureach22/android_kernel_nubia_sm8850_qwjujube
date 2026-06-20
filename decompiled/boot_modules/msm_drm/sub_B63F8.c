__int64 sub_B63F8()
{
  __asm { PRFM            #0x17, [X19,#0x36C8] }
  return hfi_util_u32_prop_helper_get_payload_addr();
}
