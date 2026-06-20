__int64 __fastcall qcom_scm_cfg_pddr_protected_region(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x21
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  _QWORD *v11; // x8
  __int64 v12; // x9
  _DWORD *v13; // x20
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x11
  __int64 v17; // x19
  int convention; // w0
  __int64 v19; // x2
  unsigned int v20; // w19
  __int64 v21; // [xsp+8h] [xbp-B8h] BYREF
  _DWORD *v22; // [xsp+10h] [xbp-B0h]
  __int64 v23; // [xsp+18h] [xbp-A8h]
  __int64 v24; // [xsp+20h] [xbp-A0h] BYREF
  _QWORD *v25; // [xsp+28h] [xbp-98h]
  __int64 v26; // [xsp+30h] [xbp-90h]
  _QWORD v27[7]; // [xsp+38h] [xbp-88h] BYREF
  __int64 v28; // [xsp+70h] [xbp-50h]
  __int64 v29; // [xsp+78h] [xbp-48h]
  __int64 v30; // [xsp+80h] [xbp-40h]
  __int64 v31; // [xsp+88h] [xbp-38h]
  __int64 v32; // [xsp+90h] [xbp-30h]
  __int64 v33; // [xsp+98h] [xbp-28h]
  _QWORD v34[4]; // [xsp+A0h] [xbp-20h] BYREF

  v34[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = nullptr;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = nullptr;
  if ( result )
  {
    v1 = *(unsigned int *)(result + 16);
    if ( (unsigned int)(v1 - 1) > 5 )
    {
      result = 4294967274LL;
      goto LABEL_28;
    }
    v2 = (_QWORD *)result;
    if ( (qtee_shmbridge_is_enabled() & 1) == 0 )
    {
      result = 4294967201LL;
      goto LABEL_28;
    }
    result = qtee_shmbridge_allocate_shm(4, &v21);
    if ( !(_DWORD)result )
    {
      *v22 = 0;
      if ( (qtee_shmbridge_is_enabled() & 1) == 0 )
      {
        v20 = -95;
        goto LABEL_26;
      }
      v3 = qtee_shmbridge_allocate_shm(80, &v24);
      if ( (_DWORD)v3 )
      {
        v20 = v3;
        goto LABEL_26;
      }
      v11 = v25;
      *v25 = 0;
      v11[1] = 0;
      v11[2] = 0;
      v11[3] = 0;
      v12 = v21;
      v13 = v22;
      v14 = v24;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      v11[7] = 0;
      v11[8] = 0;
      v11[9] = 0;
      *v13 = 0;
      if ( !v11 )
      {
        v20 = 0;
        goto LABEL_27;
      }
      *v11 = *v2;
      v11[1] = v2[1];
      v15 = *v2;
      v34[0] = 0;
      v34[1] = 0;
      v11[2] = v15;
      v16 = v2[1];
      *((_DWORD *)v11 + 10) = 0;
      v11[6] = 0;
      v11[3] = v16;
      v11[4] = 0;
      v11[8] = 0;
      *((_DWORD *)v11 + 18) = 0;
      v27[0] = 0x200000027LL;
      v27[1] = 2182;
      v27[2] = 1;
      v27[3] = v14;
      v27[4] = 80;
      v27[5] = v12;
      v27[6] = 4;
      v28 = v1;
      v34[2] = 0;
      v29 = 0;
      v30 = 0;
      v31 = 0;
      v32 = 0;
      v33 = 2;
      while ( 1 )
      {
        v17 = *(_QWORD *)_scm;
        convention = _get_convention(v3, v4, v5, v6, v7, v8, v9, v10);
        if ( (unsigned int)(convention - 2) >= 2 )
        {
          if ( convention != 1 )
          {
            printk(&unk_124E9, "qcom_scm_call", v19);
            LODWORD(v3) = -22;
            goto LABEL_25;
          }
          v3 = scm_legacy_call(v17, (__int64)v27, v34);
          if ( (_DWORD)v3 )
            goto LABEL_25;
        }
        else
        {
          v3 = _scm_smc_call(v17, v27, qcom_scm_convention, v34, 0);
          if ( (_DWORD)v3 )
            goto LABEL_25;
        }
        if ( *v13 != 2 )
        {
          LODWORD(v3) = v34[0];
          if ( !LODWORD(v34[0]) )
          {
            v20 = map_to_linux_error((unsigned int)*v13);
            qtee_shmbridge_free_shm(&v24);
            if ( !v20 )
              goto LABEL_27;
LABEL_26:
            printk(&unk_12254, "qcom_scm_cfg_pddr_protected_region", "qcom_scm_cfg_pddr_protected_region");
LABEL_27:
            qtee_shmbridge_free_shm(&v21);
            result = v20;
            break;
          }
LABEL_25:
          v20 = v3;
          printk(&unk_12761, "__qcom_scm_cfg_phys_ddr_protections_for_region", (unsigned int)v3);
          qtee_shmbridge_free_shm(&v24);
          goto LABEL_26;
        }
        v28 = 0;
      }
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
