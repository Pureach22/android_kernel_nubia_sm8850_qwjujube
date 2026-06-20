__int64 __fastcall mem_prot_pool_alloc(__int64 a1, __int64 *a2, unsigned int a3)
{
  char *v3; // x24
  __int64 v6; // x21
  __int64 v7; // x1
  __int64 v8; // x0
  _QWORD *v9; // x8
  __int64 v10; // x22
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x10
  bool v13; // cf
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x23
  int v17; // w22
  __int64 result; // x0
  int v19; // w0
  __int64 v20; // x8
  int v21; // w9
  __int64 v22; // x0
  __int64 v23; // x20
  unsigned int v24; // w19
  unsigned __int64 v25; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-30h] BYREF
  int v27; // [xsp+20h] [xbp-20h]
  int v28; // [xsp+24h] [xbp-1Ch]
  __int64 v29; // [xsp+28h] [xbp-18h]
  __int64 v30; // [xsp+30h] [xbp-10h]
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 8 )
  {
    __break(0x5512u);
LABEL_30:
    __break(1u);
  }
  if ( a3 == 7 )
    goto LABEL_30;
  v3 = (char *)&mem_prot_pools + 120 * a3;
  if ( *((_QWORD *)v3 + 7) )
  {
    mutex_lock(v3 + 72);
    if ( (v3[48] & 1) == 0 )
    {
      v6 = *((_QWORD *)v3 + 7);
      v7 = *((_QWORD *)v3 + 5);
      v25 = 0;
      v8 = dma_alloc_attrs(v6, v7, &v25, 3264, 0);
      *((_QWORD *)v3 + 3) = v8;
      if ( !v8 )
      {
        v17 = -22;
        goto LABEL_27;
      }
      v9 = *(_QWORD **)(v6 + 664);
      v10 = v25;
      if ( v9 )
      {
        v11 = v9[2];
        if ( v11 )
        {
          while ( 1 )
          {
            v12 = v9[1];
            v13 = v25 >= v12;
            v14 = v25 - v12;
            if ( v13 && v14 < v11 )
              break;
            v11 = v9[5];
            v9 += 3;
            if ( !v11 )
              goto LABEL_8;
          }
          v10 = *v9 + v14;
        }
        else
        {
LABEL_8:
          v10 = -1;
        }
      }
      v15 = gen_pool_create(12, 0xFFFFFFFFLL);
      v16 = v15;
      if ( v15 >= 0xFFFFFFFFFFFFF001LL )
      {
        v17 = v15;
LABEL_20:
        dma_free_attrs(v6, *((_QWORD *)v3 + 5), *((_QWORD *)v3 + 3), v25, 0);
LABEL_27:
        v24 = v17;
        printk(&unk_6F0C, "mem_prot_pool_alloc");
        goto LABEL_28;
      }
      gen_pool_set_algo(v15, &gen_pool_best_fit, 0);
      v19 = gen_pool_add_owner(v16, v10, -1, *((_QWORD *)v3 + 5), 0xFFFFFFFFLL, 0);
      if ( v19 )
        goto LABEL_19;
      v20 = *((_QWORD *)v3 + 5);
      v21 = *((_DWORD *)v3 + 8);
      v29 = 0;
      v30 = 0;
      v26[0] = v10;
      v26[1] = v20 + v10;
      v28 = 0;
      v27 = v21;
      v19 = qcom_scm_cfg_pddr_protected_region(v26);
      if ( v19 )
      {
LABEL_19:
        v17 = v19;
        gen_pool_destroy(v16);
        goto LABEL_20;
      }
      *((_QWORD *)v3 + 2) = v16;
      v3[48] = 1;
    }
    v22 = gen_pool_alloc_algo_owner(
            *((_QWORD *)v3 + 2),
            a1,
            *(_QWORD *)(*((_QWORD *)v3 + 2) + 32LL),
            *(_QWORD *)(*((_QWORD *)v3 + 2) + 40LL),
            0);
    if ( !v22 )
    {
      printk(&unk_6CAF, "mem_prot_pool_alloc");
      v24 = -12;
LABEL_28:
      mutex_unlock(v3 + 72);
      result = v24;
      goto LABEL_23;
    }
    v23 = v22;
    mutex_unlock(v3 + 72);
    result = 0;
    *a2 = v23;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
