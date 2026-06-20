__int64 sub_8438()
{
  int v0; // w21

  if ( (v0 & 0x10000) != 0 )
    JUMPOUT(0x2F68);
  return spi_geni_unprepare_message();
}
