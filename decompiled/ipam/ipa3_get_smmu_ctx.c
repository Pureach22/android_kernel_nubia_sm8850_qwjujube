char *__fastcall ipa3_get_smmu_ctx(
        unsigned int a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        float a6)
{
  short float v6; // h8
  short float v7; // h12

  if ( a1 < 8 )
    return &smmu_cb[56 * a1];
  __break(0x5512u);
  *(short float *)&a6 = -(short float)(v7 + (short float)(v6 * *(short float *)&a6));
  return (char *)ipa3_send_macsec_info(a2, a3, a4, a5, a6);
}
