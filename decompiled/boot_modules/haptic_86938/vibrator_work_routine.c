__int64 __fastcall vibrator_work_routine(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x21
  void (__fastcall *v4)(__int64, __int64); // x8
  void (__fastcall *v5)(_QWORD); // x8
  unsigned int v7; // w4
  unsigned int v8; // w9
  unsigned int v9; // w22
  unsigned int v10; // w23
  _DWORD *v11; // x8
  _DWORD *v12; // x8
  _DWORD *v13; // x8
  _DWORD *v14; // x8
  int v15; // w8
  __int64 v16; // x8
  void (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w8
  void (__fastcall *v19)(__int64, __int64); // x8
  void (__fastcall *v20)(__int64, __int64); // x8
  void (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x1
  void (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x1
  void (__fastcall *v25)(__int64, __int64); // x8
  void (__fastcall *v26)(__int64, __int64); // x8
  void (__fastcall *v27)(__int64, __int64); // x8
  void (__fastcall *v28)(__int64, __int64); // x8
  __int64 v29; // x1
  void *v30; // x0
  __int64 v31; // x2
  signed int v32; // w8
  void (__fastcall *v33)(__int64, __int64); // x9
  __int64 v34; // x1

  v1 = a1 - 312;
  v3 = a1 - 1064;
  mutex_lock(a1 - 312);
  v4 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 280LL);
  if ( *((_DWORD *)v4 - 1) != -746885483 )
    __break(0x8228u);
  v4(v3, 1);
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 416) + 56LL);
  if ( *((_DWORD *)v5 - 1) != -2072377296 )
    __break(0x8228u);
  v5(v3);
  if ( *(_DWORD *)(a1 - 1000) )
  {
    printk(&unk_1584F, "haptic_hv", 962, "ram_select_waveform");
    v7 = *(_DWORD *)(a1 - 980);
    if ( (int)v7 > 0 )
    {
      v8 = *(unsigned __int8 *)(a1 + 60);
      *(_BYTE *)(a1 - 1037) = 1;
      if ( v7 >= v8 )
      {
        if ( v7 >= *(unsigned __int8 *)(a1 + 61) )
        {
          if ( v7 >= *(unsigned __int8 *)(a1 + 62) )
          {
            v10 = 4;
            v9 = 15;
            *(_BYTE *)(a1 - 1037) = 5;
          }
          else
          {
            v9 = 0;
            v10 = 1;
          }
        }
        else
        {
          v9 = 0;
          v10 = 2;
        }
      }
      else
      {
        v9 = 0;
        v10 = 3;
      }
      printk(&unk_149EA, "haptic_hv", 982, "ram_select_waveform");
      v11 = *(_DWORD **)(*(_QWORD *)(a1 + 416) + 192LL);
      if ( *(v11 - 1) != 2072477285 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v11)(v3, 0, v10);
      v12 = *(_DWORD **)(*(_QWORD *)(a1 + 416) + 200LL);
      if ( *(v12 - 1) != 2072477285 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v12)(v3, 0, v9);
      v13 = *(_DWORD **)(*(_QWORD *)(a1 + 416) + 192LL);
      if ( *(v13 - 1) != 2072477285 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v13)(v3, 1, 0);
      v14 = *(_DWORD **)(*(_QWORD *)(a1 + 416) + 200LL);
      if ( *(v14 - 1) != 2072477285 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v14)(v3, 1, 0);
    }
    else
    {
      printk(&unk_148E9, "haptic_hv", 964, "ram_select_waveform");
    }
    v15 = *(unsigned __int8 *)(a1 - 1037);
    if ( v15 == 4 )
    {
      v21 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 416) + 72LL);
      if ( *((_DWORD *)v21 - 1) != -2072377296 )
        __break(0x8228u);
      v21(v3);
      goto LABEL_39;
    }
    if ( v15 != 5 )
    {
      if ( v15 == 1 )
      {
        v22 = *(unsigned int *)(a1 - 1012);
        v23 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 136LL);
        if ( *((_DWORD *)v23 - 1) != 487251822 )
          __break(0x8228u);
        v23(v3, v22);
        printk(&unk_14CD6, "haptic_hv", 665, "ram_vbat_comp");
        v24 = *(unsigned __int8 *)(a1 + 111);
        v25 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 160LL);
        if ( *(unsigned __int8 *)(a1 + 57) <= (unsigned int)(unsigned __int8)(v24 - 1) )
          v24 = *(unsigned int *)(a1 - 1016);
        if ( *((_DWORD *)v25 - 1) != 487251822 )
          __break(0x8228u);
        v25(v3, v24);
        v26 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 152LL);
        if ( *((_DWORD *)v26 - 1) != 487251822 )
          __break(0x8228u);
        v26(v3, 1);
        v27 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 96LL);
        if ( *((_DWORD *)v27 - 1) != 487251822 )
          __break(0x8228u);
        v27(v3, 1);
      }
      else
      {
        printk(&unk_16439, "haptic_hv", 1035, "vibrator_work_routine");
      }
      return mutex_unlock(v1);
    }
    v16 = *(_QWORD *)(a1 + 416);
    if ( *(_BYTE *)(a1 - 1036) == 1 )
    {
      v17 = *(void (__fastcall **)(_QWORD))(v16 + 64);
      if ( *((_DWORD *)v17 - 1) != -2072377296 )
        __break(0x8228u);
      v17(v3);
      v18 = *(_DWORD *)(a1 - 960);
      if ( v18 > 0x1194 )
        goto LABEL_31;
      v32 = 4500 * *(_DWORD *)(a1 - 1012) / v18;
      v33 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 136LL);
      if ( v32 >= 192 )
        v34 = 192;
      else
        v34 = (unsigned int)v32;
      if ( *((_DWORD *)v33 - 1) != 487251822 )
        __break(0x8229u);
      v33(v3, v34);
      v30 = &unk_15263;
      v31 = 658;
    }
    else
    {
      v28 = *(void (__fastcall **)(__int64, __int64))(v16 + 136);
      v29 = *(unsigned int *)(a1 - 1012);
      if ( *((_DWORD *)v28 - 1) != 487251822 )
        __break(0x8228u);
      v28(v3, v29);
      v30 = &unk_14CD6;
      v31 = 661;
    }
    printk(v30, "haptic_hv", v31, "ram_vbat_comp");
LABEL_31:
    v19 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 152LL);
    if ( *((_DWORD *)v19 - 1) != 487251822 )
      __break(0x8228u);
    v19(v3, 5);
    v20 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 416) + 96LL);
    if ( *((_DWORD *)v20 - 1) != 487251822 )
      __break(0x8228u);
    v20(v3, 1);
LABEL_39:
    hrtimer_start_range_ns(
      a1 - 248,
      1000000 * (*(_DWORD *)(a1 - 980) % 1000) + 1000000000LL * (*(_DWORD *)(a1 - 980) / 1000),
      0,
      1);
  }
  return mutex_unlock(v1);
}
