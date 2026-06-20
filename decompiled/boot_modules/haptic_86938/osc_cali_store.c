__int64 __fastcall osc_cali_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x26
  int v6; // w0
  _DWORD *v7; // x8
  unsigned int v8; // w20
  __int64 (__fastcall *v9)(_QWORD); // x8
  unsigned int v10; // w0
  void (__fastcall *v11)(__int64, __int64); // x8
  unsigned int v13; // w8
  unsigned int v14; // w8
  __int64 v15; // x2
  unsigned int v16; // w8
  unsigned int v17; // w23
  unsigned int v18; // w8
  unsigned int v19; // w9
  unsigned int v20; // w10
  unsigned int v21; // w9
  unsigned int v22; // kr04_4
  unsigned int v23; // w24
  __int64 v24; // x8
  void (__fastcall *v25)(__int64, __int64); // x8
  int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v26 = 0;
  v6 = kstrtouint(a3, 0, &v26);
  if ( (v6 & 0x80000000) == 0 )
  {
    mutex_lock(v5 + 584);
    if ( v26 == 2 )
    {
      v11 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 1312) + 280LL);
      if ( *((_DWORD *)v11 - 1) != -746885483 )
        __break(0x8228u);
      v11(v5 - 168, 2);
      rtp_osc_cali(v5 - 168);
      goto LABEL_14;
    }
    if ( v26 != 1 )
    {
LABEL_14:
      mutex_unlock(v5 + 584);
      goto LABEL_15;
    }
    v7 = *(_DWORD **)(*(_QWORD *)(v5 + 1312) + 280LL);
    if ( *(v7 - 1) != -746885483 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v7)(v5 - 168, 0);
    rtp_osc_cali(v5 - 168);
    v8 = *(_DWORD *)(v5 - 8);
    v9 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v5 + 1312) + 392LL);
    if ( *((_DWORD *)v9 - 1) != 161711603 )
      __break(0x8228u);
    v10 = v9(v5 - 168);
    if ( v10 == v8 )
    {
      printk(&unk_157E5, "haptic_hv", 869, "rtp_trim_lra_cali");
      goto LABEL_14;
    }
    if ( v10 >= v8 )
    {
      v14 = v10 - v8;
      if ( v10 <= v8 )
      {
        v16 = *(unsigned __int8 *)(v5 + 1611);
        v17 = 0;
      }
      else
      {
        if ( v14 > v10 / 0x32 )
        {
          printk(&unk_14C84, "haptic_hv", 892, "rtp_trim_lra_cali");
          goto LABEL_14;
        }
        if ( v14 < 10 * v10 / 0x2710 )
        {
          v15 = 898;
          goto LABEL_27;
        }
        v22 = v14 / (v10 / 0x186A0);
        v16 = *(unsigned __int8 *)(v5 + 1611);
        v17 = v16
            - v22 / 0xF0
            - ((unsigned int)(v22 / 0x18 - 10 * ((429496730 * (unsigned __int64)(v22 / 0x18)) >> 32)) > 4);
      }
    }
    else
    {
      v13 = v8 - v10;
      if ( v8 - v10 > v10 / 0x32 )
      {
        printk(&unk_142F9, "haptic_hv", 874, "rtp_trim_lra_cali");
        goto LABEL_14;
      }
      if ( v13 < 10 * v10 / 0x2710 )
      {
        v15 = 881;
LABEL_27:
        printk(&unk_161E2, "haptic_hv", v15, "rtp_trim_lra_cali");
        goto LABEL_14;
      }
      v18 = 100000 * v13 / (24 * v10);
      v19 = v18 / 0xA;
      v20 = v18 % 0xA;
      v16 = *(unsigned __int8 *)(v5 + 1611);
      v21 = v19 + v16;
      if ( v20 <= 4 )
        v17 = v21;
      else
        v17 = v21 + 1;
    }
    if ( v17 >= v16 )
      v16 = -v16;
    v23 = v16 + v17;
    v24 = *(_QWORD *)(v5 + 1312);
    *(_DWORD *)(v5 - 16) = v23;
    v25 = *(void (__fastcall **)(__int64, __int64))(v24 + 280);
    if ( *((_DWORD *)v25 - 1) != -746885483 )
      __break(0x8228u);
    v25(v5 - 168, 2);
    printk(&unk_140A1, "haptic_hv", 936, "rtp_trim_lra_cali");
    printk(&unk_150F7, "haptic_hv", 937, "rtp_trim_lra_cali");
    goto LABEL_14;
  }
  a4 = v6;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return a4;
}
