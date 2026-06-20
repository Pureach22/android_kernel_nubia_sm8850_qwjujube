__int64 __fastcall sub_4E558(__int64 a1, __int64 a2)
{
  int v2; // w22

  if ( (v2 & 0x2000000) != 0 )
    JUMPOUT(0x4D128);
  return msm_vidc_debugfs_init_inst(a1, a2);
}
