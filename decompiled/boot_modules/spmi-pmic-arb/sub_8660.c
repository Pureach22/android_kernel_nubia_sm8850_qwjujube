__int64 sub_8660()
{
  int v0; // w17

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0x12F0);
  return pmic_arb_apid_map_offset_v7();
}
