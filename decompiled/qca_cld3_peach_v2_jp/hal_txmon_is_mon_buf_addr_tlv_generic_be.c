bool __fastcall hal_txmon_is_mon_buf_addr_tlv_generic_be(_DWORD *a1)
{
  return (*a1 & 0x3FE) == 884;
}
