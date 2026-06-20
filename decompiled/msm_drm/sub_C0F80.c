__int64 sub_C0F80()
{
  int v0; // w17

  if ( (v0 & 0x40000000) != 0 )
    JUMPOUT(0xBBB4C);
  return dsi_hfi_process_misr_read();
}
