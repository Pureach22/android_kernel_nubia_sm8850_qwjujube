__int64 __fastcall ipa_imm_cmd_modify_ip_packet_init_ex_dest_pipe(__int64 result, char a2)
{
  if ( *(_DWORD *)ipahal_ctx < 0x18u )
    *(_BYTE *)(result + 10) = a2;
  else
    *(_BYTE *)(result + 16) = a2;
  return result;
}
