__int64 __fastcall _qcom_pmu_read(unsigned int a1, __int64 a2, __int64 *a3, char a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 *v6; // x21
  char v7; // w22
  __int64 result; // x0
  int v11; // w8
  int v12; // w9
  unsigned int v18; // w8
  unsigned int v20; // w9

  if ( qcom_pmu_inited != 1 )
    return 4294967277LL;
  result = 4294967274LL;
  if ( (_DWORD)a2
    && a3
    && ((*(_QWORD *)((char *)&_cpu_possible_mask + (((unsigned __int64)a1 >> 3) & 0x1FFFFFF8)) >> a1) & 1) != 0 )
  {
    if ( a1 < 0x20 )
    {
      v5 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[a1]);
      v11 = *(_DWORD *)(v5 + 328);
      if ( !v11 )
      {
        v12 = 0;
        v4 = 0;
        goto LABEL_12;
      }
      v4 = v5 + 8;
      if ( *(_DWORD *)(v5 + 8) == (_DWORD)a2 )
      {
        v12 = 0;
        goto LABEL_12;
      }
      if ( v11 == 1 )
        return 4294967294LL;
      v4 = v5 + 48;
      if ( *(_DWORD *)(v5 + 48) == (_DWORD)a2 )
      {
        v12 = 1;
        goto LABEL_12;
      }
      if ( v11 == 2 )
        return 4294967294LL;
      v4 = v5 + 88;
      if ( *(_DWORD *)(v5 + 88) == (_DWORD)a2 )
      {
        v12 = 2;
        goto LABEL_12;
      }
      if ( v11 == 3 )
        return 4294967294LL;
      v4 = v5 + 128;
      if ( *(_DWORD *)(v5 + 128) == (_DWORD)a2 )
      {
        v12 = 3;
        goto LABEL_12;
      }
      if ( v11 == 4 )
        return 4294967294LL;
      v4 = v5 + 168;
      if ( *(_DWORD *)(v5 + 168) == (_DWORD)a2 )
      {
        v12 = 4;
        goto LABEL_12;
      }
      if ( v11 == 5 )
        return 4294967294LL;
      v4 = v5 + 208;
      if ( *(_DWORD *)(v5 + 208) == (_DWORD)a2 )
      {
        v12 = 5;
        goto LABEL_12;
      }
      if ( v11 == 6 )
        return 4294967294LL;
      v4 = v5 + 248;
      if ( *(_DWORD *)(v5 + 248) == (_DWORD)a2 )
      {
        v12 = 6;
        goto LABEL_12;
      }
      if ( v11 == 7 )
        return 4294967294LL;
      if ( *(_DWORD *)(v5 + 288) == (_DWORD)a2 )
      {
        v4 = v5 + 288;
        v12 = 7;
        goto LABEL_12;
      }
      if ( v11 == 8 )
        return 4294967294LL;
      if ( v11 == (_DWORD)a2 )
      {
        v4 = v5 + 328;
        v12 = 8;
LABEL_12:
        if ( v12 != v11 )
        {
          v7 = a4;
          v6 = a3;
          a2 = raw_spin_lock_irqsave(v5 + 336);
          if ( (*(_BYTE *)(v5 + 1) & 1) != 0 || (*(_BYTE *)v5 & 1) != 0 || *(_BYTE *)(v5 + 2) == 1 )
          {
            raw_spin_unlock_irqrestore(v5 + 336, a2);
            *v6 = *(_QWORD *)(v4 + 24);
            return 0;
          }
          _X23 = (unsigned int *)(v5 + 332);
          goto LABEL_45;
        }
        return 4294967294LL;
      }
      if ( v11 == 9 )
        return 4294967294LL;
    }
    __break(0x5512u);
LABEL_45:
    __asm { PRFM            #0x11, [X23] }
    do
      v18 = __ldxr(_X23);
    while ( __stxr(v18 + 1, _X23) );
    raw_spin_unlock_irqrestore(v5 + 336, a2);
    *v6 = read_event(v4, v7 & 1);
    __asm { PRFM            #0x11, [X23] }
    do
      v20 = __ldxr(_X23);
    while ( __stxr(v20 - 1, _X23) );
    return 0;
  }
  return result;
}
