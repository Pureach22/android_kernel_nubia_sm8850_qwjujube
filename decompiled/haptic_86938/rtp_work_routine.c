__int64 __fastcall rtp_work_routine(__int64 a1)
{
  __int64 v1; // x19
  unsigned int *v3; // x25
  __int64 v4; // x8
  __int64 v5; // x0
  unsigned __int64 v6; // x21
  _DWORD *v7; // x0
  unsigned int v8; // w9
  __int64 v9; // x9
  void (__fastcall *v10)(__int64, __int64); // x8
  _DWORD *v11; // x8
  void (__fastcall *v12)(_QWORD); // x8
  void (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x1
  void (__fastcall *v15)(__int64, __int64); // x8
  __int64 v16; // x1
  void (__fastcall *v17)(__int64, __int64); // x8
  void (__fastcall *v18)(__int64, __int64); // x8
  void (__fastcall *v19)(__int64, __int64); // x8
  int v20; // w22
  __int64 (__fastcall *v21)(_QWORD); // x8
  void (__fastcall *v23)(_QWORD); // x8
  _DWORD *v24; // x27
  _BYTE *v25; // x26
  unsigned __int8 (__fastcall *v26)(_QWORD); // x8
  unsigned int v27; // w9
  __int64 v28; // x10
  __int64 v29; // x1
  _DWORD *v30; // x12
  unsigned int v31; // w22
  __int64 v32; // x9
  __int64 (__fastcall *v33)(_QWORD); // x8
  char v34; // w0
  void *v35; // x0
  __int64 v36; // x2
  void (__fastcall *v37)(__int64, __int64); // x8
  __int64 result; // x0
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 - 48;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  mutex_lock(a1 - 48);
  v3 = (unsigned int *)(a1 - 784);
  v4 = *(unsigned int *)(a1 - 784);
  *(_BYTE *)(a1 - 899) = 1;
  if ( (unsigned int)v4 >= 6 )
    goto LABEL_65;
  if ( (request_firmware(v39, &aw_rtp_name[64 * v4], *(_QWORD *)(a1 - 128)) & 0x80000000) != 0 )
  {
    if ( *v3 <= 5 )
    {
      printk(&unk_14D82, "haptic_hv", 1133, "rtp_work_routine");
      v5 = v1;
      goto LABEL_64;
    }
    goto LABEL_65;
  }
  *(_BYTE *)(a1 - 923) = 0;
  vfree(aw_rtp);
  v6 = *(_QWORD *)v39[0] + 4LL;
  v7 = (_DWORD *)vmalloc_noprof(v6);
  aw_rtp = (__int64)v7;
  if ( !v7 )
  {
    release_firmware(v39[0]);
    printk(&unk_155B6, "haptic_hv", 1143, "rtp_work_routine");
    v5 = v1;
    goto LABEL_64;
  }
  if ( v6 < 4 )
LABEL_66:
    __break(1u);
  v8 = *v3;
  *v7 = *(_DWORD *)v39[0];
  if ( v8 > 5 )
  {
LABEL_65:
    __break(0x5512u);
    goto LABEL_66;
  }
  printk(&unk_1640B, "haptic_hv", 1150, "rtp_work_routine");
  memcpy((void *)(aw_rtp + 4), *(const void **)(v39[0] + 8LL), *(_QWORD *)v39[0]);
  mutex_unlock(v1);
  release_firmware(v39[0]);
  mutex_lock(a1 - 176);
  v9 = *(_QWORD *)(a1 + 552);
  *(_BYTE *)(a1 - 923) = 1;
  v10 = *(void (__fastcall **)(__int64, __int64))(v9 + 280);
  if ( *((_DWORD *)v10 - 1) != -746885483 )
    __break(0x8228u);
  v10(a1 - 928, 2);
  v11 = *(_DWORD **)(*(_QWORD *)(a1 + 552) + 272LL);
  if ( *(v11 - 1) != 487251822 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v11)(a1 - 928, 0);
  v12 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 552) + 240LL);
  if ( *((_DWORD *)v12 - 1) != -2072377296 )
    __break(0x8228u);
  v12(a1 - 928);
  v13 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 552) + 56LL);
  if ( *((_DWORD *)v13 - 1) != -2072377296 )
    __break(0x8228u);
  v13(a1 - 928);
  v14 = *(unsigned int *)(a1 - 876);
  v15 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 552) + 136LL);
  if ( *((_DWORD *)v15 - 1) != 487251822 )
    __break(0x8228u);
  v15(a1 - 928, v14);
  printk(&unk_14CD6, "haptic_hv", 665, "ram_vbat_comp");
  v16 = *(unsigned __int8 *)(a1 + 248);
  v17 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 552) + 160LL);
  if ( *(unsigned __int8 *)(a1 + 193) <= (unsigned int)(unsigned __int8)(v16 - 1) )
    v16 = *(unsigned int *)(a1 - 880);
  if ( *((_DWORD *)v17 - 1) != 487251822 )
    __break(0x8228u);
  v17(a1 - 928, v16);
  v18 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 552) + 152LL);
  if ( *((_DWORD *)v18 - 1) != 487251822 )
    __break(0x8228u);
  v18(a1 - 928, 2);
  v19 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 552) + 96LL);
  if ( *((_DWORD *)v19 - 1) != 487251822 )
    __break(0x8228u);
  v19(a1 - 928, 1);
  usleep_range_state(2000, 2500, 2);
  v20 = -200;
  while ( 1 )
  {
    v21 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 552) + 352LL);
    if ( *((_DWORD *)v21 - 1) != 2018195540 )
      __break(0x8228u);
    if ( (v21(a1 - 928) & 0xF) == 8 )
      break;
    usleep_range_state(2000, 2500, 2);
    if ( __CFADD__(v20++, 1) )
    {
      v23 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 552) + 56LL);
      if ( *((_DWORD *)v23 - 1) != -2072377296 )
        __break(0x8228u);
      v23(a1 - 928);
      printk(&unk_15293, "haptic_hv", 1192, "rtp_work_routine");
      goto LABEL_63;
    }
  }
  printk(&unk_14E37, "haptic_hv", 1180, "rtp_work_routine");
  usleep_range_state(2000, 2500, 2);
  cpu_latency_qos_add_request(&aw_pm_qos_req_vb, 0);
  v24 = (_DWORD *)(a1 - 812);
  *(_DWORD *)(a1 - 812) = 0;
  mutex_lock(v1);
  v25 = (_BYTE *)(a1 - 905);
  while ( 1 )
  {
    v26 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 552) + 368LL);
    if ( *((_DWORD *)v26 - 1) != 2018195540 )
      __break(0x8228u);
    if ( v26(a1 - 928) )
      break;
    if ( *v25 != 2 )
      goto LABEL_62;
    if ( !aw_rtp )
    {
      printk(&unk_15BBB, "haptic_hv", 1059, "rtp_play");
      break;
    }
    v27 = *(_DWORD *)(a1 + 184);
    v28 = (unsigned int)*v24;
    v29 = aw_rtp + v28 + 4;
    if ( (unsigned int)v28 >= v27 )
      v27 >>= 2;
    v30 = *(_DWORD **)(*(_QWORD *)(a1 + 552) + 208LL);
    if ( *(_DWORD *)aw_rtp - (int)v28 >= v27 )
      v31 = v27;
    else
      v31 = *(_DWORD *)aw_rtp - v28;
    if ( *(v30 - 1) != -962088293 )
      __break(0x822Cu);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v30)(a1 - 928, v29, v31);
    v32 = *(_QWORD *)(a1 + 552);
    *v24 += v31;
    v33 = *(__int64 (__fastcall **)(_QWORD))(v32 + 352);
    if ( *((_DWORD *)v33 - 1) != 2018195540 )
      __break(0x8228u);
    v34 = v33(a1 - 928);
    if ( *v24 == *(_DWORD *)aw_rtp || (v34 & 0xF) == 0 )
    {
      if ( *v24 == *(_DWORD *)aw_rtp )
      {
        v35 = &unk_16B25;
        v36 = 1101;
      }
      else
      {
        v35 = &unk_15EB5;
        v36 = 1099;
      }
      printk(v35, "haptic_hv", v36, "rtp_play");
      *v24 = 0;
      break;
    }
  }
  if ( *v25 == 2 )
  {
    v37 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 552) + 272LL);
    if ( *((_DWORD *)v37 - 1) != 487251822 )
      __break(0x8228u);
    v37(a1 - 928, 1);
  }
LABEL_62:
  mutex_unlock(v1);
  cpu_latency_qos_remove_request(&aw_pm_qos_req_vb);
LABEL_63:
  v5 = a1 - 176;
LABEL_64:
  *(_BYTE *)(a1 - 899) = 0;
  result = mutex_unlock(v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
