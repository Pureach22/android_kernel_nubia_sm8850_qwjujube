__int64 __fastcall rmnet_vnd_tx_fixup(__int64 result, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x10

  v2 = *(_QWORD *)(result + 2704);
  v3 = _ReadStatusReg(TPIDR_EL1) + v2;
  v4 = *(_QWORD *)(v3 + 24) + a2;
  ++*(_QWORD *)(v3 + 16);
  *(_QWORD *)(v3 + 24) = v4;
  return result;
}
