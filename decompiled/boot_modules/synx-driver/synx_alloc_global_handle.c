__int64 __fastcall synx_alloc_global_handle(_DWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x5
  __int64 v12; // x4
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  result = synx_global_alloc_index(&v13, a2, a3, a4, a5, a6);
  if ( !(_DWORD)result )
  {
    if ( v13 <= 0xFFF )
      v12 = v13 + 0x100000;
    else
      v12 = 0;
    *a1 = v12;
    if ( (synx_debug & 8) != 0 )
    {
      printk(&unk_2B708, &unk_2A972, "synx_alloc_global_handle", 564, v12, (unsigned int)v12);
      v12 = (unsigned int)*a1;
    }
    result = synx_global_init_coredata(v12, a2, v9, v10, v12, v11);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
