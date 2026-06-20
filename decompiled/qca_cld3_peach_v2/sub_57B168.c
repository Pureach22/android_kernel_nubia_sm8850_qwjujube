__int64 sub_57B168()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return hal_get_tlv_hdr_size_be();
}
