__int64 __fastcall mem_prot_pool_free(__int64 a1, __int64 a2, unsigned int a3)
{
  char *v3; // x22
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x20
  __int64 v10; // x8
  unsigned __int64 v11; // x19
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  _QWORD *v14; // x8
  unsigned __int64 v15; // x10
  bool v16; // cf
  unsigned __int64 v17; // x10
  __int64 result; // x0
  _QWORD v19[2]; // [xsp+0h] [xbp-30h] BYREF
  int v20; // [xsp+10h] [xbp-20h]
  int v21; // [xsp+14h] [xbp-1Ch]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 8 )
  {
    __break(0x5512u);
LABEL_23:
    __break(1u);
  }
  if ( a3 == 7 )
    goto LABEL_23;
  v3 = (char *)&mem_prot_pools + 120 * a3;
  v6 = *((_QWORD *)v3 + 2);
  if ( v6 )
  {
    gen_pool_free_owner(v6, a1, a2, 0);
    mutex_lock(v3 + 72);
    if ( *((_QWORD *)v3 + 2) )
    {
      if ( v3[48] == 1 )
      {
        v7 = gen_pool_avail();
        if ( v7 == *((_QWORD *)v3 + 5) )
        {
          v8 = *((_QWORD *)v3 + 2);
          v9 = *((_QWORD *)v3 + 7);
          v10 = *(_QWORD *)(v8 + 8);
          v22 = 0;
          v23 = 0;
          v11 = *(_QWORD *)(v10 + 40);
          v19[0] = v11;
          v19[1] = v11 + v7;
          v21 = 0;
          v20 = 1;
          if ( (unsigned int)qcom_scm_cfg_pddr_protected_region(v19) )
          {
            printk(&unk_6E52, "mem_prot_disable_pool");
          }
          else
          {
            gen_pool_destroy(v8);
            v12 = *(_QWORD *)(v9 + 664);
            if ( v12 )
            {
              v13 = *(_QWORD *)(v12 + 16);
              if ( v13 )
              {
                v14 = (_QWORD *)(v12 + 8);
                while ( 1 )
                {
                  v15 = *(v14 - 1);
                  v16 = v11 >= v15;
                  v17 = v11 - v15;
                  if ( v16 && v17 < v13 )
                    break;
                  v13 = v14[4];
                  v14 += 3;
                  if ( !v13 )
                    goto LABEL_17;
                }
                v11 = *v14 + v17;
              }
              else
              {
LABEL_17:
                v11 = -1;
              }
            }
            dma_free_attrs(v9, *((_QWORD *)v3 + 5), *((_QWORD *)v3 + 3), v11, 0);
            v3[48] = 0;
            *((_QWORD *)v3 + 2) = 0;
          }
        }
      }
    }
    mutex_unlock(v3 + 72);
    result = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
