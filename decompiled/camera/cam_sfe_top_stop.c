__int64 __fastcall cam_sfe_top_stop(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x21
  int *v5; // x20
  __int64 v6; // x23
  __int64 result; // x0
  __int64 v8; // x22
  int v9; // w8
  __int64 v10; // x9
  int v11; // w22
  __int16 v12; // w9
  __int16 v13; // w9
  int v14; // w0
  __int64 v15; // x8

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_stop",
      2139,
      "Invalid args");
    return 4294967274LL;
  }
  if ( (unsigned int)(*(_DWORD *)(a2 + 8) - 1) < 2 )
    return 0;
  *(_DWORD *)(a2 + 8) = 2;
  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_QWORD *)(a2 + 24);
  v5 = (int *)(a1 + 32228);
  if ( *(_DWORD *)(a1 + 22588) == v2 )
  {
    v6 = 0;
  }
  else if ( *(_DWORD *)(a1 + 22740) == v2 )
  {
    v6 = 1;
  }
  else if ( *(_DWORD *)(a1 + 22892) == v2 )
  {
    v6 = 2;
  }
  else if ( *(_DWORD *)(a1 + 23044) == v2 )
  {
    v6 = 3;
  }
  else if ( *(_DWORD *)(a1 + 23196) == v2 )
  {
    v6 = 4;
  }
  else
  {
    v8 = a2;
    if ( *(_DWORD *)(a1 + 23348) != v2 )
      goto LABEL_20;
    v6 = 5;
  }
  v8 = a2;
  if ( (*(_BYTE *)(a1 + 32320) & 1) == 0 )
    *(_QWORD *)(a1 + 8 * v6 + 23512) = 0;
  memset((void *)(a1 + 608LL * (unsigned int)v6 + 24184), 0, 0x260u);
  *(_DWORD *)(a1 + 4 * v6 + 31584) = 0;
LABEL_20:
  if ( *(int *)(v3 + 68) >= 1 )
  {
    ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 32));
    *(_DWORD *)(v3 + 68) = 0;
  }
  v9 = *v5;
  if ( (*v5 & 4) != 0 )
  {
    v10 = *(unsigned int *)(v8 + 4);
    if ( (unsigned int)v10 <= 5 )
    {
      v11 = dword_44E3D0[v10];
      v12 = *((_WORD *)v5 + 17);
      if ( !v12 )
        goto LABEL_25;
LABEL_29:
      v13 = v12 - 1;
      *((_WORD *)v5 + 17) = v13;
      if ( (v9 & 6) == 0 || v13 )
      {
        if ( (v9 & 4) == 0 )
          goto LABEL_33;
LABEL_35:
        v14 = cam_io_r(*(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 28LL));
        cam_io_w(v14 & (unsigned int)~v11, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 28LL));
        if ( !*((_WORD *)v5 + 17) )
          goto LABEL_36;
        return 0;
      }
LABEL_31:
      v11 |= *(_DWORD *)(*(_QWORD *)(v3 + 32) + 4LL);
      goto LABEL_35;
    }
  }
  v11 = 0;
  v12 = *((_WORD *)v5 + 17);
  if ( v12 )
    goto LABEL_29;
LABEL_25:
  if ( (v9 & 6) != 0 )
    goto LABEL_31;
  v13 = 0;
  if ( (v9 & 4) != 0 )
    goto LABEL_35;
LABEL_33:
  if ( v13 )
    return 0;
LABEL_36:
  if ( (v5[23] & 1) == 0 )
    *(_QWORD *)(a1 + 23504) = 0;
  if ( v5[7] >= 1 )
  {
    ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 32));
    v5[7] = 0;
  }
  v15 = *(_QWORD *)(a1 + 16);
  if ( !*(_DWORD *)(v15 + 84) )
    return 0;
  if ( *((_BYTE *)v5 + 12) == 1 )
  {
    cam_io_w_mb(0, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 88LL));
    v15 = *(_QWORD *)(a1 + 16);
  }
  *((_BYTE *)v5 + 12) = 0;
  result = 0;
  if ( *(_DWORD *)(v15 + 84) >= 2u )
  {
    if ( *((_BYTE *)v5 + 20) == 1 )
    {
      cam_io_w_mb(0, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 112LL));
      v15 = *(_QWORD *)(a1 + 16);
    }
    *((_BYTE *)v5 + 20) = 0;
    result = 0;
    if ( *(_DWORD *)(v15 + 84) > 2u )
    {
      __break(0x5512u);
      return 0;
    }
  }
  return result;
}
