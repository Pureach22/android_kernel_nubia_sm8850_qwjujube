unsigned __int64 __fastcall kgsl_drawobj_add_bind(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v5; // x20
  unsigned __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-28h] BYREF
  __int64 v8; // [xsp+10h] [xbp-20h]
  __int64 v9; // [xsp+18h] [xbp-18h]
  __int64 v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 8);
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  result = get_aux_command(a3, a4, 1, (__int64)&v7, 0x20u);
  if ( !(_DWORD)result )
  {
    result = kgsl_sharedmem_create_bind_op(v5, (unsigned int)v10, v7, (unsigned int)v8, v9);
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(result + 24) = kgsl_drawobj_bind_callback;
      *(_QWORD *)(result + 32) = a2;
      *(_QWORD *)(a2 + 64) = result;
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
