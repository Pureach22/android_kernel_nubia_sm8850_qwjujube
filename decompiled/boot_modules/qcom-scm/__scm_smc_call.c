__int64 __fastcall _scm_smc_call(__int64 a1, _QWORD *a2, int a3, _QWORD *a4, int a5)
{
  int v5; // w20
  int v6; // w21
  unsigned int v7; // w19
  __int64 v8; // x25
  __int64 v9; // x26
  int v10; // w23
  int v11; // w22
  int v12; // w24
  __int64 v13; // x28
  __int64 v14; // x19
  char is_enabled; // w27
  unsigned int v16; // w19
  __int64 v17; // x23
  unsigned int v18; // w20
  __int64 v19; // x27
  __int64 v20; // x28
  __int64 v21; // x19
  __int64 v22; // x8
  unsigned int v23; // w24
  __int64 v24; // x20
  unsigned __int64 v25; // x0
  unsigned int v26; // w20
  __int64 v27; // x8
  __int64 v28; // x9
  _QWORD *v31; // x25
  _DWORD *v32; // x8
  __int64 v33; // x10
  __int64 v34; // x0
  __int64 v36; // [xsp+18h] [xbp-B8h]
  char v37; // [xsp+24h] [xbp-ACh]
  __int64 v38; // [xsp+28h] [xbp-A8h]
  __int64 v39; // [xsp+30h] [xbp-A0h]
  __int64 v40; // [xsp+38h] [xbp-98h]
  __int64 v41; // [xsp+38h] [xbp-98h]
  __int64 v43; // [xsp+48h] [xbp-88h]
  __int64 v44; // [xsp+48h] [xbp-88h]
  __int64 v45; // [xsp+50h] [xbp-80h]
  __int64 v46; // [xsp+50h] [xbp-80h]
  unsigned int v47; // [xsp+58h] [xbp-78h]
  char v48; // [xsp+5Ch] [xbp-74h]
  __int64 v49; // [xsp+60h] [xbp-70h]
  __int64 v51; // [xsp+70h] [xbp-60h]
  __int64 v52; // [xsp+78h] [xbp-58h] BYREF
  __int64 v53; // [xsp+80h] [xbp-50h]
  __int64 v54; // [xsp+88h] [xbp-48h]
  __int64 v55; // [xsp+90h] [xbp-40h]
  __int64 v56; // [xsp+98h] [xbp-38h] BYREF
  _DWORD *v57; // [xsp+A0h] [xbp-30h]
  __int64 v58; // [xsp+A8h] [xbp-28h]
  __int64 v59; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v60; // [xsp+B8h] [xbp-18h]
  __int64 v61; // [xsp+C0h] [xbp-10h]

  v5 = a3 != 2;
  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a5 == 1;
  if ( a5 == 1 )
    v7 = 2080;
  else
    v7 = 3072;
  v8 = a2[2];
  v9 = a2[3];
  v10 = *((_DWORD *)a2 + 24);
  v11 = *(_DWORD *)a2;
  v12 = *((unsigned __int8 *)a2 + 4);
  v13 = a2[4];
  v45 = *((unsigned int *)a2 + 2);
  v57 = nullptr;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v52 = 0;
  if ( ((unsigned __int8)v45 & 0xFu) >= 5 )
  {
    if ( !a1 )
    {
      v16 = -517;
      goto LABEL_56;
    }
    v41 = v9;
    v44 = v8;
    v31 = a2;
    is_enabled = qtee_shmbridge_is_enabled();
    if ( (is_enabled & 1) != 0 )
    {
      v16 = qtee_shmbridge_allocate_shm(56, &v56);
      if ( v16 )
        goto LABEL_56;
    }
    else
    {
      v57 = (_DWORD *)kzalloc_noprof(v7);
      if ( !v57 )
      {
        v16 = -12;
        goto LABEL_56;
      }
    }
    v32 = v57;
    v33 = v31[5];
    if ( a3 == 2 )
    {
      *v57 = v33;
      v32[1] = v31[6];
      v32[2] = v31[7];
      v32[3] = v31[8];
      v32[4] = v31[9];
      v32[5] = v31[10];
      v32[6] = v31[11];
    }
    else
    {
      *(_QWORD *)v57 = v33;
      *((_QWORD *)v32 + 1) = v31[6];
      *((_QWORD *)v32 + 2) = v31[7];
      *((_QWORD *)v32 + 3) = v31[8];
      *((_QWORD *)v32 + 4) = v31[9];
      *((_QWORD *)v32 + 5) = v31[10];
      *((_QWORD *)v32 + 6) = v31[11];
    }
    v34 = dma_map_single_attrs(a1, v57);
    v56 = v34;
    if ( v34 == -1 )
    {
      if ( (is_enabled & 1) != 0 )
        qtee_shmbridge_free_shm(&v56);
      else
        kfree(v57);
      v16 = -12;
      goto LABEL_56;
    }
    a2 = v31;
    v8 = v44;
    v9 = v41;
    v14 = v34;
    v36 = 56;
  }
  else
  {
    v14 = a2[5];
    is_enabled = 0;
    v36 = 0;
  }
  v49 = (v5 << 30) | (v6 << 31) | ((v10 & 0x3F) << 24) | v12 & 0xFFFF00FF | ((unsigned __int8)v11 << 8);
  v48 = qcom_scm_multi_call_allow(a1, *((unsigned __int8 *)a2 + 100));
  v37 = is_enabled;
  if ( a5 == 1 )
  {
    v59 = 1;
    v60 = 0;
    if ( (hab_calling_convention & 1) == 0 )
    {
      _arm_smccc_smc(v49, v45, v8, v9, v13, v14, 0, 0, &v52, &v59);
      while ( v52 == 1 )
        _arm_smccc_smc(1, v45, v8, v9, v13, v14, v60, 0, &v52, &v59);
    }
LABEL_8:
    v16 = 0;
  }
  else
  {
    v17 = v45;
    v18 = 0;
    v19 = v13;
    v20 = v14;
    while ( 1 )
    {
      v47 = v18;
      if ( (v48 & 1) == 0 )
        mutex_lock(&qcom_scm_lock);
      down(&qcom_scm_sem_lock);
      v21 = v49;
      v39 = v19;
      v40 = v9;
      v38 = v20;
      v43 = v8;
      v46 = v17;
      while ( 1 )
      {
        v59 = 1;
        v60 = 0;
        if ( (hab_calling_convention & 1) != 0 )
        {
          v22 = v52;
        }
        else
        {
          _arm_smccc_smc(v21, v17, v8, v9, v19, v20, 0, 0, &v52, &v59);
          while ( 1 )
          {
            v22 = v52;
            if ( v52 != 1 )
              break;
            _arm_smccc_smc(1, v17, v8, v9, v19, v20, v60, 0, &v52, &v59);
          }
        }
        v51 = v21;
        if ( (v22 & 0xFFFFFFFFFFFFFFFELL) != 2 )
        {
          v16 = 0;
          if ( v22 < 0 )
          {
            v8 = v43;
            v17 = v46;
            v19 = v39;
            v9 = v40;
            v20 = v38;
            v51 = v49;
          }
          goto LABEL_35;
        }
        if ( !a1 )
        {
          v8 = v43;
          v17 = v46;
          v16 = -517;
          v51 = v49;
LABEL_35:
          v26 = v47;
          goto LABEL_36;
        }
        v23 = v53;
        v24 = (unsigned int)v54;
        v25 = qcom_scm_lookup_wq(*(_QWORD *)(a1 + 152), (unsigned int)v53);
        v16 = v25;
        if ( !v25 || v25 >= 0xFFFFFFFFFFFFF001LL )
          break;
        if ( v52 == 2 )
        {
          wait_for_completion();
          v9 = 0;
          v19 = 0;
          v20 = 0;
          v21 = 1107305474;
        }
        else
        {
          scm_waitq_flag_handler();
          v21 = 1107305473;
        }
        v8 = v24;
        v17 = 1;
        if ( (v52 & 0xFFFFFFFFFFFFFFFELL) != 2 )
        {
          v51 = v21;
          v16 = 0;
          v17 = 1;
          v8 = v24;
          goto LABEL_35;
        }
      }
      printk(&unk_1214D, v23, v25);
      v26 = v47;
LABEL_36:
      up(&qcom_scm_sem_lock);
      if ( (v48 & 1) == 0 )
        mutex_unlock(&qcom_scm_lock);
      if ( v16 || v52 != -12 || a5 == 2 || v26 > 0x14 )
        break;
      v18 = v26 + 1;
      msleep(30);
      v49 = v51;
      if ( v52 != -12 )
        goto LABEL_8;
    }
  }
  if ( !v57 )
    goto LABEL_12;
  dma_unmap_page_attrs(a1, v56, v36, 1, 0);
  if ( (v37 & 1) != 0 )
  {
    qtee_shmbridge_free_shm(&v56);
LABEL_12:
    if ( v16 )
      goto LABEL_56;
    goto LABEL_46;
  }
  kfree(v57);
  if ( v16 )
    goto LABEL_56;
LABEL_46:
  if ( a4 )
  {
    v27 = v53;
    v28 = v54;
    a4[2] = v55;
    *a4 = v27;
    a4[1] = v28;
  }
  if ( v52 )
  {
    if ( (unsigned int)v52 < 0xFFFFFFF4 )
      v16 = -22;
    else
      v16 = *(_DWORD *)((char *)&unk_12DE8 + (((v52 << 32) + 0xC00000000LL) >> 30));
  }
  else
  {
    v16 = 0;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v16;
}
