__int64 __fastcall spmi_pmic_arb_bus_init(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x22
  _QWORD *v7; // x0
  unsigned __int64 v8; // x24
  __int64 v9; // x23
  _QWORD *v10; // x27
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned int matched; // w0
  __int64 v15; // x0
  __int64 v16; // x25
  unsigned int v17; // w0
  int byname; // w0
  int v19; // w26
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64, __int64, __int64); // x9
  _DWORD *v22; // x8
  __int64 v23; // x0
  _QWORD v25[13]; // [xsp+8h] [xbp-68h] BYREF

  v25[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)(a3 + 104);
  memset(v25, 0, 96);
  v7 = (_QWORD *)devm_spmi_controller_alloc(a1 + 16, 192);
  if ( (unsigned __int64)v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v8) = (_DWORD)v7;
    goto LABEL_38;
  }
  v7[115] = pmic_arb_cmd;
  v7[116] = pmic_arb_read_cmd;
  v7[117] = pmic_arb_write_cmd;
  if ( (unsigned int)v6 < 4 )
  {
    v9 = v7[19];
    v10 = v7;
    *(_QWORD *)(a3 + 8 * v6 + 72) = v9;
    *(_DWORD *)(v9 + 48) = 0;
    v11 = devm_kmalloc(a1 + 16, 0x4000, 3520);
    *(_QWORD *)(v9 + 136) = v11;
    if ( v11 )
    {
      v12 = *(unsigned int *)(a3 + 64);
      if ( (v12 & 0x80000000) != 0 )
      {
        *(_QWORD *)(v9 + 152) = 0;
        goto LABEL_37;
      }
      v13 = devm_kmalloc(a1 + 16, 4 * v12, 3520);
      *(_QWORD *)(v9 + 152) = v13;
      if ( v13 )
      {
        matched = of_property_match_string(a2, "reg-names", "cnfg");
        if ( (matched & 0x80000000) != 0 )
        {
          dev_err(a1 + 16, "cnfg reg region missing\n");
        }
        else
        {
          if ( (unsigned int)of_address_to_resource(a2, matched, v25) || (v15 = devm_ioremap(a1 + 16)) == 0 )
          {
            LODWORD(v8) = -99;
            goto LABEL_38;
          }
          v16 = v15;
          v17 = of_property_match_string(a2, "reg-names", "intr");
          if ( (v17 & 0x80000000) == 0 )
          {
            v8 = devm_of_iomap(a1 + 16, a2, v17, 0);
            if ( v8 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_38;
            if ( of_find_property(a2, "interrupt-names", 0) )
            {
              byname = of_irq_get_byname(a2, "periph_irq");
              v19 = byname;
              if ( byname <= 0 )
              {
                if ( byname )
                  LODWORD(v8) = byname;
                else
                  LODWORD(v8) = -6;
                goto LABEL_38;
              }
            }
            else
            {
              v19 = 0;
            }
            *(_QWORD *)v9 = a3;
            *(_QWORD *)(v9 + 16) = v8;
            *(_QWORD *)(v9 + 24) = v16;
            *(_DWORD *)(v9 + 164) = v19;
            *(_QWORD *)(v9 + 40) = v10;
            *(_BYTE *)(v9 + 168) = v6;
            v20 = *(_QWORD *)(a3 + 56);
            v21 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v20 + 16);
            if ( v21 )
            {
              if ( *((_DWORD *)v21 - 1) != 2105128764 )
                __break(0x8229u);
              LODWORD(v8) = v21(a1, a2, v9);
              if ( (_DWORD)v8 )
                goto LABEL_38;
              v20 = *(_QWORD *)(a3 + 56);
            }
            v22 = *(_DWORD **)(v20 + 24);
            if ( *(v22 - 1) != 1474274682 )
              __break(0x8228u);
            LODWORD(v8) = ((__int64 (__fastcall *)(__int64, _QWORD))v22)(v9, (unsigned int)v6);
            if ( (_DWORD)v8 )
            {
LABEL_38:
              _ReadStatusReg(SP_EL0);
              return (unsigned int)v8;
            }
            if ( !v19 )
            {
LABEL_32:
              v10[93] = a2;
              dev_set_name(v10, "spmi-%d", v6);
              LODWORD(v8) = devm_spmi_controller_add(a1 + 16, v10);
              if ( !(_DWORD)v8 )
              {
                spmi_pmic_arb_debugfs_init(v9);
                ++*(_DWORD *)(a3 + 104);
              }
              goto LABEL_38;
            }
            v23 = irq_domain_add_tree(a2, v9);
            *(_QWORD *)(v9 + 8) = v23;
            if ( v23 )
            {
              irq_set_chained_handler_and_data(*(unsigned int *)(v9 + 164), pmic_arb_chained_irq, v9);
              goto LABEL_32;
            }
            dev_err(a1 + 16, "unable to create irq_domain\n");
            goto LABEL_37;
          }
          dev_err(a1 + 16, "intr reg region missing\n");
        }
        LODWORD(v8) = -22;
        goto LABEL_38;
      }
    }
LABEL_37:
    LODWORD(v8) = -12;
    goto LABEL_38;
  }
  __break(0x5512u);
  return pmic_arb_cmd();
}
