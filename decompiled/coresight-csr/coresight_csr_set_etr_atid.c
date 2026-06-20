__int64 __fastcall coresight_csr_set_etr_atid(__int64 a1, unsigned int a2, char a3, __int64 path)
{
  __int64 sink; // x0
  __int64 v7; // x23
  __int64 v8; // x0
  int v9; // w8
  __int64 result; // x0
  const char *v11; // x22
  __int64 v12; // x21
  _UNKNOWN **v13; // x25
  __int64 v14; // x22
  unsigned __int64 v15; // x21
  int v16; // w23
  __int64 v17; // x1
  unsigned int v18; // w8
  unsigned int v19; // w19
  __int64 v20; // x8
  bool v21; // zf
  int v22; // w10
  int v23; // w13
  int v24; // w10
  const char *v25; // [xsp+8h] [xbp-68h] BYREF
  int v26; // [xsp+14h] [xbp-5Ch] BYREF
  _QWORD v27[11]; // [xsp+18h] [xbp-58h] BYREF

  v27[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v25 = nullptr;
  if ( !path )
  {
    path = coresight_get_path();
    if ( !path )
      goto LABEL_20;
  }
  sink = coresight_get_sink(path);
  if ( !sink )
    goto LABEL_20;
  v7 = sink;
  v8 = *(_QWORD *)(*(_QWORD *)(sink + 152) + 744LL);
  memset(v27, 0, 80);
  v9 = _of_parse_phandle_with_args(v8, "coresight-csr", 0, 0, 0, v27);
  result = 0;
  if ( v9 || !v27[0] )
    goto LABEL_21;
  if ( (unsigned int)of_property_read_string(v27[0], "device-name", &v25) )
  {
    result = 0;
    goto LABEL_21;
  }
  v11 = v25;
  v12 = raw_spin_lock_irqsave(&csr_spinlock);
  v13 = &csr_list;
  while ( 1 )
  {
    v13 = (_UNKNOWN **)*v13;
    if ( v13 == &csr_list )
      break;
    if ( !strcmp((const char *)*(v13 - 1), v11) )
    {
      v14 = (__int64)(v13 - 1);
      goto LABEL_13;
    }
  }
  v14 = -22;
LABEL_13:
  raw_spin_unlock_irqrestore(&csr_spinlock, v12);
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(v7 + 152) + 744LL), "csr-atid-offset", &v26, 1, 0)
      & 0x80000000) != 0
    || !v14 )
  {
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v15 = v14 - 120;
  result = 4294967274LL;
  if ( v14 != 120 && v15 <= 0xFFFFFFFFFFFFF000LL )
  {
    v16 = v26;
    if ( v26 )
    {
      v17 = raw_spin_lock_irqsave(v14 + 32);
      *(_DWORD *)(*(_QWORD *)(v14 - 120) + 4016LL) = -978530731;
      __dsb(0xFu);
      v18 = (a2 >> 3) & 0x1FFFFFFC;
      if ( v18 < 0xD )
      {
        v20 = v16 + v18;
        v21 = (a3 & 1) == 0;
        v19 = 0;
        v22 = *(_DWORD *)(*(_QWORD *)v15 + v20);
        v23 = v22 | (1 << a2);
        v24 = v22 & ~(1 << a2);
        if ( !v21 )
          v24 = v23;
        *(_DWORD *)(*(_QWORD *)v15 + v20) = v24;
        __dsb(0xFu);
        *(_DWORD *)(*(_QWORD *)v15 + 4016LL) = 0;
      }
      else
      {
        __dsb(0xFu);
        v19 = -22;
        *(_DWORD *)(*(_QWORD *)v15 + 4016LL) = 0;
      }
      raw_spin_unlock_irqrestore(v14 + 32, v17);
      result = v19;
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
