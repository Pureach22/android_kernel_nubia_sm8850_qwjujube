__int64 __fastcall tpd_test_cmd_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned int v4; // w0
  unsigned int v5; // w20
  void *v6; // x0
  __int64 v7; // x2
  unsigned int v9; // w0

  v3 = *(_QWORD *)(a1 + 3072);
  if ( *(_DWORD *)(v3 + 1404) == 1 )
  {
    printk(unk_34878, "tpd_test_cmd_store", a3);
    v4 = syna_testing_pt01_zte((__int64 *)v3);
    if ( (v4 & 0x80000000) != 0 )
    {
      v5 = v4;
      v6 = unk_3458E;
    }
    else
    {
      v9 = syna_testing_pt05_zte((_BYTE *)v3);
      if ( (v9 & 0x80000000) != 0 )
      {
        v5 = v9;
        v6 = unk_3C89A;
      }
      else
      {
        v5 = syna_testing_pt0a_zte((_BYTE *)v3);
        if ( (v5 & 0x80000000) == 0 )
          goto LABEL_6;
        v6 = unk_3A6C6;
      }
    }
  }
  else
  {
    v5 = 0;
    v6 = unk_3B5E0;
  }
  printk(v6, "tpd_test_cmd_store", a3);
LABEL_6:
  syna_spi_hw_reset(*(_QWORD *)(v3 + 624));
  printk(unk_38B8E, "tpd_test_cmd_store", v7);
  return v5;
}
