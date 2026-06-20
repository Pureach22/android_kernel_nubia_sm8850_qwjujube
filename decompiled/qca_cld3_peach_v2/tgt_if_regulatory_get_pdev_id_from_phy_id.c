__int64 __fastcall tgt_if_regulatory_get_pdev_id_from_phy_id(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
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
  __int64 v13; // x9
  __int64 v14; // x9

  if ( a2 >= 3u )
  {
    v11 = "%s: phy_id is greater than PSOC_MAX_PHY_REG_CAP";
LABEL_3:
    qdf_trace_msg(0x49u, 2u, v11, a4, a5, a6, a7, a8, a9, a10, a11, "tgt_if_regulatory_get_pdev_id_from_phy_id");
    return 16;
  }
  v13 = *(_QWORD *)(a1 + 2800);
  *a3 = a2;
  if ( !v13 )
    return 0;
  v14 = v13 + 4096;
  if ( *(_BYTE *)(v14 + 1649) != 1 )
    return 0;
  if ( *(unsigned __int8 *)(v14 + 1648) != a2 )
  {
    v11 = "%s: pdev_id is greater than WLAN_UMAC_MAX_PDEVS";
    goto LABEL_3;
  }
  *a3 = 0;
  return 0;
}
