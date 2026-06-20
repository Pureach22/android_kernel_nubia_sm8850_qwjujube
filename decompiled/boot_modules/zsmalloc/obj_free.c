__int64 __fastcall obj_free(__int64 result, unsigned __int64 a2)
{
  __int64 v2; // x9
  _DWORD *v3; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x9

  v2 = ((a2 >> 18) & 0x3FFFFFFFFFC0LL) - ((__int64)memstart_addr >> 12 << 6) - 0x140000000LL;
  v3 = *(_DWORD **)(((a2 >> 18) & 0x3FFFFFFFFFC0LL) - ((__int64)memstart_addr >> 12 << 6) - 0x13FFFFFD8LL);
  if ( (*v3 & 0x3FC000) != 0x160000 )
  {
    __break(0x800u);
    JUMPOUT(0x7658);
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  ++*(_DWORD *)(StatusReg + 3220);
  if ( (*(_BYTE *)v3 & 1) != 0 )
    *(_QWORD *)(v2 + 32) = 0;
  else
    *(_QWORD *)((((v2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + (((_WORD)a2 * (_WORD)result) & 0xFFF)) = (unsigned int)(2 * v3[2]);
  v3[2] = a2 & 0xFFFFFF;
  --*(_DWORD *)(StatusReg + 3220);
  v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v5;
  if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
    result = preempt_schedule(result);
  --v3[1];
  return result;
}
