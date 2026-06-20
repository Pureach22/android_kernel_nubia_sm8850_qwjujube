__int64 __fastcall qcom_dcvs_fp_probe(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w0
  int v5; // w8
  unsigned int inited; // w0
  unsigned int v7; // w21
  const char *v9; // x2
  const char *v10; // x1

  v1 = a1 + 16;
  mutex_lock(&ddrllcc_lock);
  if ( ddrllcc_data )
  {
    dev_err(v1, "Only one fast path client allowed\n");
    v7 = -22;
    goto LABEL_10;
  }
  v2 = (_QWORD *)devm_kmalloc(v1, 80, 3520);
  if ( !v2 )
  {
    v7 = -12;
    goto LABEL_10;
  }
  v3 = (__int64)v2;
  *v2 = v1;
  v4 = populate_bcm_data(v1, v2 + 3, "qcom,ddr-bcm-name");
  if ( (v4 & 0x80000000) != 0 )
  {
    v9 = "qcom,ddr-bcm-name";
LABEL_14:
    v7 = v4;
    dev_err(v1, "Error importing %s bcm data: %d\n", v9);
    goto LABEL_10;
  }
  v4 = populate_bcm_data(v1, v3 + 40, "qcom,llcc-bcm-name");
  if ( (v4 & 0x80000000) != 0 )
  {
    v9 = "qcom,llcc-bcm-name";
    goto LABEL_14;
  }
  *(_DWORD *)(v3 + 56) = *(_DWORD *)(v3 + 24);
  v5 = *(_DWORD *)(v3 + 40);
  *(_QWORD *)(v3 + 60) = 1610612736;
  *(_DWORD *)(v3 + 68) = v5;
  *(_QWORD *)(v3 + 72) = 1610612736;
  inited = rpmh_init_fast_path(v1, v3 + 56, 2);
  if ( (inited & 0x80000000) != 0 )
  {
    v10 = "Error initializing rpmh fast path: %d\n";
LABEL_17:
    v7 = inited;
    dev_err(v1, v10);
    goto LABEL_10;
  }
  inited = rpmh_write_async(v1, 0, v3 + 56, 2);
  if ( (inited & 0x80000000) != 0 )
  {
    v10 = "Error initing dcvs_fp sleep vote: %d\n";
    goto LABEL_17;
  }
  *(_DWORD *)(v3 + 60) = 1610612737;
  *(_DWORD *)(v3 + 72) = 1610612737;
  v7 = rpmh_write_async(v1, 1, v3 + 56, 2);
  if ( (v7 & 0x80000000) != 0 )
    dev_err(v1, "Error initing dcvs_fp wake vote: %d\n", v7);
  else
    ddrllcc_data = v3;
LABEL_10:
  mutex_unlock(&ddrllcc_lock);
  return v7;
}
