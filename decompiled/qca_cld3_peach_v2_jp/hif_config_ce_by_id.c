__int64 __fastcall hif_config_ce_by_id(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  unsigned int v3; // w21
  __int64 v4; // x22
  __int64 v6; // x23
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x24
  _DWORD *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w8
  unsigned int v14; // w8
  unsigned int v21; // w10

  if ( (int)a2 > 11 )
    return 4294967274LL;
  if ( a2 >= 0xD )
  {
    __break(0x5512u);
LABEL_19:
    _X8 = (unsigned int *)(v2 + 24);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 - 1, _X8) );
    goto LABEL_16;
  }
  v6 = a1 + 480;
  v7 = a1 + 136LL * a2;
  v8 = *(_QWORD *)(a1 + 480 + 8LL * a2);
  v2 = v7 + 27416;
  *(_QWORD *)(v7 + 27432) = a1;
  *(_BYTE *)(v7 + 27424) = a2;
  if ( v8 )
    return 8;
  v9 = a2;
  v4 = a1;
  v3 = a2;
  v10 = (_DWORD *)(*(_QWORD *)(a1 + 27400) + 32LL * a2);
  v11 = ce_init(a1, a2, v10);
  v12 = *(_QWORD *)(v6 + 8 * v9);
  *(_QWORD *)v2 = v11;
  if ( !v12 )
    return 16;
  *(_DWORD *)(v2 + 40) = 0;
  *(_QWORD *)(v2 + 48) = 0;
  if ( !v11 )
    return 16;
  *(_QWORD *)(v12 + 280) = 0;
  if ( (*(_BYTE *)v10 & 0x20) != 0 )
  {
    *(_QWORD *)(v4 + 29152) = *(_QWORD *)v2;
    return 0;
  }
  *(_QWORD *)(v2 + 32) = (unsigned int)v10[3];
  v13 = v10[4];
  if ( v13 )
  {
    *(_DWORD *)(v2 + 24) = init_buffer_count((unsigned int)(v13 - 1));
    v14 = *(_DWORD *)(hif_get_target_info_handle(v4) + 4);
    if ( v14 > 0x2B || ((1LL << v14) & 0xFBFFFB00000LL) == 0 )
      goto LABEL_16;
    goto LABEL_19;
  }
  *(_DWORD *)(v2 + 24) = 0;
LABEL_16:
  ce_tasklet_init(v4, (unsigned int)(1 << v3));
  ce_register_irq(v4, (unsigned int)(1 << v3));
  ((void (__fastcall *)(__int64, _QWORD))init_tasklet_worker_by_ceid)(v4, v3);
  return 0;
}
