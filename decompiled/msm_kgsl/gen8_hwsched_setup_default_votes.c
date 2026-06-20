__int64 __fastcall gen8_hwsched_setup_default_votes(__int64 a1)
{
  unsigned int v2; // w21
  _BYTE *v3; // x23
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w25
  int v7; // w22
  int v8; // w0
  unsigned int v9; // w22
  int v10; // w0
  int v11; // w8
  int v12; // w9
  int v13; // w22
  int v14; // w0
  int v15; // w8
  unsigned int v16; // w22
  int v17; // w0
  __int64 v18; // x22
  _BYTE *v19; // x25
  unsigned __int64 v27; // x24
  unsigned __int64 v30; // x9

  if ( *(_BYTE *)(a1 + 14232) == 1 )
    return (unsigned int)kgsl_pwrctrl_setup_default_votes(a1);
  v3 = (_BYTE *)(a1 + 23560);
  v4 = to_gen8_hfi(a1);
  v5 = v4;
  if ( *(_DWORD *)(a1 + 10048) <= *(_DWORD *)(a1 + 10552) )
    v6 = *(_DWORD *)(a1 + 10552);
  else
    v6 = *(_DWORD *)(a1 + 10048);
  _X8 = (unsigned __int64 *)(v4 + 936);
  __asm { PRFM            #0x11, [X8] }
  do
    v27 = __ldxr(_X8);
  while ( __stlxr(v27 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
  __dmb(0xBu);
  if ( *v3 == 1 )
  {
    v7 = *(unsigned __int8 *)(a1 + 8660);
    v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))gen8_hwsched_hfi_set_value)(
           a1,
           131,
           0,
           *(unsigned __int8 *)(a1 + 8660));
    v2 = 0;
    if ( v8 )
    {
      v2 = v8;
      dev_err(
        *(_QWORD *)(a1 + 1544) + 16LL,
        "Failed to set %s for value %u for HFI type %u, ret: %d\n",
        "default",
        v7,
        131,
        v8);
    }
  }
  else
  {
    v2 = 0;
  }
  if ( v6 )
  {
    v9 = *(_DWORD *)(a1 + 10068) - v6;
    v10 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))gen8_hwsched_hfi_set_value)(a1, 108, 0, v9);
    v2 = 0;
    if ( v10 )
    {
      v2 = v10;
      dev_err(
        *(_QWORD *)(a1 + 1544) + 16LL,
        "Failed to set %s for value %u for HFI type %u, ret: %d\n",
        "default",
        v9,
        108,
        v10);
    }
  }
  v11 = *(_DWORD *)(a1 + 10068);
  v12 = *(_DWORD *)(a1 + 10060);
  if ( v12 != v11 - 1
    && (v13 = v11 - v12,
        v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))gen8_hwsched_hfi_set_value)(
                a1,
                105,
                0,
                (unsigned int)(v11 - v12)),
        v2 = 0,
        v14) )
  {
    v2 = v14;
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Failed to set %s for value %u for HFI type %u, ret: %d\n",
      "default",
      v13,
      105,
      v14);
    v15 = *(_DWORD *)(a1 + 10056);
    if ( v15 )
    {
LABEL_16:
      v16 = *(_DWORD *)(a1 + 10068) - v15;
      v17 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))gen8_hwsched_hfi_set_value)(a1, 104, 0, v16);
      v2 = 0;
      if ( v17 )
      {
        v2 = v17;
        dev_err(
          *(_QWORD *)(a1 + 1544) + 16LL,
          "Failed to set %s for value %u for HFI type %u, ret: %d\n",
          "default",
          v16,
          104,
          v17);
      }
    }
  }
  else
  {
    v15 = *(_DWORD *)(a1 + 10056);
    if ( v15 )
      goto LABEL_16;
  }
  v18 = 0;
  v19 = (_BYTE *)(a1 + 23764);
  do
  {
    if ( *v19 == 1 )
      gen8_hwsched_set_tuning_attrs((_QWORD *)a1, 132, v18, *((_DWORD *)v19 - 1));
    ++v18;
    v19 += 8;
  }
  while ( v18 != 17 );
  if ( (v27 & 0x2000) != 0 )
  {
    _X8 = (unsigned __int64 *)(v5 + 936);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 | 0x2000, _X8) );
  }
  *v3 = 0;
  return v2;
}
