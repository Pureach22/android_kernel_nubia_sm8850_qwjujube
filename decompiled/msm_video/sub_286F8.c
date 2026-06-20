__int64 sub_286F8()
{
  int v0; // w27

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0x2130C);
  return msm_vidc_get_cap_id();
}
