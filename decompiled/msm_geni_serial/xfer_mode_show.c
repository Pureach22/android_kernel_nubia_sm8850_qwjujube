__int64 __fastcall xfer_mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 result; // x0

  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 584LL);
  if ( v3 == 2 )
  {
    LODWORD(result) = scnprintf(a3, 8, "SE_DMA\n");
    return (int)result;
  }
  if ( v3 == 1 )
  {
    LODWORD(result) = scnprintf(a3, 6, "FIFO\n");
    return (int)result;
  }
  return 0;
}
