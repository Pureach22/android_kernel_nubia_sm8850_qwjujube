unsigned __int64 __fastcall tmc_etr_get_sysfs_buffer(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x8
  unsigned __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x21
  char v7; // w22
  __int64 v8; // x8
  void (__fastcall *v9)(_QWORD); // x8
  unsigned __int64 v10; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  raw_spin_lock_irqsave(v2 + 104);
  v3 = *(_QWORD *)(v2 + 288);
  if ( v3 && *(_QWORD *)(v3 + 16) == *(_DWORD *)(v2 + 132) )
  {
    v4 = 0;
    if ( (*(_BYTE *)(v2 + 112) & 1) != 0 )
      goto LABEL_12;
    goto LABEL_11;
  }
  raw_spin_unlock_irqrestore(v2 + 104);
  if ( *(_DWORD *)(v2 + 332) == 2 && *(_DWORD *)(*(_QWORD *)(v2 + 336) + 8LL) == 1 )
    v5 = 0x4000000;
  else
    v5 = *(unsigned int *)(v2 + 132);
  v4 = tmc_alloc_etr_buf(v2, v5, 0);
  if ( v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    raw_spin_lock_irqsave(v2 + 104);
    if ( (*(_BYTE *)(v2 + 112) & 1) != 0 )
      goto LABEL_12;
LABEL_11:
    if ( (unsigned int)*(_QWORD *)(a1 + 968) != 2 )
    {
      v10 = *(_QWORD *)(v2 + 288);
      if ( v10 )
      {
        if ( v4 )
        {
          if ( *(_QWORD *)(v10 + 16) != *(_QWORD *)(v4 + 16) )
          {
            *(_QWORD *)(v2 + 288) = v4;
            v4 = v10;
          }
          raw_spin_unlock_irqrestore(v2 + 104);
          v6 = 0;
          v7 = 1;
          v8 = *(_QWORD *)(v4 + 48);
          if ( v8 )
            goto LABEL_14;
          goto LABEL_21;
        }
      }
      else
      {
        *(_QWORD *)(v2 + 288) = v4;
      }
      raw_spin_unlock_irqrestore(v2 + 104);
      return *(_QWORD *)(v2 + 288);
    }
LABEL_12:
    raw_spin_unlock_irqrestore(v2 + 104);
    v6 = -16;
    if ( !v4 )
      return v6;
    v7 = 0;
    v8 = *(_QWORD *)(v4 + 48);
    if ( v8 )
    {
LABEL_14:
      v9 = *(void (__fastcall **)(_QWORD))(v8 + 24);
      if ( v9 )
        goto LABEL_22;
    }
LABEL_21:
    __break(0x800u);
    v9 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v4 + 48) + 24LL);
LABEL_22:
    if ( *((_DWORD *)v9 - 1) != 1050944703 )
      __break(0x8228u);
    v9(v4);
    kfree(v4);
    if ( (v7 & 1) == 0 )
      return v6;
    return *(_QWORD *)(v2 + 288);
  }
  return v4;
}
