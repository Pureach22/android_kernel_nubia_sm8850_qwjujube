__int64 __fastcall qcom_ice_derive_sw_secret(__int64 a1, const void *a2, unsigned int a3, _QWORD *a4)
{
  size_t v4; // x20
  __int64 result; // x0
  unsigned int v8; // w21
  _QWORD *v9; // x8
  __int64 v10; // x3
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x11
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h] BYREF
  void *dest; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v4 = a3;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = nullptr;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = nullptr;
  if ( (unsigned int)qtee_shmbridge_allocate_shm(a3, &v17) )
  {
    result = 4294967284LL;
  }
  else
  {
    v8 = qtee_shmbridge_allocate_shm(32, &v14);
    if ( !v8 )
    {
      memcpy(dest, a2, v4);
      qtee_shmbridge_flush_shm_buf(&v17);
      v9 = v15;
      v15[2] = 0;
      v9[3] = 0;
      *v9 = 0;
      v9[1] = 0;
      qtee_shmbridge_flush_shm_buf(&v14);
      v8 = qcom_scm_derive_sw_secret(v17, v4, v14, 32);
      if ( v8 )
      {
        printk(&unk_707C, "qcom_ice_derive_sw_secret", v8, v10);
      }
      else
      {
        qtee_shmbridge_inv_shm_buf(&v14);
        v11 = v15[3];
        v12 = *v15;
        v13 = v15[1];
        a4[2] = v15[2];
        a4[3] = v11;
        *a4 = v12;
        a4[1] = v13;
        qtee_shmbridge_inv_shm_buf(&v17);
      }
      qtee_shmbridge_free_shm(&v14);
    }
    qtee_shmbridge_free_shm(&v17);
    result = v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
