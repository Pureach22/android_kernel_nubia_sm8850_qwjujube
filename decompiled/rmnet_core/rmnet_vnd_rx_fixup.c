__int64 __fastcall rmnet_vnd_rx_fixup(__int64 result, unsigned int a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x8
  __int64 v4; // x10

  v2 = *(_QWORD *)(result + 2704);
  v3 = (_QWORD *)(_ReadStatusReg(TPIDR_EL1) + v2);
  v4 = v3[1] + a2;
  ++*v3;
  v3[1] = v4;
  return result;
}
