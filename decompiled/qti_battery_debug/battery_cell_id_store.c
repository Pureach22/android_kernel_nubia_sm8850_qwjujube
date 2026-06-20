__int64 __fastcall battery_cell_id_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (unsigned int)kstrtouint(a3, 0, *(_QWORD *)(a1 + 152) + 4780LL) )
    return -22;
  else
    return a4;
}
