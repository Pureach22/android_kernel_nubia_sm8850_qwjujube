__int64 __fastcall eval_need(__int64 a1)
{
  __int64 v2; // x19
  int v3; // w9
  int v4; // w10
  unsigned int v5; // w9
  unsigned int v6; // w8
  unsigned int v7; // w21
  int v8; // w22
  __int64 v9; // x0
  unsigned int v10; // w4
  __int64 v11; // x23
  _BOOL4 v12; // w6
  int v13; // w5
  unsigned int v14; // w20

  if ( *(_BYTE *)a1 != 1 )
    return 0;
  v2 = raw_spin_lock_irqsave(&state_lock);
  if ( *(_DWORD *)(a1 + 148) || (*(_BYTE *)(a1 + 136) & 1) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 136) & 1) != 0 )
    {
      v5 = *(_DWORD *)(a1 + 12);
      goto LABEL_16;
    }
LABEL_23:
    v7 = *(_DWORD *)(a1 + 72);
    goto LABEL_24;
  }
  v3 = *(_DWORD *)(a1 + 140);
  if ( (unsigned int)v3 >= *(_DWORD *)(a1 + 92) )
  {
    if ( (*(_BYTE *)(a1 + 136) & 1) != 0 )
    {
      v5 = *(_DWORD *)(a1 + 72);
      goto LABEL_16;
    }
    goto LABEL_23;
  }
  v4 = *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 104);
  if ( v3 <= v4 )
    v5 = *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 104);
  else
    v5 = v4 + 1;
  if ( *(_DWORD *)(a1 + 96) > 4u )
    ++v5;
  if ( v5 <= *(_DWORD *)(a1 + 248) )
    v5 = *(_DWORD *)(a1 + 248);
  if ( (*(_BYTE *)(a1 + 136) & 1) == 0 )
    goto LABEL_23;
LABEL_16:
  v6 = *(_DWORD *)(a1 + 4);
  if ( v6 <= v5 )
    v6 = v5;
  if ( v6 >= *(_DWORD *)(a1 + 12) )
    v7 = *(_DWORD *)(a1 + 12);
  else
    v7 = v6;
LABEL_24:
  v8 = *(_DWORD *)(a1 + 88);
  v9 = ktime_get();
  v10 = *(_DWORD *)(a1 + 68);
  v11 = v9 / 1000000;
  if ( v7 <= v10 )
  {
    if ( v7 == v8 && v7 == v10 )
    {
      v13 = 0;
      v12 = 0;
      *(_QWORD *)(a1 + 112) = v11;
      goto LABEL_32;
    }
    if ( v11 - *(_QWORD *)(a1 + 112) < *(unsigned int *)(a1 + 16) )
    {
      v13 = 0;
      v12 = 0;
      goto LABEL_32;
    }
    v12 = v10 > v7;
  }
  else
  {
    v12 = _sw_hweight64(*(_DWORD *)(a1 + 80) & ((unsigned int)cpus_part_paused_by_us | (unsigned int)cpus_paused_by_us)) != 0;
  }
  v13 = 1;
  *(_QWORD *)(a1 + 112) = v11;
  *(_DWORD *)(a1 + 88) = v7;
LABEL_32:
  v14 = v13 & v12;
  raw_spin_unlock_irqrestore(&state_lock, v2);
  return v14;
}
