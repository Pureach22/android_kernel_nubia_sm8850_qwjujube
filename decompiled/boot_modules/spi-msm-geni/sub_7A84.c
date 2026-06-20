__int64 sub_7A84()
{
  int v0; // w21

  if ( (v0 & 0x10000) != 0 )
    JUMPOUT(0x25B4);
  return spi_geni_prepare_message();
}
