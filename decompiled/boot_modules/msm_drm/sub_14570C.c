__int64 __fastcall sub_14570C(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w27

  if ( (v3 & 0x20000000) != 0 )
    JUMPOUT(0x14D6EC);
  return msm_dss_ioremap_byname(a1, a2, a3);
}
