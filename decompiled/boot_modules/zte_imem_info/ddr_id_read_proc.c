__int64 __fastcall ddr_id_read_proc(__int64 a1)
{
  __int64 compatible_node; // x0
  __int64 v3; // x2
  void *v4; // x0
  unsigned int *v5; // x0
  const char *v6; // x20
  __int64 v7; // x0
  __int64 v8; // x2
  void *v9; // x0
  unsigned int *v10; // x0
  const char *v11; // x21
  __int64 v12; // x0
  __int64 v13; // x2
  void *v14; // x0
  unsigned int *v15; // x0
  int v16; // w3
  int v17; // w20
  int v18; // w8
  unsigned int v19; // w21
  int v20; // w22

  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-ddr_memory_manufacture");
  if ( !compatible_node )
  {
    v4 = &unk_6864;
    goto LABEL_5;
  }
  v5 = (unsigned int *)of_iomap(compatible_node, 0);
  vendor_imem_info_addr = (__int64)v5;
  if ( !v5 )
  {
    v4 = &unk_67F5;
LABEL_5:
    printk(v4, "qcom,msm-imem-ddr_memory_manufacture", v3);
LABEL_6:
    v6 = "UNKNOWN";
    goto LABEL_7;
  }
  v17 = *v5;
  printk(&unk_67E5, "qcom,msm-imem-ddr_memory_manufacture", *v5);
  v18 = v17 - 1;
  v6 = "SAMSUNG";
  switch ( v18 )
  {
    case 0:
      break;
    case 1:
      v6 = "QIMONDA";
      break;
    case 2:
      v6 = "ELPIDA";
      break;
    case 3:
      v6 = "ETRON";
      break;
    case 4:
      v6 = "NANYA";
      break;
    case 5:
      v6 = "HYNIX";
      break;
    case 6:
      v6 = "MOSEL";
      break;
    case 7:
      v6 = "WINBOND";
      break;
    case 8:
      v6 = "ESMT";
      break;
    case 9:
      goto LABEL_6;
    case 10:
      v6 = "SPANSION";
      break;
    case 11:
      v6 = (const char *)&unk_67F1;
      break;
    case 12:
      v6 = "ZMOS";
      break;
    case 13:
      v6 = "INTEL";
      break;
    default:
      if ( (unsigned int)"SAMSUNG" == 254 )
      {
        v6 = "NUMONYX";
      }
      else
      {
        if ( (unsigned int)"SAMSUNG" != 255 )
          goto LABEL_6;
        v6 = "MICRON";
      }
      break;
  }
LABEL_7:
  v7 = of_find_compatible_node(0, 0, "qcom,msm-imem-ddr_memory_type");
  if ( !v7 )
  {
    v9 = &unk_6864;
LABEL_11:
    printk(v9, "qcom,msm-imem-ddr_memory_type", v8);
LABEL_12:
    v11 = "UNKNOWN";
    goto LABEL_13;
  }
  v10 = (unsigned int *)of_iomap(v7, 0);
  vendor_imem_info_addr = (__int64)v10;
  if ( !v10 )
  {
    v9 = &unk_67F5;
    goto LABEL_11;
  }
  v19 = *v10;
  printk(&unk_67E5, "qcom,msm-imem-ddr_memory_type", *v10);
  if ( v19 >= 0xA )
    goto LABEL_12;
  v11 = off_6650[v19];
LABEL_13:
  v12 = of_find_compatible_node(0, 0, "qcom,msm-imem-ddr_memory_size");
  if ( v12 )
  {
    v15 = (unsigned int *)of_iomap(v12, 0);
    vendor_imem_info_addr = (__int64)v15;
    if ( v15 )
    {
      v20 = *v15;
      printk(&unk_67E5, "qcom,msm-imem-ddr_memory_size", *v15);
      v16 = v20 / 1024;
      goto LABEL_23;
    }
    v14 = &unk_67F5;
  }
  else
  {
    v14 = &unk_6864;
  }
  printk(v14, "qcom,msm-imem-ddr_memory_size", v13);
  v16 = 0;
LABEL_23:
  seq_printf(a1, "%s-NA-NA-%dGB-%s\n", v6, v16, v11);
  return 0;
}
