__int64 __fastcall hal_reg_wr_fail_history_add(__int64 result, int a2, int a3, int a4)
{
  __int64 v5; // x8
  unsigned int v11; // w10
  unsigned int v12; // w10

  _X9 = *(unsigned int **)(result + 74456);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v11 = __ldxr(_X9);
    v12 = v11 + 1;
  }
  while ( __stlxr(v12, _X9) );
  __dmb(0xBu);
  v5 = *(_QWORD *)(result + 74456) + 24LL * (v12 & 7);
  __isb(0xFu);
  *(_QWORD *)(v5 + 8) = _ReadStatusReg(CNTVCT_EL0);
  *(_DWORD *)(v5 + 16) = a2;
  *(_DWORD *)(v5 + 20) = a3;
  *(_DWORD *)(v5 + 24) = a4;
  return result;
}
