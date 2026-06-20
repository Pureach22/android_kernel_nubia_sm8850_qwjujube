__int64 __fastcall llcc_enable(__int64 a1, char a2)
{
  __int64 v3; // x8
  unsigned int v4; // w20
  unsigned int v5; // w9
  unsigned __int64 v6; // x8
  _QWORD *v7; // x25
  _QWORD *v8; // x28
  unsigned int v9; // w0
  unsigned int v11; // w20

  if ( (a2 & 1) == 0 )
  {
    _disable_subcaches(a1);
    return 0;
  }
  if ( (msm_vidc_syscache_disable & 1) != 0 || !*(_DWORD *)(*(_QWORD *)(a1 + 3912) + 120LL) )
    return 0;
  v3 = *(_QWORD *)(a1 + 3904);
  v4 = 0;
  v5 = *(_DWORD *)(v3 + 104);
  v6 = *(_QWORD *)(v3 + 96);
  if ( v6 >= v6 + 24LL * v5 )
  {
LABEL_13:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_928C3, "high", 0xFFFFFFFFLL, "codec", v4);
    return 0;
  }
  v7 = (_QWORD *)(v6 + 8);
  while ( 1 )
  {
    v8 = v7 - 1;
    v9 = llcc_slice_activate(*(v7 - 1));
    if ( v9 )
      break;
    *((_BYTE *)v7 + 12) = 1;
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_902DE, "high", 0xFFFFFFFFLL, "codec", *v7);
    ++v4;
    v7 += 3;
    if ( (unsigned __int64)(v8 + 3) >= *(_QWORD *)(*(_QWORD *)(a1 + 3904) + 96LL)
                                     + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 104LL) )
      goto LABEL_13;
  }
  v11 = v9;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_7FD97, "err ", 0xFFFFFFFFLL, "codec", *v7);
  __break(0x800u);
  _disable_subcaches(a1);
  return v11;
}
