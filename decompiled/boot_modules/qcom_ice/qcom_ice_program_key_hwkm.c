__int64 __fastcall qcom_ice_program_key_hwkm(
        __int64 *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        _DWORD *a4,
        unsigned __int8 a5,
        unsigned int a6)
{
  int v7; // w19
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v10; // x9
  int v11; // w20
  __int64 v15; // x22
  unsigned int v17; // w0
  unsigned int v18; // w20
  __int64 v19; // [xsp+0h] [xbp-20h] BYREF
  void *dest; // [xsp+8h] [xbp-18h]
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v7 = a2;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a1;
  if ( !a2 && (a3 == 3 || a3 == 5) )
  {
    if ( a4[3] != 2 )
      goto LABEL_14;
    if ( *((_BYTE *)a1 + 33) == 1 )
    {
      v10 = a1[1];
      v11 = *((unsigned __int8 *)a1 + 32);
      dest = nullptr;
      v21 = 0;
      v15 = (int)((a6 << 7) + 16448);
      v19 = 0;
      writel(0, v10 + v15);
      if ( (unsigned int)qtee_shmbridge_allocate_shm((unsigned int)a4[5], &v19) )
      {
        result = 4294967284LL;
        goto LABEL_5;
      }
      memcpy(dest, a4 + 6, (unsigned int)a4[5]);
      qtee_shmbridge_flush_shm_buf(&v19);
      v17 = qcom_scm_config_set_ice_key(a6 << (v11 != 1), v19, (unsigned int)a4[5], 0, 0, 0);
      if ( v17 )
      {
        v18 = v17;
        printk(&unk_7161, "qcom_ice_program_wrapped_key", v17, a6);
        result = v18;
        goto LABEL_5;
      }
      writel(a5 | 0x80000300, a1[1] + v15);
      qtee_shmbridge_inv_shm_buf(&v19);
      qtee_shmbridge_free_shm(&v19);
LABEL_14:
      result = 0;
      goto LABEL_5;
    }
  }
  else if ( (unsigned int)__ratelimit(&qcom_ice_program_key_hwkm__rs, "qcom_ice_program_key_hwkm") )
  {
    dev_err(v8, "Unhandled crypto capability; algorithm_id=%d, key_size=%d\n", v7, a3);
  }
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
