__int64 __fastcall synx_native_signal_core(unsigned __int64 a1, unsigned int a2, char a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x5
  unsigned __int64 v9; // x26
  unsigned __int64 v10; // x25
  __int64 *v11; // x28
  _QWORD *v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x1
  unsigned __int64 v17; // x28
  __int64 v18; // x20
  unsigned int v19; // w25
  __int64 v20; // x26
  unsigned __int64 bind_ops; // x0
  __int64 v22; // x5
  _QWORD *v23; // x24
  _DWORD *v24; // x8
  __int64 v25; // x2
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x0
  _DWORD *v28; // x8
  __int64 v29; // x0
  unsigned int v30; // [xsp+4h] [xbp-DCh] BYREF
  __int64 v31; // [xsp+8h] [xbp-D8h] BYREF
  _QWORD v32[26]; // [xsp+10h] [xbp-D0h] BYREF

  result = 4294967274LL;
  v32[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = a4;
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_48;
  v30 = 0;
  synx_util_callback_dispatch(a1);
  if ( !*(_DWORD *)(a1 + 132) )
    goto LABEL_47;
  v9 = 0;
  v10 = 0;
  v11 = (__int64 *)(a1 + 136);
  memset(v32, 0, 192);
  do
  {
    if ( (a3 & 1) == 0 )
    {
      if ( v9 > 8 || v10 >= 9 )
      {
LABEL_49:
        __break(0x5512u);
LABEL_50:
        __break(1u);
      }
      goto LABEL_6;
    }
    if ( v9 >= 8 )
      goto LABEL_49;
    if ( v31 != *v11 )
    {
      if ( v10 > 8 )
        goto LABEL_49;
LABEL_6:
      v12 = &v32[3 * v10];
      v13 = *v11;
      v14 = v11[1];
      v15 = v11[2];
      ++v10;
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
      *v12 = v13;
      v12[1] = v14;
      v12[2] = v15;
      goto LABEL_7;
    }
    if ( (synx_debug & 0x10) != 0 )
      printk(&unk_2A8A4, "verb", "synx_native_signal_core", 455, v31, v8);
    v16 = *((unsigned int *)v11 + 2);
    *v11 = 0;
    v11[1] = 0;
    v11[2] = 0;
    synx_util_remove_data(&v31, v16);
LABEL_7:
    ++v9;
    v11 += 3;
  }
  while ( v9 < *(unsigned int *)(a1 + 132) );
  *(_DWORD *)(a1 + 132) = 0;
  if ( v10 )
  {
    v17 = 0;
    v18 = 24 * v10;
    do
    {
      if ( v17 == 192 )
        goto LABEL_49;
      v30 = v32[v17 / 8];
      if ( v17 - 176 < 0xFFFFFFFFFFFFFF40LL || v17 - 184 < 0xFFFFFFFFFFFFFF40LL )
        goto LABEL_50;
      v19 = v32[v17 / 8 + 1];
      v20 = v32[v17 / 8 + 2];
      bind_ops = synx_util_get_bind_ops(v19);
      if ( !bind_ops || (v23 = (_QWORD *)bind_ops, bind_ops >= 0xFFFFFFFFFFFFF001LL) )
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_28DBA, &unk_29207, "synx_native_signal_core", 480, v19, v22);
        goto LABEL_21;
      }
      synx_util_remove_data(&v30, v19);
      v24 = (_DWORD *)v23[1];
      v25 = v30;
      if ( *(v24 - 1) != 2137877367 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(_QWORD, __int64, __int64))v24)(synx_external_callback, v20, v25) & 0x80000000) != 0 )
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_29407, &unk_29207, "synx_native_signal_core", 497, v30, v19);
        goto LABEL_22;
      }
      if ( (synx_debug & 0x10) != 0 )
      {
        printk(&unk_27176, "verb", "synx_native_signal_core", 502, v30, v19);
        v26 = (__int64 (__fastcall *)(_QWORD))v23[2];
        if ( v26 )
        {
LABEL_33:
          v27 = v30;
          if ( *((_DWORD *)v26 - 1) != -841055669 )
            __break(0x8228u);
          if ( (v26(v27) & 0x80000000) != 0 && (synx_debug & 1) != 0 )
            printk(&unk_271BB, &unk_29207, "synx_native_signal_core", 509, v30, v19);
        }
      }
      else
      {
        v26 = (__int64 (__fastcall *)(_QWORD))v23[2];
        if ( v26 )
          goto LABEL_33;
      }
      v28 = (_DWORD *)v23[3];
      v29 = v30;
      if ( *(v28 - 1) != -1209982386 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(__int64, _QWORD))v28)(v29, a2) & 0x80000000) != 0 && (synx_debug & 1) != 0 )
        printk(&unk_2A52B, &unk_29207, "synx_native_signal_core", 515, v30, v19);
LABEL_21:
      kfree(v20);
LABEL_22:
      v17 += 24LL;
    }
    while ( v18 != v17 );
  }
LABEL_47:
  result = 0;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
