__int64 __fastcall tiktap_work_routine(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  unsigned __int8 *v4; // x27
  __int64 v5; // x8
  void (__fastcall *v6)(__int64, __int64); // x8
  void (__fastcall *v7)(__int64, __int64); // x8
  int v8; // w22
  void (__fastcall *v9)(__int64, __int64); // x8
  __int64 result; // x0
  __int64 v11; // x0
  int v12; // w23
  __int64 v13; // x0
  int v14; // w22
  __int64 v15; // x0
  __int64 (__fastcall *v16)(_QWORD); // x8
  char v17; // w28
  __int64 (__fastcall *v18)(_QWORD); // x8
  int v19; // w4
  __int64 v20; // x2
  void (__fastcall *v21)(__int64, unsigned __int8 *, __int64); // x8
  __int64 v22; // x0
  void *v23; // x0
  __int64 v24; // x2
  __int64 v25; // [xsp+18h] [xbp-18h] BYREF
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v1 = a1 - 824;
  v3 = a1 - 1576;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 **)(a1 - 24);
  mutex_lock(a1 - 824);
  v5 = *(_QWORD *)(a1 - 96);
  *(_BYTE *)(a1 - 16) = 0;
  v6 = *(void (__fastcall **)(__int64, __int64))(v5 + 152);
  if ( *((_DWORD *)v6 - 1) != 487251822 )
    __break(0x8228u);
  v6(v3, 2);
  v7 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 96) + 280LL);
  if ( *((_DWORD *)v7 - 1) != -746885483 )
    __break(0x8228u);
  v7(v3, 2);
  v8 = 99;
  while ( *v4 != 85 )
  {
    if ( (*(_BYTE *)(a1 - 16) & 1) != 0 )
      goto LABEL_15;
    _const_udelay(4295000);
    if ( --v8 == -1 )
      goto LABEL_13;
  }
  v9 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 96) + 96LL);
  if ( *((_DWORD *)v9 - 1) != 487251822 )
    __break(0x8228u);
  v9(v3, 1);
  _const_udelay(4295000);
  if ( v8 <= 0 )
  {
LABEL_13:
    printk(&unk_1625A, "haptic_hv", 3710, "tiktap_work_routine");
    goto LABEL_14;
  }
  *(_BYTE *)(a1 - 15) = 1;
  mutex_unlock(v1);
  v1 = a1 - 696;
  mutex_lock(a1 - 696);
  if ( (cpu_latency_qos_request_active(&aw_pm_qos_req_vb) & 1) == 0 )
    cpu_latency_qos_add_request(&aw_pm_qos_req_vb, 0);
  v25 = 0;
  v26 = 0;
  ktime_get_coarse_real_ts64(&v25);
  v11 = timespec64_to_jiffies(&v25);
  v12 = jiffies_to_msecs(v11);
  v25 = 0;
  v26 = 0;
  ktime_get_coarse_real_ts64(&v25);
  v13 = timespec64_to_jiffies(&v25);
  if ( (unsigned int)jiffies_to_msecs(v13) > v12 + 800 )
  {
LABEL_19:
    printk(&unk_14352, "haptic_hv", 3734, "tiktap_work_routine");
    goto LABEL_40;
  }
  v14 = 0;
  while ( 1 )
  {
    v16 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 96) + 376LL);
    if ( *((_DWORD *)v16 - 1) != 2018195540 )
      __break(0x8228u);
    v17 = v16(v3);
    v18 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 96) + 352LL);
    if ( *((_DWORD *)v18 - 1) != 2018195540 )
      __break(0x8228u);
    if ( (v18(v3) & 0xF) == 0 )
      break;
    v19 = *v4;
    if ( (*(_BYTE *)(a1 - 16) & 1) != 0 )
      goto LABEL_37;
    if ( v19 == 85 )
    {
      if ( (v17 & 1) != 0 )
      {
        printk(&unk_15152, "haptic_hv", 3751, "tiktap_work_routine");
        printk(&unk_16B4B, "haptic_hv", 3755, "tiktap_work_routine");
        v20 = (unsigned int)*((__int16 *)v4 + 1);
        v21 = *(void (__fastcall **)(__int64, unsigned __int8 *, __int64))(*(_QWORD *)(a1 - 96) + 208LL);
        if ( *((_DWORD *)v21 - 1) != -962088293 )
          __break(0x8228u);
        v21(v3, v4 + 24, v20);
        *v4 = -86;
        v4 = *((unsigned __int8 **)v4 + 1);
        v25 = 0;
        v26 = 0;
        ktime_get_coarse_real_ts64(&v25);
        v22 = timespec64_to_jiffies(&v25);
        v12 = jiffies_to_msecs(v22);
        ++v14;
        goto LABEL_23;
      }
    }
    else if ( v19 == 255 || v19 == 170 )
    {
LABEL_37:
      v23 = &unk_15F55;
      v24 = 3747;
      goto LABEL_39;
    }
    _const_udelay(4295000);
LABEL_23:
    v25 = 0;
    v26 = 0;
    ktime_get_coarse_real_ts64(&v25);
    v15 = timespec64_to_jiffies(&v25);
    if ( (unsigned int)jiffies_to_msecs(v15) > v12 + 800 )
      goto LABEL_19;
  }
  v23 = &unk_15F14;
  v24 = 3741;
LABEL_39:
  printk(v23, "haptic_hv", v24, "tiktap_work_routine");
LABEL_40:
  if ( (cpu_latency_qos_request_active(&aw_pm_qos_req_vb) & 1) != 0 )
    cpu_latency_qos_remove_request(&aw_pm_qos_req_vb);
LABEL_14:
  *(_BYTE *)(a1 - 16) = 1;
LABEL_15:
  result = mutex_unlock(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
