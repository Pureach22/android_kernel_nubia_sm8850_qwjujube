__int64 __fastcall sde_hw_qdss_init(int a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x1
  unsigned int v10; // w2
  int v11; // w9
  int v12; // w8
  int v13; // w4
  __int64 v14; // x19
  __int64 v16; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v18; // x23
  __int64 (__fastcall *v19)(_QWORD, _QWORD, _QWORD); // x0

  v6 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  if ( !v6 )
    return -12;
  while ( 1 )
  {
    v7 = a3[4822];
    if ( !v7 )
      break;
    if ( a3[4828] == a1 )
    {
      v8 = 4824;
LABEL_5:
      v9 = (unsigned __int64)&a3[v8];
      goto LABEL_6;
    }
    if ( v7 == 1 )
      break;
    if ( a3[4840] == a1 )
    {
      v8 = 4836;
      goto LABEL_5;
    }
    if ( v7 == 2 )
      break;
    if ( a3[4852] == a1 )
    {
      v8 = 4848;
      goto LABEL_5;
    }
    if ( v7 == 3 )
      break;
    if ( a3[4864] == a1 )
    {
      v8 = 4860;
      goto LABEL_5;
    }
    if ( v7 == 4 )
      break;
    if ( a3[4876] == a1 )
    {
      v8 = 4872;
      goto LABEL_5;
    }
    if ( v7 == 5 )
      break;
    if ( a3[4888] == a1 )
    {
      v8 = 4884;
      goto LABEL_5;
    }
    if ( v7 == 6 )
      break;
    if ( a3[4900] == a1 )
    {
      v8 = 4896;
      goto LABEL_5;
    }
    if ( v7 == 7 )
      break;
    if ( a3[4912] == a1 )
    {
      v16 = 4908;
      goto LABEL_31;
    }
    if ( v7 == 8 )
      break;
    if ( a3[4924] == a1 )
    {
      v16 = 4920;
      goto LABEL_31;
    }
    if ( v7 == 9 )
      break;
    if ( a3[4936] == a1 )
    {
      v16 = 4932;
      goto LABEL_31;
    }
    if ( v7 == 10 )
      break;
    if ( a3[4948] == a1 )
    {
      v16 = 4944;
      goto LABEL_31;
    }
    if ( v7 == 11 )
      break;
    if ( a3[4960] == a1 )
    {
      v16 = 4956;
LABEL_31:
      v9 = (unsigned __int64)&a3[v16];
LABEL_6:
      v10 = *(_DWORD *)(v9 + 20);
      v11 = *(_DWORD *)(v9 + 24);
      v12 = *a3;
      *(_QWORD *)v6 = a2;
      *(_DWORD *)(v6 + 8) = v10;
      *(_DWORD *)(v6 + 12) = v11;
      *(_DWORD *)(v6 + 20) = v12;
      *(_DWORD *)(v6 + 24) = 0x10000;
      if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
      {
        v13 = *(_DWORD *)(v6 + 16);
        *(_QWORD *)(v6 + 40) = v9;
        *(_QWORD *)(v6 + 48) = sde_hw_qdss_enable_qdss_events;
        *(_DWORD *)(v6 + 32) = a1;
        v14 = v6;
        sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v9, v10, v11 + v10, v13);
        return v14;
      }
      break;
    }
    if ( v7 == 12 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_QWORD *)(StatusReg + 80);
    v19 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_qdss_init__alloc_tag;
    v6 = _kmalloc_cache_noprof(v19, 3520, 72);
    *(_QWORD *)(StatusReg + 80) = v18;
    if ( !v6 )
      return -12;
  }
  kfree(v6);
  return -22;
}
