__int64 __fastcall cali_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x24
  int v6; // w0
  int v7; // w21
  int v8; // w22
  _DWORD *v9; // x8
  unsigned int (__fastcall *v10)(_QWORD); // x8
  unsigned int v11; // w8
  unsigned int v12; // w9
  int v13; // w21
  unsigned int v14; // w22
  unsigned int v15; // w23
  unsigned int v16; // w4
  unsigned int v17; // w21
  int v18; // w8
  int v19; // w9
  unsigned int v21; // w9
  int v22; // w11
  int v23; // w11
  void (__fastcall *v24)(__int64, __int64); // x8
  void (__fastcall *v25)(_QWORD); // x8
  int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v26 = 0;
  v6 = kstrtouint(a3, 0, &v26);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else if ( v26 )
  {
    mutex_lock(v5 + 584);
    v7 = *(_DWORD *)(v5 + 960);
    v8 = *(unsigned __int8 *)(v5 + 954);
    v9 = *(_DWORD **)(*(_QWORD *)(v5 + 1312) + 280LL);
    if ( *(v9 - 1) != -746885483 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v9)(v5 - 168, 0);
    v10 = **(unsigned int (__fastcall ***)(_QWORD))(v5 + 1312);
    if ( *((_DWORD *)v10 - 1) != 1361900016 )
      __break(0x8228u);
    if ( v10(v5 - 168) )
    {
      printk(&unk_14C45, "haptic_hv", 682, "f0_cali");
    }
    else
    {
      v11 = (v8 + 100) * v7;
      v12 = (100 - v8) * v7;
      v13 = *(_DWORD *)(v5 - 72);
      v14 = v11 / 0x64;
      v15 = v12 / 0x64;
      printk(&unk_14DD0, "haptic_hv", 688, "f0_cali");
      v16 = *(_DWORD *)(v5 - 72);
      if ( v16 < v15 || v16 > v14 )
      {
        printk(&unk_161AA, "haptic_hv", 693, "f0_cali");
LABEL_28:
        mutex_unlock(v5 + 584);
        goto LABEL_15;
      }
      printk(&unk_16A80, "haptic_hv", 697, "f0_cali");
      v17 = 100000 * (v13 - *(_DWORD *)(v5 + 960)) / (24 * v13);
      printk(&unk_142C9, "haptic_hv", 702, "f0_cali");
      if ( (v17 & 0x80000000) != 0 )
      {
        v21 = -v17 / 0xA;
        v18 = *(unsigned __int8 *)(v5 + 1611);
        v22 = ~v21;
        v19 = v18 - v21;
        v23 = v18 + v22;
        if ( -v17 % 0xA >= 5 )
          v19 = v23;
      }
      else
      {
        v18 = *(unsigned __int8 *)(v5 + 1611);
        v19 = v17 / 0xA + v18;
        if ( v17 % 0xA > 4 )
          ++v19;
      }
      if ( v19 >= v18 )
        v18 = -v18;
      *(_DWORD *)(v5 - 32) = (unsigned __int8)(v18 + v19);
      printk(&unk_141A1, "haptic_hv", 721, "f0_cali");
    }
    v24 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1312) + 280LL);
    if ( *((_DWORD *)v24 - 1) != -746885483 )
      __break(0x8228u);
    v24(v5 - 168, 1);
    v25 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1312) + 56LL);
    if ( *((_DWORD *)v25 - 1) != -2072377296 )
      __break(0x8228u);
    v25(v5 - 168);
    goto LABEL_28;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return a4;
}
