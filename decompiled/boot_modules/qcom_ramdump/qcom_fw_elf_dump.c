__int64 __fastcall qcom_fw_elf_dump(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned __int64 v4; // x22
  _DWORD *v5; // x23
  __int64 **v6; // x0
  __int64 **v7; // x1
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 **v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 8);
  v9 = (__int64)&v9;
  v10 = (__int64 **)&v9;
  if ( !*(_WORD *)(v3 + 44) )
  {
LABEL_13:
    qcom_elf_dump(&v9, a2, 1u);
    result = 0;
    goto LABEL_14;
  }
  v4 = 0;
  v5 = (_DWORD *)(v3 + 76);
  _ReadStatusReg(SP_EL0);
  while ( *(v5 - 6) != 1 || (*v5 & 0x7000000) == 0x2000000 || !*(v5 - 1) )
  {
LABEL_4:
    ++v4;
    v5 += 8;
    if ( v4 >= *(unsigned __int16 *)(v3 + 44) )
      goto LABEL_13;
  }
  v6 = (__int64 **)_kmalloc_cache_noprof(mutex_unlock, 3520, 40);
  if ( v6 )
  {
    v7 = v10;
    v6[2] = (__int64 *)(unsigned int)*(v5 - 3);
    v6[4] = (__int64 *)(unsigned int)*(v5 - 1);
    if ( v7 == v6 || *v7 != &v9 )
    {
      _list_add_valid_or_report();
    }
    else
    {
      v10 = v6;
      *v6 = &v9;
      v6[1] = (__int64 *)v7;
      *v7 = (__int64 *)v6;
    }
    goto LABEL_4;
  }
  result = 4294967284LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
