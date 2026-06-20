__int64 __fastcall qcom_ice_hwkm_init(__int64 result)
{
  __int64 v1; // x19

  if ( *(_BYTE *)(result + 33) == 1 )
  {
    v1 = result;
    writel(6, *(_QWORD *)(result + 8) + 36864LL);
    writel(0xFFFFFFFFLL, *(_QWORD *)(v1 + 8) + 53248LL);
    writel(0xFFFFFFFFLL, *(_QWORD *)(v1 + 8) + 53252LL);
    writel(0xFFFFFFFFLL, *(_QWORD *)(v1 + 8) + 53256LL);
    writel(0xFFFFFFFFLL, *(_QWORD *)(v1 + 8) + 53260LL);
    writel(0xFFFFFFFFLL, *(_QWORD *)(v1 + 8) + 53264LL);
    result = writel(8, *(_QWORD *)(v1 + 8) + 40968LL);
    *(_BYTE *)(v1 + 34) = 1;
  }
  return result;
}
