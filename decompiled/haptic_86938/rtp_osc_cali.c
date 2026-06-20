__int64 __fastcall rtp_osc_cali(__int64 a1)
{
  __int64 v2; // x2
  void *v3; // x0
  __int64 v4; // x2
  void (__fastcall *v5)(_QWORD); // x8
  unsigned __int64 v6; // x20
  _DWORD *v7; // x0
  _QWORD *v8; // x8
  __int64 result; // x0
  __int64 v10; // x1
  void (__fastcall *v11)(__int64, __int64); // x8
  void (__fastcall *v12)(__int64, __int64); // x8
  _DWORD *v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  void (__fastcall *v16)(__int64, __int64); // x8
  unsigned __int8 (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x0
  __int64 v19; // x8
  unsigned int v20; // w9
  unsigned int v21; // w20
  __int64 v22; // x0
  _DWORD *v23; // x10
  __int64 (__fastcall *v24)(_QWORD); // x8
  __int64 v25; // x0
  int v26; // w20
  __int64 v27; // x0
  unsigned __int64 v28; // x8
  void *v29; // x0
  __int64 v30; // x2
  __int64 v31; // x0
  __int64 v32; // x0
  _QWORD v33[2]; // [xsp+0h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 800);
  *(_DWORD *)(a1 + 116) = 0;
  *(_DWORD *)(a1 + 148) = 1;
  v33[0] = 0;
  if ( (request_firmware(v33, aw_rtp_name, v2) & 0x80000000) != 0 )
  {
    v3 = &unk_14D82;
    v4 = 761;
LABEL_37:
    result = printk(v3, "haptic_hv", v4, "rtp_osc_cali");
    goto LABEL_38;
  }
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 56LL);
  if ( *((_DWORD *)v5 - 1) != -2072377296 )
    __break(0x8228u);
  v5(a1);
  *(_BYTE *)(a1 + 5) = 0;
  mutex_lock(a1 + 880);
  vfree(aw_rtp);
  v6 = *(_QWORD *)v33[0] + 4LL;
  v7 = (_DWORD *)vmalloc_noprof(v6);
  v8 = (_QWORD *)v33[0];
  aw_rtp = (__int64)v7;
  if ( v7 )
  {
    if ( v6 < 4 )
      __break(1u);
    *v7 = *(_DWORD *)v33[0];
    *(_DWORD *)(a1 + 120) = *v8;
    printk(&unk_1640B, "haptic_hv", 778, "rtp_osc_cali");
    memcpy((void *)(aw_rtp + 4), *(const void **)(v33[0] + 8LL), *(_QWORD *)v33[0]);
    release_firmware(v33[0]);
    mutex_unlock(a1 + 880);
    v10 = *(unsigned int *)(a1 + 52);
    v11 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 136LL);
    if ( *((_DWORD *)v11 - 1) != 487251822 )
      __break(0x8228u);
    v11(a1, v10);
    printk(&unk_14CD6, "haptic_hv", 665, "ram_vbat_comp");
    v12 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 152LL);
    if ( *((_DWORD *)v12 - 1) != 487251822 )
      __break(0x8228u);
    v12(a1, 2);
    v13 = *(_DWORD **)(*(_QWORD *)(a1 + 1480) + 296LL);
    if ( *(v13 - 1) != 487251822 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v13)(a1, 0);
    v14 = gpio_to_desc(*(unsigned int *)(a1 + 80));
    v15 = gpiod_to_irq(v14);
    disable_irq(v15);
    v16 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 96LL);
    if ( *((_DWORD *)v16 - 1) != 487251822 )
      __break(0x8228u);
    v16(a1, 1);
    cpu_latency_qos_add_request(&aw_pm_qos_req_vb, 0);
    while ( 1 )
    {
      v17 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 368LL);
      if ( *((_DWORD *)v17 - 1) != 2018195540 )
        __break(0x8228u);
      if ( !v17(a1) )
      {
        v18 = mutex_lock(a1 + 880);
        v19 = aw_rtp;
        v20 = *(_DWORD *)(a1 + 116);
        if ( *(_DWORD *)aw_rtp - v20 >= *(_DWORD *)(a1 + 1112) >> 2 )
          v21 = *(_DWORD *)(a1 + 1112) >> 2;
        else
          v21 = *(_DWORD *)aw_rtp - v20;
        if ( *(_DWORD *)aw_rtp != v20 )
        {
          if ( *(_DWORD *)(a1 + 148) == 1 )
          {
            v22 = ktime_get(v18);
            v19 = aw_rtp;
            v20 = *(_DWORD *)(a1 + 116);
            *(_QWORD *)(a1 + 624) = v22;
            *(_DWORD *)(a1 + 148) = 0;
          }
          v23 = *(_DWORD **)(*(_QWORD *)(a1 + 1480) + 208LL);
          if ( *(v23 - 1) != -962088293 )
            __break(0x822Au);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v23)(a1, v19 + v20 + 4, v21);
          *(_DWORD *)(a1 + 116) += v21;
        }
        mutex_unlock(a1 + 880);
      }
      v24 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 360LL);
      if ( *((_DWORD *)v24 - 1) != 2018195540 )
        __break(0x8228u);
      v25 = v24(a1);
      v26 = (unsigned __int8)v25;
      v27 = ktime_get(v25);
      *(_QWORD *)(a1 + 616) = v27;
      if ( v26 )
        break;
      v28 = (v27 - *(_QWORD *)(a1 + 624)) / 1000;
      *(_QWORD *)(a1 + 160) = v28;
      if ( v28 >= 0x4DD1E1 )
      {
        v29 = &unk_155DF;
        v30 = 832;
        goto LABEL_36;
      }
    }
    v29 = &unk_15224;
    v30 = 824;
LABEL_36:
    printk(v29, "haptic_hv", v30, "rtp_osc_cali");
    cpu_latency_qos_remove_request(&aw_pm_qos_req_vb);
    v31 = gpio_to_desc(*(unsigned int *)(a1 + 80));
    v32 = gpiod_to_irq(v31);
    enable_irq(v32);
    v3 = &unk_15619;
    v4 = 842;
    *(_QWORD *)(a1 + 160) = (*(_QWORD *)(a1 + 616) - *(_QWORD *)(a1 + 624)) / 1000LL;
    goto LABEL_37;
  }
  release_firmware(v33[0]);
  mutex_unlock(a1 + 880);
  result = printk(&unk_155B6, "haptic_hv", 773, "rtp_osc_cali");
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
