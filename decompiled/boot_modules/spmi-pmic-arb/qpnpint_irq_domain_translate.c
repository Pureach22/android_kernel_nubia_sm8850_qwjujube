__int64 __fastcall qpnpint_irq_domain_translate(__int64 a1, _DWORD *a2, _QWORD *a3, int *a4)
{
  unsigned __int64 v4; // x9
  __int64 v5; // x19
  unsigned __int64 v6; // x8
  void *v7; // x8
  unsigned __int64 v8; // x9
  unsigned int v9; // w8
  unsigned int v10; // w9
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  int v18; // w0
  __int64 v19; // x8
  unsigned int v20; // w19

  v4 = *(_QWORD *)(a1 + 104);
  v5 = *(_QWORD *)(a1 + 32);
  v6 = 0;
  if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    v7 = *(void **)(v4 + 8);
    v8 = v4 - 24;
    if ( v7 == &of_fwnode_ops )
      v6 = v8;
    else
      v6 = 0;
  }
  if ( v6 != *(_QWORD *)(*(_QWORD *)(v5 + 40) + 744LL) )
    return 4294967274LL;
  if ( a2[2] != 4 )
    return 4294967274LL;
  v9 = a2[3];
  if ( v9 > 0x1F )
    return 4294967274LL;
  v10 = a2[4];
  if ( v10 > 0xFF || a2[5] > 7u )
    return 4294967274LL;
  v13 = v10 | (v9 << 8);
  v14 = *(_QWORD *)(a1 + 32);
  v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)v5 + 56LL) + 32LL);
  if ( *((_DWORD *)v17 - 1) != -817839700 )
    __break(0x8228u);
  v18 = v17(v14, v13);
  if ( v18 < 0 )
  {
    v19 = *(_QWORD *)(v5 + 40);
    v20 = v18;
    dev_err(v19, "failed to xlate sid = %#x, periph = %#x, irq = %u rc = %d\n", a2[3], a2[4], a2[5], v18);
    return v20;
  }
  else
  {
    if ( (unsigned __int16)v18 > (unsigned int)*(unsigned __int16 *)(v5 + 162) )
      *(_WORD *)(v5 + 162) = v18;
    if ( (unsigned __int16)v18 < (unsigned int)*(unsigned __int16 *)(v5 + 160) )
      *(_WORD *)(v5 + 160) = v18;
    *a3 = (a2[3] << 28) | ((unsigned __int8)a2[4] << 20) | ((a2[5] & 7) << 16) | v18 & 0x1FFFu;
    *a4 = a2[6] & 0xF;
    return 0;
  }
}
