__int64 __fastcall msm_ep_update_ops(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  _QWORD *v4; // x22
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  _QWORD *v7; // x0
  __int64 *v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x13
  __int64 v14; // x14
  __int64 v15; // x15
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x11
  unsigned __int64 StatusReg; // x22
  __int64 v22; // x23
  __int64 (__fastcall *v23)(_QWORD, _QWORD, _QWORD); // x0

  v2 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(v2 + 368) + 96LL) + 152LL);
  v5 = raw_spin_lock_irqsave(v2 + 312);
  v6 = *(unsigned __int8 *)(a1 + 170);
  if ( v6 >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    v23 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &msm_ep_update_ops__alloc_tag;
    v7 = (_QWORD *)_kmalloc_cache_noprof(v23, 2336, 96);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( v7 )
      goto LABEL_4;
  }
  else
  {
    v1 = v5;
    if ( v4[v6 + 7] )
    {
      raw_spin_unlock_irqrestore(v2 + 312, v5);
      dev_err(
        *v4,
        "ep [%s,%d] already configured as msm endpoint\n",
        *(const char **)(a1 + 8),
        *(unsigned __int8 *)(a1 + 170));
      return 0xFFFFFFFFLL;
    }
    v4[v6 + 7] = *(_QWORD *)(a1 + 16);
    v7 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 96);
    if ( v7 )
    {
LABEL_4:
      v8 = *(__int64 **)(a1 + 16);
      v9 = v8[4];
      v10 = v8[6];
      v11 = v8[7];
      v7[5] = v8[5];
      v12 = v8[2];
      v13 = v8[3];
      v15 = *v8;
      v14 = v8[1];
      v7[6] = v10;
      v7[7] = v11;
      v7[4] = v9;
      v7[2] = v12;
      v7[3] = v13;
      *v7 = v15;
      v7[1] = v14;
      v17 = v8[10];
      v16 = v8[11];
      v19 = v8[8];
      v18 = v8[9];
      *(_QWORD *)(a1 + 16) = v7;
      v7[10] = v17;
      v7[11] = v16;
      v7[8] = v19;
      v7[9] = v18;
      v7[5] = dwc3_msm_ep_queue;
      *v7 = dwc3_msm_ep_enable;
      raw_spin_unlock_irqrestore(v2 + 312, v1);
      return 0;
    }
  }
  raw_spin_unlock_irqrestore(v2 + 312, v1);
  return 4294967284LL;
}
