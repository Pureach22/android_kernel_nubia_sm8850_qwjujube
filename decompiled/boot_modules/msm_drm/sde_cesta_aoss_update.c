__int64 __fastcall sde_cesta_aoss_update(int *a1, int a2)
{
  __int64 v3; // x0
  __int64 v4; // x2
  unsigned int v6; // w21
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  int v9; // [xsp+10h] [xbp-10h]
  int v10; // [xsp+14h] [xbp-Ch]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( !a1 || a1[1] )
  {
    printk(&unk_25C1E1, "sde_cesta_aoss_update");
    v6 = -22;
  }
  else if ( *(_DWORD *)cesta_list_0 >> 8 >= 0x403u )
  {
    printk(&unk_24408F, "sde_cesta_aoss_update");
    v6 = -95;
  }
  else
  {
    v3 = *(_QWORD *)(cesta_list_0 + 1120);
    v4 = (unsigned int)a1[2];
    v9 = a2;
    LOBYTE(v10) = 1;
    v8 = 0;
    v6 = crm_write_perf_ol(v3, 1, v4, &v8);
    if ( v6 )
      printk(&unk_247339, "sde_cesta_aoss_update");
    else
      a1[24] = a2;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_cesta_aoss_update", 758, -1, *a1, a1[2], a2, v6, 239);
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
