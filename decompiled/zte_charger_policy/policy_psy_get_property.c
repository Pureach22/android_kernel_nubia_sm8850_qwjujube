__int64 __fastcall policy_psy_get_property(__int64 a1, unsigned int a2, int *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x20
  char v9; // w8
  int v10; // w9
  unsigned int v11; // w8
  __int64 v13; // x20

  drvdata = power_supply_get_drvdata();
  if ( !drvdata )
  {
    printk(&unk_ADFB, "policy_psy_get_property", v6, v7);
    return (unsigned int)-61;
  }
  switch ( a2 )
  {
    case 4u:
      v10 = *(_DWORD *)(drvdata + 492);
LABEL_10:
      v11 = 0;
      *a3 = v10;
      return v11;
    case 5u:
      if ( *(_BYTE *)(drvdata + 537) != 1
        || (v8 = drvdata, v9 = charger_policy_check_usb_present(drvdata), drvdata = v8, (v9 & 1) == 0) )
      {
        if ( *(_BYTE *)(drvdata + 538) != 1 || *(_BYTE *)(drvdata + 539) != 1 )
        {
          v11 = 0;
          *a3 = 0;
          return v11;
        }
      }
      v10 = 1;
      goto LABEL_10;
    case 3u:
      v13 = drvdata;
      printk(&unk_9208, "policy_psy_get_property", *(unsigned int *)(drvdata + 488), v7);
      v11 = 0;
      *a3 = *(_DWORD *)(v13 + 488) == 0;
      break;
    default:
      printk(&unk_9D87, a2, v6, v7);
      return (unsigned int)-22;
  }
  return v11;
}
