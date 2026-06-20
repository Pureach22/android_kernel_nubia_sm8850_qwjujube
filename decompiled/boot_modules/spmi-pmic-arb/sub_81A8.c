__int64 sub_81A8()
{
  int v0; // w17

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0xE38);
  return pmic_arb_apid_map_offset_v5();
}
