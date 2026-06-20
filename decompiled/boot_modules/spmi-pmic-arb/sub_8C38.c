__int64 sub_8C38()
{
  int v0; // w17

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0x18C8);
  return pmic_arb_apid_map_offset_v8();
}
