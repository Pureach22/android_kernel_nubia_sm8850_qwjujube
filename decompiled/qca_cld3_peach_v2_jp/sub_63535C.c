__int64 __fastcall sub_63535C(double a1, double a2, double _D2)
{
  __asm { STTR            D2, [X6,#0x8C] }
  return send_coap_add_keepalive_pattern_cmd_tlv();
}
