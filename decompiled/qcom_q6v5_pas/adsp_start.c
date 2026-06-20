__int64 __fastcall adsp_start(__int64 a1)
{
  __int64 **v2; // x19
  __int64 v3; // x1
  __int64 *v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w21
  bool v7; // w24
  __int64 v8; // x0
  __int64 v9; // x22
  _QWORD *v10; // x25
  __int64 v11; // x0
  int v12; // w8
  int v13; // w8
  int v14; // w0
  unsigned int v15; // w0
  int v16; // w8
  char *v17; // x9
  __int64 v18; // x0
  __int64 v19; // x8
  int v20; // w25
  _QWORD **v21; // x23
  __int64 v22; // x24
  int v23; // w22
  unsigned int v24; // w0
  __int64 *v25; // x22
  unsigned int v26; // w0
  _QWORD *v27; // x8
  unsigned int v28; // w9
  unsigned int v35; // w11
  __int64 v36; // x22
  int v37; // w0
  int v38; // w21
  __int64 *v39; // x22
  int v40; // w0
  int v41; // w0
  int v42; // w0
  int v43; // w0
  __int64 v44; // x0
  int v45; // w0
  int v46; // w0
  __int64 v47; // x0
  int v48; // w22
  int no_init; // w0
  int v50; // w21
  __int64 *v51; // x0
  int v52; // w22
  __int64 v53; // x26
  int i; // w25
  __int64 *v55; // x0
  __int64 v57; // x0
  int v58; // w22
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  unsigned int v62; // w0
  const char *v63; // [xsp+8h] [xbp-D8h]
  __int64 v64; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v65; // [xsp+18h] [xbp-C8h]
  __int64 v66; // [xsp+20h] [xbp-C0h]
  __int64 v67; // [xsp+28h] [xbp-B8h]
  __int64 v68; // [xsp+30h] [xbp-B0h]
  __int64 v69; // [xsp+38h] [xbp-A8h]
  __int64 v70; // [xsp+40h] [xbp-A0h]
  __int64 v71; // [xsp+48h] [xbp-98h]
  __int64 v72; // [xsp+50h] [xbp-90h]
  __int64 v73; // [xsp+58h] [xbp-88h]
  __int64 v74; // [xsp+60h] [xbp-80h]
  __int64 v75; // [xsp+68h] [xbp-78h]
  __int64 v76; // [xsp+70h] [xbp-70h] BYREF
  __int64 v77; // [xsp+78h] [xbp-68h] BYREF
  _QWORD v78[12]; // [xsp+80h] [xbp-60h] BYREF

  v78[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 ***)(a1 + 40);
  v3 = (*v2)[14];
  if ( !v3 )
    v3 = **v2;
  if ( *((_BYTE *)v2 + 1328) == 1 )
    *((_DWORD *)v2 + 326) = 0;
  if ( *((_BYTE *)v2 + 784) == 1 )
    v4 = *v2;
  else
    v4 = nullptr;
  v5 = qcom_q6v5_prepare(v2 + 3, v3);
  if ( v5 )
  {
    v6 = v5;
    v7 = 0;
    v8 = *((unsigned int *)v2 + 115);
    if ( !(_DWORD)v8 )
      goto LABEL_91;
    goto LABEL_88;
  }
  if ( (*((_BYTE *)v2 + 752) != 1 || (*((_BYTE *)v2 + 786) & 1) == 0)
    && *((_DWORD *)v2 + 186)
    && *((int *)v2 + 187) >= 1 )
  {
    v9 = 0;
    v10 = v2 + 95;
    v76 = 0;
    v77 = 0;
    v64 = 0;
    v65 = 0;
    v66 = 0;
    v67 = 0;
    v68 = 0;
    v69 = 0;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    v73 = 0;
    v63 = "missing shareable memory-region %d\n";
    v74 = 0;
    v75 = 0;
    while ( 1 )
    {
      v11 = (*v2)[93];
      v12 = *((_DWORD *)v2 + 186);
      memset(v78, 0, 80);
      v13 = _of_parse_phandle_with_args(v11, "memory-region", 0, 0, (unsigned int)(v9 + v12), v78);
      v14 = -22;
      if ( v13 || !v78[0] )
        break;
      v15 = of_address_to_resource(v78[0], 0, &v64);
      if ( v15 )
      {
        v6 = v15;
        v7 = 0;
        goto LABEL_87;
      }
      v16 = *((_DWORD *)v2 + 189);
      if ( ((_BYTE)v2[94] & 1) != 0 )
      {
        v17 = (char *)&v77 + 4;
        HIDWORD(v76) = 6;
        LODWORD(v77) = v16;
        v16 = 3;
      }
      else
      {
        v17 = (char *)&v76 + 4;
      }
      LODWORD(v76) = v16;
      *(_DWORD *)v17 = 6;
      if ( v9 == 3 )
        __break(0x5512u);
      v18 = v64;
      *(v10 - 12) = v64;
      v19 = v65;
      *v10 = 8;
      *(v10 - 5) = v19 - v18 + 1;
      v14 = qcom_scm_assign_mem();
      if ( v14 < 0 )
      {
        v63 = "assign memory %d failed\n";
        break;
      }
      ++v9;
      ++v10;
      if ( v9 >= *((int *)v2 + 187) )
        goto LABEL_25;
    }
    v6 = v14;
    dev_err(*v2, v63, (unsigned int)v9);
    v7 = 0;
LABEL_87:
    qcom_q6v5_unprepare(v2 + 3);
    v8 = *((unsigned int *)v2 + 115);
    if ( !(_DWORD)v8 )
      goto LABEL_91;
    goto LABEL_88;
  }
LABEL_25:
  v20 = *((_DWORD *)v2 + 110);
  v21 = v2 + 52;
  *((_BYTE *)v2 + 786) = 1;
  if ( v20 )
  {
    v22 = 0;
    v23 = 0;
    while ( 1 )
    {
      dev_pm_genpd_set_performance_state(v21[v22], 0x7FFFFFFF);
      v24 = _pm_runtime_resume(v21[v22], 4);
      if ( (v24 & 0x80000000) != 0 )
        break;
      v22 = ++v23;
      if ( v20 == v23 )
        goto LABEL_29;
    }
    v27 = v21[v22];
    v28 = *((_DWORD *)v27 + 120);
    do
    {
      if ( !v28 )
        break;
      _X13 = (unsigned int *)(v27 + 60);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v35 = __ldxr(_X13);
        if ( v35 != v28 )
          break;
        if ( !__stlxr(v28 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v35 == v28;
      v28 = v35;
    }
    while ( !_ZF );
    v6 = v24;
    dev_pm_genpd_set_performance_state(v21[v22], 0);
    if ( v23 - 1 >= 0 )
    {
      v36 = (unsigned int)(v23 - 1);
      do
      {
        dev_pm_genpd_set_performance_state(v21[v36], 0);
        _pm_runtime_idle(v21[v36--], 5);
      }
      while ( v36 != -1 );
    }
    v7 = 0;
    goto LABEL_86;
  }
LABEL_29:
  v25 = v2[46];
  v26 = clk_prepare(v25);
  if ( v26 )
  {
    v7 = 0;
    goto LABEL_83;
  }
  v37 = clk_enable(v25);
  if ( v37 )
  {
    v38 = v37;
    v7 = 0;
LABEL_82:
    clk_unprepare(v25);
    v26 = v38;
LABEL_83:
    v52 = *((_DWORD *)v2 + 110);
    v6 = v26;
    if ( v52 )
    {
      v53 = 0;
      for ( i = 0; i != v52; v53 = i )
      {
        dev_pm_genpd_set_performance_state(v21[v53], 0);
        _pm_runtime_idle(v21[v53], 5);
        ++i;
      }
    }
LABEL_86:
    *((_BYTE *)v2 + 786) = 0;
    adsp_unassign_memory_region(v2);
    goto LABEL_87;
  }
  v39 = v2[47];
  v40 = clk_prepare(v39);
  if ( v40 )
  {
    v38 = v40;
    v7 = 0;
LABEL_81:
    v25 = v2[46];
    clk_disable(v25);
    goto LABEL_82;
  }
  v41 = clk_enable(v39);
  if ( v41 )
  {
    v38 = v41;
    v7 = 0;
LABEL_80:
    clk_unprepare(v39);
    goto LABEL_81;
  }
  if ( v2[48] )
  {
    v42 = regulator_enable();
    if ( v42 )
    {
      v38 = v42;
      v7 = 0;
LABEL_79:
      v39 = v2[47];
      clk_disable(v39);
      goto LABEL_80;
    }
  }
  if ( v2[49] )
  {
    v43 = regulator_enable();
    if ( v43 )
    {
      v7 = 0;
LABEL_77:
      v38 = v43;
      v51 = v2[48];
      if ( v51 )
        regulator_disable(v51);
      goto LABEL_79;
    }
  }
  v43 = enable_regulators(v2);
  if ( v43 )
  {
    v7 = 0;
    goto LABEL_75;
  }
  qcom_q6v5_pas_set_bw(v2 + 3, 0xFFFFFFFFLL, 0xFFFFFFFFLL);
  v44 = (*v2)[14];
  if ( !v44 )
    v44 = **v2;
  trace_rproc_qcom_event(v44, "dtb_auth_reset", "enter");
  v45 = *((_DWORD *)v2 + 115);
  v7 = v45 != 0;
  if ( v45 )
  {
    v46 = ((__int64 (*)(void))qcom_scm_pas_auth_and_reset)();
    if ( v46 )
      panic("Panicking, auth and reset failed for remoteproc %s dtb ret=%d\n", *(const char **)(a1 + 24), v46);
  }
  v47 = (*v2)[14];
  if ( !v47 )
    v47 = **v2;
  trace_rproc_qcom_event(v47, "Q6_firmware_loading", "enter");
  v48 = qcom_mdt_pas_init(
          *v2,
          v2[63],
          *(_QWORD *)(a1 + 32),
          *((unsigned int *)v2 + 114),
          v2[79],
          v2 + 145,
          *((unsigned __int8 *)v2 + 784));
  if ( v48 )
  {
LABEL_74:
    disable_regulators(v2);
    v43 = v48;
LABEL_75:
    if ( v2[49] )
    {
      v50 = v43;
      regulator_disable(v2[49]);
      v43 = v50;
    }
    goto LABEL_77;
  }
  no_init = qcom_mdt_load_no_init(
              *v2,
              v2[63],
              *(_QWORD *)(a1 + 32),
              *((unsigned int *)v2 + 114),
              v2[86],
              v2[79],
              v2[88],
              v2 + 81);
  if ( no_init )
  {
    v48 = no_init;
    if ( *((_BYTE *)v2 + 784) == 1
      && (unsigned int)qcom_scm_pas_shutdown(*((unsigned int *)v2 + 114))
      && (*((_BYTE *)v2 + 488) != 1 || (unsigned int)adsp_shutdown_poll_decrypt(v2)) )
    {
      panic("Panicking, remoteproc %s failed to unlock pas_metadata.\n", *(const char **)(a1 + 24));
    }
    goto LABEL_73;
  }
  qcom_pil_info_store(v2[62], v2[79], v2[88]);
  adsp_add_coredump_segments(v2, v2[63]);
  v57 = (*v2)[14];
  if ( !v57 )
    v57 = **v2;
  trace_rproc_qcom_event(v57, "Q6_auth_reset", "enter");
  v58 = qcom_scm_pas_auth_and_reset(*((unsigned int *)v2 + 114));
  v59 = (*v2)[14];
  if ( !v59 )
    v59 = **v2;
  trace_rproc_qcom_event(v59, "Q6_auth_reset", "exit");
  if ( v58 )
    panic("Panicking, auth and reset failed for remoteproc %s ret=%d\n", *(const char **)(a1 + 24), v58);
  v60 = (*v2)[14];
  if ( !v60 )
    v60 = **v2;
  v61 = trace_rproc_qcom_event(v60, "Q6_auth_reset", "exit");
  if ( (qcom_pil_timeouts_disabled(v61) & 1) != 0 )
  {
    v6 = 0;
  }
  else
  {
    v62 = qcom_q6v5_wait_for_start(v2 + 3, 1250);
    if ( *(_BYTE *)(a1 + 1204) == 1 && v62 )
      panic("Panicking, remoteproc %s failed to bootup.\n", (const char *)v2[2][3]);
    v6 = v62;
    if ( v62 == -110 )
    {
      dev_err(*v2, "start timed out\n");
      v48 = -110;
LABEL_73:
      qcom_scm_pas_metadata_release(v2 + 145, v4);
      goto LABEL_74;
    }
  }
  qcom_scm_pas_metadata_release(v2 + 145, v4);
  v2[41] = (__int64 *)((char *)v2[41] + 1);
  v8 = *((unsigned int *)v2 + 115);
  if ( !(_DWORD)v8 )
    goto LABEL_91;
LABEL_88:
  if ( v7 || ((_BYTE)v2[98] & 1) == 0 || (qcom_scm_pas_shutdown(v8), *((_DWORD *)v2 + 115)) )
    qcom_scm_pas_metadata_release(v2 + 148, v4);
LABEL_91:
  release_firmware(v2[64]);
  v55 = v2[9];
  if ( v55 && (icc_set_bw(v55, 0, 0) & 0x80000000) != 0 )
  {
    dev_err(v2[3], "failed to set crypto_path bandwidth request\n");
    icc_set_bw(v2[9], 0, 0);
  }
  v2[63] = nullptr;
  _ReadStatusReg(SP_EL0);
  return v6;
}
