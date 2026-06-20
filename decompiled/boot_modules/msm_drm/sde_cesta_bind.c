__int64 __fastcall sde_cesta_bind(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 v6; // x24
  __int64 phys_addr; // x0
  __int64 v8; // x23
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 v13; // x0
  unsigned __int64 v14; // x26
  __int64 *v15; // x28
  __int64 v16; // x24
  __int64 v17; // x25
  __int64 v18; // x0
  __int64 result; // x0
  _QWORD v20[4]; // [xsp+8h] [xbp-48h] BYREF
  char s[8]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v22; // [xsp+30h] [xbp-20h]
  __int64 v23; // [xsp+38h] [xbp-18h]
  __int64 v24; // [xsp+40h] [xbp-10h]
  __int64 v25; // [xsp+48h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v20, 0, 24);
  v20[3] = sde_cesta_get_io_resources;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 152);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 744);
      v6 = *(unsigned int *)(v4 + 736);
      phys_addr = msm_get_phys_addr(a1 - 16, "rscc");
      sde_dbg_reg_register_base("sde_rsc_rscc", v5, v6, phys_addr, 2);
      v8 = *(_QWORD *)(v4 + 760);
      v9 = *(unsigned int *)(v4 + 752);
      v10 = msm_get_phys_addr(a1 - 16, "wrapper");
      sde_dbg_reg_register_base("sde_rsc_wrapper", v8, v9, v10, 2);
      v11 = *(_QWORD *)(v4 + 776);
      v12 = *(unsigned int *)(v4 + 768);
      v13 = msm_get_phys_addr(a1 - 16, "disp_cc");
      sde_dbg_reg_register_base("disp_cc", v11, v12, v13, 2);
      if ( *(_DWORD *)(v4 + 724) )
      {
        v14 = 0;
        v15 = (__int64 *)(v4 + 552);
        do
        {
          v23 = 0;
          v24 = 0;
          *(_QWORD *)s = 0;
          v22 = 0;
          if ( v14 == 9 )
            __break(0x5512u);
          snprintf(s, 0x20u, "scc_%u", *(_DWORD *)(v4 + 688 + 4 * v14));
          v16 = *v15;
          v17 = *((unsigned int *)v15 - 2);
          v18 = msm_get_phys_addr(a1 - 16, s);
          sde_dbg_reg_register_base(s, v16, v17, v18, 2);
          ++v14;
          v15 += 2;
        }
        while ( v14 < *(unsigned int *)(v4 + 724) );
      }
      msm_register_vm_event(a2, a1, v20, v4);
      result = 0;
    }
    else
    {
      printk(&unk_25C232, "sde_cesta_bind");
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_26DDCA, "sde_cesta_bind");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
