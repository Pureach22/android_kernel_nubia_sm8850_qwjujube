__int64 __fastcall qdf_iommu_domain_get_attr(__int64 a1, int a2, _DWORD *a3)
{
  int v4; // w20
  int mappings_configuration; // w0
  int v6; // w8

  switch ( a2 )
  {
    case 10:
      v4 = 1;
      mappings_configuration = qcom_iommu_get_mappings_configuration();
      if ( (mappings_configuration & 0x80000000) == 0 )
        goto LABEL_7;
      break;
    case 13:
      v4 = 4;
      mappings_configuration = qcom_iommu_get_mappings_configuration();
      if ( (mappings_configuration & 0x80000000) == 0 )
        goto LABEL_7;
      break;
    case 11:
      v4 = 2;
      mappings_configuration = qcom_iommu_get_mappings_configuration();
      if ( mappings_configuration < 0 )
        return 4294967274LL;
LABEL_7:
      v6 = mappings_configuration;
      *a3 = (v6 & v4) != 0;
      return 0;
    default:
      return 4294967274LL;
  }
  return 4294967274LL;
}
