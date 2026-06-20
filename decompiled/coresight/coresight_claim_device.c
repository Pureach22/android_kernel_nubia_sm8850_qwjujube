__int64 __fastcall coresight_claim_device(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x8
  unsigned int v4; // w19

  if ( a1 )
  {
    writel_relaxed(3316436565LL, *(_QWORD *)(a1 + 40) + 4016LL);
    __dsb(0xFu);
    v2 = coresight_claim_device_unlocked(a1);
    v3 = *(_QWORD *)(a1 + 40);
    __dsb(0xFu);
    v4 = v2;
    writel_relaxed(0, v3 + 4016);
  }
  else
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  return v4;
}
