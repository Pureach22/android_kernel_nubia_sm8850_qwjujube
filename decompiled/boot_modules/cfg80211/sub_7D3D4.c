void __fastcall sub_7D3D4(__int64 a1, __int64 a2)
{
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v2 + 24) = a2;
    JUMPOUT(0x7D41C);
  }
  JUMPOUT(0x7D32C);
}
