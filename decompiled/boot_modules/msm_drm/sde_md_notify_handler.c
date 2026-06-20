__int64 sde_md_notify_handler()
{
  __int64 *v0; // x25
  __int64 v1; // x21
  __int64 v2; // x19
  int v3; // w20
  int v4; // w11
  __int64 v5; // x10
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x13
  bool v8; // cf
  int v9; // w14
  int v10; // w12
  int v11; // w13
  unsigned __int64 v12; // x12

  v0 = (__int64 *)qword_2942A8;
  v1 = *(_QWORD *)(*(_QWORD *)(qword_2942C8 + 152) + 56LL);
  v2 = *(_QWORD *)(v1 + 8);
  if ( (__int64 *)qword_2942A8 == &qword_2942A8 )
  {
    v3 = 0;
  }
  else
  {
    v3 = 0;
    do
    {
      if ( v0 && v0[14] )
      {
        v5 = v0[2];
        v6 = v0[18];
        if ( (__int64 *)v5 == v0 + 2 )
        {
          v4 = ((v6 + 15) & 0xFFFFFFF0) + 120;
        }
        else
        {
          v4 = 0;
          do
          {
            v12 = *(unsigned int *)(v5 + 64);
            if ( (_DWORD)v12 || (v11 = v0[18], *(_DWORD *)(v5 + 68)) )
            {
              if ( v6 > v12 )
              {
                v7 = *(unsigned int *)(v5 + 68);
                v8 = (unsigned int)v7 >= (unsigned int)v12;
                v9 = v7 - v12;
                v10 = v6 - v12;
                if ( !v8 )
                  v9 = 0;
                if ( v6 < v7 )
                  v11 = v10;
                else
                  v11 = v9;
              }
              else
              {
                v11 = 0;
              }
            }
            v5 = *(_QWORD *)v5;
            v4 += ((v11 + 15) & 0xFFFFFFF0) + 120;
          }
          while ( (__int64 *)v5 != v0 + 2 );
        }
      }
      else
      {
        printk(&unk_23FB8D, "_sde_dbg_get_reg_blk_size");
        v4 = 0;
      }
      v0 = (__int64 *)*v0;
      v3 += v4;
    }
    while ( v0 != &qword_2942A8 );
  }
  sde_mini_dump_add_va_region("msm_drm_priv", 5928, v1);
  sde_mini_dump_add_va_region("sde_evtlog", 786496, sde_dbg_base_evtlog);
  sde_mini_dump_add_va_region("sde_reglog", 24624, sde_dbg_base_reglog);
  sde_mini_dump_add_va_region("sde_reg_dump", v3, qword_2942B8);
  sde_mini_dump_add_va_region("sde_dbgbus", 4 * dword_2943A4, qword_294398);
  sde_mini_dump_add_va_region("vbif_dbgbus", 4 * dword_2943FC, qword_2943F0);
  sde_mini_dump_add_va_region("dsi_dbgbus", 4 * dword_294454, qword_294448);
  sde_mini_dump_add_va_region("lutdma_dbgbus", 4 * dword_294504, qword_2944F8);
  sde_mini_dump_add_va_region("rsc_dbgbus", 4 * dword_2944AC, qword_2944A0);
  sde_mini_dump_add_va_region("dp_dbgbus", 4 * HIDWORD(qword_294558), qword_294550);
  ((void (__fastcall *)(__int64))sde_kms_add_data_to_minidump_va)(v2);
  return 0;
}
