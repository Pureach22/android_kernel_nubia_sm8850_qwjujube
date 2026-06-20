__int64 __fastcall integration_test_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _QWORD *v6; // x20
  int v7; // w0
  int v8; // w22
  __int64 v9; // x8
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v11[0] = 0;
  v6 = *(_QWORD **)(v5 + 152);
  v7 = kstrtoull(a3, 10, v11);
  if ( v7 )
  {
    a4 = v7;
  }
  else if ( v11[0] == 1 && (unsigned int)*(_QWORD *)(v6[2] + 968LL) == 1 )
  {
    writel_relaxed(0xC5ACCE55, (unsigned int *)(*v6 + 4016LL));
    __dsb(0xFu);
    writel_relaxed(1u, (unsigned int *)(*v6 + 3840LL));
    v8 = 9;
    do
    {
      writel_relaxed(0x400E9600u, (unsigned int *)(*v6 + 3824LL));
      writel_relaxed(0x401E9600u, (unsigned int *)(*v6 + 3824LL));
      writel_relaxed(0x401E9700u, (unsigned int *)(*v6 + 3824LL));
      writel_relaxed(0x400E9700u, (unsigned int *)(*v6 + 3824LL));
      --v8;
    }
    while ( v8 );
    writel_relaxed(0, (unsigned int *)(*v6 + 3840LL));
    v9 = *v6;
    __dsb(0xFu);
    writel_relaxed(0, (unsigned int *)(v9 + 4016));
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
