unsigned __int64 __fastcall qcom_dma_pgprot(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a1 + 844) & 0x20) != 0 )
    return a2;
  else
    return a2 & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
}
