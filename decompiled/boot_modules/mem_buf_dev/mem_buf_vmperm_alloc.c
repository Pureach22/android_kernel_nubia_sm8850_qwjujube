__int64 __fastcall mem_buf_vmperm_alloc(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v4; // [xsp+0h] [xbp-10h] BYREF
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 7;
  v5 = current_vmid;
  result = mem_buf_vmperm_alloc_flags(a1, 0, &v5, (__int64)&v4, 1u, a2, a3, 0xFFFFFFFF);
  _ReadStatusReg(SP_EL0);
  return result;
}
