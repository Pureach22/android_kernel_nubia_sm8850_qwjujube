__int64 sub_23967C()
{
  __int64 v0; // x24

  if ( (v0 & 0x400000000LL) != 0 )
    JUMPOUT(0x23C928);
  return wmi_unified_update_edca_pifs_param();
}
