__int64 __fastcall msm_dss_mmrm_register(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _BYTE *a5)
{
  __int64 v5; // x28
  __int64 *v6; // x26
  __int64 v10; // x22
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x8
  _QWORD *v14; // x0
  __int64 v15; // x1
  unsigned int v17; // [xsp+14h] [xbp-CCh]
  _QWORD v18[16]; // [xsp+28h] [xbp-B8h] BYREF
  __int64 v19; // [xsp+A8h] [xbp-38h]
  __int64 v20; // [xsp+B0h] [xbp-30h]
  __int64 v21; // [xsp+B8h] [xbp-28h]
  _QWORD *v22; // [xsp+C0h] [xbp-20h]
  __int64 v23; // [xsp+C8h] [xbp-18h]
  __int64 v24; // [xsp+D0h] [xbp-10h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned int *)(a2 + 32);
  v6 = *(__int64 **)(a2 + 40);
  *a5 = 0;
  if ( (int)v5 < 1 )
  {
    v17 = 0;
    goto LABEL_17;
  }
  v10 = 0;
  v17 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v22 = nullptr;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    v19 = 0;
    memset(v18, 0, sizeof(v18));
    if ( *((_DWORD *)v6 + 10) == 2 )
      break;
LABEL_4:
    ++v10;
    v6 += 15;
    if ( v5 == v10 )
      goto LABEL_17;
  }
  v11 = strnlen((const char *)v6 + 8, 0x20u);
  if ( v11 >= 0x20 && v11 != 128 )
    goto LABEL_19;
  if ( v11 == 128 )
    v12 = 128;
  else
    v12 = v11 + 1;
  if ( v12 >= 0xA9 )
  {
    v11 = _fortify_panic(7, 168, v12);
LABEL_19:
    _fortify_panic(2, 32, v11 + 1);
  }
  sized_strscpy(v18, v6 + 1);
  v13 = *v6;
  LODWORD(v21) = 2;
  v19 = v13;
  _init_waitqueue_head(v6 + 12, "&clk_array[i].mmrm.mmrm_cb_wq", &msm_dss_mmrm_register___key);
  v14 = (_QWORD *)_kmalloc_cache_noprof(kthread_create_on_node, 3520, 16);
  if ( v14 )
  {
    *v14 = a4;
    v14[1] = v6;
    v6[10] = (__int64)v14;
    v22 = v14;
    v23 = a3;
    if ( v6[9] )
    {
      *a5 = 1;
    }
    else
    {
      printk(&unk_235ABB, v15);
      printk(&unk_235AD2, (unsigned int)v10);
      v17 = -22;
    }
    goto LABEL_4;
  }
  v17 = -12;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v17;
}
