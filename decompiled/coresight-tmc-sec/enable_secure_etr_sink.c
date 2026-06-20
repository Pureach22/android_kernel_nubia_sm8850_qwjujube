__int64 __fastcall enable_secure_etr_sink(__int64 a1)
{
  _QWORD *v2; // x19
  unsigned int v3; // w21
  int v4; // w0
  __int64 v5; // x8
  __int64 device; // x0
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x22
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x0
  void *v14; // x21
  unsigned __int64 v15; // x24
  __int64 v16; // x22
  _QWORD *v17; // x0
  __int64 v18; // x1
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x20
  __int64 v24; // x20
  _QWORD v26[2]; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 152) + 152LL);
  mutex_lock(v2 + 24);
  if ( (*((_BYTE *)v2 + 244) & 1) != 0 )
  {
    v3 = -16;
    goto LABEL_21;
  }
  if ( (unsigned int)*(_QWORD *)(a1 + 968) == 1 )
  {
    v3 = 0;
LABEL_5:
    ++*(_DWORD *)(a1 + 976);
    goto LABEL_21;
  }
  v4 = hashlen_string(0, v2[21]);
  v5 = v2[1];
  LODWORD(v26[0]) = v4;
  device = bus_find_device(*(_QWORD *)(v5 + 184), 0, v26, coresight_sink_by_id);
  if ( !device || (v7 = *(_QWORD *)(*(_QWORD *)(device + 96) + 152LL)) == 0 )
  {
    dev_info(*v2, "real_sink config error\n");
    v3 = -22;
    goto LABEL_21;
  }
  v8 = *(_QWORD *)(v7 + 16);
  if ( (unsigned int)*(_QWORD *)(v8 + 968) == 1 || (unsigned int)*(_QWORD *)(v8 + 968) == 2 )
  {
    dev_info(*v2, "%s is enabled, please disable it\n", (const char *)v2[21]);
    v3 = -16;
    goto LABEL_21;
  }
  v9 = v2[35];
  v3 = clk_prepare(v9);
  if ( !v3 )
  {
    v10 = clk_enable(v9);
    if ( v10 )
    {
      v3 = v10;
      v11 = v9;
    }
    else
    {
      v26[1] = 0;
      v27[0] = 0;
      v12 = *((unsigned int *)v2 + 69);
      v26[0] = 0;
      v13 = dmam_alloc_attrs(*v2, v12, v27, 3264, 0);
      if ( !v13
        || (v14 = (void *)v13,
            dma_get_sgtable_attrs(*v2, v26, v13, v27[0], *((unsigned int *)v2 + 69), 0),
            v15 = memstart_addr,
            v16 = *(_QWORD *)v26[0],
            sg_free_table(v26),
            memset(v14, 0, *((unsigned int *)v2 + 69)),
            (v17 = (_QWORD *)devm_kmalloc(*v2, 24, 3520)) == nullptr) )
      {
        v24 = v2[35];
        clk_disable(v24);
        clk_unprepare(v24);
        v3 = -12;
        goto LABEL_21;
      }
      *v17 = v14;
      v18 = *((unsigned int *)v2 + 69);
      v26[0] = 0x60000000FLL;
      v27[0] = 8;
      v17[1] = (((v16 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (v15 >> 12)) << 6) + 0x5000000000LL;
      v17[2] = v18;
      v2[31] = v17;
      qcom_scm_assign_mem((((v16 & 0x3FFFFFFFFFFFFFCLL) - -64LL * (v15 >> 12)) << 6) + 0x5000000000LL, v18, v27, v26, 1);
      v19 = secure_etr_assign_to_mpss(v2);
      if ( !v19 )
      {
        dev_info(*v2, "modem etr enable\n");
        if ( (*(_QWORD *)(a1 + 968) & 0xFFFFFFFELL) != 0 )
        {
          _warn_printk("Device already in use\n");
          __break(0x800u);
        }
        v3 = 0;
        *(_QWORD *)(a1 + 968) = 1;
        *(_BYTE *)(v7 + 113) = 1;
        v2[22] = v7;
        goto LABEL_5;
      }
      v20 = v2[31];
      v3 = v19;
      v21 = *(_QWORD *)(v20 + 8);
      v22 = *(_QWORD *)(v20 + 16);
      v26[0] = 0x700000003LL;
      v27[0] = 0x8000;
      qcom_scm_assign_mem(v21, v22, v27, v26, 1);
      dmam_free_coherent(*v2, *(_QWORD *)(v2[31] + 16LL), *(_QWORD *)v2[31], *(_QWORD *)(v2[31] + 8LL));
      v23 = v2[35];
      clk_disable(v23);
      v11 = v23;
    }
    clk_unprepare(v11);
  }
LABEL_21:
  mutex_unlock(v2 + 24);
  _ReadStatusReg(SP_EL0);
  return v3;
}
