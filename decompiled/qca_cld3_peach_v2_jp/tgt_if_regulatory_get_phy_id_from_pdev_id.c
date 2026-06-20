__int64 __fastcall tgt_if_regulatory_get_phy_id_from_pdev_id(
        __int64 a1,
        char a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v11; // x2
  __int64 v13; // x8
  __int64 v14; // x8
  unsigned int v15; // w8

  if ( a2 )
  {
    v11 = "%s: pdev_id is greater than WLAN_UMAC_MAX_PDEVS";
LABEL_3:
    qdf_trace_msg(0x49u, 2u, v11, a4, a5, a6, a7, a8, a9, a10, a11, "tgt_if_regulatory_get_phy_id_from_pdev_id");
    return 16;
  }
  v13 = *(_QWORD *)(a1 + 2800);
  *a3 = 0;
  if ( !v13 )
    return 0;
  v14 = v13 + 4096;
  if ( *(_BYTE *)(v14 + 369) != 1 )
    return 0;
  v15 = *(unsigned __int8 *)(v14 + 368);
  if ( v15 > 2 )
  {
    v11 = "%s: phy_id is greater than PSOC_MAX_PHY_REG_CAP";
    goto LABEL_3;
  }
  *a3 = v15;
  return 0;
}
