__int64 __fastcall hw_fence_get_soccp_props(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x30
  __int64 v8; // x19
  __int64 v10; // x0
  __int64 v11; // x26
  int v12; // w22
  int v13; // w24
  int v14; // w25
  int v15; // w26
  __int64 qtime; // x0
  unsigned int v17; // w0
  __int64 v18; // x4
  __int64 v19; // x22
  __int64 v20; // x4
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9
  unsigned __int64 v29; // x8
  __int64 v30; // x0
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  unsigned int v34; // w24
  unsigned int v35; // w25
  __int64 v36; // x22
  _BYTE s[257]; // [xsp+Fh] [xbp-111h] BYREF
  __int64 v39; // [xsp+110h] [xbp-10h]

  v8 = v4;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a1 || (v10 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    printk(&unk_2A0F5, "hw_fence_get_soccp_props", 1442, v8, a1);
    v19 = -22;
    goto LABEL_20;
  }
  v11 = v10 + 0x8000;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    v34 = *(unsigned __int8 *)(v10 + 33672);
    v35 = *(_DWORD *)(v10 + 33760);
    v36 = *(_QWORD *)(a1 + 32);
    hw_fence_get_qtime(v10);
    printk(&unk_20F46, "hw_fence_get_soccp_props", 1450, v34, v35);
    v10 = v36;
  }
  v12 = *(unsigned __int8 *)(v11 + 904);
  v13 = *(_DWORD *)(v11 + 992);
  v14 = *(_DWORD *)(v11 + 908);
  v15 = *(_DWORD *)(v11 + 840);
  qtime = hw_fence_get_qtime(v10);
  v17 = scnprintf(s, 257, "is_awake:%d, ssr_cnt:%d, usg_cnt:%d, rproc_ph:[%d], qtime:%llu\n", v12, v13, v14, v15, qtime);
  v19 = v17;
  if ( (v17 & 0x80000000) != 0 || v17 > a3 )
  {
    printk(&unk_277B7, "hw_fence_get_soccp_props", 1458, v8, v17);
  }
  else if ( v17 )
  {
    if ( v17 >= 0x102 )
    {
      _copy_overflow(257, v17);
    }
    else
    {
      _check_object_size(s, v17, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v22 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v22 = a2 & ((__int64)(a2 << 8) >> 8);
      if ( 0x8000000000LL - v19 >= v22 )
      {
        v23 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v29 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v29);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v23);
        v30 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, s, v19);
        v31 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v33 - 4096);
        _WriteStatusReg(TTBR1_EL1, v33);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v31);
        if ( !v30 )
        {
          *a4 += v19;
          goto LABEL_20;
        }
      }
    }
    printk(&unk_24E1F, "hw_fence_get_soccp_props", 1469, v8, v20);
    v19 = -14;
    goto LABEL_20;
  }
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    printk(&unk_2B238, "hw_fence_get_soccp_props", 1464, a3, v18);
  v19 = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v19;
}
