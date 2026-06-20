__int64 __fastcall cam_irq_controller_update_irq(__int64 result, int a2, char a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x20
  char v8; // w23
  int v9; // w22
  __int64 v10; // x22
  __int64 v11; // x23
  unsigned int v12; // w8
  __int64 v13; // x27
  char v14; // w24
  __int64 v15; // x25
  unsigned int i; // w26
  __int64 v17; // x8
  __int64 v18; // x0
  unsigned __int64 v19; // x9
  int v20; // w8
  unsigned __int64 v21; // x8
  int v22; // w8
  __int64 v23; // x10
  __int64 v24; // x23
  __int64 v25; // x25
  signed int v26; // w24
  __int64 v27; // x8
  unsigned int v28; // w9
  int v29; // w10
  __int64 v30; // x0
  unsigned int v31; // w23
  __int64 v32; // x8
  unsigned int v33; // w21

  if ( !result )
    return result;
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = result;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v6 = 0;
  }
  else
  {
    v7 = a4;
    v8 = a3;
    v9 = a2;
    result = raw_spin_lock_irqsave(result + 320);
    a2 = v9;
    a3 = v8;
    a4 = v7;
    v6 = result;
  }
  v10 = v5 + 72;
  do
  {
    v10 = *(_QWORD *)v10;
    if ( v10 == v5 + 72 )
    {
      result = 4294967274LL;
      goto LABEL_36;
    }
  }
  while ( *(_DWORD *)(v10 + 32) != a2 );
  if ( v10 != 72 )
  {
    v11 = *(unsigned int *)(v10 - 72);
    v12 = *(_DWORD *)(v5 + 24);
    if ( (int)v11 > 4 )
      goto LABEL_15;
    if ( !v12 )
      goto LABEL_22;
    if ( (unsigned int)v11 > 4 )
      goto LABEL_39;
    v13 = *(_QWORD *)(v10 - 64);
    v14 = a3;
    v15 = a4;
    for ( i = 0; i < v12; ++i )
    {
      v17 = *(_QWORD *)(v5 + 32) + 112LL * (int)i;
      *(_DWORD *)(v17 + 4 * v11 + 32) &= ~*(_DWORD *)(v13 + 4LL * (int)i);
      v18 = *(_DWORD *)(v17 + 52) & (unsigned int)~*(_DWORD *)(v13 + 4LL * (int)i);
      *(_DWORD *)(v17 + 52) = v18;
      result = cam_io_w_mb(v18, *(_QWORD *)(v5 + 16) + *(unsigned int *)(v17 + 4));
      v12 = *(_DWORD *)(v5 + 24);
    }
    a4 = v15;
    a3 = v14;
LABEL_15:
    if ( !v12 )
    {
LABEL_22:
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        goto LABEL_35;
      goto LABEL_33;
    }
    v19 = 0;
    do
    {
      v22 = *(_DWORD *)(a4 + 4 * v19);
      v23 = *(_QWORD *)(v10 - 64);
      if ( (a3 & 1) != 0 )
        v20 = *(_DWORD *)(v23 + 4 * v19) | v22;
      else
        v20 = *(_DWORD *)(v23 + 4 * v19) & ~v22;
      *(_DWORD *)(v23 + 4 * v19++) = v20;
      v21 = *(unsigned int *)(v5 + 24);
    }
    while ( v19 < v21 );
    if ( (_DWORD)v21 )
    {
      v24 = *(unsigned int *)(v10 - 72);
      if ( (int)v24 <= 4 )
      {
        if ( (unsigned int)v24 <= 4 )
        {
          v25 = *(_QWORD *)(v10 - 64);
          v26 = 0;
          do
          {
            v27 = *(_QWORD *)(v5 + 32) + 112LL * v26;
            *(_DWORD *)(v27 + 4 * v24 + 32) |= *(_DWORD *)(v25 + 4LL * v26);
            v28 = *(_DWORD *)(v25 + 4LL * v26);
            v29 = *(_DWORD *)(v27 + 52);
            *(_BYTE *)(v27 + 108) = 1;
            v30 = v29 | v28;
            *(_DWORD *)(v27 + 52) = v30;
            cam_io_w_mb(v30, *(_QWORD *)(v5 + 16) + *(unsigned int *)(v27 + 4));
            LODWORD(v21) = *(_DWORD *)(v5 + 24);
            ++v26;
          }
          while ( v26 < (unsigned int)v21 );
          goto LABEL_29;
        }
LABEL_39:
        __break(0x5512u);
        return _cam_irq_controller_read_registers(result);
      }
    }
LABEL_29:
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
    {
      if ( (_DWORD)v21 )
      {
        v31 = 0;
        do
        {
          cam_io_w_mb(
            *(unsigned int *)(*(_QWORD *)(v10 - 64) + 4LL * (int)v31),
            *(_QWORD *)(v5 + 16) + *(unsigned int *)(*(_QWORD *)(v5 + 32) + 112LL * (int)v31 + 8));
          ++v31;
        }
        while ( v31 < *(_DWORD *)(v5 + 24) );
      }
LABEL_33:
      v32 = *(unsigned int *)(v5 + 48);
      if ( (_DWORD)v32 )
        cam_io_w_mb(*(unsigned int *)(v5 + 52), *(_QWORD *)(v5 + 16) + v32);
    }
  }
LABEL_35:
  result = 0;
LABEL_36:
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
  {
    v33 = result;
    raw_spin_unlock_irqrestore(v5 + 320, v6);
    return v33;
  }
  return result;
}
