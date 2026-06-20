__int64 __fastcall qdf_flex_mem_seg_alloc(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x1
  __int64 v5; // x20

  v2 = 32LL * *(unsigned __int16 *)(a1 + 42);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
  {
    v4 = 2336;
  }
  else
  {
    v4 = 2336;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      if ( *(_DWORD *)(StatusReg + 16) )
        v4 = 2336;
      else
        v4 = 3520;
    }
  }
  v5 = _kmalloc_noprof(v2 + 32, v4);
  if ( v5 )
  {
    *(_BYTE *)(v5 + 16) = 1;
    *(_QWORD *)(v5 + 24) = v5 + 32;
    *(_DWORD *)(v5 + 20) = 0;
    qdf_list_insert_back((_QWORD *)a1, (_QWORD *)v5);
  }
  return v5;
}
