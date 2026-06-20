__int64 __fastcall set_pwr_srcs_status(__int64 a1, int a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  __int64 v5; // x14
  __int64 v7; // x19
  int v8; // w20
  int voltage; // w0
  int v10; // w8
  __int64 v11; // x9
  const char *v12; // x1
  void *v13; // x0

  if ( !a1 )
    return printk(&unk_12474, "set_pwr_srcs_status");
  if ( *(_BYTE *)(a1 + 28) == 1 )
  {
    v7 = a1;
    v8 = a2;
    voltage = regulator_get_voltage(*(_QWORD *)a1);
    a2 = v8;
    v10 = voltage;
    a1 = v7;
  }
  else
  {
    v10 = -1;
  }
  v11 = *(unsigned int *)(a1 + 36);
  if ( a2 != 2 )
  {
    if ( a2 == 1 )
    {
      if ( (unsigned int)v11 > 0x23 )
        goto LABEL_23;
      power_src[v11 + 72] = v10;
      if ( v10 != -1 )
      {
        if ( *(_DWORD *)(a1 + 36) <= 0x23u )
        {
          v12 = *(const char **)(a1 + 8);
LABEL_21:
          v13 = &unk_1317E;
          return printk(v13, v12);
        }
        goto LABEL_23;
      }
    }
    else
    {
      if ( (unsigned int)v11 >= 0x24 )
        goto LABEL_23;
      power_src[v11 + 36] = v10;
      if ( v10 != -1 )
      {
        if ( *(_DWORD *)(a1 + 36) <= 0x23u )
        {
          v12 = *(const char **)(a1 + 8);
          goto LABEL_21;
        }
        goto LABEL_23;
      }
    }
LABEL_18:
    v13 = &unk_11813;
    v12 = "set_pwr_srcs_status";
    return printk(v13, v12);
  }
  if ( (unsigned int)v11 > 0x23 )
    goto LABEL_23;
  power_src[v11] = v10;
  if ( v10 == -1 )
    goto LABEL_18;
  if ( *(_DWORD *)(a1 + 36) <= 0x23u )
  {
    v12 = *(const char **)(a1 + 8);
    goto LABEL_21;
  }
LABEL_23:
  __break(0x5512u);
  atomic_store(a5, (unsigned __int8 *)(v5 + 70));
  return btpower_retenion();
}
