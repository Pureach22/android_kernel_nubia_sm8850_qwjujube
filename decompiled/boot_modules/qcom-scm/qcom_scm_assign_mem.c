__int64 __fastcall qcom_scm_assign_mem(__int64 a1, __int64 a2, unsigned __int64 *a3, _DWORD *a4, unsigned int a5)
{
  unsigned int v8; // w21
  _DWORD *v9; // x22
  unsigned __int64 v10; // x25
  __int64 v11; // x28
  unsigned __int64 v12; // x26
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  __int64 v23; // x8
  int v24; // w9
  __int64 result; // x0
  _QWORD *v26; // x10
  unsigned __int64 v27; // x23
  _QWORD *v28; // x10
  int v29; // w12
  int v30; // t1
  __int64 v31; // x21
  int convention; // w0
  __int64 v33; // x2
  int v34; // w0
  int v35; // w2
  unsigned int v36; // w21
  __int64 v37; // [xsp+0h] [xbp-90h]
  _QWORD v38[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v39[14]; // [xsp+20h] [xbp-70h] BYREF

  v8 = a5;
  v9 = a4;
  v39[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a3;
  if ( (gh_rm_needs_scm_assign(a3, a4, a5) & 1) != 0 )
  {
    v11 = 24LL * v8;
    v37 = 4 * _sw_hweight64(v10);
    v12 = (v37 + 63) & 0xFFFFFFFFFFFFFFC0LL;
    v13 = qcom_tzmem_alloc(*(_QWORD *)(_scm + 344), v12 + 64 + ((v11 + 63) & 0x3FFFFFFFC0LL), 3264);
    if ( v13 )
    {
      v14 = v13;
      v15 = qcom_tzmem_to_phys();
      v23 = 0;
      v24 = 0;
      do
      {
        if ( ((v10 >> v23) & 1) != 0 )
          *(_DWORD *)(v14 + 4LL * v24++) = v23;
        ++v23;
      }
      while ( v23 != 64 );
      v26 = (_QWORD *)(v14 + v12);
      *v26 = a1;
      v26[1] = a2;
      v27 = 0;
      if ( v8 )
      {
        v28 = v26 + 8;
        do
        {
          --v8;
          *(_DWORD *)v28 = *v9;
          v29 = v9[1];
          v28[1] = 0;
          *((_DWORD *)v28 + 4) = 0;
          *((_DWORD *)v28 + 1) = v29;
          v28 += 3;
          v30 = *v9;
          v9 += 2;
          v27 |= 1LL << v30;
        }
        while ( v8 );
      }
      v31 = *(_QWORD *)_scm;
      v39[6] = v12 + 64 + v15;
      v39[7] = v11;
      v39[2] = v15 + v12;
      v39[3] = 16;
      v39[0] = 0x160000000CLL;
      v39[1] = 4375;
      v39[4] = v15;
      v39[5] = v37;
      memset(&v39[8], 0, 32);
      v39[12] = 2;
      memset(v38, 0, sizeof(v38));
      convention = _get_convention(v15, v16, v17, v18, v19, v20, v21, v22);
      if ( (unsigned int)(convention - 2) >= 2 )
      {
        if ( convention != 1 )
        {
          printk(&unk_124E9, "qcom_scm_call", v33);
          v35 = -22;
          goto LABEL_24;
        }
        v34 = scm_legacy_call(v31, (__int64)v39, v38);
      }
      else
      {
        v34 = _scm_smc_call(v31, v39, qcom_scm_convention, v38, 0);
      }
      if ( v34 )
        v35 = v34;
      else
        v35 = v38[0];
      if ( !v35 )
      {
        v36 = 0;
        *a3 = v27;
LABEL_21:
        qcom_tzmem_free(v14);
        result = v36;
        goto LABEL_22;
      }
LABEL_24:
      dev_err(*(_QWORD *)_scm, "Assign memory protection call failed %d\n", v35);
      v36 = -22;
      goto LABEL_21;
    }
    result = 4294967284LL;
  }
  else
  {
    result = 0;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
