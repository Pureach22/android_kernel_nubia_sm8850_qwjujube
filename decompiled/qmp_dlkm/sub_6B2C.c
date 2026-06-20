__int64 sub_6B2C()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0x838);
  return qmp_dmic_component_remove();
}
