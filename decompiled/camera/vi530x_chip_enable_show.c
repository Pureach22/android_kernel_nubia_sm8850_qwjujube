__int64 __fastcall vi530x_chip_enable_show(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_QWORD *)(a1 + 152) )
    return (int)scnprintf(a3, 4096, "%u\n", (unsigned __int8)tof_enable);
  else
    return -22;
}
