__int64 sub_7A24()
{
  int v0; // w17

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0x6B4);
  return pmic_arb_apid_map_offset_v2();
}
